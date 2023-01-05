// MAN: Docs\SiFive\fe310-g002-v1p5.pdf

#pragma once

#include "StringPrinter.h"
#include "DataChannel.h"

#include <cstdint>
#include <cstddef>
#include <string>
#include <cstring>
#include <sifive/sifive_hifive1_revb.h>

class Uart : public DataChannel, public StringPrinter
{
public:
	Uart(sifive_uart0_0_Type *uart) : m_uart(uart)
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
			while (m_uart->txdata_b.full) {};
			m_uart->txdata_b.data = buffer[i];
		}
		while (m_uart->txdata_b.full) {};
	}

	virtual void Read(uint8_t *buffer, size_t length) override
	{

	}

	virtual size_t BytesAvailable() override
	{
		return 0;
	}

private:
	static constexpr size_t BUFFER_SIZE = 1024;

	sifive_uart0_0_Type *m_uart;
	// RingBuffer<uint8_t, BUFFER_SIZE> m_buffer;
};