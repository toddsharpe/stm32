#pragma once

#include "stm32f746xx.h"
#include "util/util.h"

struct RccClocks
{
	uint32_t SysClkFreq;
	uint32_t HClkFreq;
	uint32_t PClk1Freq;
	uint32_t PClk2Freq;
};

class Rcc
{
public:
	Rcc(const uint32_t hsiFreq, const uint32_t hseFreq) : m_hsiFreq(hsiFreq), m_hseFreq(hseFreq)
	{

	}

	void GetSystemClocksFreq(RccClocks &clocks) const
	{
		clocks.SysClkFreq = GetSysClkFreq();
		clocks.HClkFreq = clocks.SysClkFreq;
		clocks.PClk1Freq = GetScaledClkFreq(clocks.SysClkFreq, GET_REG_FIELD(RCC->CFGR, RCC_CFGR_PPRE1_Pos, RCC_CFGR_PPRE1));
		clocks.PClk2Freq = GetScaledClkFreq(clocks.SysClkFreq, GET_REG_FIELD(RCC->CFGR, RCC_CFGR_PPRE2_Pos, RCC_CFGR_PPRE2));
	}

	uint32_t GetSysClkFreq() const
	{
		switch (RCC->CFGR & RCC_CFGR_SWS)
		{
		case RCC_CFGR_SWS_HSI:
			return m_hsiFreq;
			break;
		case RCC_CFGR_SWS_HSE:
			return m_hseFreq;
			break;
		case RCC_CFGR_SWS_PLL:
		{
			/*
			 * PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
			 * SYSCLK = PLL_VCO / PLL_P
			 */
			const uint32_t pllSource = (uint32_t)(RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
			const uint32_t pllSourceFreq = (pllSource == RCC_PLLCFGR_PLLSRC_HSI) ? m_hsiFreq : m_hseFreq;

			const uint32_t pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;
			const uint32_t pllvco = (pllSourceFreq / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> RCC_PLLCFGR_PLLN_Pos);
			const uint32_t pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >> RCC_PLLCFGR_PLLP_Pos) + 1) * 2;
			return pllvco / pllp;
			break;
		}
		default:
			return m_hsiFreq;
			break;
		}
	}

	uint32_t GetPClk1Freq() const
	{
		const uint32_t sysClk = GetSysClkFreq();
		return GetScaledClkFreq(sysClk, GET_REG_FIELD(RCC->CFGR, RCC_CFGR_PPRE1_Pos, RCC_CFGR_PPRE1));
	}

private:
	static constexpr uint8_t APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4};

	uint32_t GetScaledClkFreq(const uint32_t sysClk, const uint32_t prescaler) const
	{
		return (sysClk >> APBPrescTable[prescaler]);
	}

	const uint32_t m_hsiFreq;
	const uint32_t m_hseFreq;
};