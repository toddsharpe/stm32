#pragma once

#include "sifive/Uart.h"
#include "boards/Board.h"
#include "sifive/GpioPin.h"

class HiFive1RevB : public Board
{
public:
	HiFive1RevB() : Board(), uart(sifive_uart0_0)
	{
	}

	void Init()
	{
		LedRed.Init(GpioOutput);
		LedGreen.Init(GpioOutput);
		LedBlue.Init(GpioOutput);
	}

	virtual void Printf(const char *format, ...) override
	{
		va_list args;
		va_start(args, format);
		uart.Printf(format, args);
		va_end(args);
	}

	virtual void Printf(const char *format, va_list args) override
	{
		uart.Printf(format, args);
	}

	virtual void Write(const std::string &str) override
	{
		uart.Write(str);
	}

	virtual uint32_t GetSysClkFreq() const override
	{
		return 0;
	}

	Uart uart;

	GpioPin<22> LedRed;
	GpioPin<19> LedGreen;
	GpioPin<21> LedBlue;
};