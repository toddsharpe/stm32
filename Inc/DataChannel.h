#pragma once

#include "Callback.h"

class DataChannel
{
public:
	virtual void Write(const uint8_t* buffer, size_t length) = 0;
	virtual void Read(uint8_t* buffer, size_t length) = 0;
	virtual size_t BytesAvailable() = 0;

	ParamCallback<const size_t> DataReceived;
};