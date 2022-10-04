#pragma once

struct ReadOnlyBuffer
{
	const void* Data;
	size_t Length;
};

struct Buffer
{
	void* Data;
	size_t Length;
};

typedef void (*InterruptHandler)(void* arg);
struct InterruptContext
{
	InterruptHandler Handler;
	void* Context;
};
