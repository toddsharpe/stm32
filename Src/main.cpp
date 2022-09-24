#include "stm32f746xx.h"
#include "stm32f7xx.h"
#include "system_stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "stm32/GpioPin.h"
#include "stm32/Usart.h"
#include "stm32/SystemTimer.h"
#include "stm32/Timer.h"

// Peripherals
SystemTimer sysTimer(TickFreq::TickFreq_10HZ);
GpioPin led1(GPIOB, 0);
GpioPin led2(GPIOB, 7);
GpioPin led3(GPIOB, 14);
GpioPin button(GPIOC, 13);
Timer timer2(TIM2);
Usart uart(USART3);

void Delay(uint32_t ms)
{
	const uint32_t ticks = sysTimer.GetTicks();
	const uint32_t target = ticks + ms;
	while (sysTimer.GetTicks() < target)
	{
		__WFI();
	}
}

int main(void)
{
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);
	SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);

	__DSB();

	sysTimer.Init();
	led1.Init(GpioOutput);
	led2.Init(GpioOutput);
	led3.Init(GpioOutput);
	button.Init(GpioInput);
	timer2.Init(500);
	uart.Init(UartDefault);

	uart.Printf("SystemCoreClock: %d\r\n", SystemCoreClock);

	while (true)
	{
		const char Test[] = "Hello STM uart !!!\r\n"; //Data to send
		uart.PrintBytes(Test,sizeof(Test));
	  	Delay(1000);
		led1.Toggle();
	}
}

extern "C" void SysTick_Handler()
{
	sysTimer.OnTick();
}

extern "C" void TIM2_IRQHandler()
{
	led2.Toggle();
	TIM2->SR &= ~(TIM_SR_UIF);
}

extern "C" void USART3_IRQHandler()
{
	led3.Toggle();
	char r[2] = {};
	r[0] = USART3->RDR;
	r[1] = '\0';
	uart.Write(r, sizeof(r));
}