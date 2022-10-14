#pragma once

#include "stm32f746xx.h"

#include "stm32/Rcc.h"
#include "stm32/Pll.h"
#include "stm32/SystemClock.h"
#include "stm32/GpioPin.h"
#include "stm32/Usart.h"
#include "boards/Board.h"
#include "util/util.h"

#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7
#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14

#define USER_Btn_Pin GPIO_PIN_13
#define USER_Btn_GPIO_Port GPIOC
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLK_RX_Pin GPIO_PIN_8
#define STLK_RX_GPIO_Port GPIOD
#define STLK_TX_Pin GPIO_PIN_9
#define STLK_TX_GPIO_Port GPIOD
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD0_Pin GPIO_PIN_13
#define RMII_TXD0_GPIO_Port GPIOG
#define SW0_Pin GPIO_PIN_3
#define SW0_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_7
#define LD2_GPIO_Port GPIOB

class NucleoF746ZG : public Board
{
public:
	NucleoF746ZG() : Board(), rcc(16'000'000, 8'000'000), uart(USART3), Led1(LD1_GPIO_Port, LD1_Pin), Led2(LD2_GPIO_Port, LD2_Pin), Led3(LD3_GPIO_Port, LD3_Pin)
	{

	}

	void Init()
	{
		//Initialize peripherals
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
		SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);
		SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);
		__DSB();
		
		//Initialize system clock
		Pll::Init(DefaultPllCOonfig);
		SystemClock::Init(DefaultSysClock);

		//Initialize peripherals
		uart.Init(rcc.GetPClk1Freq(), UartDefault);
		Led1.Init(GpioOutput);
		Led2.Init(GpioOutput);
		Led3.Init(GpioOutput);

		//Print welcome
		uart.Printf("Board initialized\r\n");

		//Print clocks
		RccClocks clocks = {};
		rcc.GetSystemClocksFreq(clocks);
		uart.Printf("SysClkFreq: %d\r\n", clocks.SysClkFreq);
		uart.Printf("HClkFreq: %d\r\n", clocks.HClkFreq);
		uart.Printf("PClk1Freq: %d\r\n", clocks.PClk1Freq);
		uart.Printf("PClk2Freq: %d\r\n", clocks.PClk2Freq);
	}

	virtual void Printf(const char *format, ...) override
	{
		va_list args;
		va_start(args, format);
		uart.Printf(format, args);
		va_end(args);
	}

	virtual uint32_t GetSysClkFreq() const override
	{
		return rcc.GetSysClkFreq();
	}

	Rcc rcc;

	Usart uart;

	GpioPin Led1;
	GpioPin Led2;
	GpioPin Led3;
};