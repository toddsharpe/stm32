#include "stm32f7xx.h"
#include "system_stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "rtos/Kernel.h"
#include "stm32/GpioPin.h"
#include "stm32/Spi.h"
#include "Drivers/St7789.h"
#include "Graphics/Color.h"

// Board and Kernel
NucleoF746ZG board = {};
Kernel kernel(board);

//Graphics buffer
GraphicsBuffer<240, 240> graphicsBuffer;

//Thread Tasks
void task1()
{
	board.Led1.Set(false);

	while (true)
	{
		board.Led1.Toggle();
		kernel.Sleep(1000);
	}
}

void spiTask()
{
	//SPI
	GpioPin<Port_A, 5> spi1_sck;
	GpioPin<Port_A, 7> spi1_mosi;
	spi1_sck.Init(GpioSpi1);
	spi1_mosi.Init(GpioSpi1);
	
	Spi spi1(SPI1);
	spi1.Init(SpiMode3);

	//Device pins
	GpioPin<Port_G, 3> dcPin;
	GpioPin<Port_G, 2> resetPin;
	dcPin.Init(GpioOutput);
	resetPin.Init(GpioOutput, true);

	//Screen
	St7789<240, 240> screen(spi1, dcPin, resetPin);
	screen.Init();

	board.Led3.Set(false);

	bool s = true;
	KernelStats stats = {};
	while (true)
	{
		kernel.GetStats(stats);
		
		graphicsBuffer.FillScreen(s ? Graphics::Colors::Black : Graphics::Colors::Blue);
		graphicsBuffer.DrawText({25, 25}, "Kernel stats\r\n", Colors::Magenta);
		graphicsBuffer.DrawPrintf({25, 35}, Colors::Magenta, "  Threads: %d\r\n", stats.Threads);
		graphicsBuffer.DrawPrintf({25, 45}, Colors::Magenta, "  SysTicks: %d\r\n", stats.SysTicks);

		screen.Write(graphicsBuffer);
		board.Led3.Toggle();
		s = !s;
		kernel.Sleep(5000);
	}
}

int main(void)
{
	board.Init();
	kernel.Init();
	kernel.RegisterInterrupt(board.uart.GetInterupt(), {&Usart::OnInterrupt, &board.uart});

	board.Printf("Application Active\r\n");

	kernel.CreateThread(&task1);
	kernel.CreateThread(&spiTask);
	kernel.Run();
}

extern "C" void exception_handler(const HardwareStackFrame* frame, const SoftwareStackFrame* context)
{
	const uint32_t irq = (__get_IPSR() & 0xFF) - 16;
	kernel.HandleInterrupt((InterruptVector)irq, frame, context);
}

void DebugPrintf(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	board.Printf(format, args);
	va_end(args);
}

void Bugcheck(const char* file, const char* line, const char* format, ...)
{
	board.Printf("Kernel Bugcheck\r\n");
	board.Printf("\r\n%s\r\n%s\r\n", file, line);

	va_list args;
	va_start(args, format);
	board.Printf(format, args);
	board.Printf("\r\n");
	va_end(args);

	kernel.Stop();
	while (1);
}

void ThreadSleep(const milli_t ms)
{
	kernel.Sleep(ms);
}

void RegisterInterrupt(const InterruptVector interrupt, const InterruptContext& context)
{
	kernel.RegisterInterrupt(interrupt, context);
}