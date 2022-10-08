#include "stm32f746xx.h"
#include "stm32f7xx.h"
#include "system_stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "stm32/GpioPin.h"
#include "stm32/Usart.h"
#include "stm32/SystemTimer.h"
#include "stm32/Timer.h"
#include "arm.h"
#include "rtos/Kernel.h"

// Peripherals
GpioPin led3(LD3_GPIO_Port, LD3_Pin);
Usart uart(USART3);

//Kernel
Kernel kernel = {};

void task1()
{
	GpioPin led1(LD1_GPIO_Port, LD1_Pin);
	led1.Init(GpioOutput);
	led1.Set(false);
	while (true)
	{
		uart.Write("Task1\r\n");
		led1.Toggle();
		kernel.Sleep(3000);
	}
}

void task2()
{
	GpioPin led2(LD2_GPIO_Port, LD2_Pin);
	led2.Init(GpioOutput);
	led2.Set(false);
	while (true)
	{
		uart.Write("Task2\r\n");
		led2.Toggle();
		kernel.Sleep(5000);
	}
}

int main(void)
{
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);
	SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);

	__DSB();

	led3.Init(GpioOutput);
	uart.Init(UartDefault);
	led3.Set(false);

	uart.Printf("SystemCoreClock: %d\r\n", SystemCoreClock);

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
	led3.Toggle();
	
	const uint32_t irq = (__get_IPSR() & 0xFF) - 16;
	kernel.HandleInterrupt((InterruptVector)irq, frame, context);
}

void Printf(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	uart.Printf(format, args);
	va_end(args);
}

void Bugcheck(const char* file, const char* line, const char* format, ...)
{
	uart.Printf("Kernel Bugcheck\r\n");
	uart.Printf("\r\n%s\r\n%s\r\n", file, line);

	va_list args;
	va_start(args, format);
	uart.Printf(format, args);
	uart.Printf("\r\n");
	va_end(args);

	kernel.Stop();
	while (1);
}
