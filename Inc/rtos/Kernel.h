#pragma once

#include "rtos/KThread.h"
#include "boards/Board.h"
#include "stm32/SystemTimer.h"
#include "stm32f746xx.h"
#include "rtos/Types.h"
#include "rtos/KEvent.h"
#include "rtos/Scheduler.h"

#include <vector>
#include <map>
#include <list>

class Kernel
{
public:
	static void OnSysTick(void* arg) { ((Kernel*)arg)->OnSysTick(); };

	Kernel(Board& board);
	bool Init();
	bool Run();
	bool Stop();

	bool CreateThread(const ThreadStart entry, const ThreadPriority priority = ThreadPriority::Normal, const size_t stackSize = DefaultStackSize);
	void Yield();
	void Sleep(const size_t ms);

	void RegisterInterrupt(const InterruptVector interrupt, const InterruptContext& context);
	void HandleInterrupt(const InterruptVector interrupt, const HardwareStackFrame* frame, const SoftwareStackFrame* context);

	WaitStatus KeWait(KSignalObject& object, const milli_t timeout = std::numeric_limits<milli_t>::max());
	void KeSignal(KEvent& event);

private:
	static constexpr size_t DefaultStackSize = 4 * 1024;

	void Reschedule();
	void OnSysTick();
	void* PendSV_Handler(void* psp);

	void* GetCurrentPSP();

	Board& m_board;
	SystemTimer m_sysTimer;
	Scheduler m_scheduler;
	std::map<InterruptVector, InterruptContext> m_interruptHandlers;
};