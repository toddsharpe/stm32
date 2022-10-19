#pragma once

class KEvent
{
public:
	KEvent(bool manualReset = false, bool initialState = false) : m_manualReset(manualReset), m_state(initialState)
	{

	}

	void Set()
	{
		m_state = true;
	}

	void Reset()
	{
		m_state = false;
	}

	bool IsManual()
	{
		return m_manualReset;
	}

	virtual bool IsSignalled() const
	{
		return m_state;
	}

private:
	bool m_manualReset;
	bool m_state;
};