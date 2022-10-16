#include "stm32/GpioPin.h"
#include "boards/NUCLEO-F746ZG.h"
#include <cstdint>
#include "arm.h"
#include "System.h"

NucleoF746ZG board = {};


typedef void (*AppMain)(void);
int main()
{
	board.Init();
	board.Printf("Bootloader Active\r\n");

	ResetVectorTable* isr_vector = (ResetVectorTable*)SystemMemoryMap::App;

	//Jump to app
	__set_MSP(isr_vector->InitialSP);
	AppMain main = (AppMain)isr_vector->Reset;
	main();

	board.Printf("App launch failed...\r\n");
	while (true)
		__WFI();
}