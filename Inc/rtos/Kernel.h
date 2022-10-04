#pragma once

#include "rtos/KThread.h"
#include "stm32/SystemTimer.h"
#include "stm32f746xx.h"
#include <vector>
#include <map>
#include "rtos/Types.h"

class Kernel
{
public:
	Kernel();
	bool Init();
	bool Run();
	bool Stop();

	bool CreateThread(const ThreadStart entry, const ThreadPriority priority = ThreadPriority::Normal, const size_t stackSize = DefaultStackSize);
	bool Yield();
	bool Sleep(const size_t ms);

	void OnSysTick();

private:
	void Reschedule();

	void* PendSV_Handler(void* psp);

	void SaveCurrentPSP(void* psp);
	void* GetCurrentPSP();
	bool SelectNextThread();

	static constexpr size_t DefaultStackSize = 4 * 1024;

	int m_threadIndex;
	std::vector<KThread*> m_threads;

	std::map<IRQn_Type, InterruptContext> m_interruptHandlers;

	SystemTimer m_sysTimer;
};