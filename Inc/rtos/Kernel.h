#pragma once

#include "rtos/KThread.h"
#include "boards/Board.h"
#include "stm32/SystemTimer.h"
#include "stm32f746xx.h"
#include <vector>
#include <map>
#include "rtos/Types.h"

class Kernel
{
public:
	static void OnSysTick(void* arg) { ((Kernel*)arg)->OnSysTick(); };

	Kernel(Board& board);
	bool Init();
	bool Run();
	bool Stop();

	bool CreateThread(const ThreadStart entry, const ThreadPriority priority = ThreadPriority::Normal, const size_t stackSize = DefaultStackSize);
	bool Yield();
	bool Sleep(const size_t ms);

	void RegisterInterrupt(const InterruptVector interrupt, const InterruptContext& context);
	void HandleInterrupt(const InterruptVector interrupt, const HardwareStackFrame* frame, const SoftwareStackFrame* context);

private:
	void Reschedule();
	void OnSysTick();

	void* PendSV_Handler(void* psp);

	void SaveCurrentPSP(void* psp);
	void* GetCurrentPSP();
	bool SelectNextThread();

	static constexpr size_t DefaultStackSize = 4 * 1024;

	int m_threadIndex;
	std::vector<KThread*> m_threads;

	std::map<InterruptVector, InterruptContext> m_interruptHandlers;

	SystemTimer m_sysTimer;

	Board& m_board;
};