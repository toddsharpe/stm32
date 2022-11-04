#pragma once

#include "KSignalObject.h"

class KEvent : public KSignalObject
{
public:
	KEvent(bool manualReset = false, bool initialState = false) : KSignalObject(KObjectType::Event), m_manualReset(manualReset), m_state(initialState)
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

	virtual bool IsSignalled() const override
	{
		return m_state;
	}

private:
	bool m_manualReset;
	bool m_state;
};