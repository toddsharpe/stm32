#pragma once

#include "rtos/Kernel.h"
#include "DataChannel.h"
#include "System.h"
#include "OTA.h"

using namespace OTA;
class Updater
{
public:
	static void OnDataReceived(void* arg, const size_t bytesAvailable) { ((Updater*)arg)->OnDataReceived(bytesAvailable); };

	Updater(Board& board, Kernel& kernel, DataChannel& channel) : m_board(board), m_kernel(kernel), m_channel(channel), m_state(State::GetApp), m_event()
	{
		m_channel.DataReceived.Context = this;
		m_channel.DataReceived.Handler = &Updater::OnDataReceived;
	}

	void Run()
	{
		uint16_t numberOfBlocks;

		while (m_state != State::Finished)
		{
			switch (m_state)
			{
				case State::GetApp:
					GetApp(numberOfBlocks);
					m_state = State::BootApp;
					break;

				case State::BootApp:
					BootApp();
					m_state = State::Finished;
					break;

				default:
					break;
			}
		}
	}

private:
	enum class State
	{
		GetApp,
		BootApp,
		Finished
	};

	void GetApp(uint16_t& numberOfBlocks)
	{
		//Send request
		{
			GetAppMessage request = {};
			request.Length = sizeof(GetAppMessage);
			request.Type = MessageType::GetApp;

			AppInfoMessage response = {};
			if (!SendAndReceive(request, response))
			{
				return;
			}
			AssertEqual(response.Type, MessageType::AppInfo);

			numberOfBlocks = response.NumberOfBlocks;
			m_board.Printf("Blocks: %d\r\n", numberOfBlocks);
		}

		//for (size_t i = 0)
		{
			GetDataBlockMessage request = {};
			request.Length = sizeof(GetDataBlockMessage);
			request.Type = MessageType::GetDataBlock;
			request.BlockNumber = 0;

			DataBlockMessage response = {};
			if (!SendAndReceive(request, response))
			{
				return;
			}
			AssertEqual(response.Type, MessageType::DataBlock);

			m_board.PrintBytes((char*)&response.Data[0], 64);
		}

		m_kernel.Sleep(5*1000);
		m_board.Printf("booting app...\r\n");
	}

	void BootApp()
	{
		ResetVectorTable* isr_vector = (ResetVectorTable*)SystemMemoryMap::App;
		if (isr_vector->Reset >= SystemMemoryMap::App && isr_vector->Reset < SystemMemoryMap::SysReserved)
		{
			//Stop old kernel
			m_kernel.Stop();
			
			AppMain main = (AppMain)isr_vector->Reset;
			__set_MSP(isr_vector->InitialSP);
			main();
		}

		//Boot app failed
		m_board.Printf("App launch failed...\r\n");
	}

	template<class TSend, class TReceive>
	bool SendAndReceive(TSend& send, TReceive& receive)
	{
		m_channel.Write((uint8_t*)&send, send.Length);

		while (m_channel.BytesAvailable() < sizeof(TReceive))
		{
			m_board.Printf("Bytes: %d\r\n", m_channel.BytesAvailable());
			WaitStatus status = m_kernel.KeWait(m_event, 5*1000);
			if (status == WaitStatus::Timeout)
			{
				m_board.Printf("SendAndReceive timeout\r\n");
				return false;
			}
		}
		m_channel.Read((uint8_t*)&receive, sizeof(TReceive));
		return true;
	}

	void OnDataReceived(const size_t bytesAvailable)
	{
		m_kernel.KeSignal(m_event);
	}

	Board& m_board;
	Kernel& m_kernel;
	DataChannel& m_channel;

	State m_state;
	KEvent m_event;
};
