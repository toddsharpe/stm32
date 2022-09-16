#pragma once

#include "stm32/GpioPin.h"
#include "StringPrinter.h"
#include <cstdint>

#define UART_DIV_SAMPLING16(__PCLK__, __BAUD__) (((__PCLK__) + ((__BAUD__) / 2U)) / (__BAUD__))

struct UartConfig
{
	uint32_t BaudRate;
};

static constexpr UartConfig const UartDefault = { .BaudRate = 115200 };

class Usart: public StringPrinter
{
public:
	Usart(USART_TypeDef *usart) : m_usart(usart), m_tx(GPIOD, 8), m_rx(GPIOD, 9)
	{
		// TODO: build pins based on usart#
	}

	void Init(const UartConfig& config)
	{
		m_usart->CR1 &= ~USART_CR1_UE; // turn it off
		m_usart->BRR = (uint32_t)(UART_DIV_SAMPLING16(SystemCoreClock, config.BaudRate));
		m_usart->CR1 |= (USART_CR1_RE | USART_CR1_TE); // RX, TX enable.
		m_usart->CR1 |= USART_CR1_RXNEIE;			   // UART3 Receive Interrupt Enable.

		CLEAR_BIT(m_usart->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
		CLEAR_BIT(m_usart->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));

		// Table 12 Alternate function mapping
		GpioPinConfig pinConfig = {};
		pinConfig.Mode = GpioMode::Alternate;
		pinConfig.OutputType = GpioOutputType::PushPull;
		pinConfig.PullType = GpioPullType::None;
		pinConfig.Speed = GpioSpeed::High;
		pinConfig.Alternate = GpioAlternate::Usart3;

		m_tx.Init(pinConfig);
		m_rx.Init(pinConfig);

		NVIC_SetPriority(USART3_IRQn, 0x00);
		NVIC_EnableIRQ(USART3_IRQn);

		m_usart->CR1 |= USART_CR1_UE; // USART3 enable.
	}

	virtual void Write(const char *ptr, const size_t len) override
	{
		for (size_t i = 0; i < len; i++)
		{
			while (!(USART3->ISR & USART_ISR_TXE)) { };
			m_usart->TDR = *ptr++;
		}
		while (!(USART3->ISR & USART_ISR_TC)) {};
	}

private:
	USART_TypeDef *m_usart;
	GpioPin m_tx;
	GpioPin m_rx;
};