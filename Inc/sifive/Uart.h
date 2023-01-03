// MAN: Docs\SiFive\fe310-g002-v1p5.pdf

#pragma once

#include "StringPrinter.h"
#include "DataChannel.h"

#include <cstdint>
#include <cstddef>
#include <string>
#include <cstring>

class Uart : public DataChannel, public StringPrinter
{
public:
	Uart(void *uart) : m_uart((_uart *)uart)
	{
	}

	void Write(const std::string &string)
	{
		this->Write((const uint8_t *)string.c_str(), (int)string.length());
	}

	virtual void Write(const uint8_t *buffer, size_t length) override
	{
		for (size_t i = 0; i < length; i++)
		{
			while (m_uart->TxData.Full) {};
			m_uart->TxData.Data = buffer[i];
		}
		while (m_uart->TxData.Full) {};
	}

	virtual void Read(uint8_t *buffer, size_t length) override
	{

	}

	virtual size_t BytesAvailable() override
	{
		return 0;
	}

private:
	// MAN 18.3
	struct uart_txdata
	{
		uint32_t Data : 8;
		uint32_t Reserved : 23;
		uint32_t Full : 1;
	};

	struct _uart
	{
		volatile uart_txdata TxData;
		volatile uint32_t RxData;
		volatile uint32_t TxCtrl;
		volatile uint32_t RxCtrl;
		volatile uint32_t IE;
		volatile uint32_t IP;
		volatile uint32_t Div;
	};

	static constexpr size_t BUFFER_SIZE = 1024;

	_uart *m_uart;
	// RingBuffer<uint8_t, BUFFER_SIZE> m_buffer;
};