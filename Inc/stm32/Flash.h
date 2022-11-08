#pragma once

#include "Assert.h"
#include "stm32f746xx.h"

#include <cstdint>

#define FLASH_FLAG_ALL_ERRORS (FLASH_SR_OPERR | FLASH_SR_WRPERR | FLASH_SR_PGAERR | \
							   FLASH_SR_PGPERR | FLASH_SR_ERSERR)

class Flash
{
public:
	static void Unlock()
	{
		BusyWait();

		// Check if already unlocked
		if (!READ_BIT(FLASH->CR, FLASH_CR_LOCK))
			return;

		/* Authorize the FLASH Registers access */
		WRITE_REG(FLASH->KEYR, FLASH_KEY1);
		WRITE_REG(FLASH->KEYR, FLASH_KEY2);

		// Spin until unlocked
		while (READ_BIT(FLASH->CR, FLASH_CR_LOCK) != 0);
	}

	static void Lock()
	{
		BusyWait();

		FLASH->CR |= FLASH_CR_LOCK;
	}

	static void EraseSector(const uint32_t sector)
	{
		Assert(sector <= SectorCount);

		BusyWait();

		// Set PSize x32
		CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);
		FLASH->CR |= PSize::x32;

		// Set sector
		CLEAR_BIT(FLASH->CR, FLASH_CR_SNB);
		FLASH->CR |= (sector << 3);

		// Set erase
		FLASH->CR |= FLASH_CR_SER;

		// Start
		FLASH->CR |= FLASH_CR_STRT;

		__DSB();

		// Wait for op
		BusyWait();

		// Clear erase and sectors
		CLEAR_BIT(FLASH->CR, (FLASH_CR_SER | FLASH_CR_SNB));
	}

	static void WriteByte(const uintptr_t address, const uint8_t data)
	{
		BusyWait();
		
		//Set PSize x8
		CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);
		FLASH->CR |= PSize::x8;

		//Set programming mode
		FLASH->CR |= FLASH_CR_PG;

		*(__IO uint8_t*)address = data;

		__DSB();

		BusyWait();
		CLEAR_BIT(FLASH->CR, FLASH_CR_PG);
	}

	static void WriteWord(const uintptr_t address, const uint32_t data)
	{
		BusyWait();

		//Set PSize x32
		CLEAR_BIT(FLASH->CR, FLASH_CR_PSIZE);
		FLASH->CR |= PSize::x32;

		//Set programming mode
		FLASH->CR |= FLASH_CR_PG;

		*(__IO uint32_t*)address = data;

		__DSB();

		BusyWait();
		CLEAR_BIT(FLASH->CR, FLASH_CR_PG);
	}

private:
	static void BusyWait()
	{
		while (READ_BIT(FLASH->SR, FLASH_SR_BSY) != 0);

		// Check no errors
		AssertPrintInt(READ_BIT(FLASH->SR, FLASH_FLAG_ALL_ERRORS) == 0, FLASH->SR);

		// CLear end of operation if set
		if (READ_BIT(FLASH->SR, FLASH_SR_EOP) != 0)
			WRITE_REG(FLASH->SR, FLASH_SR_EOP);
	}

	static constexpr uint32_t FLASH_KEY1 = 0x45670123U;
	static constexpr uint32_t FLASH_KEY2 = 0xCDEF89ABU;
	static constexpr uint32_t FLASH_OPT_KEY1 = 0x08192A3BU;
	static constexpr uint32_t FLASH_OPT_KEY2 = 0x4C5D6E7FU;

	static constexpr size_t SectorCount = 8;

	enum PSize
	{
		x8 = 0,
		x16 = FLASH_CR_PSIZE_0,
		x32 = FLASH_CR_PSIZE_1,
		x64 = FLASH_CR_PSIZE,
	};
};