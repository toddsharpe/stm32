#pragma once

#include "stm32/GpioPin.h"
#include "StringPrinter.h"
#include <cstdint>
#include <cstring>
#include <string>
#include "stm32f7xx.h"

#define UART_DIV_SAMPLING16(__PCLK__, __BAUD__) (((__PCLK__) + ((__BAUD__) / 2U)) / (__BAUD__))

struct UartConfig
{
	uint32_t BaudRate;
};

static constexpr UartConfig const UartDefault = { .BaudRate = 115200 };

typedef void (*CharReceived)(void* sender, const uint8_t c);
class Usart: public StringPrinter
{
public:
	static void OnRx(void* arg) { ((Usart*)arg)->OnRx(); };

	Usart(USART_TypeDef *usart) : OnCharReceived(), m_usart(usart), m_tx(GPIOD, 8), m_rx(GPIOD, 9)
	{
		// TODO: build pins based on usart#
	}

	CharReceived OnCharReceived;

	void Init(const uint32_t clkFreq, const UartConfig& config)
	{
		m_usart->CR1 &= ~USART_CR1_UE; // turn it off
		m_usart->BRR = (uint32_t)(UART_DIV_SAMPLING16(clkFreq, config.BaudRate));
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

		NVIC_EnableIRQ(USART3_IRQn);

		m_usart->CR1 |= USART_CR1_UE; // USART3 enable.
	}

	virtual void Write(const std::string& str) override
	{
		for (const char c : str)
		{
			while (!(m_usart->ISR & USART_ISR_TXE)) { };
			m_usart->TDR = c;
		}
		while (!(m_usart->ISR & USART_ISR_TC)) {};
	}

	void OnRx()
	{
		const uint8_t c = (uint8_t)m_usart->RDR;
		if (OnCharReceived != nullptr)
			OnCharReceived(this, c);
		char chars[2] = {};
		chars[0] = c;
		this->Write(chars);
	}

private:
	USART_TypeDef *m_usart;
	GpioPin m_tx;
	GpioPin m_rx;
};