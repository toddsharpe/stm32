#pragma once

#include <cstdint>
#include "core_cm7.h"
#include "stm32f746xx.h"

enum TickFreq
{
	TickFreq_1HZ = 1000,
	TickFreq_10HZ = 100,
	TickFreq_100HZ = 10,
	TickFreq_1KHZ = 1,
	TickFreq_DEFAULT = TickFreq_1KHZ,
};

class SystemTimer
{
public:
	SystemTimer(const TickFreq freq) :m_freq(freq), m_ticks()
	{
	}

	void Init(const uint32_t sysFreq)
	{
		const uint32_t ticks = sysFreq / (1000U / m_freq);
		SysTick->LOAD = (uint32_t)(ticks - 1UL);
		SysTick->VAL = 0;
		SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk;
	}

	void Start()
	{
		SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	}

	void Stop()
	{
		SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
	}

	void OnTick()
	{
		m_ticks += m_freq;
	}

	uint32_t GetTicks() const
	{
		return m_ticks;
	}

	void DelayThread(const uint32_t ms)
	{
		const uint32_t current = GetTicks();
		while (GetTicks() < current + ms)
			__WFI();
	}

private:
	const TickFreq m_freq;
	uint32_t m_ticks;
};