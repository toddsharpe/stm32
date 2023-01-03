#include <sifive/hifive_revb.h>
#include <sifive/Uart.h>
#include <string>
 
int main(void)
{
    Uart uart((void*)METAL_SIFIVE_UART0_10013000_BASE_ADDRESS);
    uart.Write(std::string("Hello, uart yay2!!\n"));
    uart.Write(std::string("Maybe this can work!!\n"));
    uart.Printf("Number: %d\n", 123);
    //uart.Write("Hello, uart yay!!\n");

	/* For now, just halt */
	for (;;);
}
 