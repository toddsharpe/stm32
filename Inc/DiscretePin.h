#pragma once

class DiscretePin
{
public:
	virtual void Set(bool value) = 0;

	virtual bool Get() = 0;

	virtual bool Read() = 0;
	
	void Toggle()
	{
		Set(!Get());
	}
};