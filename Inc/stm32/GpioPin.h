#include "stm32f746xx.h"
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

enum GpioUpDown
{
	None = 0b00,
	PullUp = 0b01,
	PullDown = 0b10,
	Reserved = 0b11,
	GpioUpDownMask = 0b11
};

struct GpioPinConfig
{
	GpioMode Mode;
	GpioUpDown UpDown;
};

static constexpr GpioPinConfig const GpioOutput = { .Mode = GpioMode::Output, .UpDown = GpioUpDown::None };
static constexpr GpioPinConfig const GpioInput = { .Mode = GpioMode::Input, .UpDown = GpioUpDown::None };

template <GPIO_TypeDef* PORT(), size_t TPin>
class GpioPin
{
public:
	GpioPin()
	{

	}

	void Init(const GpioPinConfig& config)
	{
		PORT()->PUPDR &= ~(GpioUpDown::GpioUpDownMask << (TPin * 2));
		PORT()->PUPDR |= (config.UpDown << (TPin * 2));

		PORT()->MODER &= ~(GpioMode::GpioModeMask << (TPin * 2));
		PORT()->MODER |= (config.Mode << (TPin * 2));
	}

	void Set(bool value)
	{
		PORT()->ODR &= ~(1 << TPin);
		PORT()->ODR |= ((value ? 1 : 0) << TPin);
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

