#include "rtos/Kernel.h"
#include "stm32f746xx.h"
#include "stm32/Usart.h"
#include "Assert.h"

extern Usart uart;

Kernel::Kernel() : m_threadIndex(), m_threads(), m_sysTimer(TickFreq::TickFreq_10HZ)
{

}

bool Kernel::Init()
{
	uart.Printf("Kernel::Init\r\n");
	
	//Create Idle Thread
	if (!CreateThread(&KThread::Idle, ThreadPriority::Low))
		return false;

	m_sysTimer.Init();
	
	return true;
}

bool Kernel::Run()
{
	uart.Printf("Kernel::Run\r\n");
	
	if (!m_threads.size())
		return false;

	m_sysTimer.Start();

	//Start kernel
	m_threads[m_threadIndex]->m_state = ThreadState::Running;
	__asm("SVC 0");
	while (1);
}

bool Kernel::Stop()
{
	m_sysTimer.Stop();
}

bool Kernel::CreateThread(const ThreadStart entry, const ThreadPriority priority, const size_t stackSize)
{
	uart.Printf("Kernel::CreateThread\r\n");
	
	KThread* thread = new KThread();
	uint8_t* stack = new uint8_t[stackSize];
	thread->Init(stack, stackSize, entry);
	thread->m_priority = priority;
	thread->m_state = ThreadState::Ready;
	uart.Printf("    Addr: 0x%x, Stack: 0x%x\r\n", thread, stack);
	m_threads.push_back(thread);

	return true;
}

bool Kernel::Sleep(const size_t ms)
{
	uart.Printf("Kernel::Sleep\r\n");
	AssertEqual(m_threads[m_threadIndex]->m_state, ThreadState::Running);
	
	const uint32_t current = m_sysTimer.GetTicks();
	m_threads[m_threadIndex]->m_state = ThreadState::Sleeping;
	m_threads[m_threadIndex]->m_sleepWake = current + ms;
	uart.Printf("    Sleep %d, Current: %d, Wake: %d\r\n", ms, current, m_threads[m_threadIndex]->m_sleepWake);

	Reschedule();
	return true;
}

bool Kernel::Yield()
{
	Reschedule();
	return true;
}

void Kernel::OnSysTick()
{
	m_sysTimer.OnTick();

	Reschedule();
}

void Kernel::Reschedule()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}

void Kernel::SaveCurrentPSP(void* psp)
{
	m_threads[m_threadIndex]->m_stack = psp;
}

void* Kernel::GetCurrentPSP()
{
	return m_threads[m_threadIndex]->m_stack;
}

bool Kernel::SelectNextThread()
{
	//__asm("cpsid i"); //disable irq
	KThread* current = m_threads[m_threadIndex];
	if (current->m_state == ThreadState::Running)
		current->m_state = ThreadState::Ready;

	//Wake sleeping threads
	for (size_t i = 0; i < m_threads.size(); i++)
	{
		if (m_threads[i]->m_state == ThreadState::Sleeping && m_threads[i]->m_sleepWake <= m_sysTimer.GetTicks())
		{
			m_threads[i]->m_state = ThreadState::Ready;
		}
	}

	//Select new thread
	while (true)
	{
		m_threadIndex = (m_threadIndex + 1) % m_threads.size();
		
		if (m_threads[m_threadIndex]->m_state == ThreadState::Ready)
			break;
	}

	KThread* next = m_threads[m_threadIndex];
	next->m_state = ThreadState::Running;

	return true;
}

void* Kernel::PendSV_Handler(void* psp)
{
	m_threads[m_threadIndex]->m_stack = psp;
	SelectNextThread();
	return GetCurrentPSP();
}
