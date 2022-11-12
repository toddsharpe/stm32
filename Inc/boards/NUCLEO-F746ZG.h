#pragma once

#include "stm32f746xx.h"

#include "stm32/Rcc.h"
#include "stm32/Pll.h"
#include "stm32/SystemClock.h"
#include "stm32/GpioPin.h"
#include "stm32/Usart.h"
#include "boards/Board.h"
#include "util/util.h"

class NucleoF746ZG : public Board
{
public:
	NucleoF746ZG() : Board(), rcc(16'000'000, 8'000'000), uart(USART3)
	{

	}

	void Init()
	{
		//Initialize peripherals
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN);
		SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);
		SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN);
		SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
		__DSB();
		
		//Initialize system clock
		Pll::Init(DefaultPllConfig);
		SystemClock::Init(DefaultSysClock);

		//Initialize peripherals
		GpioPin<Port_D, 8> uart3_tx;
		uart3_tx.Init(GpioUart3);
		GpioPin<Port_D, 9> uart3_rx;
		uart3_rx.Init(GpioUart3);
		uart.Init(rcc.GetPClk1Freq(), UartDefault);
		uart.EnableInterrupt(USART_CR1_RXNEIE);

		Led1.Init(GpioOutput);
		Led2.Init(GpioOutput);
		Led3.Init(GpioOutput);

		//Print welcome
		uart.Printf("Board initialized\r\n");

		//Print clocks
		RccClocks clocks = {};
		rcc.GetSystemClocksFreq(clocks);
		uart.Printf("-SysClkFreq: %d\r\n", clocks.SysClkFreq);
		uart.Printf("-HClkFreq: %d\r\n", clocks.HClkFreq);
		uart.Printf("-PClk1Freq: %d\r\n", clocks.PClk1Freq);
		uart.Printf("-PClk2Freq: %d\r\n", clocks.PClk2Freq);
	}

	virtual void Printf(const char *format, ...) override
	{
		va_list args;
		va_start(args, format);
		uart.Printf(format, args);
		va_end(args);
	}

	virtual void Printf(const char* format, va_list args) override
	{
		uart.Printf(format, args);
	}

	virtual void Write(const std::string& str) override
	{
		uart.Write(str);
	}

	virtual uint32_t GetSysClkFreq() const override
	{
		return rcc.GetSysClkFreq();
	}

	Rcc rcc;

	Usart uart;

	GpioPin<Port_B, 0> Led1;
	GpioPin<Port_B, 7> Led2;
	GpioPin<Port_B, 14> Led3;
};