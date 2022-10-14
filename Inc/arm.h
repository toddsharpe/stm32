#pragma once

#include <cstdint>

//M7: DUI0646C_cortex_m7_dgug.pdf

//ARM non-volatile registers
struct SoftwareStackFrame
{
	uint32_t R4;
	uint32_t R5;
	uint32_t R6;
	uint32_t R7;
	uint32_t R8;
	uint32_t R9;
	uint32_t R10;
	uint32_t R11;
	uint32_t LR;
};

//M7: Section 2.3.7
struct HardwareStackFrame
{
	uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t xPSR;
};

struct RCC_CR
{
	union
	{
		struct
		{
			uint32_t HSION : 1;
			uint32_t HSIRDY : 1;
			uint32_t _reserved1 : 1;
			uint32_t HSITRIM : 5;
			uint32_t HSICAL : 8;

			uint32_t HSEON : 1;
			uint32_t HSERDY : 1;
			uint32_t HSEBYP : 1;
			uint32_t CSSON : 1;
			uint32_t _reserved2 : 1;
			uint32_t PLLON : 1;
			uint32_t PLLRDY : 1;
			uint32_t PLLI2SON : 1;
			uint32_t PLLI2SRDY : 1;
			uint32_t PLLSAION : 1;
			uint32_t PLLSAIRDY : 1;
			uint32_t _reserved3 : 2;
		};
		uint32_t AsUint32;
	};
};
static_assert(sizeof(RCC_CR) == sizeof(uint32_t));