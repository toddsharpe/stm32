#pragma once

#include "stm32f7xx.h"
#include "stm32f746xx.h"
#include "DataChannel.h"

struct SpiConfig
{
	bool CPOL;
	bool CPHA;
	bool SoftwareSlaveManagement;
	bool SpiMaster;
	uint32_t PClkDiv;
	bool EnableDMA;
};

//NOTE(tsharpe): Logic analyzer only goes up to 24MHz
static constexpr SpiConfig const SpiMode3 = {.CPOL = true, .CPHA = true, .SoftwareSlaveManagement = true, .SpiMaster = true, .PClkDiv = SPI_CR1_BR_0, .EnableDMA = true};

class Spi : public DataChannel
{
public:
	Spi(SPI_TypeDef *spi) : m_spi(spi)
	{

	}

	void Init(const SpiConfig& config)
	{
		//Set clock phase
		MODIFY_REG(m_spi->CR1, SPI_CR1_CPHA, config.CPHA ? SPI_CR1_CPHA : 0);

		//Set clock polarity
		MODIFY_REG(m_spi->CR1, SPI_CR1_CPOL, config.CPOL ? SPI_CR1_CPOL : 0);

		//Set software slave management
		if (config.SoftwareSlaveManagement)
		{
			SET_BIT(m_spi->CR1, SPI_CR1_SSM);
			SET_BIT(m_spi->CR1, SPI_CR1_SSI);
		}

		//Set as master
		if (config.SpiMaster)
			SET_BIT(m_spi->CR1, SPI_CR1_MSTR);

		//Set clock div
		MODIFY_REG(m_spi->CR1, SPI_CR1_BR, config.PClkDiv);

		//Enable DMA
		if (config.EnableDMA)
			SET_BIT(m_spi->CR2, SPI_CR2_TXDMAEN);

		//Enable
		SET_BIT(m_spi->CR1, SPI_CR1_SPE);
	}

	//Write in 8bit chunks
	virtual void Write(const uint8_t* buffer, size_t length) override
	{
		for (size_t i = 0; i < length; i++)
		{
			while(!(m_spi->SR & (SPI_SR_TXE))) { };
			*((volatile uint8_t*)&(SPI1->DR)) = buffer[i];
		}
		while((m_spi->SR & (SPI_SR_BSY))) {};
	}

	virtual void Read(uint8_t* buffer, size_t length) override
	{
		//TODO(tsharpe): Not implemented
	}

	virtual size_t BytesAvailable() override
	{
		//TODO(tsharpe): Not implemented
		return 0;
	}

	//DMA peripheral interface?
	void* GetPeripheralAddress()
	{
		return (void*)&m_spi->DR;
	}

private:
	SPI_TypeDef *m_spi;
};