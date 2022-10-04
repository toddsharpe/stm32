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
GpioPin led3(GPIOB, 14);
GpioPin button(GPIOC, 13);
Timer timer2(TIM2);
Usart uart(USART3);

Kernel kernel = {};

void task1()
{
	GpioPin led1(GPIOB, 0);
	led1.Init(GpioOutput);
	led1.Set(false);
	while (true)
	{
		uart.Write("Task1\r\n");
		led1.Toggle();
		kernel.Sleep(1000);
	}
}

void task2()
{
	GpioPin led2(GPIOB, 7);
	led2.Init(GpioOutput);
	led2.Set(false);
	while (true)
	{
		uart.Write("Task2\r\n");
		led2.Toggle();
		kernel.Sleep(2000);
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
	button.Init(GpioInput);
	uart.Init(UartDefault);
	//timer2.Init(2000);

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

extern "C" void exception_handler(const HardwareStackFrame* ptr, const SoftwareStackFrame* ctx)
{
	const uint32_t ipsr = __get_IPSR();
	const uint32_t irq = (ipsr & 0xFF) - 16;

	uart.Printf("IRQ: %d\r\n", irq);
	uart.Printf("PC: 0x%x, LR: 0x%x, CallerLR: 0x%x\r\n", ptr->PC, ptr->LR, ctx->LR);
	uart.Printf("R4: 0x%x, R5: 0x%x, R6: 0x%x, R7: 0x%x\r\n", ctx->R4, ctx->R5, ctx->R6, ctx->R7);

	switch (irq)
	{
		case TIM2_IRQn:
		{
			TIM2->SR &= ~(TIM_SR_UIF);
		}
			break;

		case USART3_IRQn:
		{
			led3.Toggle();
			char r[2] = {};
			r[0] = USART3->RDR;
			r[1] = '\0';
			uart.Write(r, sizeof(r));
		}
			break;
	}
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
