
/****************************************************************************************************//**
 * @file     sifive_hifive1_revb.h
 *
 * @brief    CMSIS Cortex-M3 Peripheral Access Layer Header File for
 *           sifive_hifive1_revb from .
 *
 * @version  V0.1
 * @date     4. January 2023
 *
 * @note     Generated with SVDConv V2.87l 
 *           from CMSIS SVD File 'sifive_hifive1_revb.svd' Version 0.1,
 *******************************************************************************************************/



/** @addtogroup (null)
  * @{
  */

/** @addtogroup sifive_hifive1_revb
  * @{
  */

#ifndef SIFIVE_HIFIVE1_REVB_H
#define SIFIVE_HIFIVE1_REVB_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M3 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn         = -12,              /*!<   4  Memory Management, MPU mismatch, including Access Violation
                                                         and No Match                                                          */
  BusFault_IRQn                 = -11,              /*!<   5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                         related Fault                                                         */
  UsageFault_IRQn               = -10,              /*!<   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             =  -4,              /*!<  12  Debug Monitor                                                    */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* ---------------- sifive_hifive1_revb Specific Interrupt Numbers ---------------- */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M3 Processor and Core Peripherals---------------- */
#define __CM3_REV                 0x0200            /*!< Cortex-M3 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               4            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm3.h"                               /*!< Cortex-M3 processor and core peripherals                              */
//#include "system_sifive_hifive1_revb.h"             /*!< sifive_hifive1_revb System                                            */


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================                 riscv_clint0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From riscv,clint0,control peripheral generator (riscv_clint0_0)
  */

typedef struct {                                    /*!< riscv_clint0_0 Structure                                              */
  __IO uint32_t  msip_0;                            /*!< MSIP Register for hart 0                                              */
} riscv_clint0_0_Type;


/* ================================================================================ */
/* ================                  riscv_plic0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From riscv,plic0,control peripheral generator (riscv_plic0_0)
  */

typedef struct {                                    /*!< riscv_plic0_0 Structure                                               */
  __I  uint32_t  RESERVED;
  __IO uint32_t  priority_1;                        /*!< PRIORITY Register for interrupt id 1                                  */
  __IO uint32_t  priority_2;                        /*!< PRIORITY Register for interrupt id 2                                  */
  __IO uint32_t  priority_3;                        /*!< PRIORITY Register for interrupt id 3                                  */
  __IO uint32_t  priority_4;                        /*!< PRIORITY Register for interrupt id 4                                  */
  __IO uint32_t  priority_5;                        /*!< PRIORITY Register for interrupt id 5                                  */
  __IO uint32_t  priority_6;                        /*!< PRIORITY Register for interrupt id 6                                  */
  __IO uint32_t  priority_7;                        /*!< PRIORITY Register for interrupt id 7                                  */
  __IO uint32_t  priority_8;                        /*!< PRIORITY Register for interrupt id 8                                  */
  __IO uint32_t  priority_9;                        /*!< PRIORITY Register for interrupt id 9                                  */
  __IO uint32_t  priority_10;                       /*!< PRIORITY Register for interrupt id 10                                 */
  __IO uint32_t  priority_11;                       /*!< PRIORITY Register for interrupt id 11                                 */
  __IO uint32_t  priority_12;                       /*!< PRIORITY Register for interrupt id 12                                 */
  __IO uint32_t  priority_13;                       /*!< PRIORITY Register for interrupt id 13                                 */
  __IO uint32_t  priority_14;                       /*!< PRIORITY Register for interrupt id 14                                 */
  __IO uint32_t  priority_15;                       /*!< PRIORITY Register for interrupt id 15                                 */
  __IO uint32_t  priority_16;                       /*!< PRIORITY Register for interrupt id 16                                 */
  __IO uint32_t  priority_17;                       /*!< PRIORITY Register for interrupt id 17                                 */
  __IO uint32_t  priority_18;                       /*!< PRIORITY Register for interrupt id 18                                 */
  __IO uint32_t  priority_19;                       /*!< PRIORITY Register for interrupt id 19                                 */
  __IO uint32_t  priority_20;                       /*!< PRIORITY Register for interrupt id 20                                 */
  __IO uint32_t  priority_21;                       /*!< PRIORITY Register for interrupt id 21                                 */
  __IO uint32_t  priority_22;                       /*!< PRIORITY Register for interrupt id 22                                 */
  __IO uint32_t  priority_23;                       /*!< PRIORITY Register for interrupt id 23                                 */
  __IO uint32_t  priority_24;                       /*!< PRIORITY Register for interrupt id 24                                 */
  __IO uint32_t  priority_25;                       /*!< PRIORITY Register for interrupt id 25                                 */
  __IO uint32_t  priority_26;                       /*!< PRIORITY Register for interrupt id 26                                 */
  __IO uint32_t  priority_27;                       /*!< PRIORITY Register for interrupt id 27                                 */
  __IO uint32_t  priority_28;                       /*!< PRIORITY Register for interrupt id 28                                 */
  __IO uint32_t  priority_29;                       /*!< PRIORITY Register for interrupt id 29                                 */
  __IO uint32_t  priority_30;                       /*!< PRIORITY Register for interrupt id 30                                 */
  __IO uint32_t  priority_31;                       /*!< PRIORITY Register for interrupt id 31                                 */
  __IO uint32_t  priority_32;                       /*!< PRIORITY Register for interrupt id 32                                 */
  __IO uint32_t  priority_33;                       /*!< PRIORITY Register for interrupt id 33                                 */
  __IO uint32_t  priority_34;                       /*!< PRIORITY Register for interrupt id 34                                 */
  __IO uint32_t  priority_35;                       /*!< PRIORITY Register for interrupt id 35                                 */
  __IO uint32_t  priority_36;                       /*!< PRIORITY Register for interrupt id 36                                 */
  __IO uint32_t  priority_37;                       /*!< PRIORITY Register for interrupt id 37                                 */
  __IO uint32_t  priority_38;                       /*!< PRIORITY Register for interrupt id 38                                 */
  __IO uint32_t  priority_39;                       /*!< PRIORITY Register for interrupt id 39                                 */
  __IO uint32_t  priority_40;                       /*!< PRIORITY Register for interrupt id 40                                 */
  __IO uint32_t  priority_41;                       /*!< PRIORITY Register for interrupt id 41                                 */
  __IO uint32_t  priority_42;                       /*!< PRIORITY Register for interrupt id 42                                 */
  __IO uint32_t  priority_43;                       /*!< PRIORITY Register for interrupt id 43                                 */
  __IO uint32_t  priority_44;                       /*!< PRIORITY Register for interrupt id 44                                 */
  __IO uint32_t  priority_45;                       /*!< PRIORITY Register for interrupt id 45                                 */
  __IO uint32_t  priority_46;                       /*!< PRIORITY Register for interrupt id 46                                 */
  __IO uint32_t  priority_47;                       /*!< PRIORITY Register for interrupt id 47                                 */
  __IO uint32_t  priority_48;                       /*!< PRIORITY Register for interrupt id 48                                 */
  __IO uint32_t  priority_49;                       /*!< PRIORITY Register for interrupt id 49                                 */
  __IO uint32_t  priority_50;                       /*!< PRIORITY Register for interrupt id 50                                 */
  __IO uint32_t  priority_51;                       /*!< PRIORITY Register for interrupt id 51                                 */
  __IO uint32_t  priority_52;                       /*!< PRIORITY Register for interrupt id 52                                 */
  __I  uint32_t  RESERVED1[971];
  __IO uint32_t  pending_0;                         /*!< PENDING Register for interrupt ids 31 to 0                            */
  __IO uint32_t  pending_1;                         /*!< PENDING Register for interrupt ids 52 to 32                           */
  __I  uint32_t  RESERVED2[1022];
  __IO uint32_t  enable_0_0;                        /*!< ENABLE Register for interrupt ids 31 to 0 for hart 0                  */
  __IO uint32_t  enable_1_0;                        /*!< ENABLE Register for interrupt ids 52 to 32 for hart 0                 */
  __I  uint32_t  RESERVED3[522238];
  __IO uint32_t  threshold_0;                       /*!< PRIORITY THRESHOLD Register for hart 0                                */
  __IO uint32_t  claimplete_0;                      /*!< CLAIM and COMPLETE Register for hart 0                                */
} riscv_plic0_0_Type;


/* ================================================================================ */
/* ================                  sifive_aon0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,aon0,mem peripheral generator (sifive_aon0_0)
  */

typedef struct {                                    /*!< sifive_aon0_0 Structure                                               */
  
  union {
    __IO uint32_t  wdogcfg;                         /*!< wdog Configuration                                                    */
    
    struct {
      __IO uint32_t  wdogscale  :  4;               /*!< Counter scale value.                                                  */
           uint32_t             :  4;
      __IO uint32_t  wdogrsten  :  1;               /*!< Controls whether the comparator output can set the wdogrst bit
                                                         and hence cause a full reset.                                         */
      __IO uint32_t  wdogzerocmp:  1;               /*!< Reset counter to zero after match.                                    */
           uint32_t             :  2;
      __IO uint32_t  wdogenalways:  1;              /*!< Enable Always - run continuously                                      */
      __IO uint32_t  wdogcoreawake:  1;             /*!< Increment the watchdog counter if the processor is not asleep         */
           uint32_t             : 14;
      __IO uint32_t  wdogip0    :  1;               /*!< Interrupt 0 Pending                                                   */
    } wdogcfg_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  __IO uint32_t  wdogcount;                         /*!< Counter Register                                                      */
  __I  uint32_t  RESERVED1;
  __IO uint32_t  wdogs;                             /*!< Scaled value of Counter                                               */
  __I  uint32_t  RESERVED2;
  __IO uint32_t  wdogfeed;                          /*!< Feed register                                                         */
  __IO uint32_t  wdogkey;                           /*!< Key Register                                                          */
  __IO uint32_t  wdogcmp0;                          /*!< Comparator 0                                                          */
  __I  uint32_t  RESERVED3[7];
  
  union {
    __IO uint32_t  rtccfg;                          /*!< rtc Configuration                                                     */
    
    struct {
      __IO uint32_t  rtcscale   :  4;               /*!< Counter scale value.                                                  */
           uint32_t             :  8;
      __IO uint32_t  rtcenalways:  1;               /*!< Enable Always - run continuously                                      */
           uint32_t             : 15;
      __IO uint32_t  rtcip0     :  1;               /*!< Interrupt 0 Pending                                                   */
    } rtccfg_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4;
  __IO uint32_t  rtccountlo;                        /*!< Low bits of Counter                                                   */
  __IO uint32_t  rtccounthi;                        /*!< High bits of Counter                                                  */
  __IO uint32_t  rtcs;                              /*!< Scaled value of Counter                                               */
  __I  uint32_t  RESERVED5[3];
  __IO uint32_t  rtccmp0;                           /*!< Comparator 0                                                          */
  __I  uint32_t  RESERVED6[3];
  
  union {
    __IO uint32_t  lfrosccfg;                       /*!< Ring Oscillator Configuration and Status                              */
    
    struct {
      __IO uint32_t  lfroscdiv  :  6;               /*!< Ring Oscillator Divider Register                                      */
           uint32_t             : 10;
      __IO uint32_t  lfrosctrim :  5;               /*!< Ring Oscillator Trim Register                                         */
           uint32_t             :  9;
      __IO uint32_t  lfroscen   :  1;               /*!< Ring Oscillator Enable                                                */
      __I  uint32_t  lfroscrdy  :  1;               /*!< Ring Oscillator Ready                                                 */
    } lfrosccfg_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED7[2];
  
  union {
    __IO uint32_t  lfclkmux;                        /*!< Low-Frequency Clock Mux Control and Status                            */
    
    struct {
      __IO uint32_t  lfextclk_sel:  1;              /*!< Low Frequency Clock Source Selector                                   */
           uint32_t             : 30;
      __I  uint32_t  lfextclk_mux_status:  1;       /*!< Setting of the aon_lfclksel pin                                       */
    } lfclkmux_b;                                   /*!< BitSize                                                               */
  };
  __IO uint32_t  backup_0;                          /*!< Backup Register 0                                                     */
  __IO uint32_t  backup_1;                          /*!< Backup Register 1                                                     */
  __IO uint32_t  backup_2;                          /*!< Backup Register 2                                                     */
  __IO uint32_t  backup_3;                          /*!< Backup Register 3                                                     */
  __IO uint32_t  backup_4;                          /*!< Backup Register 4                                                     */
  __IO uint32_t  backup_5;                          /*!< Backup Register 5                                                     */
  __IO uint32_t  backup_6;                          /*!< Backup Register 6                                                     */
  __IO uint32_t  backup_7;                          /*!< Backup Register 7                                                     */
  __IO uint32_t  backup_8;                          /*!< Backup Register 8                                                     */
  __IO uint32_t  backup_9;                          /*!< Backup Register 9                                                     */
  __IO uint32_t  backup_10;                         /*!< Backup Register 10                                                    */
  __IO uint32_t  backup_11;                         /*!< Backup Register 11                                                    */
  __IO uint32_t  backup_12;                         /*!< Backup Register 12                                                    */
  __IO uint32_t  backup_13;                         /*!< Backup Register 13                                                    */
  __IO uint32_t  backup_14;                         /*!< Backup Register 14                                                    */
  __IO uint32_t  backup_15;                         /*!< Backup Register 15                                                    */
  __I  uint32_t  RESERVED8[16];
  __IO uint32_t  pmuwakeupi0;                       /*!< Wakeup program instruction 0                                          */
  __IO uint32_t  pmuwakeupi1;                       /*!< Wakeup program instruction 1                                          */
  __IO uint32_t  pmuwakeupi2;                       /*!< Wakeup program instruction 2                                          */
  __IO uint32_t  pmuwakeupi3;                       /*!< Wakeup program instruction 3                                          */
  __IO uint32_t  pmuwakeupi4;                       /*!< Wakeup program instruction 4                                          */
  __IO uint32_t  pmuwakeupi5;                       /*!< Wakeup program instruction 5                                          */
  __IO uint32_t  pmuwakeupi6;                       /*!< Wakeup program instruction 6                                          */
  __IO uint32_t  pmuwakeupi7;                       /*!< Wakeup program instruction 7                                          */
  __IO uint32_t  pmusleepi0;                        /*!< Sleep program instruction 0                                           */
  __IO uint32_t  pmusleepi1;                        /*!< Sleep program instruction 1                                           */
  __IO uint32_t  pmusleepi2;                        /*!< Sleep program instruction 2                                           */
  __IO uint32_t  pmusleepi3;                        /*!< Sleep program instruction 3                                           */
  __IO uint32_t  pmusleepi4;                        /*!< Sleep program instruction 4                                           */
  __IO uint32_t  pmusleepi5;                        /*!< Sleep program instruction 5                                           */
  __IO uint32_t  pmusleepi6;                        /*!< Sleep program instruction 6                                           */
  __IO uint32_t  pmusleepi7;                        /*!< Sleep program instruction 7                                           */
  __IO uint32_t  pmuie;                             /*!< PMU Interrupt Enables                                                 */
  __IO uint32_t  pmucause;                          /*!< PMU Wakeup Cause                                                      */
  __IO uint32_t  pmusleep;                          /*!< Initiate PMU Sleep Sequence                                           */
  __IO uint32_t  pmukey;                            /*!< PMU Key. Reads as 1 when PMU is unlocked                              */
  __I  uint32_t  RESERVED9[108];
  
  union {
    __I  uint32_t  aoncfg;                          /*!< AON Block Configuration Information                                   */
    
    struct {
      __I  uint32_t  has_bandgap:  1;               /*!< Bandgap feature is present                                            */
      __I  uint32_t  has_bod    :  1;               /*!< Brownout detector feature is present                                  */
      __I  uint32_t  has_lfrosc :  1;               /*!< Low Frequency Ring Oscillator feature is present                      */
      __I  uint32_t  has_lfrcosc:  1;               /*!< Low Frequency RC Oscillator feature is present                        */
      __I  uint32_t  has_lfxosc :  1;               /*!< Low Frequency Crystal Oscillator feature is present                   */
      __I  uint32_t  has_por    :  1;               /*!< Power-On-Reset feature is present                                     */
      __I  uint32_t  has_ldo    :  1;               /*!< Low Dropout Regulator feature is present                              */
    } aoncfg_b;                                     /*!< BitSize                                                               */
  };
} sifive_aon0_0_Type;


/* ================================================================================ */
/* ================            sifive_fe310_g000_prci_0            ================ */
/* ================================================================================ */


/**
  * @brief From sifive,fe310-g000,prci,mem peripheral generator (sifive_fe310_g000_prci_0)
  */

typedef struct {                                    /*!< sifive_fe310_g000_prci_0 Structure                                    */
  
  union {
    __IO uint32_t  hfrosccfg;                       /*!< Ring Oscillator Configuration and Status                              */
    
    struct {
      __IO uint32_t  hfroscdiv  :  6;               /*!< Ring Oscillator Divider Register                                      */
           uint32_t             : 10;
      __IO uint32_t  hfrosctrim :  5;               /*!< Ring Oscillator Trim Register                                         */
           uint32_t             :  9;
      __IO uint32_t  hfroscen   :  1;               /*!< Ring Oscillator Enable                                                */
      __I  uint32_t  hfroscrdy  :  1;               /*!< Ring Oscillator Ready                                                 */
    } hfrosccfg_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  hfxosccfg;                       /*!< Crystal Oscillator Configuration and Status                           */
    
    struct {
           uint32_t             : 30;
      __IO uint32_t  hfxoscen   :  1;               /*!< Crystal Oscillator Enable                                             */
      __I  uint32_t  hfxoscrdy  :  1;               /*!< Crystal Oscillator Ready                                              */
    } hfxosccfg_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pllcfg;                          /*!< PLL Configuration and Status                                          */
    
    struct {
      __IO uint32_t  pllr       :  3;               /*!< PLL R Value                                                           */
           uint32_t             :  1;
      __IO uint32_t  pllf       :  6;               /*!< PLL F Value                                                           */
      __IO uint32_t  pllq       :  2;               /*!< PLL Q Value                                                           */
           uint32_t             :  4;
      __IO uint32_t  pllsel     :  1;               /*!< PLL Select                                                            */
      __IO uint32_t  pllrefsel  :  1;               /*!< PLL Reference Select                                                  */
      __IO uint32_t  pllbypass  :  1;               /*!< PLL Bypass                                                            */
           uint32_t             : 12;
      __I  uint32_t  plllock    :  1;               /*!< PLL Lock                                                              */
    } pllcfg_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  plloutdiv;                       /*!< PLL Final Divide Configuration                                        */
    
    struct {
      __IO uint32_t  plloutdiv  :  6;               /*!< PLL Final Divider Value                                               */
           uint32_t             :  2;
      __IO uint32_t  plloutdivby1:  6;              /*!< PLL Final Divide By 1                                                 */
    } plloutdiv_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[56];
  
  union {
    __IO uint32_t  procmoncfg;                      /*!< Process Monitor Configuration and Status                              */
    
    struct {
      __IO uint32_t  procmon_div_sel:  5;           /*!< Proccess Monitor Divider                                              */
           uint32_t             :  3;
      __IO uint32_t  procmon_delay_sel:  5;         /*!< Process Monitor Delay Selector                                        */
           uint32_t             :  3;
      __IO uint32_t  procmon_en :  1;               /*!< Process Monitor Enable                                                */
           uint32_t             :  7;
      __IO uint32_t  procomon_sel:  2;              /*!< Process Monitor Select                                                */
    } procmoncfg_b;                                 /*!< BitSize                                                               */
  };
} sifive_fe310_g000_prci_0_Type;


/* ================================================================================ */
/* ================                 sifive_gpio0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,gpio0,control peripheral generator (sifive_gpio0_0)
  */

typedef struct {                                    /*!< sifive_gpio0_0 Structure                                              */
  __IO uint32_t  input_val;                         /*!< Pin value                                                             */
  __IO uint32_t  input_en;                          /*!< Pin input enable                                                      */
  __IO uint32_t  output_en;                         /*!< Pin output enable                                                     */
  __IO uint32_t  output_val;                        /*!< Output value                                                          */
  __IO uint32_t  pue;                               /*!< Internal pull-up enable                                               */
  __IO uint32_t  ds;                                /*!< Pin drive strength                                                    */
  __IO uint32_t  rise_ie;                           /*!< Rise interrupt enable                                                 */
  __IO uint32_t  rise_ip;                           /*!< Rise interrupt pending                                                */
  __IO uint32_t  fall_ie;                           /*!< Fall interrupt enable                                                 */
  __IO uint32_t  fall_ip;                           /*!< Fall interrupt pending                                                */
  __IO uint32_t  high_ie;                           /*!< High interrupt enable                                                 */
  __IO uint32_t  high_ip;                           /*!< High interrupt pending                                                */
  __IO uint32_t  low_ie;                            /*!< Low interrupt enable                                                  */
  __IO uint32_t  low_ip;                            /*!< Low interrupt pending                                                 */
  __IO uint32_t  iof_en;                            /*!< I/O function enable                                                   */
  __IO uint32_t  iof_sel;                           /*!< I/O function select                                                   */
  __IO uint32_t  out_xor;                           /*!< Output XOR (invert)                                                   */
} sifive_gpio0_0_Type;


/* ================================================================================ */
/* ================                 sifive_uart0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,uart0,control peripheral generator (sifive_uart0_0)
  */

typedef struct {                                    /*!< sifive_uart0_0 Structure                                              */
  
  union {
    __IO uint32_t  txdata;                          /*!< Transmit data register                                                */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< Transmit data                                                         */
           uint32_t             : 23;
      __I  uint32_t  full       :  1;               /*!< Transmit FIFO full                                                    */
    } txdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  rxdata;                          /*!< Receive data register                                                 */
    
    struct {
      __I  uint32_t  data       :  8;               /*!< Received data                                                         */
           uint32_t             : 23;
      __I  uint32_t  empty      :  1;               /*!< Receive FIFO empty                                                    */
    } rxdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  txctrl;                          /*!< Transmit control register                                             */
    
    struct {
      __IO uint32_t  txen       :  1;               /*!< Transmit enable                                                       */
      __IO uint32_t  nstop      :  1;               /*!< Number of stop bits                                                   */
           uint32_t             : 14;
      __IO uint32_t  txcnt      :  3;               /*!< Transmit watermark level                                              */
    } txctrl_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxctrl;                          /*!< Receive control register                                              */
    
    struct {
      __IO uint32_t  rxen       :  1;               /*!< Receive enable                                                        */
           uint32_t             : 15;
      __IO uint32_t  rxcnt      :  3;               /*!< Receive watermark level                                               */
    } rxctrl_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ie;                              /*!< UART interrupt enable                                                 */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< Transmit watermark interrupt enable                                   */
      __IO uint32_t  rxwm       :  1;               /*!< Receive watermark interrupt enable                                    */
    } ie_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ip;                              /*!< UART interrupt pending                                                */
    
    struct {
      __I  uint32_t  txwm       :  1;               /*!< Transmit watermark interrupt pending                                  */
      __I  uint32_t  rxwm       :  1;               /*!< Receive watermark interrupt pending                                   */
    } ip_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  div;                             /*!< Baud rate divisor                                                     */
    
    struct {
      __IO uint32_t  div        : 16;               /*!< Baud rate divisor.                                                    */
    } div_b;                                        /*!< BitSize                                                               */
  };
} sifive_uart0_0_Type;


/* ================================================================================ */
/* ================                  sifive_spi0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,spi0,control peripheral generator (sifive_spi0_0)
  */

typedef struct {                                    /*!< sifive_spi0_0 Structure                                               */
  
  union {
    __IO uint32_t  sckdiv;                          /*!< Serial clock divisor                                                  */
    
    struct {
      __IO uint32_t  div        : 12;               /*!< Divisor for serial clock.                                             */
    } sckdiv_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sckmode;                         /*!< Serial clock mode                                                     */
    
    struct {
      __IO uint32_t  pha        :  1;               /*!< Serial clock phase                                                    */
      __IO uint32_t  pol        :  1;               /*!< Serial clock polarity                                                 */
    } sckmode_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[2];
  
  union {
    __IO uint32_t  csid;                            /*!< Chip select ID                                                        */
    
    struct {
      __IO uint32_t  csid       : 32;               /*!< Chip select ID.                                                       */
    } csid_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  csdef;                           /*!< Chip select default                                                   */
    
    struct {
      __IO uint32_t  csdef      : 32;               /*!< Chip select default value. Reset to all-1s.                           */
    } csdef_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  csmode;                          /*!< Chip select mode                                                      */
    
    struct {
      __IO uint32_t  mode       :  2;               /*!< Chip select mode                                                      */
    } csmode_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[3];
  
  union {
    __IO uint32_t  delay0;                          /*!< Delay control 0                                                       */
    
    struct {
      __IO uint32_t  cssck      :  8;               /*!< CS to SCK Delay                                                       */
           uint32_t             :  8;
      __IO uint32_t  sckcs      :  8;               /*!< SCK to CS Delay                                                       */
    } delay0_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  delay1;                          /*!< Delay control 1                                                       */
    
    struct {
      __IO uint32_t  intercs    :  8;               /*!< Minimum CS inactive time                                              */
           uint32_t             :  8;
      __IO uint32_t  interxfr   :  8;               /*!< Maximum interframe delay                                              */
    } delay1_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[2];
  
  union {
    __IO uint32_t  extradel;                        /*!< SPI extra sampling delay to increase the SPI frequency                */
    
    struct {
      __IO uint32_t  coarse     : 12;               /*!< Coarse grain sample delay (multiples of system clocks)                */
      __IO uint32_t  fine       :  5;               /*!< Fine grain sample delay (multiples of process-specific buffer
                                                         delay)                                                                */
    } extradel_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sampledel;                       /*!< Number of delay stages from slave to the SPI controller               */
    
    struct {
      __IO uint32_t  sd         :  5;               /*!< Number of delay stages from slave to SPI controller                   */
    } sampledel_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fmt;                             /*!< Frame format                                                          */
    
    struct {
      __IO uint32_t  proto      :  2;               /*!< SPI protocol                                                          */
      __IO uint32_t  endian     :  1;               /*!< SPI endianness                                                        */
      __IO uint32_t  dir        :  1;               /*!< SPI I/O direction. This is reset to 1 for flash-enabled SPI
                                                         controllers, 0 otherwise.                                             */
           uint32_t             : 12;
      __IO uint32_t  len        :  4;               /*!< Number of bits per frame                                              */
    } fmt_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  txdata;                          /*!< Tx FIFO Data                                                          */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< Transmit data                                                         */
           uint32_t             : 23;
      __I  uint32_t  full       :  1;               /*!< FIFO full flag                                                        */
    } txdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxdata;                          /*!< Rx FIFO data                                                          */
    
    struct {
      __I  uint32_t  data       :  8;               /*!< Received data                                                         */
           uint32_t             : 23;
      __IO uint32_t  empty      :  1;               /*!< FIFO empty flag                                                       */
    } rxdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  txmark;                          /*!< Tx FIFO watermark                                                     */
    
    struct {
      __IO uint32_t  txmark     :  3;               /*!< Transmit watermark. The reset value is 1 for flash-enabled controllers,
                                                         0 otherwise.                                                          */
    } txmark_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxmark;                          /*!< Rx FIFO watermark                                                     */
    
    struct {
      __IO uint32_t  rxmark     :  3;               /*!< Receive watermark                                                     */
    } rxmark_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4[2];
  
  union {
    __IO uint32_t  fctrl;                           /*!< SPI flash interface control                                           */
    
    struct {
      __IO uint32_t  en         :  1;               /*!< SPI Flash Mode Select                                                 */
    } fctrl_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ffmt;                            /*!< SPI flash instruction format                                          */
    
    struct {
      __IO uint32_t  cmd_en     :  1;               /*!< Enable sending of command                                             */
      __IO uint32_t  addr_len   :  3;               /*!< Number of address bytes (0 to 4)                                      */
      __IO uint32_t  pad_cnt    :  4;               /*!< Number of dummy cycles                                                */
      __IO uint32_t  cmd_proto  :  2;               /*!< Protocol for transmitting command                                     */
      __IO uint32_t  addr_proto :  2;               /*!< Protocol for transmitting address and padding                         */
      __IO uint32_t  data_proto :  2;               /*!< Protocol for receiving data bytes                                     */
           uint32_t             :  2;
      __IO uint32_t  cmd_code   :  8;               /*!< Value of command byte                                                 */
      __IO uint32_t  pad_code   :  8;               /*!< First 8 bits to transmit during dummy cycles                          */
    } ffmt_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED5[2];
  
  union {
    __IO uint32_t  ie;                              /*!< SPI interrupt enable                                                  */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< Transmit watermark enable                                             */
      __IO uint32_t  rxwm       :  1;               /*!< Receive watermark enable                                              */
    } ie_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ip;                              /*!< SPI interrupt pending                                                 */
    
    struct {
      __I  uint32_t  txwm       :  1;               /*!< Transmit watermark pending                                            */
      __I  uint32_t  rxwm       :  1;               /*!< Receive watermark pending                                             */
    } ip_b;                                         /*!< BitSize                                                               */
  };
} sifive_spi0_0_Type;


/* ================================================================================ */
/* ================                  sifive_pwm0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,pwm0,control peripheral generator (sifive_pwm0_0)
  */

typedef struct {                                    /*!< sifive_pwm0_0 Structure                                               */
  
  union {
    __IO uint32_t  pwmcfg;                          /*!< PWM configuration register                                            */
    
    struct {
      __IO uint32_t  pwmscale   :  4;               /*!< PWM Counter scale                                                     */
           uint32_t             :  4;
      __IO uint32_t  pwmsticky  :  1;               /*!< PWM Sticky - disallow clearing pwmcmpXip bits                         */
      __IO uint32_t  pwmzerocmp :  1;               /*!< PWM Zero - counter resets to zero after match                         */
      __IO uint32_t  pwmdeglitch:  1;               /*!< PWM Deglitch - latch pwmcmpXip within same cycle                      */
           uint32_t             :  1;
      __IO uint32_t  pwmenalways:  1;               /*!< PWM enable always - run continuously                                  */
      __IO uint32_t  pwmenoneshot:  1;              /*!< PWM enable one shot - run one cycle                                   */
           uint32_t             :  2;
      __IO uint32_t  pwmcmp0center:  1;             /*!< PWM0 Compare Center                                                   */
      __IO uint32_t  pwmcmp1center:  1;             /*!< PWM1 Compare Center                                                   */
      __IO uint32_t  pwmcmp2center:  1;             /*!< PWM2 Compare Center                                                   */
      __IO uint32_t  pwmcmp3center:  1;             /*!< PWM3 Compare Center                                                   */
      __IO uint32_t  pwmcmp0invert:  1;             /*!< PWM0 Invert                                                           */
      __IO uint32_t  pwmcmp1invert:  1;             /*!< PWM1 Invert                                                           */
      __IO uint32_t  pwmcmp2invert:  1;             /*!< PWM2 Invert                                                           */
      __IO uint32_t  pwmcmp3invert:  1;             /*!< PWM3 Invert                                                           */
      __IO uint32_t  pwmcmp0gang:  1;               /*!< PWM0/PWM1 Compare Gang                                                */
      __IO uint32_t  pwmcmp1gang:  1;               /*!< PWM1/PWM2 Compare Gang                                                */
      __IO uint32_t  pwmcmp2gang:  1;               /*!< PWM2/PWM3 Compare Gang                                                */
      __IO uint32_t  pwmcmp3gang:  1;               /*!< PWM3/PWM0 Compare Gang                                                */
      __IO uint32_t  pwmcmp0ip  :  1;               /*!< PWM0 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp1ip  :  1;               /*!< PWM1 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp2ip  :  1;               /*!< PWM2 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp3ip  :  1;               /*!< PWM3 Interrupt Pending                                                */
    } pwmcfg_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  pwmcount;                        /*!< PWM count register                                                    */
    
    struct {
      __IO uint32_t  pwmcount   : 31;               /*!< PWM count register.                                                   */
    } pwmcount_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  pwms;                            /*!< Scaled PWM count register                                             */
    
    struct {
      __IO uint32_t  pwms       : 16;               /*!< Scaled PWM count register.                                            */
    } pwms_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[3];
  
  union {
    __IO uint32_t  pwmcmp0;                         /*!< PWM 0 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp0    : 16;               /*!< PWM 0 Compare Value                                                   */
    } pwmcmp0_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp1;                         /*!< PWM 1 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp1    : 16;               /*!< PWM 1 Compare Value                                                   */
    } pwmcmp1_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp2;                         /*!< PWM 2 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp2    : 16;               /*!< PWM 2 Compare Value                                                   */
    } pwmcmp2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp3;                         /*!< PWM 3 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp3    : 16;               /*!< PWM 3 Compare Value                                                   */
    } pwmcmp3_b;                                    /*!< BitSize                                                               */
  };
} sifive_pwm0_0_Type;


/* ================================================================================ */
/* ================                  sifive_i2c0_0                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,i2c0,control peripheral generator (sifive_i2c0_0)
  */

typedef struct {                                    /*!< sifive_i2c0_0 Structure                                               */
  __IO uint32_t  prescale_low;                      /*!< Clock Prescale register lo-byte                                       */
  __IO uint32_t  prescale_high;                     /*!< Clock Prescale register hi-byte                                       */
  
  union {
    __IO uint32_t  control;                         /*!< Control register                                                      */
    
    struct {
           uint32_t             :  6;
      __IO uint32_t  en         :  1;               /*!< I2C core enable bit                                                   */
      __IO uint32_t  ien        :  1;               /*!< I2C core interrupt enable bit                                         */
    } control_b;                                    /*!< BitSize                                                               */
  };
  __IO uint32_t  transmit__receive;                 /*!< Transmit and receive data byte register                               */
  
  union {
    __IO uint32_t  command__status;                 /*!< Command write and status read register                                */
    
    struct {
      __IO uint32_t  wr_iack__rd_if:  1;            /*!< Clear interrupt and Interrupt pending                                 */
      __IO uint32_t  wr_res__rd_tip:  1;            /*!< Reserved and Transfer in progress                                     */
      __IO uint32_t  wr_res__rd_res:  1;            /*!< Reserved and Reserved                                                 */
      __IO uint32_t  wr_ack__rd_res:  1;            /*!< Send ACK/NACK and Reserved                                            */
      __IO uint32_t  wr_txd__rd_res:  1;            /*!< Transmit data and Reserved                                            */
      __IO uint32_t  wr_rxd__rd_al:  1;             /*!< Receive data and Arbitration lost                                     */
      __IO uint32_t  wr_sto__rd_busy:  1;           /*!< Generate stop and I2C bus busy                                        */
      __IO uint32_t  wr_sta__rd_rxack:  1;          /*!< Generate start and Got ACK/NACK                                       */
    } command__status_b;                            /*!< BitSize                                                               */
  };
} sifive_i2c0_0_Type;


/* ================================================================================ */
/* ================                 sifive_uart0_1                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,uart0,control peripheral generator (sifive_uart0_1)
  */

typedef struct {                                    /*!< sifive_uart0_1 Structure                                              */
  
  union {
    __IO uint32_t  txdata;                          /*!< Transmit data register                                                */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< Transmit data                                                         */
           uint32_t             : 23;
      __I  uint32_t  full       :  1;               /*!< Transmit FIFO full                                                    */
    } txdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  rxdata;                          /*!< Receive data register                                                 */
    
    struct {
      __I  uint32_t  data       :  8;               /*!< Received data                                                         */
           uint32_t             : 23;
      __I  uint32_t  empty      :  1;               /*!< Receive FIFO empty                                                    */
    } rxdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  txctrl;                          /*!< Transmit control register                                             */
    
    struct {
      __IO uint32_t  txen       :  1;               /*!< Transmit enable                                                       */
      __IO uint32_t  nstop      :  1;               /*!< Number of stop bits                                                   */
           uint32_t             : 14;
      __IO uint32_t  txcnt      :  3;               /*!< Transmit watermark level                                              */
    } txctrl_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxctrl;                          /*!< Receive control register                                              */
    
    struct {
      __IO uint32_t  rxen       :  1;               /*!< Receive enable                                                        */
           uint32_t             : 15;
      __IO uint32_t  rxcnt      :  3;               /*!< Receive watermark level                                               */
    } rxctrl_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ie;                              /*!< UART interrupt enable                                                 */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< Transmit watermark interrupt enable                                   */
      __IO uint32_t  rxwm       :  1;               /*!< Receive watermark interrupt enable                                    */
    } ie_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ip;                              /*!< UART interrupt pending                                                */
    
    struct {
      __I  uint32_t  txwm       :  1;               /*!< Transmit watermark interrupt pending                                  */
      __I  uint32_t  rxwm       :  1;               /*!< Receive watermark interrupt pending                                   */
    } ip_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  div;                             /*!< Baud rate divisor                                                     */
    
    struct {
      __IO uint32_t  div        : 16;               /*!< Baud rate divisor.                                                    */
    } div_b;                                        /*!< BitSize                                                               */
  };
} sifive_uart0_1_Type;


/* ================================================================================ */
/* ================                  sifive_spi0_1                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,spi0,control peripheral generator (sifive_spi0_1)
  */

typedef struct {                                    /*!< sifive_spi0_1 Structure                                               */
  
  union {
    __IO uint32_t  sckdiv;                          /*!< Serial clock divisor                                                  */
    
    struct {
      __IO uint32_t  div        : 12;               /*!< Divisor for serial clock.                                             */
    } sckdiv_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sckmode;                         /*!< Serial clock mode                                                     */
    
    struct {
      __IO uint32_t  pha        :  1;               /*!< Serial clock phase                                                    */
      __IO uint32_t  pol        :  1;               /*!< Serial clock polarity                                                 */
    } sckmode_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[2];
  
  union {
    __IO uint32_t  csid;                            /*!< Chip select ID                                                        */
    
    struct {
      __IO uint32_t  csid       : 32;               /*!< Chip select ID.                                                       */
    } csid_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  csdef;                           /*!< Chip select default                                                   */
    
    struct {
      __IO uint32_t  csdef      : 32;               /*!< Chip select default value. Reset to all-1s.                           */
    } csdef_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  csmode;                          /*!< Chip select mode                                                      */
    
    struct {
      __IO uint32_t  mode       :  2;               /*!< Chip select mode                                                      */
    } csmode_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[3];
  
  union {
    __IO uint32_t  delay0;                          /*!< Delay control 0                                                       */
    
    struct {
      __IO uint32_t  cssck      :  8;               /*!< CS to SCK Delay                                                       */
           uint32_t             :  8;
      __IO uint32_t  sckcs      :  8;               /*!< SCK to CS Delay                                                       */
    } delay0_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  delay1;                          /*!< Delay control 1                                                       */
    
    struct {
      __IO uint32_t  intercs    :  8;               /*!< Minimum CS inactive time                                              */
           uint32_t             :  8;
      __IO uint32_t  interxfr   :  8;               /*!< Maximum interframe delay                                              */
    } delay1_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[2];
  
  union {
    __IO uint32_t  extradel;                        /*!< SPI extra sampling delay to increase the SPI frequency                */
    
    struct {
      __IO uint32_t  coarse     : 12;               /*!< Coarse grain sample delay (multiples of system clocks)                */
      __IO uint32_t  fine       :  5;               /*!< Fine grain sample delay (multiples of process-specific buffer
                                                         delay)                                                                */
    } extradel_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sampledel;                       /*!< Number of delay stages from slave to the SPI controller               */
    
    struct {
      __IO uint32_t  sd         :  5;               /*!< Number of delay stages from slave to SPI controller                   */
    } sampledel_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fmt;                             /*!< Frame format                                                          */
    
    struct {
      __IO uint32_t  proto      :  2;               /*!< SPI protocol                                                          */
      __IO uint32_t  endian     :  1;               /*!< SPI endianness                                                        */
      __IO uint32_t  dir        :  1;               /*!< SPI I/O direction. This is reset to 1 for flash-enabled SPI
                                                         controllers, 0 otherwise.                                             */
           uint32_t             : 12;
      __IO uint32_t  len        :  4;               /*!< Number of bits per frame                                              */
    } fmt_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  txdata;                          /*!< Tx FIFO Data                                                          */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< Transmit data                                                         */
           uint32_t             : 23;
      __I  uint32_t  full       :  1;               /*!< FIFO full flag                                                        */
    } txdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxdata;                          /*!< Rx FIFO data                                                          */
    
    struct {
      __I  uint32_t  data       :  8;               /*!< Received data                                                         */
           uint32_t             : 23;
      __IO uint32_t  empty      :  1;               /*!< FIFO empty flag                                                       */
    } rxdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  txmark;                          /*!< Tx FIFO watermark                                                     */
    
    struct {
      __IO uint32_t  txmark     :  3;               /*!< Transmit watermark. The reset value is 1 for flash-enabled controllers,
                                                         0 otherwise.                                                          */
    } txmark_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxmark;                          /*!< Rx FIFO watermark                                                     */
    
    struct {
      __IO uint32_t  rxmark     :  3;               /*!< Receive watermark                                                     */
    } rxmark_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4[2];
  
  union {
    __IO uint32_t  fctrl;                           /*!< SPI flash interface control                                           */
    
    struct {
      __IO uint32_t  en         :  1;               /*!< SPI Flash Mode Select                                                 */
    } fctrl_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ffmt;                            /*!< SPI flash instruction format                                          */
    
    struct {
      __IO uint32_t  cmd_en     :  1;               /*!< Enable sending of command                                             */
      __IO uint32_t  addr_len   :  3;               /*!< Number of address bytes (0 to 4)                                      */
      __IO uint32_t  pad_cnt    :  4;               /*!< Number of dummy cycles                                                */
      __IO uint32_t  cmd_proto  :  2;               /*!< Protocol for transmitting command                                     */
      __IO uint32_t  addr_proto :  2;               /*!< Protocol for transmitting address and padding                         */
      __IO uint32_t  data_proto :  2;               /*!< Protocol for receiving data bytes                                     */
           uint32_t             :  2;
      __IO uint32_t  cmd_code   :  8;               /*!< Value of command byte                                                 */
      __IO uint32_t  pad_code   :  8;               /*!< First 8 bits to transmit during dummy cycles                          */
    } ffmt_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED5[2];
  
  union {
    __IO uint32_t  ie;                              /*!< SPI interrupt enable                                                  */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< Transmit watermark enable                                             */
      __IO uint32_t  rxwm       :  1;               /*!< Receive watermark enable                                              */
    } ie_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ip;                              /*!< SPI interrupt pending                                                 */
    
    struct {
      __I  uint32_t  txwm       :  1;               /*!< Transmit watermark pending                                            */
      __I  uint32_t  rxwm       :  1;               /*!< Receive watermark pending                                             */
    } ip_b;                                         /*!< BitSize                                                               */
  };
} sifive_spi0_1_Type;


/* ================================================================================ */
/* ================                  sifive_pwm0_1                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,pwm0,control peripheral generator (sifive_pwm0_1)
  */

typedef struct {                                    /*!< sifive_pwm0_1 Structure                                               */
  
  union {
    __IO uint32_t  pwmcfg;                          /*!< PWM configuration register                                            */
    
    struct {
      __IO uint32_t  pwmscale   :  4;               /*!< PWM Counter scale                                                     */
           uint32_t             :  4;
      __IO uint32_t  pwmsticky  :  1;               /*!< PWM Sticky - disallow clearing pwmcmpXip bits                         */
      __IO uint32_t  pwmzerocmp :  1;               /*!< PWM Zero - counter resets to zero after match                         */
      __IO uint32_t  pwmdeglitch:  1;               /*!< PWM Deglitch - latch pwmcmpXip within same cycle                      */
           uint32_t             :  1;
      __IO uint32_t  pwmenalways:  1;               /*!< PWM enable always - run continuously                                  */
      __IO uint32_t  pwmenoneshot:  1;              /*!< PWM enable one shot - run one cycle                                   */
           uint32_t             :  2;
      __IO uint32_t  pwmcmp0center:  1;             /*!< PWM0 Compare Center                                                   */
      __IO uint32_t  pwmcmp1center:  1;             /*!< PWM1 Compare Center                                                   */
      __IO uint32_t  pwmcmp2center:  1;             /*!< PWM2 Compare Center                                                   */
      __IO uint32_t  pwmcmp3center:  1;             /*!< PWM3 Compare Center                                                   */
      __IO uint32_t  pwmcmp0invert:  1;             /*!< PWM0 Invert                                                           */
      __IO uint32_t  pwmcmp1invert:  1;             /*!< PWM1 Invert                                                           */
      __IO uint32_t  pwmcmp2invert:  1;             /*!< PWM2 Invert                                                           */
      __IO uint32_t  pwmcmp3invert:  1;             /*!< PWM3 Invert                                                           */
      __IO uint32_t  pwmcmp0gang:  1;               /*!< PWM0/PWM1 Compare Gang                                                */
      __IO uint32_t  pwmcmp1gang:  1;               /*!< PWM1/PWM2 Compare Gang                                                */
      __IO uint32_t  pwmcmp2gang:  1;               /*!< PWM2/PWM3 Compare Gang                                                */
      __IO uint32_t  pwmcmp3gang:  1;               /*!< PWM3/PWM0 Compare Gang                                                */
      __IO uint32_t  pwmcmp0ip  :  1;               /*!< PWM0 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp1ip  :  1;               /*!< PWM1 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp2ip  :  1;               /*!< PWM2 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp3ip  :  1;               /*!< PWM3 Interrupt Pending                                                */
    } pwmcfg_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  pwmcount;                        /*!< PWM count register                                                    */
    
    struct {
      __IO uint32_t  pwmcount   : 31;               /*!< PWM count register.                                                   */
    } pwmcount_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  pwms;                            /*!< Scaled PWM count register                                             */
    
    struct {
      __IO uint32_t  pwms       : 16;               /*!< Scaled PWM count register.                                            */
    } pwms_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[3];
  
  union {
    __IO uint32_t  pwmcmp0;                         /*!< PWM 0 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp0    : 16;               /*!< PWM 0 Compare Value                                                   */
    } pwmcmp0_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp1;                         /*!< PWM 1 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp1    : 16;               /*!< PWM 1 Compare Value                                                   */
    } pwmcmp1_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp2;                         /*!< PWM 2 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp2    : 16;               /*!< PWM 2 Compare Value                                                   */
    } pwmcmp2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp3;                         /*!< PWM 3 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp3    : 16;               /*!< PWM 3 Compare Value                                                   */
    } pwmcmp3_b;                                    /*!< BitSize                                                               */
  };
} sifive_pwm0_1_Type;


/* ================================================================================ */
/* ================                  sifive_spi0_2                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,spi0,control peripheral generator (sifive_spi0_2)
  */

typedef struct {                                    /*!< sifive_spi0_2 Structure                                               */
  
  union {
    __IO uint32_t  sckdiv;                          /*!< Serial clock divisor                                                  */
    
    struct {
      __IO uint32_t  div        : 12;               /*!< Divisor for serial clock.                                             */
    } sckdiv_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sckmode;                         /*!< Serial clock mode                                                     */
    
    struct {
      __IO uint32_t  pha        :  1;               /*!< Serial clock phase                                                    */
      __IO uint32_t  pol        :  1;               /*!< Serial clock polarity                                                 */
    } sckmode_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED[2];
  
  union {
    __IO uint32_t  csid;                            /*!< Chip select ID                                                        */
    
    struct {
      __IO uint32_t  csid       : 32;               /*!< Chip select ID.                                                       */
    } csid_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  csdef;                           /*!< Chip select default                                                   */
    
    struct {
      __IO uint32_t  csdef      : 32;               /*!< Chip select default value. Reset to all-1s.                           */
    } csdef_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  csmode;                          /*!< Chip select mode                                                      */
    
    struct {
      __IO uint32_t  mode       :  2;               /*!< Chip select mode                                                      */
    } csmode_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[3];
  
  union {
    __IO uint32_t  delay0;                          /*!< Delay control 0                                                       */
    
    struct {
      __IO uint32_t  cssck      :  8;               /*!< CS to SCK Delay                                                       */
           uint32_t             :  8;
      __IO uint32_t  sckcs      :  8;               /*!< SCK to CS Delay                                                       */
    } delay0_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  delay1;                          /*!< Delay control 1                                                       */
    
    struct {
      __IO uint32_t  intercs    :  8;               /*!< Minimum CS inactive time                                              */
           uint32_t             :  8;
      __IO uint32_t  interxfr   :  8;               /*!< Maximum interframe delay                                              */
    } delay1_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[2];
  
  union {
    __IO uint32_t  extradel;                        /*!< SPI extra sampling delay to increase the SPI frequency                */
    
    struct {
      __IO uint32_t  coarse     : 12;               /*!< Coarse grain sample delay (multiples of system clocks)                */
      __IO uint32_t  fine       :  5;               /*!< Fine grain sample delay (multiples of process-specific buffer
                                                         delay)                                                                */
    } extradel_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sampledel;                       /*!< Number of delay stages from slave to the SPI controller               */
    
    struct {
      __IO uint32_t  sd         :  5;               /*!< Number of delay stages from slave to SPI controller                   */
    } sampledel_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fmt;                             /*!< Frame format                                                          */
    
    struct {
      __IO uint32_t  proto      :  2;               /*!< SPI protocol                                                          */
      __IO uint32_t  endian     :  1;               /*!< SPI endianness                                                        */
      __IO uint32_t  dir        :  1;               /*!< SPI I/O direction. This is reset to 1 for flash-enabled SPI
                                                         controllers, 0 otherwise.                                             */
           uint32_t             : 12;
      __IO uint32_t  len        :  4;               /*!< Number of bits per frame                                              */
    } fmt_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  txdata;                          /*!< Tx FIFO Data                                                          */
    
    struct {
      __IO uint32_t  data       :  8;               /*!< Transmit data                                                         */
           uint32_t             : 23;
      __I  uint32_t  full       :  1;               /*!< FIFO full flag                                                        */
    } txdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxdata;                          /*!< Rx FIFO data                                                          */
    
    struct {
      __I  uint32_t  data       :  8;               /*!< Received data                                                         */
           uint32_t             : 23;
      __IO uint32_t  empty      :  1;               /*!< FIFO empty flag                                                       */
    } rxdata_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  txmark;                          /*!< Tx FIFO watermark                                                     */
    
    struct {
      __IO uint32_t  txmark     :  3;               /*!< Transmit watermark. The reset value is 1 for flash-enabled controllers,
                                                         0 otherwise.                                                          */
    } txmark_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxmark;                          /*!< Rx FIFO watermark                                                     */
    
    struct {
      __IO uint32_t  rxmark     :  3;               /*!< Receive watermark                                                     */
    } rxmark_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4[2];
  
  union {
    __IO uint32_t  fctrl;                           /*!< SPI flash interface control                                           */
    
    struct {
      __IO uint32_t  en         :  1;               /*!< SPI Flash Mode Select                                                 */
    } fctrl_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ffmt;                            /*!< SPI flash instruction format                                          */
    
    struct {
      __IO uint32_t  cmd_en     :  1;               /*!< Enable sending of command                                             */
      __IO uint32_t  addr_len   :  3;               /*!< Number of address bytes (0 to 4)                                      */
      __IO uint32_t  pad_cnt    :  4;               /*!< Number of dummy cycles                                                */
      __IO uint32_t  cmd_proto  :  2;               /*!< Protocol for transmitting command                                     */
      __IO uint32_t  addr_proto :  2;               /*!< Protocol for transmitting address and padding                         */
      __IO uint32_t  data_proto :  2;               /*!< Protocol for receiving data bytes                                     */
           uint32_t             :  2;
      __IO uint32_t  cmd_code   :  8;               /*!< Value of command byte                                                 */
      __IO uint32_t  pad_code   :  8;               /*!< First 8 bits to transmit during dummy cycles                          */
    } ffmt_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED5[2];
  
  union {
    __IO uint32_t  ie;                              /*!< SPI interrupt enable                                                  */
    
    struct {
      __IO uint32_t  txwm       :  1;               /*!< Transmit watermark enable                                             */
      __IO uint32_t  rxwm       :  1;               /*!< Receive watermark enable                                              */
    } ie_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ip;                              /*!< SPI interrupt pending                                                 */
    
    struct {
      __I  uint32_t  txwm       :  1;               /*!< Transmit watermark pending                                            */
      __I  uint32_t  rxwm       :  1;               /*!< Receive watermark pending                                             */
    } ip_b;                                         /*!< BitSize                                                               */
  };
} sifive_spi0_2_Type;


/* ================================================================================ */
/* ================                  sifive_pwm0_2                 ================ */
/* ================================================================================ */


/**
  * @brief From sifive,pwm0,control peripheral generator (sifive_pwm0_2)
  */

typedef struct {                                    /*!< sifive_pwm0_2 Structure                                               */
  
  union {
    __IO uint32_t  pwmcfg;                          /*!< PWM configuration register                                            */
    
    struct {
      __IO uint32_t  pwmscale   :  4;               /*!< PWM Counter scale                                                     */
           uint32_t             :  4;
      __IO uint32_t  pwmsticky  :  1;               /*!< PWM Sticky - disallow clearing pwmcmpXip bits                         */
      __IO uint32_t  pwmzerocmp :  1;               /*!< PWM Zero - counter resets to zero after match                         */
      __IO uint32_t  pwmdeglitch:  1;               /*!< PWM Deglitch - latch pwmcmpXip within same cycle                      */
           uint32_t             :  1;
      __IO uint32_t  pwmenalways:  1;               /*!< PWM enable always - run continuously                                  */
      __IO uint32_t  pwmenoneshot:  1;              /*!< PWM enable one shot - run one cycle                                   */
           uint32_t             :  2;
      __IO uint32_t  pwmcmp0center:  1;             /*!< PWM0 Compare Center                                                   */
      __IO uint32_t  pwmcmp1center:  1;             /*!< PWM1 Compare Center                                                   */
      __IO uint32_t  pwmcmp2center:  1;             /*!< PWM2 Compare Center                                                   */
      __IO uint32_t  pwmcmp3center:  1;             /*!< PWM3 Compare Center                                                   */
      __IO uint32_t  pwmcmp0invert:  1;             /*!< PWM0 Invert                                                           */
      __IO uint32_t  pwmcmp1invert:  1;             /*!< PWM1 Invert                                                           */
      __IO uint32_t  pwmcmp2invert:  1;             /*!< PWM2 Invert                                                           */
      __IO uint32_t  pwmcmp3invert:  1;             /*!< PWM3 Invert                                                           */
      __IO uint32_t  pwmcmp0gang:  1;               /*!< PWM0/PWM1 Compare Gang                                                */
      __IO uint32_t  pwmcmp1gang:  1;               /*!< PWM1/PWM2 Compare Gang                                                */
      __IO uint32_t  pwmcmp2gang:  1;               /*!< PWM2/PWM3 Compare Gang                                                */
      __IO uint32_t  pwmcmp3gang:  1;               /*!< PWM3/PWM0 Compare Gang                                                */
      __IO uint32_t  pwmcmp0ip  :  1;               /*!< PWM0 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp1ip  :  1;               /*!< PWM1 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp2ip  :  1;               /*!< PWM2 Interrupt Pending                                                */
      __IO uint32_t  pwmcmp3ip  :  1;               /*!< PWM3 Interrupt Pending                                                */
    } pwmcfg_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  pwmcount;                        /*!< PWM count register                                                    */
    
    struct {
      __IO uint32_t  pwmcount   : 31;               /*!< PWM count register.                                                   */
    } pwmcount_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  pwms;                            /*!< Scaled PWM count register                                             */
    
    struct {
      __IO uint32_t  pwms       : 16;               /*!< Scaled PWM count register.                                            */
    } pwms_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[3];
  
  union {
    __IO uint32_t  pwmcmp0;                         /*!< PWM 0 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp0    : 16;               /*!< PWM 0 Compare Value                                                   */
    } pwmcmp0_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp1;                         /*!< PWM 1 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp1    : 16;               /*!< PWM 1 Compare Value                                                   */
    } pwmcmp1_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp2;                         /*!< PWM 2 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp2    : 16;               /*!< PWM 2 Compare Value                                                   */
    } pwmcmp2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pwmcmp3;                         /*!< PWM 3 compare register                                                */
    
    struct {
      __IO uint32_t  pwmcmp3    : 16;               /*!< PWM 3 Compare Value                                                   */
    } pwmcmp3_b;                                    /*!< BitSize                                                               */
  };
} sifive_pwm0_2_Type;


/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif



/* ================================================================================ */
/* ================     struct 'sifive_aon0_0' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_aon0_0_wdogcfg  --------------------------- */
#define sifive_aon0_0_wdogcfg_wdogscale_Pos   (0UL)                     /*!< sifive_aon0_0 wdogcfg: wdogscale (Bit 0)                    */
#define sifive_aon0_0_wdogcfg_wdogscale_Msk   (0xfUL)                   /*!< sifive_aon0_0 wdogcfg: wdogscale (Bitfield-Mask: 0x0f)      */
#define sifive_aon0_0_wdogcfg_wdogrsten_Pos   (8UL)                     /*!< sifive_aon0_0 wdogcfg: wdogrsten (Bit 8)                    */
#define sifive_aon0_0_wdogcfg_wdogrsten_Msk   (0x100UL)                 /*!< sifive_aon0_0 wdogcfg: wdogrsten (Bitfield-Mask: 0x01)      */
#define sifive_aon0_0_wdogcfg_wdogzerocmp_Pos (9UL)                     /*!< sifive_aon0_0 wdogcfg: wdogzerocmp (Bit 9)                  */
#define sifive_aon0_0_wdogcfg_wdogzerocmp_Msk (0x200UL)                 /*!< sifive_aon0_0 wdogcfg: wdogzerocmp (Bitfield-Mask: 0x01)    */
#define sifive_aon0_0_wdogcfg_wdogenalways_Pos (12UL)                   /*!< sifive_aon0_0 wdogcfg: wdogenalways (Bit 12)                */
#define sifive_aon0_0_wdogcfg_wdogenalways_Msk (0x1000UL)               /*!< sifive_aon0_0 wdogcfg: wdogenalways (Bitfield-Mask: 0x01)   */
#define sifive_aon0_0_wdogcfg_wdogcoreawake_Pos (13UL)                  /*!< sifive_aon0_0 wdogcfg: wdogcoreawake (Bit 13)               */
#define sifive_aon0_0_wdogcfg_wdogcoreawake_Msk (0x2000UL)              /*!< sifive_aon0_0 wdogcfg: wdogcoreawake (Bitfield-Mask: 0x01)  */
#define sifive_aon0_0_wdogcfg_wdogip0_Pos     (28UL)                    /*!< sifive_aon0_0 wdogcfg: wdogip0 (Bit 28)                     */
#define sifive_aon0_0_wdogcfg_wdogip0_Msk     (0x10000000UL)            /*!< sifive_aon0_0 wdogcfg: wdogip0 (Bitfield-Mask: 0x01)        */

/* ----------------------------  sifive_aon0_0_rtccfg  ---------------------------- */
#define sifive_aon0_0_rtccfg_rtcscale_Pos     (0UL)                     /*!< sifive_aon0_0 rtccfg: rtcscale (Bit 0)                      */
#define sifive_aon0_0_rtccfg_rtcscale_Msk     (0xfUL)                   /*!< sifive_aon0_0 rtccfg: rtcscale (Bitfield-Mask: 0x0f)        */
#define sifive_aon0_0_rtccfg_rtcenalways_Pos  (12UL)                    /*!< sifive_aon0_0 rtccfg: rtcenalways (Bit 12)                  */
#define sifive_aon0_0_rtccfg_rtcenalways_Msk  (0x1000UL)                /*!< sifive_aon0_0 rtccfg: rtcenalways (Bitfield-Mask: 0x01)     */
#define sifive_aon0_0_rtccfg_rtcip0_Pos       (28UL)                    /*!< sifive_aon0_0 rtccfg: rtcip0 (Bit 28)                       */
#define sifive_aon0_0_rtccfg_rtcip0_Msk       (0x10000000UL)            /*!< sifive_aon0_0 rtccfg: rtcip0 (Bitfield-Mask: 0x01)          */

/* ---------------------------  sifive_aon0_0_lfrosccfg  -------------------------- */
#define sifive_aon0_0_lfrosccfg_lfroscdiv_Pos (0UL)                     /*!< sifive_aon0_0 lfrosccfg: lfroscdiv (Bit 0)                  */
#define sifive_aon0_0_lfrosccfg_lfroscdiv_Msk (0x3fUL)                  /*!< sifive_aon0_0 lfrosccfg: lfroscdiv (Bitfield-Mask: 0x3f)    */
#define sifive_aon0_0_lfrosccfg_lfrosctrim_Pos (16UL)                   /*!< sifive_aon0_0 lfrosccfg: lfrosctrim (Bit 16)                */
#define sifive_aon0_0_lfrosccfg_lfrosctrim_Msk (0x1f0000UL)             /*!< sifive_aon0_0 lfrosccfg: lfrosctrim (Bitfield-Mask: 0x1f)   */
#define sifive_aon0_0_lfrosccfg_lfroscen_Pos  (30UL)                    /*!< sifive_aon0_0 lfrosccfg: lfroscen (Bit 30)                  */
#define sifive_aon0_0_lfrosccfg_lfroscen_Msk  (0x40000000UL)            /*!< sifive_aon0_0 lfrosccfg: lfroscen (Bitfield-Mask: 0x01)     */
#define sifive_aon0_0_lfrosccfg_lfroscrdy_Pos (31UL)                    /*!< sifive_aon0_0 lfrosccfg: lfroscrdy (Bit 31)                 */
#define sifive_aon0_0_lfrosccfg_lfroscrdy_Msk (0x80000000UL)            /*!< sifive_aon0_0 lfrosccfg: lfroscrdy (Bitfield-Mask: 0x01)    */

/* ---------------------------  sifive_aon0_0_lfclkmux  --------------------------- */
#define sifive_aon0_0_lfclkmux_lfextclk_sel_Pos (0UL)                   /*!< sifive_aon0_0 lfclkmux: lfextclk_sel (Bit 0)                */
#define sifive_aon0_0_lfclkmux_lfextclk_sel_Msk (0x1UL)                 /*!< sifive_aon0_0 lfclkmux: lfextclk_sel (Bitfield-Mask: 0x01)  */
#define sifive_aon0_0_lfclkmux_lfextclk_mux_status_Pos (31UL)           /*!< sifive_aon0_0 lfclkmux: lfextclk_mux_status (Bit 31)        */
#define sifive_aon0_0_lfclkmux_lfextclk_mux_status_Msk (0x80000000UL)   /*!< sifive_aon0_0 lfclkmux: lfextclk_mux_status (Bitfield-Mask: 0x01) */

/* ----------------------------  sifive_aon0_0_aoncfg  ---------------------------- */
#define sifive_aon0_0_aoncfg_has_bandgap_Pos  (0UL)                     /*!< sifive_aon0_0 aoncfg: has_bandgap (Bit 0)                   */
#define sifive_aon0_0_aoncfg_has_bandgap_Msk  (0x1UL)                   /*!< sifive_aon0_0 aoncfg: has_bandgap (Bitfield-Mask: 0x01)     */
#define sifive_aon0_0_aoncfg_has_bod_Pos      (1UL)                     /*!< sifive_aon0_0 aoncfg: has_bod (Bit 1)                       */
#define sifive_aon0_0_aoncfg_has_bod_Msk      (0x2UL)                   /*!< sifive_aon0_0 aoncfg: has_bod (Bitfield-Mask: 0x01)         */
#define sifive_aon0_0_aoncfg_has_lfrosc_Pos   (2UL)                     /*!< sifive_aon0_0 aoncfg: has_lfrosc (Bit 2)                    */
#define sifive_aon0_0_aoncfg_has_lfrosc_Msk   (0x4UL)                   /*!< sifive_aon0_0 aoncfg: has_lfrosc (Bitfield-Mask: 0x01)      */
#define sifive_aon0_0_aoncfg_has_lfrcosc_Pos  (3UL)                     /*!< sifive_aon0_0 aoncfg: has_lfrcosc (Bit 3)                   */
#define sifive_aon0_0_aoncfg_has_lfrcosc_Msk  (0x8UL)                   /*!< sifive_aon0_0 aoncfg: has_lfrcosc (Bitfield-Mask: 0x01)     */
#define sifive_aon0_0_aoncfg_has_lfxosc_Pos   (4UL)                     /*!< sifive_aon0_0 aoncfg: has_lfxosc (Bit 4)                    */
#define sifive_aon0_0_aoncfg_has_lfxosc_Msk   (0x10UL)                  /*!< sifive_aon0_0 aoncfg: has_lfxosc (Bitfield-Mask: 0x01)      */
#define sifive_aon0_0_aoncfg_has_por_Pos      (5UL)                     /*!< sifive_aon0_0 aoncfg: has_por (Bit 5)                       */
#define sifive_aon0_0_aoncfg_has_por_Msk      (0x20UL)                  /*!< sifive_aon0_0 aoncfg: has_por (Bitfield-Mask: 0x01)         */
#define sifive_aon0_0_aoncfg_has_ldo_Pos      (6UL)                     /*!< sifive_aon0_0 aoncfg: has_ldo (Bit 6)                       */
#define sifive_aon0_0_aoncfg_has_ldo_Msk      (0x40UL)                  /*!< sifive_aon0_0 aoncfg: has_ldo (Bitfield-Mask: 0x01)         */


/* ================================================================================ */
/* ================struct 'sifive_fe310_g000_prci_0' Position & Mask================ */
/* ================================================================================ */


/* ---------------------  sifive_fe310_g000_prci_0_hfrosccfg  --------------------- */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfroscdiv_Pos (0UL)          /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfroscdiv (Bit 0)       */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfroscdiv_Msk (0x3fUL)       /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfroscdiv (Bitfield-Mask: 0x3f) */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfrosctrim_Pos (16UL)        /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfrosctrim (Bit 16)     */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfrosctrim_Msk (0x1f0000UL)  /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfrosctrim (Bitfield-Mask: 0x1f) */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfroscen_Pos (30UL)          /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfroscen (Bit 30)       */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfroscen_Msk (0x40000000UL)  /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfroscen (Bitfield-Mask: 0x01) */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfroscrdy_Pos (31UL)         /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfroscrdy (Bit 31)      */
#define sifive_fe310_g000_prci_0_hfrosccfg_hfroscrdy_Msk (0x80000000UL) /*!< sifive_fe310_g000_prci_0 hfrosccfg: hfroscrdy (Bitfield-Mask: 0x01) */

/* ---------------------  sifive_fe310_g000_prci_0_hfxosccfg  --------------------- */
#define sifive_fe310_g000_prci_0_hfxosccfg_hfxoscen_Pos (30UL)          /*!< sifive_fe310_g000_prci_0 hfxosccfg: hfxoscen (Bit 30)       */
#define sifive_fe310_g000_prci_0_hfxosccfg_hfxoscen_Msk (0x40000000UL)  /*!< sifive_fe310_g000_prci_0 hfxosccfg: hfxoscen (Bitfield-Mask: 0x01) */
#define sifive_fe310_g000_prci_0_hfxosccfg_hfxoscrdy_Pos (31UL)         /*!< sifive_fe310_g000_prci_0 hfxosccfg: hfxoscrdy (Bit 31)      */
#define sifive_fe310_g000_prci_0_hfxosccfg_hfxoscrdy_Msk (0x80000000UL) /*!< sifive_fe310_g000_prci_0 hfxosccfg: hfxoscrdy (Bitfield-Mask: 0x01) */

/* -----------------------  sifive_fe310_g000_prci_0_pllcfg  ---------------------- */
#define sifive_fe310_g000_prci_0_pllcfg_pllr_Pos (0UL)                  /*!< sifive_fe310_g000_prci_0 pllcfg: pllr (Bit 0)               */
#define sifive_fe310_g000_prci_0_pllcfg_pllr_Msk (0x7UL)                /*!< sifive_fe310_g000_prci_0 pllcfg: pllr (Bitfield-Mask: 0x07) */
#define sifive_fe310_g000_prci_0_pllcfg_pllf_Pos (4UL)                  /*!< sifive_fe310_g000_prci_0 pllcfg: pllf (Bit 4)               */
#define sifive_fe310_g000_prci_0_pllcfg_pllf_Msk (0x3f0UL)              /*!< sifive_fe310_g000_prci_0 pllcfg: pllf (Bitfield-Mask: 0x3f) */
#define sifive_fe310_g000_prci_0_pllcfg_pllq_Pos (10UL)                 /*!< sifive_fe310_g000_prci_0 pllcfg: pllq (Bit 10)              */
#define sifive_fe310_g000_prci_0_pllcfg_pllq_Msk (0xc00UL)              /*!< sifive_fe310_g000_prci_0 pllcfg: pllq (Bitfield-Mask: 0x03) */
#define sifive_fe310_g000_prci_0_pllcfg_pllsel_Pos (16UL)               /*!< sifive_fe310_g000_prci_0 pllcfg: pllsel (Bit 16)            */
#define sifive_fe310_g000_prci_0_pllcfg_pllsel_Msk (0x10000UL)          /*!< sifive_fe310_g000_prci_0 pllcfg: pllsel (Bitfield-Mask: 0x01) */
#define sifive_fe310_g000_prci_0_pllcfg_pllrefsel_Pos (17UL)            /*!< sifive_fe310_g000_prci_0 pllcfg: pllrefsel (Bit 17)         */
#define sifive_fe310_g000_prci_0_pllcfg_pllrefsel_Msk (0x20000UL)       /*!< sifive_fe310_g000_prci_0 pllcfg: pllrefsel (Bitfield-Mask: 0x01) */
#define sifive_fe310_g000_prci_0_pllcfg_pllbypass_Pos (18UL)            /*!< sifive_fe310_g000_prci_0 pllcfg: pllbypass (Bit 18)         */
#define sifive_fe310_g000_prci_0_pllcfg_pllbypass_Msk (0x40000UL)       /*!< sifive_fe310_g000_prci_0 pllcfg: pllbypass (Bitfield-Mask: 0x01) */
#define sifive_fe310_g000_prci_0_pllcfg_plllock_Pos (31UL)              /*!< sifive_fe310_g000_prci_0 pllcfg: plllock (Bit 31)           */
#define sifive_fe310_g000_prci_0_pllcfg_plllock_Msk (0x80000000UL)      /*!< sifive_fe310_g000_prci_0 pllcfg: plllock (Bitfield-Mask: 0x01) */

/* ---------------------  sifive_fe310_g000_prci_0_plloutdiv  --------------------- */
#define sifive_fe310_g000_prci_0_plloutdiv_plloutdiv_Pos (0UL)          /*!< sifive_fe310_g000_prci_0 plloutdiv: plloutdiv (Bit 0)       */
#define sifive_fe310_g000_prci_0_plloutdiv_plloutdiv_Msk (0x3fUL)       /*!< sifive_fe310_g000_prci_0 plloutdiv: plloutdiv (Bitfield-Mask: 0x3f) */
#define sifive_fe310_g000_prci_0_plloutdiv_plloutdivby1_Pos (8UL)       /*!< sifive_fe310_g000_prci_0 plloutdiv: plloutdivby1 (Bit 8)    */
#define sifive_fe310_g000_prci_0_plloutdiv_plloutdivby1_Msk (0x3f00UL)  /*!< sifive_fe310_g000_prci_0 plloutdiv: plloutdivby1 (Bitfield-Mask: 0x3f) */

/* ---------------------  sifive_fe310_g000_prci_0_procmoncfg  -------------------- */
#define sifive_fe310_g000_prci_0_procmoncfg_procmon_div_sel_Pos (0UL)   /*!< sifive_fe310_g000_prci_0 procmoncfg: procmon_div_sel (Bit 0) */
#define sifive_fe310_g000_prci_0_procmoncfg_procmon_div_sel_Msk (0x1fUL) /*!< sifive_fe310_g000_prci_0 procmoncfg: procmon_div_sel (Bitfield-Mask: 0x1f) */
#define sifive_fe310_g000_prci_0_procmoncfg_procmon_delay_sel_Pos (8UL) /*!< sifive_fe310_g000_prci_0 procmoncfg: procmon_delay_sel (Bit 8) */
#define sifive_fe310_g000_prci_0_procmoncfg_procmon_delay_sel_Msk (0x1f00UL) /*!< sifive_fe310_g000_prci_0 procmoncfg: procmon_delay_sel (Bitfield-Mask: 0x1f) */
#define sifive_fe310_g000_prci_0_procmoncfg_procmon_en_Pos (16UL)       /*!< sifive_fe310_g000_prci_0 procmoncfg: procmon_en (Bit 16)    */
#define sifive_fe310_g000_prci_0_procmoncfg_procmon_en_Msk (0x10000UL)  /*!< sifive_fe310_g000_prci_0 procmoncfg: procmon_en (Bitfield-Mask: 0x01) */
#define sifive_fe310_g000_prci_0_procmoncfg_procomon_sel_Pos (24UL)     /*!< sifive_fe310_g000_prci_0 procmoncfg: procomon_sel (Bit 24)  */
#define sifive_fe310_g000_prci_0_procmoncfg_procomon_sel_Msk (0x3000000UL) /*!< sifive_fe310_g000_prci_0 procmoncfg: procomon_sel (Bitfield-Mask: 0x03) */


/* ================================================================================ */
/* ================     struct 'sifive_uart0_0' Position & Mask    ================ */
/* ================================================================================ */


/* ----------------------------  sifive_uart0_0_txdata  --------------------------- */
#define sifive_uart0_0_txdata_data_Pos        (0UL)                     /*!< sifive_uart0_0 txdata: data (Bit 0)                         */
#define sifive_uart0_0_txdata_data_Msk        (0xffUL)                  /*!< sifive_uart0_0 txdata: data (Bitfield-Mask: 0xff)           */
#define sifive_uart0_0_txdata_full_Pos        (31UL)                    /*!< sifive_uart0_0 txdata: full (Bit 31)                        */
#define sifive_uart0_0_txdata_full_Msk        (0x80000000UL)            /*!< sifive_uart0_0 txdata: full (Bitfield-Mask: 0x01)           */

/* ----------------------------  sifive_uart0_0_rxdata  --------------------------- */
#define sifive_uart0_0_rxdata_data_Pos        (0UL)                     /*!< sifive_uart0_0 rxdata: data (Bit 0)                         */
#define sifive_uart0_0_rxdata_data_Msk        (0xffUL)                  /*!< sifive_uart0_0 rxdata: data (Bitfield-Mask: 0xff)           */
#define sifive_uart0_0_rxdata_empty_Pos       (31UL)                    /*!< sifive_uart0_0 rxdata: empty (Bit 31)                       */
#define sifive_uart0_0_rxdata_empty_Msk       (0x80000000UL)            /*!< sifive_uart0_0 rxdata: empty (Bitfield-Mask: 0x01)          */

/* ----------------------------  sifive_uart0_0_txctrl  --------------------------- */
#define sifive_uart0_0_txctrl_txen_Pos        (0UL)                     /*!< sifive_uart0_0 txctrl: txen (Bit 0)                         */
#define sifive_uart0_0_txctrl_txen_Msk        (0x1UL)                   /*!< sifive_uart0_0 txctrl: txen (Bitfield-Mask: 0x01)           */
#define sifive_uart0_0_txctrl_nstop_Pos       (1UL)                     /*!< sifive_uart0_0 txctrl: nstop (Bit 1)                        */
#define sifive_uart0_0_txctrl_nstop_Msk       (0x2UL)                   /*!< sifive_uart0_0 txctrl: nstop (Bitfield-Mask: 0x01)          */
#define sifive_uart0_0_txctrl_txcnt_Pos       (16UL)                    /*!< sifive_uart0_0 txctrl: txcnt (Bit 16)                       */
#define sifive_uart0_0_txctrl_txcnt_Msk       (0x70000UL)               /*!< sifive_uart0_0 txctrl: txcnt (Bitfield-Mask: 0x07)          */

/* ----------------------------  sifive_uart0_0_rxctrl  --------------------------- */
#define sifive_uart0_0_rxctrl_rxen_Pos        (0UL)                     /*!< sifive_uart0_0 rxctrl: rxen (Bit 0)                         */
#define sifive_uart0_0_rxctrl_rxen_Msk        (0x1UL)                   /*!< sifive_uart0_0 rxctrl: rxen (Bitfield-Mask: 0x01)           */
#define sifive_uart0_0_rxctrl_rxcnt_Pos       (16UL)                    /*!< sifive_uart0_0 rxctrl: rxcnt (Bit 16)                       */
#define sifive_uart0_0_rxctrl_rxcnt_Msk       (0x70000UL)               /*!< sifive_uart0_0 rxctrl: rxcnt (Bitfield-Mask: 0x07)          */

/* ------------------------------  sifive_uart0_0_ie  ----------------------------- */
#define sifive_uart0_0_ie_txwm_Pos            (0UL)                     /*!< sifive_uart0_0 ie: txwm (Bit 0)                             */
#define sifive_uart0_0_ie_txwm_Msk            (0x1UL)                   /*!< sifive_uart0_0 ie: txwm (Bitfield-Mask: 0x01)               */
#define sifive_uart0_0_ie_rxwm_Pos            (1UL)                     /*!< sifive_uart0_0 ie: rxwm (Bit 1)                             */
#define sifive_uart0_0_ie_rxwm_Msk            (0x2UL)                   /*!< sifive_uart0_0 ie: rxwm (Bitfield-Mask: 0x01)               */

/* ------------------------------  sifive_uart0_0_ip  ----------------------------- */
#define sifive_uart0_0_ip_txwm_Pos            (0UL)                     /*!< sifive_uart0_0 ip: txwm (Bit 0)                             */
#define sifive_uart0_0_ip_txwm_Msk            (0x1UL)                   /*!< sifive_uart0_0 ip: txwm (Bitfield-Mask: 0x01)               */
#define sifive_uart0_0_ip_rxwm_Pos            (1UL)                     /*!< sifive_uart0_0 ip: rxwm (Bit 1)                             */
#define sifive_uart0_0_ip_rxwm_Msk            (0x2UL)                   /*!< sifive_uart0_0 ip: rxwm (Bitfield-Mask: 0x01)               */

/* -----------------------------  sifive_uart0_0_div  ----------------------------- */
#define sifive_uart0_0_div_div_Pos            (0UL)                     /*!< sifive_uart0_0 div: div (Bit 0)                             */
#define sifive_uart0_0_div_div_Msk            (0xffffUL)                /*!< sifive_uart0_0 div: div (Bitfield-Mask: 0xffff)             */


/* ================================================================================ */
/* ================     struct 'sifive_spi0_0' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_spi0_0_sckdiv  ---------------------------- */
#define sifive_spi0_0_sckdiv_div_Pos          (0UL)                     /*!< sifive_spi0_0 sckdiv: div (Bit 0)                           */
#define sifive_spi0_0_sckdiv_div_Msk          (0xfffUL)                 /*!< sifive_spi0_0 sckdiv: div (Bitfield-Mask: 0xfff)            */

/* ----------------------------  sifive_spi0_0_sckmode  --------------------------- */
#define sifive_spi0_0_sckmode_pha_Pos         (0UL)                     /*!< sifive_spi0_0 sckmode: pha (Bit 0)                          */
#define sifive_spi0_0_sckmode_pha_Msk         (0x1UL)                   /*!< sifive_spi0_0 sckmode: pha (Bitfield-Mask: 0x01)            */
#define sifive_spi0_0_sckmode_pol_Pos         (1UL)                     /*!< sifive_spi0_0 sckmode: pol (Bit 1)                          */
#define sifive_spi0_0_sckmode_pol_Msk         (0x2UL)                   /*!< sifive_spi0_0 sckmode: pol (Bitfield-Mask: 0x01)            */

/* -----------------------------  sifive_spi0_0_csid  ----------------------------- */
#define sifive_spi0_0_csid_csid_Pos           (0UL)                     /*!< sifive_spi0_0 csid: csid (Bit 0)                            */
#define sifive_spi0_0_csid_csid_Msk           (0xffffffffUL)            /*!< sifive_spi0_0 csid: csid (Bitfield-Mask: 0xffffffff)        */

/* -----------------------------  sifive_spi0_0_csdef  ---------------------------- */
#define sifive_spi0_0_csdef_csdef_Pos         (0UL)                     /*!< sifive_spi0_0 csdef: csdef (Bit 0)                          */
#define sifive_spi0_0_csdef_csdef_Msk         (0xffffffffUL)            /*!< sifive_spi0_0 csdef: csdef (Bitfield-Mask: 0xffffffff)      */

/* ----------------------------  sifive_spi0_0_csmode  ---------------------------- */
#define sifive_spi0_0_csmode_mode_Pos         (0UL)                     /*!< sifive_spi0_0 csmode: mode (Bit 0)                          */
#define sifive_spi0_0_csmode_mode_Msk         (0x3UL)                   /*!< sifive_spi0_0 csmode: mode (Bitfield-Mask: 0x03)            */

/* ----------------------------  sifive_spi0_0_delay0  ---------------------------- */
#define sifive_spi0_0_delay0_cssck_Pos        (0UL)                     /*!< sifive_spi0_0 delay0: cssck (Bit 0)                         */
#define sifive_spi0_0_delay0_cssck_Msk        (0xffUL)                  /*!< sifive_spi0_0 delay0: cssck (Bitfield-Mask: 0xff)           */
#define sifive_spi0_0_delay0_sckcs_Pos        (16UL)                    /*!< sifive_spi0_0 delay0: sckcs (Bit 16)                        */
#define sifive_spi0_0_delay0_sckcs_Msk        (0xff0000UL)              /*!< sifive_spi0_0 delay0: sckcs (Bitfield-Mask: 0xff)           */

/* ----------------------------  sifive_spi0_0_delay1  ---------------------------- */
#define sifive_spi0_0_delay1_intercs_Pos      (0UL)                     /*!< sifive_spi0_0 delay1: intercs (Bit 0)                       */
#define sifive_spi0_0_delay1_intercs_Msk      (0xffUL)                  /*!< sifive_spi0_0 delay1: intercs (Bitfield-Mask: 0xff)         */
#define sifive_spi0_0_delay1_interxfr_Pos     (16UL)                    /*!< sifive_spi0_0 delay1: interxfr (Bit 16)                     */
#define sifive_spi0_0_delay1_interxfr_Msk     (0xff0000UL)              /*!< sifive_spi0_0 delay1: interxfr (Bitfield-Mask: 0xff)        */

/* ---------------------------  sifive_spi0_0_extradel  --------------------------- */
#define sifive_spi0_0_extradel_coarse_Pos     (0UL)                     /*!< sifive_spi0_0 extradel: coarse (Bit 0)                      */
#define sifive_spi0_0_extradel_coarse_Msk     (0xfffUL)                 /*!< sifive_spi0_0 extradel: coarse (Bitfield-Mask: 0xfff)       */
#define sifive_spi0_0_extradel_fine_Pos       (12UL)                    /*!< sifive_spi0_0 extradel: fine (Bit 12)                       */
#define sifive_spi0_0_extradel_fine_Msk       (0x1f000UL)               /*!< sifive_spi0_0 extradel: fine (Bitfield-Mask: 0x1f)          */

/* ---------------------------  sifive_spi0_0_sampledel  -------------------------- */
#define sifive_spi0_0_sampledel_sd_Pos        (0UL)                     /*!< sifive_spi0_0 sampledel: sd (Bit 0)                         */
#define sifive_spi0_0_sampledel_sd_Msk        (0x1fUL)                  /*!< sifive_spi0_0 sampledel: sd (Bitfield-Mask: 0x1f)           */

/* ------------------------------  sifive_spi0_0_fmt  ----------------------------- */
#define sifive_spi0_0_fmt_proto_Pos           (0UL)                     /*!< sifive_spi0_0 fmt: proto (Bit 0)                            */
#define sifive_spi0_0_fmt_proto_Msk           (0x3UL)                   /*!< sifive_spi0_0 fmt: proto (Bitfield-Mask: 0x03)              */
#define sifive_spi0_0_fmt_endian_Pos          (2UL)                     /*!< sifive_spi0_0 fmt: endian (Bit 2)                           */
#define sifive_spi0_0_fmt_endian_Msk          (0x4UL)                   /*!< sifive_spi0_0 fmt: endian (Bitfield-Mask: 0x01)             */
#define sifive_spi0_0_fmt_dir_Pos             (3UL)                     /*!< sifive_spi0_0 fmt: dir (Bit 3)                              */
#define sifive_spi0_0_fmt_dir_Msk             (0x8UL)                   /*!< sifive_spi0_0 fmt: dir (Bitfield-Mask: 0x01)                */
#define sifive_spi0_0_fmt_len_Pos             (16UL)                    /*!< sifive_spi0_0 fmt: len (Bit 16)                             */
#define sifive_spi0_0_fmt_len_Msk             (0xf0000UL)               /*!< sifive_spi0_0 fmt: len (Bitfield-Mask: 0x0f)                */

/* ----------------------------  sifive_spi0_0_txdata  ---------------------------- */
#define sifive_spi0_0_txdata_data_Pos         (0UL)                     /*!< sifive_spi0_0 txdata: data (Bit 0)                          */
#define sifive_spi0_0_txdata_data_Msk         (0xffUL)                  /*!< sifive_spi0_0 txdata: data (Bitfield-Mask: 0xff)            */
#define sifive_spi0_0_txdata_full_Pos         (31UL)                    /*!< sifive_spi0_0 txdata: full (Bit 31)                         */
#define sifive_spi0_0_txdata_full_Msk         (0x80000000UL)            /*!< sifive_spi0_0 txdata: full (Bitfield-Mask: 0x01)            */

/* ----------------------------  sifive_spi0_0_rxdata  ---------------------------- */
#define sifive_spi0_0_rxdata_data_Pos         (0UL)                     /*!< sifive_spi0_0 rxdata: data (Bit 0)                          */
#define sifive_spi0_0_rxdata_data_Msk         (0xffUL)                  /*!< sifive_spi0_0 rxdata: data (Bitfield-Mask: 0xff)            */
#define sifive_spi0_0_rxdata_empty_Pos        (31UL)                    /*!< sifive_spi0_0 rxdata: empty (Bit 31)                        */
#define sifive_spi0_0_rxdata_empty_Msk        (0x80000000UL)            /*!< sifive_spi0_0 rxdata: empty (Bitfield-Mask: 0x01)           */

/* ----------------------------  sifive_spi0_0_txmark  ---------------------------- */
#define sifive_spi0_0_txmark_txmark_Pos       (0UL)                     /*!< sifive_spi0_0 txmark: txmark (Bit 0)                        */
#define sifive_spi0_0_txmark_txmark_Msk       (0x7UL)                   /*!< sifive_spi0_0 txmark: txmark (Bitfield-Mask: 0x07)          */

/* ----------------------------  sifive_spi0_0_rxmark  ---------------------------- */
#define sifive_spi0_0_rxmark_rxmark_Pos       (0UL)                     /*!< sifive_spi0_0 rxmark: rxmark (Bit 0)                        */
#define sifive_spi0_0_rxmark_rxmark_Msk       (0x7UL)                   /*!< sifive_spi0_0 rxmark: rxmark (Bitfield-Mask: 0x07)          */

/* -----------------------------  sifive_spi0_0_fctrl  ---------------------------- */
#define sifive_spi0_0_fctrl_en_Pos            (0UL)                     /*!< sifive_spi0_0 fctrl: en (Bit 0)                             */
#define sifive_spi0_0_fctrl_en_Msk            (0x1UL)                   /*!< sifive_spi0_0 fctrl: en (Bitfield-Mask: 0x01)               */

/* -----------------------------  sifive_spi0_0_ffmt  ----------------------------- */
#define sifive_spi0_0_ffmt_cmd_en_Pos         (0UL)                     /*!< sifive_spi0_0 ffmt: cmd_en (Bit 0)                          */
#define sifive_spi0_0_ffmt_cmd_en_Msk         (0x1UL)                   /*!< sifive_spi0_0 ffmt: cmd_en (Bitfield-Mask: 0x01)            */
#define sifive_spi0_0_ffmt_addr_len_Pos       (1UL)                     /*!< sifive_spi0_0 ffmt: addr_len (Bit 1)                        */
#define sifive_spi0_0_ffmt_addr_len_Msk       (0xeUL)                   /*!< sifive_spi0_0 ffmt: addr_len (Bitfield-Mask: 0x07)          */
#define sifive_spi0_0_ffmt_pad_cnt_Pos        (4UL)                     /*!< sifive_spi0_0 ffmt: pad_cnt (Bit 4)                         */
#define sifive_spi0_0_ffmt_pad_cnt_Msk        (0xf0UL)                  /*!< sifive_spi0_0 ffmt: pad_cnt (Bitfield-Mask: 0x0f)           */
#define sifive_spi0_0_ffmt_cmd_proto_Pos      (8UL)                     /*!< sifive_spi0_0 ffmt: cmd_proto (Bit 8)                       */
#define sifive_spi0_0_ffmt_cmd_proto_Msk      (0x300UL)                 /*!< sifive_spi0_0 ffmt: cmd_proto (Bitfield-Mask: 0x03)         */
#define sifive_spi0_0_ffmt_addr_proto_Pos     (10UL)                    /*!< sifive_spi0_0 ffmt: addr_proto (Bit 10)                     */
#define sifive_spi0_0_ffmt_addr_proto_Msk     (0xc00UL)                 /*!< sifive_spi0_0 ffmt: addr_proto (Bitfield-Mask: 0x03)        */
#define sifive_spi0_0_ffmt_data_proto_Pos     (12UL)                    /*!< sifive_spi0_0 ffmt: data_proto (Bit 12)                     */
#define sifive_spi0_0_ffmt_data_proto_Msk     (0x3000UL)                /*!< sifive_spi0_0 ffmt: data_proto (Bitfield-Mask: 0x03)        */
#define sifive_spi0_0_ffmt_cmd_code_Pos       (16UL)                    /*!< sifive_spi0_0 ffmt: cmd_code (Bit 16)                       */
#define sifive_spi0_0_ffmt_cmd_code_Msk       (0xff0000UL)              /*!< sifive_spi0_0 ffmt: cmd_code (Bitfield-Mask: 0xff)          */
#define sifive_spi0_0_ffmt_pad_code_Pos       (24UL)                    /*!< sifive_spi0_0 ffmt: pad_code (Bit 24)                       */
#define sifive_spi0_0_ffmt_pad_code_Msk       (0xff000000UL)            /*!< sifive_spi0_0 ffmt: pad_code (Bitfield-Mask: 0xff)          */

/* ------------------------------  sifive_spi0_0_ie  ------------------------------ */
#define sifive_spi0_0_ie_txwm_Pos             (0UL)                     /*!< sifive_spi0_0 ie: txwm (Bit 0)                              */
#define sifive_spi0_0_ie_txwm_Msk             (0x1UL)                   /*!< sifive_spi0_0 ie: txwm (Bitfield-Mask: 0x01)                */
#define sifive_spi0_0_ie_rxwm_Pos             (1UL)                     /*!< sifive_spi0_0 ie: rxwm (Bit 1)                              */
#define sifive_spi0_0_ie_rxwm_Msk             (0x2UL)                   /*!< sifive_spi0_0 ie: rxwm (Bitfield-Mask: 0x01)                */

/* ------------------------------  sifive_spi0_0_ip  ------------------------------ */
#define sifive_spi0_0_ip_txwm_Pos             (0UL)                     /*!< sifive_spi0_0 ip: txwm (Bit 0)                              */
#define sifive_spi0_0_ip_txwm_Msk             (0x1UL)                   /*!< sifive_spi0_0 ip: txwm (Bitfield-Mask: 0x01)                */
#define sifive_spi0_0_ip_rxwm_Pos             (1UL)                     /*!< sifive_spi0_0 ip: rxwm (Bit 1)                              */
#define sifive_spi0_0_ip_rxwm_Msk             (0x2UL)                   /*!< sifive_spi0_0 ip: rxwm (Bitfield-Mask: 0x01)                */


/* ================================================================================ */
/* ================     struct 'sifive_pwm0_0' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_pwm0_0_pwmcfg  ---------------------------- */
#define sifive_pwm0_0_pwmcfg_pwmscale_Pos     (0UL)                     /*!< sifive_pwm0_0 pwmcfg: pwmscale (Bit 0)                      */
#define sifive_pwm0_0_pwmcfg_pwmscale_Msk     (0xfUL)                   /*!< sifive_pwm0_0 pwmcfg: pwmscale (Bitfield-Mask: 0x0f)        */
#define sifive_pwm0_0_pwmcfg_pwmsticky_Pos    (8UL)                     /*!< sifive_pwm0_0 pwmcfg: pwmsticky (Bit 8)                     */
#define sifive_pwm0_0_pwmcfg_pwmsticky_Msk    (0x100UL)                 /*!< sifive_pwm0_0 pwmcfg: pwmsticky (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_0_pwmcfg_pwmzerocmp_Pos   (9UL)                     /*!< sifive_pwm0_0 pwmcfg: pwmzerocmp (Bit 9)                    */
#define sifive_pwm0_0_pwmcfg_pwmzerocmp_Msk   (0x200UL)                 /*!< sifive_pwm0_0 pwmcfg: pwmzerocmp (Bitfield-Mask: 0x01)      */
#define sifive_pwm0_0_pwmcfg_pwmdeglitch_Pos  (10UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmdeglitch (Bit 10)                  */
#define sifive_pwm0_0_pwmcfg_pwmdeglitch_Msk  (0x400UL)                 /*!< sifive_pwm0_0 pwmcfg: pwmdeglitch (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_0_pwmcfg_pwmenalways_Pos  (12UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmenalways (Bit 12)                  */
#define sifive_pwm0_0_pwmcfg_pwmenalways_Msk  (0x1000UL)                /*!< sifive_pwm0_0 pwmcfg: pwmenalways (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_0_pwmcfg_pwmenoneshot_Pos (13UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmenoneshot (Bit 13)                 */
#define sifive_pwm0_0_pwmcfg_pwmenoneshot_Msk (0x2000UL)                /*!< sifive_pwm0_0 pwmcfg: pwmenoneshot (Bitfield-Mask: 0x01)    */
#define sifive_pwm0_0_pwmcfg_pwmcmp0center_Pos (16UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp0center (Bit 16)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp0center_Msk (0x10000UL)              /*!< sifive_pwm0_0 pwmcfg: pwmcmp0center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp1center_Pos (17UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp1center (Bit 17)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp1center_Msk (0x20000UL)              /*!< sifive_pwm0_0 pwmcfg: pwmcmp1center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp2center_Pos (18UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp2center (Bit 18)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp2center_Msk (0x40000UL)              /*!< sifive_pwm0_0 pwmcfg: pwmcmp2center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp3center_Pos (19UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp3center (Bit 19)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp3center_Msk (0x80000UL)              /*!< sifive_pwm0_0 pwmcfg: pwmcmp3center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp0invert_Pos (20UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp0invert (Bit 20)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp0invert_Msk (0x100000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp0invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp1invert_Pos (21UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp1invert (Bit 21)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp1invert_Msk (0x200000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp1invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp2invert_Pos (22UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp2invert (Bit 22)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp2invert_Msk (0x400000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp2invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp3invert_Pos (23UL)                   /*!< sifive_pwm0_0 pwmcfg: pwmcmp3invert (Bit 23)                */
#define sifive_pwm0_0_pwmcfg_pwmcmp3invert_Msk (0x800000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp3invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_0_pwmcfg_pwmcmp0gang_Pos  (24UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp0gang (Bit 24)                  */
#define sifive_pwm0_0_pwmcfg_pwmcmp0gang_Msk  (0x1000000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp0gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_0_pwmcfg_pwmcmp1gang_Pos  (25UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp1gang (Bit 25)                  */
#define sifive_pwm0_0_pwmcfg_pwmcmp1gang_Msk  (0x2000000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp1gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_0_pwmcfg_pwmcmp2gang_Pos  (26UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp2gang (Bit 26)                  */
#define sifive_pwm0_0_pwmcfg_pwmcmp2gang_Msk  (0x4000000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp2gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_0_pwmcfg_pwmcmp3gang_Pos  (27UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp3gang (Bit 27)                  */
#define sifive_pwm0_0_pwmcfg_pwmcmp3gang_Msk  (0x8000000UL)             /*!< sifive_pwm0_0 pwmcfg: pwmcmp3gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_0_pwmcfg_pwmcmp0ip_Pos    (28UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp0ip (Bit 28)                    */
#define sifive_pwm0_0_pwmcfg_pwmcmp0ip_Msk    (0x10000000UL)            /*!< sifive_pwm0_0 pwmcfg: pwmcmp0ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_0_pwmcfg_pwmcmp1ip_Pos    (29UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp1ip (Bit 29)                    */
#define sifive_pwm0_0_pwmcfg_pwmcmp1ip_Msk    (0x20000000UL)            /*!< sifive_pwm0_0 pwmcfg: pwmcmp1ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_0_pwmcfg_pwmcmp2ip_Pos    (30UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp2ip (Bit 30)                    */
#define sifive_pwm0_0_pwmcfg_pwmcmp2ip_Msk    (0x40000000UL)            /*!< sifive_pwm0_0 pwmcfg: pwmcmp2ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_0_pwmcfg_pwmcmp3ip_Pos    (31UL)                    /*!< sifive_pwm0_0 pwmcfg: pwmcmp3ip (Bit 31)                    */
#define sifive_pwm0_0_pwmcfg_pwmcmp3ip_Msk    (0x80000000UL)            /*!< sifive_pwm0_0 pwmcfg: pwmcmp3ip (Bitfield-Mask: 0x01)       */

/* ---------------------------  sifive_pwm0_0_pwmcount  --------------------------- */
#define sifive_pwm0_0_pwmcount_pwmcount_Pos   (0UL)                     /*!< sifive_pwm0_0 pwmcount: pwmcount (Bit 0)                    */
#define sifive_pwm0_0_pwmcount_pwmcount_Msk   (0x7fffffffUL)            /*!< sifive_pwm0_0 pwmcount: pwmcount (Bitfield-Mask: 0x7fffffff) */

/* -----------------------------  sifive_pwm0_0_pwms  ----------------------------- */
#define sifive_pwm0_0_pwms_pwms_Pos           (0UL)                     /*!< sifive_pwm0_0 pwms: pwms (Bit 0)                            */
#define sifive_pwm0_0_pwms_pwms_Msk           (0xffffUL)                /*!< sifive_pwm0_0 pwms: pwms (Bitfield-Mask: 0xffff)            */

/* ----------------------------  sifive_pwm0_0_pwmcmp0  --------------------------- */
#define sifive_pwm0_0_pwmcmp0_pwmcmp0_Pos     (0UL)                     /*!< sifive_pwm0_0 pwmcmp0: pwmcmp0 (Bit 0)                      */
#define sifive_pwm0_0_pwmcmp0_pwmcmp0_Msk     (0xffffUL)                /*!< sifive_pwm0_0 pwmcmp0: pwmcmp0 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_0_pwmcmp1  --------------------------- */
#define sifive_pwm0_0_pwmcmp1_pwmcmp1_Pos     (0UL)                     /*!< sifive_pwm0_0 pwmcmp1: pwmcmp1 (Bit 0)                      */
#define sifive_pwm0_0_pwmcmp1_pwmcmp1_Msk     (0xffffUL)                /*!< sifive_pwm0_0 pwmcmp1: pwmcmp1 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_0_pwmcmp2  --------------------------- */
#define sifive_pwm0_0_pwmcmp2_pwmcmp2_Pos     (0UL)                     /*!< sifive_pwm0_0 pwmcmp2: pwmcmp2 (Bit 0)                      */
#define sifive_pwm0_0_pwmcmp2_pwmcmp2_Msk     (0xffffUL)                /*!< sifive_pwm0_0 pwmcmp2: pwmcmp2 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_0_pwmcmp3  --------------------------- */
#define sifive_pwm0_0_pwmcmp3_pwmcmp3_Pos     (0UL)                     /*!< sifive_pwm0_0 pwmcmp3: pwmcmp3 (Bit 0)                      */
#define sifive_pwm0_0_pwmcmp3_pwmcmp3_Msk     (0xffffUL)                /*!< sifive_pwm0_0 pwmcmp3: pwmcmp3 (Bitfield-Mask: 0xffff)      */


/* ================================================================================ */
/* ================     struct 'sifive_i2c0_0' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_i2c0_0_control  --------------------------- */
#define sifive_i2c0_0_control_en_Pos          (6UL)                     /*!< sifive_i2c0_0 control: en (Bit 6)                           */
#define sifive_i2c0_0_control_en_Msk          (0x40UL)                  /*!< sifive_i2c0_0 control: en (Bitfield-Mask: 0x01)             */
#define sifive_i2c0_0_control_ien_Pos         (7UL)                     /*!< sifive_i2c0_0 control: ien (Bit 7)                          */
#define sifive_i2c0_0_control_ien_Msk         (0x80UL)                  /*!< sifive_i2c0_0 control: ien (Bitfield-Mask: 0x01)            */

/* ------------------------  sifive_i2c0_0_command__status  ----------------------- */
#define sifive_i2c0_0_command__status_wr_iack__rd_if_Pos (0UL)          /*!< sifive_i2c0_0 command__status: wr_iack__rd_if (Bit 0)       */
#define sifive_i2c0_0_command__status_wr_iack__rd_if_Msk (0x1UL)        /*!< sifive_i2c0_0 command__status: wr_iack__rd_if (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_res__rd_tip_Pos (1UL)          /*!< sifive_i2c0_0 command__status: wr_res__rd_tip (Bit 1)       */
#define sifive_i2c0_0_command__status_wr_res__rd_tip_Msk (0x2UL)        /*!< sifive_i2c0_0 command__status: wr_res__rd_tip (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_res__rd_res_Pos (2UL)          /*!< sifive_i2c0_0 command__status: wr_res__rd_res (Bit 2)       */
#define sifive_i2c0_0_command__status_wr_res__rd_res_Msk (0x4UL)        /*!< sifive_i2c0_0 command__status: wr_res__rd_res (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_ack__rd_res_Pos (3UL)          /*!< sifive_i2c0_0 command__status: wr_ack__rd_res (Bit 3)       */
#define sifive_i2c0_0_command__status_wr_ack__rd_res_Msk (0x8UL)        /*!< sifive_i2c0_0 command__status: wr_ack__rd_res (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_txd__rd_res_Pos (4UL)          /*!< sifive_i2c0_0 command__status: wr_txd__rd_res (Bit 4)       */
#define sifive_i2c0_0_command__status_wr_txd__rd_res_Msk (0x10UL)       /*!< sifive_i2c0_0 command__status: wr_txd__rd_res (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_rxd__rd_al_Pos (5UL)           /*!< sifive_i2c0_0 command__status: wr_rxd__rd_al (Bit 5)        */
#define sifive_i2c0_0_command__status_wr_rxd__rd_al_Msk (0x20UL)        /*!< sifive_i2c0_0 command__status: wr_rxd__rd_al (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_sto__rd_busy_Pos (6UL)         /*!< sifive_i2c0_0 command__status: wr_sto__rd_busy (Bit 6)      */
#define sifive_i2c0_0_command__status_wr_sto__rd_busy_Msk (0x40UL)      /*!< sifive_i2c0_0 command__status: wr_sto__rd_busy (Bitfield-Mask: 0x01) */
#define sifive_i2c0_0_command__status_wr_sta__rd_rxack_Pos (7UL)        /*!< sifive_i2c0_0 command__status: wr_sta__rd_rxack (Bit 7)     */
#define sifive_i2c0_0_command__status_wr_sta__rd_rxack_Msk (0x80UL)     /*!< sifive_i2c0_0 command__status: wr_sta__rd_rxack (Bitfield-Mask: 0x01) */


/* ================================================================================ */
/* ================     struct 'sifive_uart0_1' Position & Mask    ================ */
/* ================================================================================ */


/* ----------------------------  sifive_uart0_1_txdata  --------------------------- */
#define sifive_uart0_1_txdata_data_Pos        (0UL)                     /*!< sifive_uart0_1 txdata: data (Bit 0)                         */
#define sifive_uart0_1_txdata_data_Msk        (0xffUL)                  /*!< sifive_uart0_1 txdata: data (Bitfield-Mask: 0xff)           */
#define sifive_uart0_1_txdata_full_Pos        (31UL)                    /*!< sifive_uart0_1 txdata: full (Bit 31)                        */
#define sifive_uart0_1_txdata_full_Msk        (0x80000000UL)            /*!< sifive_uart0_1 txdata: full (Bitfield-Mask: 0x01)           */

/* ----------------------------  sifive_uart0_1_rxdata  --------------------------- */
#define sifive_uart0_1_rxdata_data_Pos        (0UL)                     /*!< sifive_uart0_1 rxdata: data (Bit 0)                         */
#define sifive_uart0_1_rxdata_data_Msk        (0xffUL)                  /*!< sifive_uart0_1 rxdata: data (Bitfield-Mask: 0xff)           */
#define sifive_uart0_1_rxdata_empty_Pos       (31UL)                    /*!< sifive_uart0_1 rxdata: empty (Bit 31)                       */
#define sifive_uart0_1_rxdata_empty_Msk       (0x80000000UL)            /*!< sifive_uart0_1 rxdata: empty (Bitfield-Mask: 0x01)          */

/* ----------------------------  sifive_uart0_1_txctrl  --------------------------- */
#define sifive_uart0_1_txctrl_txen_Pos        (0UL)                     /*!< sifive_uart0_1 txctrl: txen (Bit 0)                         */
#define sifive_uart0_1_txctrl_txen_Msk        (0x1UL)                   /*!< sifive_uart0_1 txctrl: txen (Bitfield-Mask: 0x01)           */
#define sifive_uart0_1_txctrl_nstop_Pos       (1UL)                     /*!< sifive_uart0_1 txctrl: nstop (Bit 1)                        */
#define sifive_uart0_1_txctrl_nstop_Msk       (0x2UL)                   /*!< sifive_uart0_1 txctrl: nstop (Bitfield-Mask: 0x01)          */
#define sifive_uart0_1_txctrl_txcnt_Pos       (16UL)                    /*!< sifive_uart0_1 txctrl: txcnt (Bit 16)                       */
#define sifive_uart0_1_txctrl_txcnt_Msk       (0x70000UL)               /*!< sifive_uart0_1 txctrl: txcnt (Bitfield-Mask: 0x07)          */

/* ----------------------------  sifive_uart0_1_rxctrl  --------------------------- */
#define sifive_uart0_1_rxctrl_rxen_Pos        (0UL)                     /*!< sifive_uart0_1 rxctrl: rxen (Bit 0)                         */
#define sifive_uart0_1_rxctrl_rxen_Msk        (0x1UL)                   /*!< sifive_uart0_1 rxctrl: rxen (Bitfield-Mask: 0x01)           */
#define sifive_uart0_1_rxctrl_rxcnt_Pos       (16UL)                    /*!< sifive_uart0_1 rxctrl: rxcnt (Bit 16)                       */
#define sifive_uart0_1_rxctrl_rxcnt_Msk       (0x70000UL)               /*!< sifive_uart0_1 rxctrl: rxcnt (Bitfield-Mask: 0x07)          */

/* ------------------------------  sifive_uart0_1_ie  ----------------------------- */
#define sifive_uart0_1_ie_txwm_Pos            (0UL)                     /*!< sifive_uart0_1 ie: txwm (Bit 0)                             */
#define sifive_uart0_1_ie_txwm_Msk            (0x1UL)                   /*!< sifive_uart0_1 ie: txwm (Bitfield-Mask: 0x01)               */
#define sifive_uart0_1_ie_rxwm_Pos            (1UL)                     /*!< sifive_uart0_1 ie: rxwm (Bit 1)                             */
#define sifive_uart0_1_ie_rxwm_Msk            (0x2UL)                   /*!< sifive_uart0_1 ie: rxwm (Bitfield-Mask: 0x01)               */

/* ------------------------------  sifive_uart0_1_ip  ----------------------------- */
#define sifive_uart0_1_ip_txwm_Pos            (0UL)                     /*!< sifive_uart0_1 ip: txwm (Bit 0)                             */
#define sifive_uart0_1_ip_txwm_Msk            (0x1UL)                   /*!< sifive_uart0_1 ip: txwm (Bitfield-Mask: 0x01)               */
#define sifive_uart0_1_ip_rxwm_Pos            (1UL)                     /*!< sifive_uart0_1 ip: rxwm (Bit 1)                             */
#define sifive_uart0_1_ip_rxwm_Msk            (0x2UL)                   /*!< sifive_uart0_1 ip: rxwm (Bitfield-Mask: 0x01)               */

/* -----------------------------  sifive_uart0_1_div  ----------------------------- */
#define sifive_uart0_1_div_div_Pos            (0UL)                     /*!< sifive_uart0_1 div: div (Bit 0)                             */
#define sifive_uart0_1_div_div_Msk            (0xffffUL)                /*!< sifive_uart0_1 div: div (Bitfield-Mask: 0xffff)             */


/* ================================================================================ */
/* ================     struct 'sifive_spi0_1' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_spi0_1_sckdiv  ---------------------------- */
#define sifive_spi0_1_sckdiv_div_Pos          (0UL)                     /*!< sifive_spi0_1 sckdiv: div (Bit 0)                           */
#define sifive_spi0_1_sckdiv_div_Msk          (0xfffUL)                 /*!< sifive_spi0_1 sckdiv: div (Bitfield-Mask: 0xfff)            */

/* ----------------------------  sifive_spi0_1_sckmode  --------------------------- */
#define sifive_spi0_1_sckmode_pha_Pos         (0UL)                     /*!< sifive_spi0_1 sckmode: pha (Bit 0)                          */
#define sifive_spi0_1_sckmode_pha_Msk         (0x1UL)                   /*!< sifive_spi0_1 sckmode: pha (Bitfield-Mask: 0x01)            */
#define sifive_spi0_1_sckmode_pol_Pos         (1UL)                     /*!< sifive_spi0_1 sckmode: pol (Bit 1)                          */
#define sifive_spi0_1_sckmode_pol_Msk         (0x2UL)                   /*!< sifive_spi0_1 sckmode: pol (Bitfield-Mask: 0x01)            */

/* -----------------------------  sifive_spi0_1_csid  ----------------------------- */
#define sifive_spi0_1_csid_csid_Pos           (0UL)                     /*!< sifive_spi0_1 csid: csid (Bit 0)                            */
#define sifive_spi0_1_csid_csid_Msk           (0xffffffffUL)            /*!< sifive_spi0_1 csid: csid (Bitfield-Mask: 0xffffffff)        */

/* -----------------------------  sifive_spi0_1_csdef  ---------------------------- */
#define sifive_spi0_1_csdef_csdef_Pos         (0UL)                     /*!< sifive_spi0_1 csdef: csdef (Bit 0)                          */
#define sifive_spi0_1_csdef_csdef_Msk         (0xffffffffUL)            /*!< sifive_spi0_1 csdef: csdef (Bitfield-Mask: 0xffffffff)      */

/* ----------------------------  sifive_spi0_1_csmode  ---------------------------- */
#define sifive_spi0_1_csmode_mode_Pos         (0UL)                     /*!< sifive_spi0_1 csmode: mode (Bit 0)                          */
#define sifive_spi0_1_csmode_mode_Msk         (0x3UL)                   /*!< sifive_spi0_1 csmode: mode (Bitfield-Mask: 0x03)            */

/* ----------------------------  sifive_spi0_1_delay0  ---------------------------- */
#define sifive_spi0_1_delay0_cssck_Pos        (0UL)                     /*!< sifive_spi0_1 delay0: cssck (Bit 0)                         */
#define sifive_spi0_1_delay0_cssck_Msk        (0xffUL)                  /*!< sifive_spi0_1 delay0: cssck (Bitfield-Mask: 0xff)           */
#define sifive_spi0_1_delay0_sckcs_Pos        (16UL)                    /*!< sifive_spi0_1 delay0: sckcs (Bit 16)                        */
#define sifive_spi0_1_delay0_sckcs_Msk        (0xff0000UL)              /*!< sifive_spi0_1 delay0: sckcs (Bitfield-Mask: 0xff)           */

/* ----------------------------  sifive_spi0_1_delay1  ---------------------------- */
#define sifive_spi0_1_delay1_intercs_Pos      (0UL)                     /*!< sifive_spi0_1 delay1: intercs (Bit 0)                       */
#define sifive_spi0_1_delay1_intercs_Msk      (0xffUL)                  /*!< sifive_spi0_1 delay1: intercs (Bitfield-Mask: 0xff)         */
#define sifive_spi0_1_delay1_interxfr_Pos     (16UL)                    /*!< sifive_spi0_1 delay1: interxfr (Bit 16)                     */
#define sifive_spi0_1_delay1_interxfr_Msk     (0xff0000UL)              /*!< sifive_spi0_1 delay1: interxfr (Bitfield-Mask: 0xff)        */

/* ---------------------------  sifive_spi0_1_extradel  --------------------------- */
#define sifive_spi0_1_extradel_coarse_Pos     (0UL)                     /*!< sifive_spi0_1 extradel: coarse (Bit 0)                      */
#define sifive_spi0_1_extradel_coarse_Msk     (0xfffUL)                 /*!< sifive_spi0_1 extradel: coarse (Bitfield-Mask: 0xfff)       */
#define sifive_spi0_1_extradel_fine_Pos       (12UL)                    /*!< sifive_spi0_1 extradel: fine (Bit 12)                       */
#define sifive_spi0_1_extradel_fine_Msk       (0x1f000UL)               /*!< sifive_spi0_1 extradel: fine (Bitfield-Mask: 0x1f)          */

/* ---------------------------  sifive_spi0_1_sampledel  -------------------------- */
#define sifive_spi0_1_sampledel_sd_Pos        (0UL)                     /*!< sifive_spi0_1 sampledel: sd (Bit 0)                         */
#define sifive_spi0_1_sampledel_sd_Msk        (0x1fUL)                  /*!< sifive_spi0_1 sampledel: sd (Bitfield-Mask: 0x1f)           */

/* ------------------------------  sifive_spi0_1_fmt  ----------------------------- */
#define sifive_spi0_1_fmt_proto_Pos           (0UL)                     /*!< sifive_spi0_1 fmt: proto (Bit 0)                            */
#define sifive_spi0_1_fmt_proto_Msk           (0x3UL)                   /*!< sifive_spi0_1 fmt: proto (Bitfield-Mask: 0x03)              */
#define sifive_spi0_1_fmt_endian_Pos          (2UL)                     /*!< sifive_spi0_1 fmt: endian (Bit 2)                           */
#define sifive_spi0_1_fmt_endian_Msk          (0x4UL)                   /*!< sifive_spi0_1 fmt: endian (Bitfield-Mask: 0x01)             */
#define sifive_spi0_1_fmt_dir_Pos             (3UL)                     /*!< sifive_spi0_1 fmt: dir (Bit 3)                              */
#define sifive_spi0_1_fmt_dir_Msk             (0x8UL)                   /*!< sifive_spi0_1 fmt: dir (Bitfield-Mask: 0x01)                */
#define sifive_spi0_1_fmt_len_Pos             (16UL)                    /*!< sifive_spi0_1 fmt: len (Bit 16)                             */
#define sifive_spi0_1_fmt_len_Msk             (0xf0000UL)               /*!< sifive_spi0_1 fmt: len (Bitfield-Mask: 0x0f)                */

/* ----------------------------  sifive_spi0_1_txdata  ---------------------------- */
#define sifive_spi0_1_txdata_data_Pos         (0UL)                     /*!< sifive_spi0_1 txdata: data (Bit 0)                          */
#define sifive_spi0_1_txdata_data_Msk         (0xffUL)                  /*!< sifive_spi0_1 txdata: data (Bitfield-Mask: 0xff)            */
#define sifive_spi0_1_txdata_full_Pos         (31UL)                    /*!< sifive_spi0_1 txdata: full (Bit 31)                         */
#define sifive_spi0_1_txdata_full_Msk         (0x80000000UL)            /*!< sifive_spi0_1 txdata: full (Bitfield-Mask: 0x01)            */

/* ----------------------------  sifive_spi0_1_rxdata  ---------------------------- */
#define sifive_spi0_1_rxdata_data_Pos         (0UL)                     /*!< sifive_spi0_1 rxdata: data (Bit 0)                          */
#define sifive_spi0_1_rxdata_data_Msk         (0xffUL)                  /*!< sifive_spi0_1 rxdata: data (Bitfield-Mask: 0xff)            */
#define sifive_spi0_1_rxdata_empty_Pos        (31UL)                    /*!< sifive_spi0_1 rxdata: empty (Bit 31)                        */
#define sifive_spi0_1_rxdata_empty_Msk        (0x80000000UL)            /*!< sifive_spi0_1 rxdata: empty (Bitfield-Mask: 0x01)           */

/* ----------------------------  sifive_spi0_1_txmark  ---------------------------- */
#define sifive_spi0_1_txmark_txmark_Pos       (0UL)                     /*!< sifive_spi0_1 txmark: txmark (Bit 0)                        */
#define sifive_spi0_1_txmark_txmark_Msk       (0x7UL)                   /*!< sifive_spi0_1 txmark: txmark (Bitfield-Mask: 0x07)          */

/* ----------------------------  sifive_spi0_1_rxmark  ---------------------------- */
#define sifive_spi0_1_rxmark_rxmark_Pos       (0UL)                     /*!< sifive_spi0_1 rxmark: rxmark (Bit 0)                        */
#define sifive_spi0_1_rxmark_rxmark_Msk       (0x7UL)                   /*!< sifive_spi0_1 rxmark: rxmark (Bitfield-Mask: 0x07)          */

/* -----------------------------  sifive_spi0_1_fctrl  ---------------------------- */
#define sifive_spi0_1_fctrl_en_Pos            (0UL)                     /*!< sifive_spi0_1 fctrl: en (Bit 0)                             */
#define sifive_spi0_1_fctrl_en_Msk            (0x1UL)                   /*!< sifive_spi0_1 fctrl: en (Bitfield-Mask: 0x01)               */

/* -----------------------------  sifive_spi0_1_ffmt  ----------------------------- */
#define sifive_spi0_1_ffmt_cmd_en_Pos         (0UL)                     /*!< sifive_spi0_1 ffmt: cmd_en (Bit 0)                          */
#define sifive_spi0_1_ffmt_cmd_en_Msk         (0x1UL)                   /*!< sifive_spi0_1 ffmt: cmd_en (Bitfield-Mask: 0x01)            */
#define sifive_spi0_1_ffmt_addr_len_Pos       (1UL)                     /*!< sifive_spi0_1 ffmt: addr_len (Bit 1)                        */
#define sifive_spi0_1_ffmt_addr_len_Msk       (0xeUL)                   /*!< sifive_spi0_1 ffmt: addr_len (Bitfield-Mask: 0x07)          */
#define sifive_spi0_1_ffmt_pad_cnt_Pos        (4UL)                     /*!< sifive_spi0_1 ffmt: pad_cnt (Bit 4)                         */
#define sifive_spi0_1_ffmt_pad_cnt_Msk        (0xf0UL)                  /*!< sifive_spi0_1 ffmt: pad_cnt (Bitfield-Mask: 0x0f)           */
#define sifive_spi0_1_ffmt_cmd_proto_Pos      (8UL)                     /*!< sifive_spi0_1 ffmt: cmd_proto (Bit 8)                       */
#define sifive_spi0_1_ffmt_cmd_proto_Msk      (0x300UL)                 /*!< sifive_spi0_1 ffmt: cmd_proto (Bitfield-Mask: 0x03)         */
#define sifive_spi0_1_ffmt_addr_proto_Pos     (10UL)                    /*!< sifive_spi0_1 ffmt: addr_proto (Bit 10)                     */
#define sifive_spi0_1_ffmt_addr_proto_Msk     (0xc00UL)                 /*!< sifive_spi0_1 ffmt: addr_proto (Bitfield-Mask: 0x03)        */
#define sifive_spi0_1_ffmt_data_proto_Pos     (12UL)                    /*!< sifive_spi0_1 ffmt: data_proto (Bit 12)                     */
#define sifive_spi0_1_ffmt_data_proto_Msk     (0x3000UL)                /*!< sifive_spi0_1 ffmt: data_proto (Bitfield-Mask: 0x03)        */
#define sifive_spi0_1_ffmt_cmd_code_Pos       (16UL)                    /*!< sifive_spi0_1 ffmt: cmd_code (Bit 16)                       */
#define sifive_spi0_1_ffmt_cmd_code_Msk       (0xff0000UL)              /*!< sifive_spi0_1 ffmt: cmd_code (Bitfield-Mask: 0xff)          */
#define sifive_spi0_1_ffmt_pad_code_Pos       (24UL)                    /*!< sifive_spi0_1 ffmt: pad_code (Bit 24)                       */
#define sifive_spi0_1_ffmt_pad_code_Msk       (0xff000000UL)            /*!< sifive_spi0_1 ffmt: pad_code (Bitfield-Mask: 0xff)          */

/* ------------------------------  sifive_spi0_1_ie  ------------------------------ */
#define sifive_spi0_1_ie_txwm_Pos             (0UL)                     /*!< sifive_spi0_1 ie: txwm (Bit 0)                              */
#define sifive_spi0_1_ie_txwm_Msk             (0x1UL)                   /*!< sifive_spi0_1 ie: txwm (Bitfield-Mask: 0x01)                */
#define sifive_spi0_1_ie_rxwm_Pos             (1UL)                     /*!< sifive_spi0_1 ie: rxwm (Bit 1)                              */
#define sifive_spi0_1_ie_rxwm_Msk             (0x2UL)                   /*!< sifive_spi0_1 ie: rxwm (Bitfield-Mask: 0x01)                */

/* ------------------------------  sifive_spi0_1_ip  ------------------------------ */
#define sifive_spi0_1_ip_txwm_Pos             (0UL)                     /*!< sifive_spi0_1 ip: txwm (Bit 0)                              */
#define sifive_spi0_1_ip_txwm_Msk             (0x1UL)                   /*!< sifive_spi0_1 ip: txwm (Bitfield-Mask: 0x01)                */
#define sifive_spi0_1_ip_rxwm_Pos             (1UL)                     /*!< sifive_spi0_1 ip: rxwm (Bit 1)                              */
#define sifive_spi0_1_ip_rxwm_Msk             (0x2UL)                   /*!< sifive_spi0_1 ip: rxwm (Bitfield-Mask: 0x01)                */


/* ================================================================================ */
/* ================     struct 'sifive_pwm0_1' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_pwm0_1_pwmcfg  ---------------------------- */
#define sifive_pwm0_1_pwmcfg_pwmscale_Pos     (0UL)                     /*!< sifive_pwm0_1 pwmcfg: pwmscale (Bit 0)                      */
#define sifive_pwm0_1_pwmcfg_pwmscale_Msk     (0xfUL)                   /*!< sifive_pwm0_1 pwmcfg: pwmscale (Bitfield-Mask: 0x0f)        */
#define sifive_pwm0_1_pwmcfg_pwmsticky_Pos    (8UL)                     /*!< sifive_pwm0_1 pwmcfg: pwmsticky (Bit 8)                     */
#define sifive_pwm0_1_pwmcfg_pwmsticky_Msk    (0x100UL)                 /*!< sifive_pwm0_1 pwmcfg: pwmsticky (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_1_pwmcfg_pwmzerocmp_Pos   (9UL)                     /*!< sifive_pwm0_1 pwmcfg: pwmzerocmp (Bit 9)                    */
#define sifive_pwm0_1_pwmcfg_pwmzerocmp_Msk   (0x200UL)                 /*!< sifive_pwm0_1 pwmcfg: pwmzerocmp (Bitfield-Mask: 0x01)      */
#define sifive_pwm0_1_pwmcfg_pwmdeglitch_Pos  (10UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmdeglitch (Bit 10)                  */
#define sifive_pwm0_1_pwmcfg_pwmdeglitch_Msk  (0x400UL)                 /*!< sifive_pwm0_1 pwmcfg: pwmdeglitch (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_1_pwmcfg_pwmenalways_Pos  (12UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmenalways (Bit 12)                  */
#define sifive_pwm0_1_pwmcfg_pwmenalways_Msk  (0x1000UL)                /*!< sifive_pwm0_1 pwmcfg: pwmenalways (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_1_pwmcfg_pwmenoneshot_Pos (13UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmenoneshot (Bit 13)                 */
#define sifive_pwm0_1_pwmcfg_pwmenoneshot_Msk (0x2000UL)                /*!< sifive_pwm0_1 pwmcfg: pwmenoneshot (Bitfield-Mask: 0x01)    */
#define sifive_pwm0_1_pwmcfg_pwmcmp0center_Pos (16UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp0center (Bit 16)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp0center_Msk (0x10000UL)              /*!< sifive_pwm0_1 pwmcfg: pwmcmp0center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp1center_Pos (17UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp1center (Bit 17)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp1center_Msk (0x20000UL)              /*!< sifive_pwm0_1 pwmcfg: pwmcmp1center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp2center_Pos (18UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp2center (Bit 18)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp2center_Msk (0x40000UL)              /*!< sifive_pwm0_1 pwmcfg: pwmcmp2center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp3center_Pos (19UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp3center (Bit 19)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp3center_Msk (0x80000UL)              /*!< sifive_pwm0_1 pwmcfg: pwmcmp3center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp0invert_Pos (20UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp0invert (Bit 20)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp0invert_Msk (0x100000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp0invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp1invert_Pos (21UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp1invert (Bit 21)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp1invert_Msk (0x200000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp1invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp2invert_Pos (22UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp2invert (Bit 22)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp2invert_Msk (0x400000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp2invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp3invert_Pos (23UL)                   /*!< sifive_pwm0_1 pwmcfg: pwmcmp3invert (Bit 23)                */
#define sifive_pwm0_1_pwmcfg_pwmcmp3invert_Msk (0x800000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp3invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_1_pwmcfg_pwmcmp0gang_Pos  (24UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp0gang (Bit 24)                  */
#define sifive_pwm0_1_pwmcfg_pwmcmp0gang_Msk  (0x1000000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp0gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_1_pwmcfg_pwmcmp1gang_Pos  (25UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp1gang (Bit 25)                  */
#define sifive_pwm0_1_pwmcfg_pwmcmp1gang_Msk  (0x2000000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp1gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_1_pwmcfg_pwmcmp2gang_Pos  (26UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp2gang (Bit 26)                  */
#define sifive_pwm0_1_pwmcfg_pwmcmp2gang_Msk  (0x4000000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp2gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_1_pwmcfg_pwmcmp3gang_Pos  (27UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp3gang (Bit 27)                  */
#define sifive_pwm0_1_pwmcfg_pwmcmp3gang_Msk  (0x8000000UL)             /*!< sifive_pwm0_1 pwmcfg: pwmcmp3gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_1_pwmcfg_pwmcmp0ip_Pos    (28UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp0ip (Bit 28)                    */
#define sifive_pwm0_1_pwmcfg_pwmcmp0ip_Msk    (0x10000000UL)            /*!< sifive_pwm0_1 pwmcfg: pwmcmp0ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_1_pwmcfg_pwmcmp1ip_Pos    (29UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp1ip (Bit 29)                    */
#define sifive_pwm0_1_pwmcfg_pwmcmp1ip_Msk    (0x20000000UL)            /*!< sifive_pwm0_1 pwmcfg: pwmcmp1ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_1_pwmcfg_pwmcmp2ip_Pos    (30UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp2ip (Bit 30)                    */
#define sifive_pwm0_1_pwmcfg_pwmcmp2ip_Msk    (0x40000000UL)            /*!< sifive_pwm0_1 pwmcfg: pwmcmp2ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_1_pwmcfg_pwmcmp3ip_Pos    (31UL)                    /*!< sifive_pwm0_1 pwmcfg: pwmcmp3ip (Bit 31)                    */
#define sifive_pwm0_1_pwmcfg_pwmcmp3ip_Msk    (0x80000000UL)            /*!< sifive_pwm0_1 pwmcfg: pwmcmp3ip (Bitfield-Mask: 0x01)       */

/* ---------------------------  sifive_pwm0_1_pwmcount  --------------------------- */
#define sifive_pwm0_1_pwmcount_pwmcount_Pos   (0UL)                     /*!< sifive_pwm0_1 pwmcount: pwmcount (Bit 0)                    */
#define sifive_pwm0_1_pwmcount_pwmcount_Msk   (0x7fffffffUL)            /*!< sifive_pwm0_1 pwmcount: pwmcount (Bitfield-Mask: 0x7fffffff) */

/* -----------------------------  sifive_pwm0_1_pwms  ----------------------------- */
#define sifive_pwm0_1_pwms_pwms_Pos           (0UL)                     /*!< sifive_pwm0_1 pwms: pwms (Bit 0)                            */
#define sifive_pwm0_1_pwms_pwms_Msk           (0xffffUL)                /*!< sifive_pwm0_1 pwms: pwms (Bitfield-Mask: 0xffff)            */

/* ----------------------------  sifive_pwm0_1_pwmcmp0  --------------------------- */
#define sifive_pwm0_1_pwmcmp0_pwmcmp0_Pos     (0UL)                     /*!< sifive_pwm0_1 pwmcmp0: pwmcmp0 (Bit 0)                      */
#define sifive_pwm0_1_pwmcmp0_pwmcmp0_Msk     (0xffffUL)                /*!< sifive_pwm0_1 pwmcmp0: pwmcmp0 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_1_pwmcmp1  --------------------------- */
#define sifive_pwm0_1_pwmcmp1_pwmcmp1_Pos     (0UL)                     /*!< sifive_pwm0_1 pwmcmp1: pwmcmp1 (Bit 0)                      */
#define sifive_pwm0_1_pwmcmp1_pwmcmp1_Msk     (0xffffUL)                /*!< sifive_pwm0_1 pwmcmp1: pwmcmp1 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_1_pwmcmp2  --------------------------- */
#define sifive_pwm0_1_pwmcmp2_pwmcmp2_Pos     (0UL)                     /*!< sifive_pwm0_1 pwmcmp2: pwmcmp2 (Bit 0)                      */
#define sifive_pwm0_1_pwmcmp2_pwmcmp2_Msk     (0xffffUL)                /*!< sifive_pwm0_1 pwmcmp2: pwmcmp2 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_1_pwmcmp3  --------------------------- */
#define sifive_pwm0_1_pwmcmp3_pwmcmp3_Pos     (0UL)                     /*!< sifive_pwm0_1 pwmcmp3: pwmcmp3 (Bit 0)                      */
#define sifive_pwm0_1_pwmcmp3_pwmcmp3_Msk     (0xffffUL)                /*!< sifive_pwm0_1 pwmcmp3: pwmcmp3 (Bitfield-Mask: 0xffff)      */


/* ================================================================================ */
/* ================     struct 'sifive_spi0_2' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_spi0_2_sckdiv  ---------------------------- */
#define sifive_spi0_2_sckdiv_div_Pos          (0UL)                     /*!< sifive_spi0_2 sckdiv: div (Bit 0)                           */
#define sifive_spi0_2_sckdiv_div_Msk          (0xfffUL)                 /*!< sifive_spi0_2 sckdiv: div (Bitfield-Mask: 0xfff)            */

/* ----------------------------  sifive_spi0_2_sckmode  --------------------------- */
#define sifive_spi0_2_sckmode_pha_Pos         (0UL)                     /*!< sifive_spi0_2 sckmode: pha (Bit 0)                          */
#define sifive_spi0_2_sckmode_pha_Msk         (0x1UL)                   /*!< sifive_spi0_2 sckmode: pha (Bitfield-Mask: 0x01)            */
#define sifive_spi0_2_sckmode_pol_Pos         (1UL)                     /*!< sifive_spi0_2 sckmode: pol (Bit 1)                          */
#define sifive_spi0_2_sckmode_pol_Msk         (0x2UL)                   /*!< sifive_spi0_2 sckmode: pol (Bitfield-Mask: 0x01)            */

/* -----------------------------  sifive_spi0_2_csid  ----------------------------- */
#define sifive_spi0_2_csid_csid_Pos           (0UL)                     /*!< sifive_spi0_2 csid: csid (Bit 0)                            */
#define sifive_spi0_2_csid_csid_Msk           (0xffffffffUL)            /*!< sifive_spi0_2 csid: csid (Bitfield-Mask: 0xffffffff)        */

/* -----------------------------  sifive_spi0_2_csdef  ---------------------------- */
#define sifive_spi0_2_csdef_csdef_Pos         (0UL)                     /*!< sifive_spi0_2 csdef: csdef (Bit 0)                          */
#define sifive_spi0_2_csdef_csdef_Msk         (0xffffffffUL)            /*!< sifive_spi0_2 csdef: csdef (Bitfield-Mask: 0xffffffff)      */

/* ----------------------------  sifive_spi0_2_csmode  ---------------------------- */
#define sifive_spi0_2_csmode_mode_Pos         (0UL)                     /*!< sifive_spi0_2 csmode: mode (Bit 0)                          */
#define sifive_spi0_2_csmode_mode_Msk         (0x3UL)                   /*!< sifive_spi0_2 csmode: mode (Bitfield-Mask: 0x03)            */

/* ----------------------------  sifive_spi0_2_delay0  ---------------------------- */
#define sifive_spi0_2_delay0_cssck_Pos        (0UL)                     /*!< sifive_spi0_2 delay0: cssck (Bit 0)                         */
#define sifive_spi0_2_delay0_cssck_Msk        (0xffUL)                  /*!< sifive_spi0_2 delay0: cssck (Bitfield-Mask: 0xff)           */
#define sifive_spi0_2_delay0_sckcs_Pos        (16UL)                    /*!< sifive_spi0_2 delay0: sckcs (Bit 16)                        */
#define sifive_spi0_2_delay0_sckcs_Msk        (0xff0000UL)              /*!< sifive_spi0_2 delay0: sckcs (Bitfield-Mask: 0xff)           */

/* ----------------------------  sifive_spi0_2_delay1  ---------------------------- */
#define sifive_spi0_2_delay1_intercs_Pos      (0UL)                     /*!< sifive_spi0_2 delay1: intercs (Bit 0)                       */
#define sifive_spi0_2_delay1_intercs_Msk      (0xffUL)                  /*!< sifive_spi0_2 delay1: intercs (Bitfield-Mask: 0xff)         */
#define sifive_spi0_2_delay1_interxfr_Pos     (16UL)                    /*!< sifive_spi0_2 delay1: interxfr (Bit 16)                     */
#define sifive_spi0_2_delay1_interxfr_Msk     (0xff0000UL)              /*!< sifive_spi0_2 delay1: interxfr (Bitfield-Mask: 0xff)        */

/* ---------------------------  sifive_spi0_2_extradel  --------------------------- */
#define sifive_spi0_2_extradel_coarse_Pos     (0UL)                     /*!< sifive_spi0_2 extradel: coarse (Bit 0)                      */
#define sifive_spi0_2_extradel_coarse_Msk     (0xfffUL)                 /*!< sifive_spi0_2 extradel: coarse (Bitfield-Mask: 0xfff)       */
#define sifive_spi0_2_extradel_fine_Pos       (12UL)                    /*!< sifive_spi0_2 extradel: fine (Bit 12)                       */
#define sifive_spi0_2_extradel_fine_Msk       (0x1f000UL)               /*!< sifive_spi0_2 extradel: fine (Bitfield-Mask: 0x1f)          */

/* ---------------------------  sifive_spi0_2_sampledel  -------------------------- */
#define sifive_spi0_2_sampledel_sd_Pos        (0UL)                     /*!< sifive_spi0_2 sampledel: sd (Bit 0)                         */
#define sifive_spi0_2_sampledel_sd_Msk        (0x1fUL)                  /*!< sifive_spi0_2 sampledel: sd (Bitfield-Mask: 0x1f)           */

/* ------------------------------  sifive_spi0_2_fmt  ----------------------------- */
#define sifive_spi0_2_fmt_proto_Pos           (0UL)                     /*!< sifive_spi0_2 fmt: proto (Bit 0)                            */
#define sifive_spi0_2_fmt_proto_Msk           (0x3UL)                   /*!< sifive_spi0_2 fmt: proto (Bitfield-Mask: 0x03)              */
#define sifive_spi0_2_fmt_endian_Pos          (2UL)                     /*!< sifive_spi0_2 fmt: endian (Bit 2)                           */
#define sifive_spi0_2_fmt_endian_Msk          (0x4UL)                   /*!< sifive_spi0_2 fmt: endian (Bitfield-Mask: 0x01)             */
#define sifive_spi0_2_fmt_dir_Pos             (3UL)                     /*!< sifive_spi0_2 fmt: dir (Bit 3)                              */
#define sifive_spi0_2_fmt_dir_Msk             (0x8UL)                   /*!< sifive_spi0_2 fmt: dir (Bitfield-Mask: 0x01)                */
#define sifive_spi0_2_fmt_len_Pos             (16UL)                    /*!< sifive_spi0_2 fmt: len (Bit 16)                             */
#define sifive_spi0_2_fmt_len_Msk             (0xf0000UL)               /*!< sifive_spi0_2 fmt: len (Bitfield-Mask: 0x0f)                */

/* ----------------------------  sifive_spi0_2_txdata  ---------------------------- */
#define sifive_spi0_2_txdata_data_Pos         (0UL)                     /*!< sifive_spi0_2 txdata: data (Bit 0)                          */
#define sifive_spi0_2_txdata_data_Msk         (0xffUL)                  /*!< sifive_spi0_2 txdata: data (Bitfield-Mask: 0xff)            */
#define sifive_spi0_2_txdata_full_Pos         (31UL)                    /*!< sifive_spi0_2 txdata: full (Bit 31)                         */
#define sifive_spi0_2_txdata_full_Msk         (0x80000000UL)            /*!< sifive_spi0_2 txdata: full (Bitfield-Mask: 0x01)            */

/* ----------------------------  sifive_spi0_2_rxdata  ---------------------------- */
#define sifive_spi0_2_rxdata_data_Pos         (0UL)                     /*!< sifive_spi0_2 rxdata: data (Bit 0)                          */
#define sifive_spi0_2_rxdata_data_Msk         (0xffUL)                  /*!< sifive_spi0_2 rxdata: data (Bitfield-Mask: 0xff)            */
#define sifive_spi0_2_rxdata_empty_Pos        (31UL)                    /*!< sifive_spi0_2 rxdata: empty (Bit 31)                        */
#define sifive_spi0_2_rxdata_empty_Msk        (0x80000000UL)            /*!< sifive_spi0_2 rxdata: empty (Bitfield-Mask: 0x01)           */

/* ----------------------------  sifive_spi0_2_txmark  ---------------------------- */
#define sifive_spi0_2_txmark_txmark_Pos       (0UL)                     /*!< sifive_spi0_2 txmark: txmark (Bit 0)                        */
#define sifive_spi0_2_txmark_txmark_Msk       (0x7UL)                   /*!< sifive_spi0_2 txmark: txmark (Bitfield-Mask: 0x07)          */

/* ----------------------------  sifive_spi0_2_rxmark  ---------------------------- */
#define sifive_spi0_2_rxmark_rxmark_Pos       (0UL)                     /*!< sifive_spi0_2 rxmark: rxmark (Bit 0)                        */
#define sifive_spi0_2_rxmark_rxmark_Msk       (0x7UL)                   /*!< sifive_spi0_2 rxmark: rxmark (Bitfield-Mask: 0x07)          */

/* -----------------------------  sifive_spi0_2_fctrl  ---------------------------- */
#define sifive_spi0_2_fctrl_en_Pos            (0UL)                     /*!< sifive_spi0_2 fctrl: en (Bit 0)                             */
#define sifive_spi0_2_fctrl_en_Msk            (0x1UL)                   /*!< sifive_spi0_2 fctrl: en (Bitfield-Mask: 0x01)               */

/* -----------------------------  sifive_spi0_2_ffmt  ----------------------------- */
#define sifive_spi0_2_ffmt_cmd_en_Pos         (0UL)                     /*!< sifive_spi0_2 ffmt: cmd_en (Bit 0)                          */
#define sifive_spi0_2_ffmt_cmd_en_Msk         (0x1UL)                   /*!< sifive_spi0_2 ffmt: cmd_en (Bitfield-Mask: 0x01)            */
#define sifive_spi0_2_ffmt_addr_len_Pos       (1UL)                     /*!< sifive_spi0_2 ffmt: addr_len (Bit 1)                        */
#define sifive_spi0_2_ffmt_addr_len_Msk       (0xeUL)                   /*!< sifive_spi0_2 ffmt: addr_len (Bitfield-Mask: 0x07)          */
#define sifive_spi0_2_ffmt_pad_cnt_Pos        (4UL)                     /*!< sifive_spi0_2 ffmt: pad_cnt (Bit 4)                         */
#define sifive_spi0_2_ffmt_pad_cnt_Msk        (0xf0UL)                  /*!< sifive_spi0_2 ffmt: pad_cnt (Bitfield-Mask: 0x0f)           */
#define sifive_spi0_2_ffmt_cmd_proto_Pos      (8UL)                     /*!< sifive_spi0_2 ffmt: cmd_proto (Bit 8)                       */
#define sifive_spi0_2_ffmt_cmd_proto_Msk      (0x300UL)                 /*!< sifive_spi0_2 ffmt: cmd_proto (Bitfield-Mask: 0x03)         */
#define sifive_spi0_2_ffmt_addr_proto_Pos     (10UL)                    /*!< sifive_spi0_2 ffmt: addr_proto (Bit 10)                     */
#define sifive_spi0_2_ffmt_addr_proto_Msk     (0xc00UL)                 /*!< sifive_spi0_2 ffmt: addr_proto (Bitfield-Mask: 0x03)        */
#define sifive_spi0_2_ffmt_data_proto_Pos     (12UL)                    /*!< sifive_spi0_2 ffmt: data_proto (Bit 12)                     */
#define sifive_spi0_2_ffmt_data_proto_Msk     (0x3000UL)                /*!< sifive_spi0_2 ffmt: data_proto (Bitfield-Mask: 0x03)        */
#define sifive_spi0_2_ffmt_cmd_code_Pos       (16UL)                    /*!< sifive_spi0_2 ffmt: cmd_code (Bit 16)                       */
#define sifive_spi0_2_ffmt_cmd_code_Msk       (0xff0000UL)              /*!< sifive_spi0_2 ffmt: cmd_code (Bitfield-Mask: 0xff)          */
#define sifive_spi0_2_ffmt_pad_code_Pos       (24UL)                    /*!< sifive_spi0_2 ffmt: pad_code (Bit 24)                       */
#define sifive_spi0_2_ffmt_pad_code_Msk       (0xff000000UL)            /*!< sifive_spi0_2 ffmt: pad_code (Bitfield-Mask: 0xff)          */

/* ------------------------------  sifive_spi0_2_ie  ------------------------------ */
#define sifive_spi0_2_ie_txwm_Pos             (0UL)                     /*!< sifive_spi0_2 ie: txwm (Bit 0)                              */
#define sifive_spi0_2_ie_txwm_Msk             (0x1UL)                   /*!< sifive_spi0_2 ie: txwm (Bitfield-Mask: 0x01)                */
#define sifive_spi0_2_ie_rxwm_Pos             (1UL)                     /*!< sifive_spi0_2 ie: rxwm (Bit 1)                              */
#define sifive_spi0_2_ie_rxwm_Msk             (0x2UL)                   /*!< sifive_spi0_2 ie: rxwm (Bitfield-Mask: 0x01)                */

/* ------------------------------  sifive_spi0_2_ip  ------------------------------ */
#define sifive_spi0_2_ip_txwm_Pos             (0UL)                     /*!< sifive_spi0_2 ip: txwm (Bit 0)                              */
#define sifive_spi0_2_ip_txwm_Msk             (0x1UL)                   /*!< sifive_spi0_2 ip: txwm (Bitfield-Mask: 0x01)                */
#define sifive_spi0_2_ip_rxwm_Pos             (1UL)                     /*!< sifive_spi0_2 ip: rxwm (Bit 1)                              */
#define sifive_spi0_2_ip_rxwm_Msk             (0x2UL)                   /*!< sifive_spi0_2 ip: rxwm (Bitfield-Mask: 0x01)                */


/* ================================================================================ */
/* ================     struct 'sifive_pwm0_2' Position & Mask     ================ */
/* ================================================================================ */


/* ----------------------------  sifive_pwm0_2_pwmcfg  ---------------------------- */
#define sifive_pwm0_2_pwmcfg_pwmscale_Pos     (0UL)                     /*!< sifive_pwm0_2 pwmcfg: pwmscale (Bit 0)                      */
#define sifive_pwm0_2_pwmcfg_pwmscale_Msk     (0xfUL)                   /*!< sifive_pwm0_2 pwmcfg: pwmscale (Bitfield-Mask: 0x0f)        */
#define sifive_pwm0_2_pwmcfg_pwmsticky_Pos    (8UL)                     /*!< sifive_pwm0_2 pwmcfg: pwmsticky (Bit 8)                     */
#define sifive_pwm0_2_pwmcfg_pwmsticky_Msk    (0x100UL)                 /*!< sifive_pwm0_2 pwmcfg: pwmsticky (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_2_pwmcfg_pwmzerocmp_Pos   (9UL)                     /*!< sifive_pwm0_2 pwmcfg: pwmzerocmp (Bit 9)                    */
#define sifive_pwm0_2_pwmcfg_pwmzerocmp_Msk   (0x200UL)                 /*!< sifive_pwm0_2 pwmcfg: pwmzerocmp (Bitfield-Mask: 0x01)      */
#define sifive_pwm0_2_pwmcfg_pwmdeglitch_Pos  (10UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmdeglitch (Bit 10)                  */
#define sifive_pwm0_2_pwmcfg_pwmdeglitch_Msk  (0x400UL)                 /*!< sifive_pwm0_2 pwmcfg: pwmdeglitch (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_2_pwmcfg_pwmenalways_Pos  (12UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmenalways (Bit 12)                  */
#define sifive_pwm0_2_pwmcfg_pwmenalways_Msk  (0x1000UL)                /*!< sifive_pwm0_2 pwmcfg: pwmenalways (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_2_pwmcfg_pwmenoneshot_Pos (13UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmenoneshot (Bit 13)                 */
#define sifive_pwm0_2_pwmcfg_pwmenoneshot_Msk (0x2000UL)                /*!< sifive_pwm0_2 pwmcfg: pwmenoneshot (Bitfield-Mask: 0x01)    */
#define sifive_pwm0_2_pwmcfg_pwmcmp0center_Pos (16UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp0center (Bit 16)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp0center_Msk (0x10000UL)              /*!< sifive_pwm0_2 pwmcfg: pwmcmp0center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp1center_Pos (17UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp1center (Bit 17)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp1center_Msk (0x20000UL)              /*!< sifive_pwm0_2 pwmcfg: pwmcmp1center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp2center_Pos (18UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp2center (Bit 18)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp2center_Msk (0x40000UL)              /*!< sifive_pwm0_2 pwmcfg: pwmcmp2center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp3center_Pos (19UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp3center (Bit 19)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp3center_Msk (0x80000UL)              /*!< sifive_pwm0_2 pwmcfg: pwmcmp3center (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp0invert_Pos (20UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp0invert (Bit 20)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp0invert_Msk (0x100000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp0invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp1invert_Pos (21UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp1invert (Bit 21)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp1invert_Msk (0x200000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp1invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp2invert_Pos (22UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp2invert (Bit 22)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp2invert_Msk (0x400000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp2invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp3invert_Pos (23UL)                   /*!< sifive_pwm0_2 pwmcfg: pwmcmp3invert (Bit 23)                */
#define sifive_pwm0_2_pwmcfg_pwmcmp3invert_Msk (0x800000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp3invert (Bitfield-Mask: 0x01)   */
#define sifive_pwm0_2_pwmcfg_pwmcmp0gang_Pos  (24UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp0gang (Bit 24)                  */
#define sifive_pwm0_2_pwmcfg_pwmcmp0gang_Msk  (0x1000000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp0gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_2_pwmcfg_pwmcmp1gang_Pos  (25UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp1gang (Bit 25)                  */
#define sifive_pwm0_2_pwmcfg_pwmcmp1gang_Msk  (0x2000000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp1gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_2_pwmcfg_pwmcmp2gang_Pos  (26UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp2gang (Bit 26)                  */
#define sifive_pwm0_2_pwmcfg_pwmcmp2gang_Msk  (0x4000000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp2gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_2_pwmcfg_pwmcmp3gang_Pos  (27UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp3gang (Bit 27)                  */
#define sifive_pwm0_2_pwmcfg_pwmcmp3gang_Msk  (0x8000000UL)             /*!< sifive_pwm0_2 pwmcfg: pwmcmp3gang (Bitfield-Mask: 0x01)     */
#define sifive_pwm0_2_pwmcfg_pwmcmp0ip_Pos    (28UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp0ip (Bit 28)                    */
#define sifive_pwm0_2_pwmcfg_pwmcmp0ip_Msk    (0x10000000UL)            /*!< sifive_pwm0_2 pwmcfg: pwmcmp0ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_2_pwmcfg_pwmcmp1ip_Pos    (29UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp1ip (Bit 29)                    */
#define sifive_pwm0_2_pwmcfg_pwmcmp1ip_Msk    (0x20000000UL)            /*!< sifive_pwm0_2 pwmcfg: pwmcmp1ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_2_pwmcfg_pwmcmp2ip_Pos    (30UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp2ip (Bit 30)                    */
#define sifive_pwm0_2_pwmcfg_pwmcmp2ip_Msk    (0x40000000UL)            /*!< sifive_pwm0_2 pwmcfg: pwmcmp2ip (Bitfield-Mask: 0x01)       */
#define sifive_pwm0_2_pwmcfg_pwmcmp3ip_Pos    (31UL)                    /*!< sifive_pwm0_2 pwmcfg: pwmcmp3ip (Bit 31)                    */
#define sifive_pwm0_2_pwmcfg_pwmcmp3ip_Msk    (0x80000000UL)            /*!< sifive_pwm0_2 pwmcfg: pwmcmp3ip (Bitfield-Mask: 0x01)       */

/* ---------------------------  sifive_pwm0_2_pwmcount  --------------------------- */
#define sifive_pwm0_2_pwmcount_pwmcount_Pos   (0UL)                     /*!< sifive_pwm0_2 pwmcount: pwmcount (Bit 0)                    */
#define sifive_pwm0_2_pwmcount_pwmcount_Msk   (0x7fffffffUL)            /*!< sifive_pwm0_2 pwmcount: pwmcount (Bitfield-Mask: 0x7fffffff) */

/* -----------------------------  sifive_pwm0_2_pwms  ----------------------------- */
#define sifive_pwm0_2_pwms_pwms_Pos           (0UL)                     /*!< sifive_pwm0_2 pwms: pwms (Bit 0)                            */
#define sifive_pwm0_2_pwms_pwms_Msk           (0xffffUL)                /*!< sifive_pwm0_2 pwms: pwms (Bitfield-Mask: 0xffff)            */

/* ----------------------------  sifive_pwm0_2_pwmcmp0  --------------------------- */
#define sifive_pwm0_2_pwmcmp0_pwmcmp0_Pos     (0UL)                     /*!< sifive_pwm0_2 pwmcmp0: pwmcmp0 (Bit 0)                      */
#define sifive_pwm0_2_pwmcmp0_pwmcmp0_Msk     (0xffffUL)                /*!< sifive_pwm0_2 pwmcmp0: pwmcmp0 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_2_pwmcmp1  --------------------------- */
#define sifive_pwm0_2_pwmcmp1_pwmcmp1_Pos     (0UL)                     /*!< sifive_pwm0_2 pwmcmp1: pwmcmp1 (Bit 0)                      */
#define sifive_pwm0_2_pwmcmp1_pwmcmp1_Msk     (0xffffUL)                /*!< sifive_pwm0_2 pwmcmp1: pwmcmp1 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_2_pwmcmp2  --------------------------- */
#define sifive_pwm0_2_pwmcmp2_pwmcmp2_Pos     (0UL)                     /*!< sifive_pwm0_2 pwmcmp2: pwmcmp2 (Bit 0)                      */
#define sifive_pwm0_2_pwmcmp2_pwmcmp2_Msk     (0xffffUL)                /*!< sifive_pwm0_2 pwmcmp2: pwmcmp2 (Bitfield-Mask: 0xffff)      */

/* ----------------------------  sifive_pwm0_2_pwmcmp3  --------------------------- */
#define sifive_pwm0_2_pwmcmp3_pwmcmp3_Pos     (0UL)                     /*!< sifive_pwm0_2 pwmcmp3: pwmcmp3 (Bit 0)                      */
#define sifive_pwm0_2_pwmcmp3_pwmcmp3_Msk     (0xffffUL)                /*!< sifive_pwm0_2 pwmcmp3: pwmcmp3 (Bitfield-Mask: 0xffff)      */



/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define riscv_clint0_0_BASE             0x02000000UL
#define riscv_plic0_0_BASE              0x0C000000UL
#define sifive_aon0_0_BASE              0x10000000UL
#define sifive_fe310_g000_prci_0_BASE   0x10008000UL
#define sifive_gpio0_0_BASE             0x10012000UL
#define sifive_uart0_0_BASE             0x10013000UL
#define sifive_spi0_0_BASE              0x10014000UL
#define sifive_pwm0_0_BASE              0x10015000UL
#define sifive_i2c0_0_BASE              0x10016000UL
#define sifive_uart0_1_BASE             0x10023000UL
#define sifive_spi0_1_BASE              0x10024000UL
#define sifive_pwm0_1_BASE              0x10025000UL
#define sifive_spi0_2_BASE              0x10034000UL
#define sifive_pwm0_2_BASE              0x10035000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define riscv_clint0_0                  ((riscv_clint0_0_Type     *) riscv_clint0_0_BASE)
#define riscv_plic0_0                   ((riscv_plic0_0_Type      *) riscv_plic0_0_BASE)
#define sifive_aon0_0                   ((sifive_aon0_0_Type      *) sifive_aon0_0_BASE)
#define sifive_fe310_g000_prci_0        ((sifive_fe310_g000_prci_0_Type *) sifive_fe310_g000_prci_0_BASE)
#define sifive_gpio0_0                  ((sifive_gpio0_0_Type     *) sifive_gpio0_0_BASE)
#define sifive_uart0_0                  ((sifive_uart0_0_Type     *) sifive_uart0_0_BASE)
#define sifive_spi0_0                   ((sifive_spi0_0_Type      *) sifive_spi0_0_BASE)
#define sifive_pwm0_0                   ((sifive_pwm0_0_Type      *) sifive_pwm0_0_BASE)
#define sifive_i2c0_0                   ((sifive_i2c0_0_Type      *) sifive_i2c0_0_BASE)
#define sifive_uart0_1                  ((sifive_uart0_1_Type     *) sifive_uart0_1_BASE)
#define sifive_spi0_1                   ((sifive_spi0_1_Type      *) sifive_spi0_1_BASE)
#define sifive_pwm0_1                   ((sifive_pwm0_1_Type      *) sifive_pwm0_1_BASE)
#define sifive_spi0_2                   ((sifive_spi0_2_Type      *) sifive_spi0_2_BASE)
#define sifive_pwm0_2                   ((sifive_pwm0_2_Type      *) sifive_pwm0_2_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group sifive_hifive1_revb */
/** @} */ /* End of group (null) */

#ifdef __cplusplus
}
#endif


#endif  /* sifive_hifive1_revb_H */

