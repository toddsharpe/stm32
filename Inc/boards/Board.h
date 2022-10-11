#pragma once

class Board
{
public:
	virtual void Printf(const char *format, ...) = 0;
	virtual uint32_t GetSysClkFreq() const = 0;

};