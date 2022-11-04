#pragma once

#include "rtos/KThread.h"
#include "rtos/KSignalObject.h"
#include "stm32/SystemTimer.h"
#include "Assert.h"
#include "rtos/KSleep.h"

#include <vector>
#include <map>
#include <list>

class Scheduler
{
public:
	Scheduler(const SystemTimer& timer) : m_sysTimer(timer), m_threadIndex(), m_threads(), m_signalWaits()
	{

	}

	void AddThread(KThread*& thread)
	{
		thread->m_state = ThreadState::Ready;
		m_threads.push_back(thread);
	}

	void Sleep(const milli_t ms)
	{
		AssertOp(m_threadIndex, <, m_threads.size());
		AssertEqual(m_threads[m_threadIndex]->m_state, ThreadState::Running);

		KSleep sleep;
		WaitStatus status = ObjectWait(sleep, ms);
		AssertEqual(status, WaitStatus::Timeout);
	}

	WaitStatus ObjectWait(KSignalObject& object, const milli_t timeout)
	{
		AssertOp(m_threadIndex, <, m_threads.size());
		AssertEqual(m_threads[m_threadIndex]->m_state, ThreadState::Running);
		KThread *current = m_threads[m_threadIndex];

		if (object.IsSignalled())
			return WaitStatus::Signaled;

		const milli_t deadline = m_sysTimer.GetTicks() + timeout;
		current->m_state = ThreadState::SignalWait;
		m_signalWaits[&object].push_back({current, deadline});
		Reschedule();
		
		current = m_threads[m_threadIndex];
		return current->m_waitStatus;
	}

	void ObjectSignalled(KSignalObject& object)
	{
		Assert(object.IsSignalled());

		if (!m_signalWaits[&object].size())
			return;

		//Ready threads waiting on object
		for (auto& wait : m_signalWaits[&object])
		{
			KThread* thread = wait.Thread;
			thread->m_waitStatus = WaitStatus::Signaled;
			AddThread(thread);
		}
		m_signalWaits[&object].clear();
		m_signalWaits.erase(&object);
	}

	bool ObjectSignalledOne(KSignalObject& object)
	{
		if (object.GetType() != KObjectType::Semaphore)
			Assert(object.IsSignalled());

		if (!m_signalWaits[&object].size())
			return false;

		const Wait& wait = m_signalWaits[&object].front();
		m_signalWaits[&object].pop_front();
		KThread* thread = wait.Thread;
		thread->m_waitStatus = WaitStatus::Signaled;
		AddThread(thread);
		return true;
	}

	void SaveCurrentPSP(void *psp)
	{
		m_threads[m_threadIndex]->m_stack = psp;
	}

	void *GetCurrentPSP()
	{
		//TODO(tsharpe): This function side-effect is a hack for the call to this function with the boot thread (SVC_Handler)
		m_threads[m_threadIndex]->m_state = ThreadState::Running;
		return m_threads[m_threadIndex]->m_stack;
	}

	void Reschedule()
	{
		SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
	}

	void SelectNextThread()
	{
		// Promote timeouts/sleeps off queue
		if (!m_signalWaits.empty())
		{
			for (auto &pair : m_signalWaits)
			{
				// Loop through waits
				auto it = pair.second.begin();
				while (it != pair.second.end())
				{
					Wait &item = *it;
					if (item.Deadline <= m_sysTimer.GetTicks())
					{
						KThread *thread = item.Thread;
						Assert(thread);
						thread->m_waitStatus = WaitStatus::Timeout;
						thread->m_state = ThreadState::Ready;
						it = pair.second.erase(it);
					}
					else
					{
						it++;
					}
				}
			}
		}

		KThread *current = m_threads[m_threadIndex];
		if (current->m_state == ThreadState::Running)
			current->m_state = ThreadState::Ready;

		// Select new thread
		while (true)
		{
			m_threadIndex = (m_threadIndex + 1) % m_threads.size();

			if (m_threads[m_threadIndex]->m_state == ThreadState::Ready)
				break;
		}

		KThread *next = m_threads[m_threadIndex];
		next->m_state = ThreadState::Running;
	}

private:
	struct Wait
	{
		KThread *Thread;
		milli_t Deadline;
	};

	const SystemTimer& m_sysTimer;

	size_t m_threadIndex;
	std::vector<KThread*> m_threads;
	std::map<KSignalObject*, std::list<Wait>> m_signalWaits;
};