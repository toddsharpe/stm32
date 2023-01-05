// MAN: fe310-g002-manual-v19p05.pdf

#pragma once

#include <sifive/sifive_hifive1_revb.h>
#include "DiscretePin.h"
#include <stddef.h>
#include <cstdint>

enum GpioMode : uint8_t
{
	Input = 0b0,
	Output = 0b1,
};

struct GpioPinConfig
{
	GpioMode Mode;
};

static constexpr GpioPinConfig const GpioOutput = { .Mode = GpioMode::Output };

template <size_t TPin>
class GpioPin : public DiscretePin
{
public:
	GpioPin()
	{
	}

	void Init(const GpioPinConfig &config, const bool initValue = false)
	{
		Set(initValue);

		if (config.Mode == GpioMode::Output)
		{
			sifive_gpio0_0->input_en &= ~(1 << TPin);
			sifive_gpio0_0->output_en |= (1 << TPin);
		}
		else
		{
			sifive_gpio0_0->input_en |= (1 << TPin);
			sifive_gpio0_0->output_en &= ~(1 << TPin);
		}

		//TODO(tsharpe): Why is this required or else output has to be inverted?
		sifive_gpio0_0->out_xor |= (1 << TPin);
	}

	virtual void Set(const bool value) override
	{
		if (value)
			sifive_gpio0_0->output_val |= (1 << TPin);
		else
			sifive_gpio0_0->output_val &= ~(1 << TPin);
	}

	virtual bool Get() override
	{
		return (sifive_gpio0_0->output_val) != 0;
	}

	virtual bool Read() override
	{
		return (sifive_gpio0_0->input_val & (1 << TPin)) != 0;
	}
};
