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

