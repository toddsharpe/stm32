// DOC: ST7789.pdf

#pragma once

#include "DiscretePin.h"
#include "stm32/Spi.h"
#include "stm32/DmaStream.h"
#include "Graphics/GraphicsBuffer.h"
#include "Assert.h"

//TODO(tsharpe): Don't hardcode DMA2_STREAM3
#include "stm32f746xx.h"

extern void ThreadSleep(const milli_t ms);
extern void RegisterInterrupt(const InterruptVector interrupt, const InterruptContext& context);

//Framebuffer is sent via DMA, commands/simple data is sent with SPI polling.
template<size_t Width, size_t Height>
class St7789
{
public:
	static void OnTransferComplete(void* arg) { ((St7789*)arg)->OnTransferComplete(); };

	St7789(Spi& spi, DiscretePin& dcPin, DiscretePin& resetPin) :
		m_spi(spi),
		m_dcPin(dcPin),
		m_resetPin(resetPin),
		m_dmaStream(DMA2_Stream3, DMA2),
		m_xOffset(0),
		m_yOffset(0)
	{

	}

	void Init()
	{
		m_resetPin.Set(true);
		ThreadSleep(50);
		m_resetPin.Set(false);
		ThreadSleep(50);
		m_resetPin.Set(true);
		ThreadSleep(50);

		SendCommand(Command::SWRESET);
		ThreadSleep(150);

		SendCommand(Command::SLPOUT);
		ThreadSleep(500);

		SendCommand(Command::COLMOD);
		SendData(COLOR_MODE_16bit);
		ThreadSleep(10);

		SendCommand(Command::MADCTL);
		{
			MADCTL_REG reg = { 0 };
			//reg.MV = 1;
			SendData(reg.AsUint8);
		}

		SendCommand(Command::INVON);
		ThreadSleep(10);
		SendCommand(Command::NORON);
		ThreadSleep(10);
		SendCommand(Command::DISPON);
		ThreadSleep(500);

		m_dmaStream.Init(SPI1_TX_Stream3Channel3);
		m_dmaStream.TransferComplete.Context = this;
		m_dmaStream.TransferComplete.Handler = &St7789::OnTransferComplete;

		RegisterInterrupt(m_dmaStream.GetInterupt(), {&DmaStream::OnInterrupt, &m_dmaStream});
	}

	void Write(GraphicsBuffer<Width, Height>& framebuffer)
	{
		//Set address
		SetAddressWindow(0, 0, Width - 1, Height - 1);

		AssertOp(Width * Height, <, DmaStream::MaxTransfer);
		SendDataDMA((uint16_t*)framebuffer.GetAddress(), Width * Height);
	}

private:
	static constexpr uint8_t COLOR_MODE_16bit = 0x55; // RGB565 (16bit)

	//DOC 9.1 System Function Command Table 1
	enum Command : uint8_t
	{
		NOP = 0x00,
		SWRESET = 0x01,
		RDDID = 0x04,
		RDDST = 0x09,

		SLPIN = 0x10,
		SLPOUT = 0x11,
		PTLON = 0x12,
		NORON = 0x13,

		INVOFF = 0x20,
		INVON = 0x21,
		DISPOFF = 0x28,
		DISPON = 0x29,
		CASET = 0x2A,
		RASET = 0x2B,
		RAMWR = 0x2C,
		MADCTL = 0x36,
		COLMOD = 0x3A,
	};

	//9.1.28 MADCTL (36h): Memory Data Access Control 
	struct MADCTL_REG
	{
		union
		{
			struct
			{
				uint8_t Reserved : 2;
				uint8_t MH : 1; // Display Data Latch Data Order. 0 = Left to right, 1 = Right to Left
				uint8_t RGB : 1; // RGB/BGR Order. 0 = RGB, 1 = BGR
				uint8_t ML : 1; // Line Address Order. 0 = Top to bottom, 1 = Bottom to Top
				uint8_t MV : 1; // Page/Column Order. 0 = Normal mode, 1 = Reverse mode
				uint8_t MX : 1; // Column Address Order. 0 = Left to Right. 1 = Right to Left.
				uint8_t MY : 1; // Page Address Order. 0 = Top to Bottom, 1 = Bottom to top.
			};
			uint8_t AsUint8;
		};
	};

	void OnTransferComplete()
	{
		m_event.Set();
	}

	//NOTE(tsharpe): This method doesn't allow for offsets
	void SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
	{
		uint16_t x_start = x0, x_end = x1;
		uint16_t y_start = y0, y_end = y1;
		
		uint8_t b[] = {0, 0, 0, (uint8_t)x_end};
		SendData(b, sizeof(b));

		//Column address set
		SendCommand(Command::CASET);
		{
			uint8_t data[] = {(uint8_t)(x_start >> 8), (uint8_t)(x_start & 0xFF), (uint8_t)(x_end >> 8), (uint8_t)(x_end & 0xFF)};
			SendData(data, sizeof(data));
		}

		//Row address set
		SendCommand(Command::RASET);
		{
			uint8_t data[] = {(uint8_t)(y_start >> 8), (uint8_t)(y_start & 0xFF), (uint8_t)(y_end >> 8), (uint8_t)(y_end & 0xFF)};
			SendData(data, sizeof(data));
		}

		/* Write to RAM */
		SendCommand(Command::RAMWR);
	}

	void SendCommand(Command command)
	{
		m_dcPin.Set(false);

		uint8_t buffer[1] = {};
		buffer[0] = (uint8_t)command;
		m_spi.Write(buffer, sizeof(buffer));
	}

	void SendData(uint8_t data)
	{
		m_dcPin.Set(true);

		uint8_t buffer[1] = {};
		buffer[0] = data;
		m_spi.Write(buffer, sizeof(buffer));
	}

	void SendData(const uint8_t* buffer, size_t length)
	{
		m_dcPin.Set(true);

		m_spi.Write(buffer, length);
	}

	void SendDataDMA(const uint16_t* buffer, size_t length)
	{
		m_dcPin.Set(true);

		m_dmaStream.Start(buffer, m_spi.GetPeripheralAddress(), length);
		while (!m_event.IsSignalled());
	}

	Spi& m_spi;
	DiscretePin& m_dcPin;
	DiscretePin& m_resetPin;

	DmaStream m_dmaStream;
	KEvent m_event;

	size_t m_xOffset;
	size_t m_yOffset;
};