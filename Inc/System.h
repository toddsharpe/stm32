#pragma once

#include "stm32f746xx.h"

enum SystemMemoryMap
{
	Bootloader = FLASH_BASE,
	App = FLASH_BASE + 0x00040000U
};