#include "rtos/Kernel.h"
#include "stm32f746xx.h"
#include "stm32/Usart.h"
#include "Assert.h"

Kernel::Kernel(Board& board) : m_board(board), m_sysTimer(TickFreq::TickFreq_100HZ), m_scheduler(m_sysTimer), m_interruptHandlers()
{

}

bool Kernel::Init()
{
	m_board.Printf("Kernel::Init\r\n");
	
	//Create Idle Thread
	if (!CreateThread(&KThread::Idle, ThreadPriority::Low))
		return false;

	//Create timer
	m_sysTimer.Init(m_board.GetSysClkFreq());
	this->RegisterInterrupt(IRQn_Type::SysTick_IRQn, {&Kernel::OnSysTick, this});

	return true;
}

bool Kernel::Run()
{
	m_board.Printf("Kernel::Run\r\n");
	m_sysTimer.Start();

	//Start kernel
	__asm("SVC 0");
	while (1);
}

bool Kernel::Stop()
{
	m_sysTimer.Stop();

	return true;
}

bool Kernel::CreateThread(const ThreadStart entry, const ThreadPriority priority, const size_t stackSize)
{
	m_board.Printf("Kernel::CreateThread\r\n");
	
	KThread* thread = new KThread();
	uint8_t* stack = new uint8_t[stackSize];
	thread->Init(stack, stackSize, entry);
	thread->m_priority = priority;
	m_board.Printf("    Addr: 0x%x, Stack: 0x%x\r\n", thread, stack);
	m_scheduler.AddThread(thread);

	return true;
}

void Kernel::Sleep(const size_t ms)
{
	m_scheduler.Sleep(ms);
}

void Kernel::Yield()
{
	m_scheduler.Reschedule();
}

void Kernel::RegisterInterrupt(const InterruptVector interrupt, const InterruptContext& context)
{
	Assert(m_interruptHandlers.find(interrupt) == m_interruptHandlers.end());
	m_interruptHandlers.insert({ interrupt, context });
}

void Kernel::HandleInterrupt(const InterruptVector interrupt, const HardwareStackFrame* frame, const SoftwareStackFrame* context)
{
	const auto& it = m_interruptHandlers.find(interrupt);
	if (it != m_interruptHandlers.end())
	{
		InterruptContext ctx = it->second;
		ctx.Handler(ctx.Context);
		return;
	}

	m_board.Printf("Unhandled interrupt\r\n");
	m_board.Printf("IRQ: %d\r\n", interrupt);
	m_board.Printf("PC: 0x%x, LR: 0x%x, CallerLR: 0x%x\r\n", frame->PC, frame->LR, frame->LR);
	m_board.Printf("R4: 0x%x, R5: 0x%x, R6: 0x%x, R7: 0x%x\r\n", context->R4, context->R5, context->R6, context->R7);
	
	KThread::Idle();
}

void Kernel::OnSysTick()
{
	m_sysTimer.OnTick();
	m_scheduler.Reschedule();
}

//TODO(tsharpe): Move both these to scheduler? what about asm file?
void* Kernel::PendSV_Handler(void* psp)
{
	m_scheduler.SaveCurrentPSP(psp);
	m_scheduler.SelectNextThread();
	return m_scheduler.GetCurrentPSP();
}

WaitStatus Kernel::KeWait(KSignalObject& object, const milli_t timeout)
{
	WaitStatus status = m_scheduler.ObjectWait(object, timeout);
	
	switch (object.GetType())
	{
	case KObjectType::Event:
	{
		KEvent& event = (KEvent&)object;
		if (!event.IsManual())
			event.Reset();
	}
		break;

	case KObjectType::Semaphore:
	case KObjectType::Sleep:
		break;
	}

	return status;
}

void* Kernel::GetCurrentPSP()
{
	return m_scheduler.GetCurrentPSP();
}

void Kernel::KeSignal(KEvent& event)
{
	event.Set();
	if (event.IsManual())
	{
		m_scheduler.ObjectSignalled(event);
	}
	else
	{
		if (m_scheduler.ObjectSignalledOne(event))
			event.Reset();
	}
}