#pragma once

#include "stm32f746xx.h"
#include "stm32f7xx.h"
#include "Callback.h"

enum DmaStreamDir
{
	PeriphToMemory = 0,
	MemoryToPeriph = DMA_SxCR_DIR_0,
	MemoryToMem = DMA_SxCR_DIR_1
};

enum DmaStreamDataSize
{
	Byte = 0,
	HalfWord = 1,
	Word = 2,
};

struct DmaStreamConfig
{
	uint8_t Channel;
	DmaStreamDir Direction;
	bool MemInc;
	bool PeriphInc;
	DmaStreamDataSize MemSize;
	DmaStreamDataSize PeriphSize;
};

static constexpr DmaStreamConfig const SPI1_TX_Stream3Channel3 =
{
	.Channel = 3,
	.Direction = DmaStreamDir::MemoryToPeriph,
	.MemInc = true,
	.PeriphInc = false,
	.MemSize = DmaStreamDataSize::HalfWord,
	.PeriphSize = DmaStreamDataSize::HalfWord,
};

class DmaStream
{
public:
	static constexpr size_t MaxTransfer = (1 << 16) - 1;

	static void OnInterrupt(void* arg) { ((DmaStream*)arg)->OnInterrupt(); };

	DmaStream(DMA_Stream_TypeDef* stream, DMA_TypeDef* dma) : TransferError(), TransferComplete(), m_stream(stream), m_dma(dma)
	{
		Assert(m_dma == DMA2);
		Assert(m_stream == DMA2_Stream3);
	}

	Callback TransferError;
	Callback TransferComplete;

	void Init(const DmaStreamConfig& config)
	{
		Assert(config.Direction == DmaStreamDir::MemoryToPeriph);

		//Stop any in progress transactions
		CLEAR_BIT(m_stream->CR, DMA_SxCR_EN);
		while(READ_BIT(m_stream->CR, DMA_SxCR_EN));

		//Set config
		MODIFY_REG(m_stream->CR, DMA_SxCR_CHSEL, config.Channel << DMA_SxCR_CHSEL_Pos);
		MODIFY_REG(m_stream->CR, DMA_SxCR_DIR, config.Direction);
		MODIFY_REG(m_stream->CR, DMA_SxCR_PINC, config.PeriphInc ? DMA_SxCR_PINC : 0);
		MODIFY_REG(m_stream->CR, DMA_SxCR_MINC, config.MemInc ? DMA_SxCR_MINC : 0);
		MODIFY_REG(m_stream->CR, DMA_SxCR_MSIZE, config.MemSize << DMA_SxCR_MSIZE_Pos);
		MODIFY_REG(m_stream->CR, DMA_SxCR_PSIZE, config.PeriphSize << DMA_SxCR_PSIZE_Pos);

		//Enable direct mode
		MODIFY_REG(m_stream->FCR, DMA_SxFCR_DMDIS, 0);

		//Enable interrupts
		SET_BIT(m_stream->CR, DMA_SxCR_TCIE);//Transfer complete
		SET_BIT(m_stream->CR, DMA_SxCR_TEIE);//Transfer error
		SET_BIT(m_stream->CR, DMA_SxCR_DMEIE);//Direct mode error

		NVIC_EnableIRQ(GetInterupt());
	}

	void Start(const void* source, const void* destination, const size_t length)
	{
		AssertOp(length, <, MaxTransfer);

		m_dma->LIFCR |= DMA_LIFCR_CTCIF3|DMA_LIFCR_CTEIF3|DMA_LIFCR_CDMEIF3|DMA_LIFCR_CFEIF3;
		m_stream->PAR = (uint32_t)destination;
		m_stream->M0AR = (uint32_t)source;
		m_stream->NDTR = (uint16_t)length;

		//Start!
		SET_BIT(m_stream->CR, DMA_SxCR_EN);
	}

	IRQn_Type GetInterupt()
	{
		return IRQn_Type::DMA2_Stream3_IRQn;
	}

private:

	//NOTE(tsharpe): LISR is for streams 0-3, HISR for streams 4-7
	void OnInterrupt()
	{
		bool error = false;
		if (m_dma->LISR & DMA_LISR_FEIF3)
		{
			//Can be ignored in direct mode
			m_dma->LIFCR |= DMA_LIFCR_CFEIF3;
		}

		if (m_dma->LISR & DMA_LISR_DMEIF3)
		{
			m_dma->LIFCR |= DMA_LIFCR_CDMEIF3;
			error = true;
		}

		if (m_dma->LISR & DMA_LISR_TEIF3)
		{
			m_dma->LIFCR |= DMA_LIFCR_CTEIF3;
			error = true;
		}

		if (m_dma->LISR & DMA_LISR_HTIF3)
		{
			m_dma->LIFCR |= DMA_LIFCR_CHTIF3;
			//TODO(tsharpe): Half transfer callback
		}

		if (m_dma->LISR & DMA_LISR_TCIF3)
		{
			m_dma->LIFCR |= DMA_LIFCR_CTCIF3;
			CLEAR_BIT(m_stream->CR, DMA_SxCR_EN);

			if (TransferComplete.IsCallable() && !error)
				TransferComplete.Invoke();
		}

		if (error)
		{
			if (TransferError.IsCallable())
				TransferError.Invoke();
		}

		NVIC_ClearPendingIRQ(GetInterupt());
	}

	DMA_Stream_TypeDef* m_stream;
	DMA_TypeDef* m_dma;
};