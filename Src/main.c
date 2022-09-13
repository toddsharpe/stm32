#include "stm32f746xx.h"

#define GREENLED_PORT GPIOB
#define GREENLED_PIN 0

#define BLUELED_PORT GPIOB
#define BLUELED_PIN 7

int main(void)
{
	RCC ->AHB1ENR = RCC_AHB1ENR_GPIOBEN;
	__DSB();
	GREENLED_PORT->MODER &= !(0b11 << (GREENLED_PIN * 2));
	GREENLED_PORT->MODER |= (0b01 << (GREENLED_PIN * 2));
	BLUELED_PORT->MODER |= (0b01 << (BLUELED_PIN * 2));

	while (1)
	{
		GREENLED_PORT -> ODR ^= 1 << GREENLED_PIN;
		
		for (unsigned count = 0; count < 100000; count++)
			asm("");

		BLUELED_PORT -> ODR ^= 1 << BLUELED_PIN;

		for (unsigned count = 0; count < 100000; count++)
			asm("");
	}
}
