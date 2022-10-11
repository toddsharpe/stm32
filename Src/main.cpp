#include "stm32f7xx.h"
#include "system_stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "stm32/GpioPin.h"
#include "rtos/Kernel.h"

// Board and Kernel
NucleoF746ZG board = {};
Kernel kernel(board);

//Thread Tasks
void task1()
{
	GpioPin& led1 = board.Led1;
	led1.Set(false);

	while (true)
	{
		board.Printf("Task1\r\n");
		led1.Toggle();
		kernel.Sleep(1000);
	}
}

void task2()
{
	GpioPin& led2 = board.Led2;
	led2.Set(false);

	while (true)
	{
		board.Printf("Task2\r\n");
		led2.Toggle();
		kernel.Sleep(2000);
	}
}

int main(void)
{
	board.Init();
	kernel.Init();

	kernel.CreateThread(&task1);
	kernel.CreateThread(&task2);
	kernel.Run();
}

extern "C" void SysTick_Handler()
{
	kernel.OnSysTick();
}

extern "C" void exception_handler(const HardwareStackFrame* frame, const SoftwareStackFrame* context)
{
	board.Led3.Toggle();
	
	const uint32_t irq = (__get_IPSR() & 0xFF) - 16;
	kernel.HandleInterrupt((InterruptVector)irq, frame, context);
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
