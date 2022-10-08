#pragma once

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <string>

class StringPrinter
{
public:
	virtual void Write(const std::string& str) = 0;

	void Printf(const char *format, ...);
	void Printf(const char *format, const va_list args);

	void PrintBytes(const char *buffer, const size_t length);
};