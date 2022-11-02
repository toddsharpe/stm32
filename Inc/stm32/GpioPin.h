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

constexpr GPIO_TypeDef* Port_A() {
  return GPIOA;
}

constexpr GPIO_TypeDef* Port_B() {
  return GPIOB;
}

constexpr GPIO_TypeDef* Port_C() {
  return GPIOC;
}

constexpr GPIO_TypeDef* Port_D() {
  return GPIOD;
}

template <GPIO_TypeDef* PORT(), size_t TPin>
class GpioPin
{
public:
	GpioPin()
	{

	}

	void Init(const GpioPinConfig& config)
	{
		if (config.Mode == GpioMode::Output || config.Mode == GpioMode::Alternate)
		{
			SET_REG_FIELD(PORT()->OSPEEDR, TPin * 2, GpioSpeed::GpioSpeedMask, config.Speed);
			SET_REG_FIELD(PORT()->OTYPER, TPin, GpioOutputType::GpioOutputTypeMask, config.OutputType);
		}

		if (config.Mode != GpioMode::Analog)
		{
			SET_REG_FIELD(PORT()->PUPDR, TPin * 2, GpioPullType::GpioPullTypeMask, config.PullType);
		}

		if (config.Mode == GpioMode::Alternate)
		{
			SET_REG_FIELD(PORT()->AFR[TPin >> 3], (TPin & 0b111) * 4, GpioAlternate::GpioAlternateMask, config.Alternate);
		}
		
		SET_REG_FIELD(PORT()->MODER, TPin * 2, GpioMode::GpioModeMask, config.Mode);
	}

	void Set(bool value)
	{
		PORT()->BSRR = (1 << (TPin + (value ? 0 : 16)));
	}

	bool Get()
	{
		return (PORT()->ODR & (1 << TPin)) != 0;
	}

	bool Read()
	{
		return (PORT()->IDR & (1 << TPin)) != 0;
	}

	void Toggle()
	{
		Set(!Get());
	}
};
