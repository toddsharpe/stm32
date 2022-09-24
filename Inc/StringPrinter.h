#pragma once

#include <cstdarg>
#include <cstddef>

class StringPrinter
{
public:
	virtual void Write(const char *ptr, const size_t len) = 0;

	void Printf(const char *format, ...);
	void Printf(const char *format, const va_list args);

	void PrintBytes(const char *buffer, const size_t length);
};