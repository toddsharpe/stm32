#include "stm32f746xx.h"
#include "stm32f7xx.h"
#include "boards/NUCLEO-F746ZG.h"
#include "stm32/GpioPin.h"

#define GREENLED_PORT GPIOB
#define GREENLED_PIN 0

#define BLUELED_PORT GPIOB
#define BLUELED_PIN 7

constexpr GPIO_TypeDef* Port_B() {
  return GPIOB;
}

constexpr GPIO_TypeDef* Port_C() {
  return GPIOC;
}

int main(void)
{
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
	
	__DSB();

	GpioPin<Port_B, 0> led1;
	led1.Init(GpioOutput);

	GpioPin<Port_B, 7> led2;
	led2.Init(GpioOutput);

	GpioPin<Port_B, 14> led3;
	led3.Init(GpioOutput);

	GpioPin<Port_C, 13> button1;
	button1.Init(GpioInput);

	led1.Set(false);
	led2.Set(true);
	
	while (1)
	{
		led1.Toggle();
		led2.Toggle();
		led3.Set(button1.Read());

		for (unsigned count = 0; count < 300000; count++)
			asm("");
	}
}
