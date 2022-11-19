#include "stm32f7xx.h"
#include "system_stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "rtos/Kernel.h"
#include "stm32/GpioPin.h"

//Board and Kernel
NucleoF746ZG board = {};
Kernel kernel(board);

//Tasks
extern void DisplayTask();
void AliveTask()
{
	board.Led1.Set(false);

	while (true)
	{
		board.Led1.Toggle();
		kernel.Sleep(1000);
	}
}

int main(void)
{
	board.Init();
	kernel.Init();
	kernel.RegisterInterrupt(board.uart.GetInterupt(), {&Usart::OnInterrupt, &board.uart});

	board.Printf("Application Active\r\n");

	kernel.CreateThread(&AliveTask);
	kernel.CreateThread(&DisplayTask);
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
