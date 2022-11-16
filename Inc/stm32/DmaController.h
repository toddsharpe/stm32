#pragma once

#include "stm32f746xx.h"

//UNUSED CLASS
class DmaController
{
public:
	DmaController(DMA_TypeDef* dma) : m_dma(dma)
	{

	}

private:
	DMA_TypeDef* m_dma;
};