// STM: stm32f746ng.pdf

#pragma once

#include "stm32f746xx.h"
#include "util/util.h"
#include <stddef.h>
#include <cstdint>

enum GpioMode : uint8_t
{
	Input = 0b00,
	Output = 0b01,
	Alternate = 0b10,
	Analog = 0b11,
	GpioModeMask = 0b11
};

enum GpioOutputType : uint8_t
{
	PushPull = 0b0,
	OpenDrain = 0b1,
	GpioOutputTypeMask = 0b1
};

enum GpioPullType
{
	None = 0b00,
	PullUp = 0b01,
	PullDown = 0b10,
	Reserved = 0b11,
	GpioPullTypeMask = 0b11
};

enum GpioSpeed
{
	Low = 0b00,
	Medium = 0b01,
	Fast = 0b10,
	High = 0b11,
	GpioSpeedMask = High
};

// STM: Table 12 Alternate function mapping
enum GpioAlternate
{
	Usart1 = 7,
	Usart2 = 7,
	Usart3 = 7,
	GpioAlternateMask = 0b1111
};

struct GpioPinConfig
{
	GpioMode Mode;
	GpioOutputType OutputType;
	GpioPullType PullType;
	GpioSpeed Speed;
	GpioAlternate Alternate;
};

static constexpr GpioPinConfig const GpioOutput = { .Mode = GpioMode::Output, .PullType = GpioPullType::None };
static constexpr GpioPinConfig const GpioInput = { .Mode = GpioMode::Input, .PullType = GpioPullType::None };

static constexpr GpioPinConfig const GpioUart2 = {.Mode = GpioMode::Alternate, .OutputType = GpioOutputType::PushPull, .PullType = GpioPullType::None, .Speed = GpioSpeed::High, .Alternate = GpioAlternate::Usart2 };
static constexpr GpioPinConfig const GpioUart3 = {.Mode = GpioMode::Alternate, .OutputType = GpioOutputType::PushPull, .PullType = GpioPullType::None, .Speed = GpioSpeed::High, .Alternate = GpioAlternate::Usart3 };

class GpioPin
{
public:
	GpioPin(GPIO_TypeDef* port, const size_t pin) : m_port(port), m_pin(pin)
	{

	}

	void Init(const GpioPinConfig& config)
	{
		if (config.Mode == GpioMode::Output || config.Mode == GpioMode::Alternate)
		{
			SET_REG_FIELD(m_port->OSPEEDR, m_pin * 2, GpioSpeed::GpioSpeedMask, config.Speed);
			SET_REG_FIELD(m_port->OTYPER, m_pin, GpioOutputType::GpioOutputTypeMask, config.OutputType);
		}

		if (config.Mode != GpioMode::Analog)
		{
			SET_REG_FIELD(m_port->PUPDR, m_pin * 2, GpioPullType::GpioPullTypeMask, config.PullType);
		}

		if (config.Mode == GpioMode::Alternate)
		{
			SET_REG_FIELD(m_port->AFR[m_pin >> 3], (m_pin & 0b111) * 4, GpioAlternate::GpioAlternateMask, config.Alternate);
		}
		
		SET_REG_FIELD(m_port->MODER, m_pin * 2, GpioMode::GpioModeMask, config.Mode);
	}

	void Set(bool value)
	{
		m_port->BSRR = (1 << (m_pin + (value ? 0 : 16)));
	}

	bool Get()
	{
		return (m_port->ODR & (1 << m_pin)) != 0;
	}

	bool Read()
	{
		return (m_port->IDR & (1 << m_pin)) != 0;
	}

	void Toggle()
	{
		Set(!Get());
	}

private:
	GPIO_TypeDef* m_port;
	const size_t m_pin;
};

