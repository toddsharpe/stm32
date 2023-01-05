#include "rtos/Kernel.h"
#include "stm32/GpioPin.h"
#include "stm32/Spi.h"
#include "Drivers/St7789.h"
#include "Graphics/Color.h"
#include "Graphics/StaticFrameBuffer.h"
#include "UI/Window.h"
#include "UI/Label.h"

#include <sstream>

//Board and Kernel
extern Kernel kernel;

//Graphics buffer
Graphics::StaticFrameBuffer<240, 240> frameBuffer;

void DisplayTask()
{
	//SPI
	GpioPin<Port_A, 5> spi1_sck;
	GpioPin<Port_A, 7> spi1_mosi;
	spi1_sck.Init(GpioSpi1);
	spi1_mosi.Init(GpioSpi1);
	
	Spi spi1(SPI1);
	spi1.Init(SpiMode3);

	DmaStream dmaStream(DMA2_Stream3, DMA2);
	dmaStream.Init(SPI1_TX_Stream3Channel3);
	kernel.RegisterInterrupt(dmaStream.GetInterupt(), {&DmaStream::OnInterrupt, &dmaStream});

	//Device pins
	GpioPin<Port_G, 3> dcPin;
	GpioPin<Port_G, 2> resetPin;
	dcPin.Init(GpioOutput);
	resetPin.Init(GpioOutput, true);

	//Screen
	St7789<240, 240> screen(spi1, dmaStream, dcPin, resetPin);
	screen.Init();

	KernelStats stats = {};
	UI::Window window("Nucleo App");
	window.Background = Graphics::Colors::Black;

	UI::Label output("Output", {5, 25, 0, 0});
	window.Children.push_back(&output);

	while (true)
	{
		kernel.GetStats(stats);

		std::stringstream ss;
		ss << "Kernel stats" << std::endl;
		ss << "  Threads: " << stats.Threads << std::endl;
		ss << " SysTicks: " << stats.SysTicks << std::endl;
		output.Text = ss.str();
		
		window.Draw(frameBuffer);
		screen.Write(frameBuffer);

		kernel.Sleep(1000);
	}
}