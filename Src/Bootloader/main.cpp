#include "stm32f7xx.h"
#include "system_stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "rtos/Kernel.h"
#include "arm.h"
#include "System.h"
#include "Updater.h"

#include "stm32/GpioPin.h"
#include "Drivers/Hc06.h"

// Board and Kernel
NucleoF746ZG board = {};
Kernel kernel(board);

//Peripherals
Usart uart2(USART2);
Hc06 bluetooth(uart2);

//Updater
Updater updater(board, kernel, bluetooth);

void bootloader()
{
	updater.Run();
}

int main()
{
	//Init Board
	board.Init();
	kernel.Init();
	kernel.RegisterInterrupt(uart2.GetInterupt(), {&Usart::OnInterrupt, &uart2});

	//Init Peripherals
	{
		GpioPin<Port_D, 5> uart2_tx;
		uart2_tx.Init(GpioUart2);
		GpioPin<Port_D, 6> uart2_rx;
		uart2_rx.Init(GpioUart2);
	}
	uart2.Init(board.rcc.GetPClk1Freq(), UartDefault);
	bluetooth.Init();

	board.Printf("Bootloader Active\r\n");

	kernel.CreateThread(&bootloader);
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