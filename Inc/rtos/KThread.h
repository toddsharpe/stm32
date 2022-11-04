#pragma once

#include "arm.h"
#include <cstring>
#include "stm32f746xx.h"
#include <cstdint>
#include "rtos/Types.h"

// M7: DUI0646C_cortex_m7_dgug.pdf

enum class ThreadState
{
	Uninit,
	Ready,
	Running,
	SignalWait
};

enum class ThreadPriority
{
	Unset,
	Low,
	Normal,
	High,
};

typedef void (*ThreadStart)();
class KThread
{
public:
	static void Idle()
	{
		while (true)
			__WFI();
	}

	KThread() :
		m_stack(),
		m_frame(),
		m_context(),
		m_state(ThreadState::Uninit),
		m_priority(ThreadPriority::Normal),
		m_waitStatus(WaitStatus::None)
	{
	}

	void Init(uint8_t *stack, size_t stackSize, ThreadStart entry)
	{
		stack += stackSize;

		// Allocate Interrupt frame
		stack -= sizeof(HardwareStackFrame);
		m_frame = (HardwareStackFrame *)stack;
		memset(m_frame, 0, sizeof(HardwareStackFrame));
		m_frame->LR = (uint32_t)&Idle;
		m_frame->PC = (uint32_t)entry;
		m_frame->xPSR = 0x01000000;

		// Allocate software context
		stack -= sizeof(SoftwareStackFrame);
		m_context = (SoftwareStackFrame *)stack;
		memset(m_context, 0, sizeof(SoftwareStackFrame));
		m_context->LR = 0xFFFFFFFD; // M7: Table 2-15

		// Save stack pointer
		m_stack = stack;

		m_state = ThreadState::Ready;
	}

public:
	// Always keep as first member
	void *m_stack;
	HardwareStackFrame *m_frame;
	SoftwareStackFrame *m_context;

	ThreadState m_state;
	ThreadPriority m_priority;
	WaitStatus m_waitStatus;
};