#pragma once

#include "stm32f746xx.h"
#include "stm32f7xx.h"
#include "Assert.h"

enum PllSrc
{
	HSI = 0,
	HSE = 1,
};

enum PllDiv
{
	Div2 = 0b00,
	Div4 = 0b01,
	Div6 = 0b10,
	Div8 = 0b11,
};

struct PllConfig
{
	PllSrc Source;
	uint32_t M;
	uint32_t N;
	PllDiv P;
	uint32_t Q;
};

struct RCC_PLLCFGR
{
	union
	{
		struct
		{
			uint32_t PLLM : 6;
			uint32_t PLLN : 9;
			uint32_t _reserved1 : 1;
			uint32_t PLLP : 2;
			uint32_t _reserved2 : 4;
			uint32_t PLLSRC : 1;
			uint32_t _reserved3 : 1;
			uint32_t PLLQ : 4;
			uint32_t _reserved4 : 4;
		};
		uint32_t AsUint32;
	};
};
static_assert(sizeof(RCC_PLLCFGR) == sizeof(uint32_t));

static constexpr PllConfig const DefaultPllCOonfig = { .Source = PllSrc::HSE, .M = 4, .N = 72, .P = PllDiv::Div2, .Q = 3 };

class Pll
{
public:
	static void Init(const PllConfig& config)
	{
		//Only for HSE
		AssertEqual(config.Source, PllSrc::HSE);

		//On Nucleo, HSE clock is provided by STLink
		SET_BIT(RCC->CR, RCC_CR_HSEBYP);
		SET_BIT(RCC->CR, RCC_CR_HSEON);

		//Wait for HSE to be ready
		while (!READ_BIT(RCC->CR, RCC_CR_HSERDY))
			continue;

		//Disable PLL
		CLEAR_BIT(RCC->CR, RCC_CR_PLLON);

		//Set PLL Config
		RCC_PLLCFGR cfgr;
		cfgr.AsUint32 = RCC->PLLCFGR;
		cfgr.PLLM = config.M;
		cfgr.PLLN = config.N;
		cfgr.PLLP = config.P;
		cfgr.PLLSRC = config.Source;
		cfgr.PLLQ = config.Q;
		RCC->PLLCFGR = cfgr.AsUint32;

		//Enable PLL
		SET_BIT(RCC->CR, RCC_CR_PLLON);

		//Wait for PLL to be ready
		while (!READ_BIT(RCC->CR, RCC_CR_PLLRDY))
			continue;
	}
};