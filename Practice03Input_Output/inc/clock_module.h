#ifndef __CLOCK_MODULE_H
#define __CLOCK_MODULE_H

/*
 * =====================================================================================
 *
 *       Filename:  clock_module.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/02/2022 10:50:03
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author: José Adrian 
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */


/*-----------------------------------------------------------------------------
 *  ENUM
 *-----------------------------------------------------------------------------*/
typedef enum _CKM_MODULE_REG{
   // CKM_PER zone
	CKM_PER_L4LS_CLKSTCTRL      = 0x000,
   CKM_PER_L3S_CLKSTCTRL       = 0x004,
   CKM_PER_L4FW_CLKSTCTRL      = 0x008,
   CKM_PER_L3_CLKSTCTRL        = 0x00C,
   CKM_PER_CPGMAC0_CLKCTRL     = 0x014,
   CKM_PER_LCDC_CLKCTRL        = 0x018,
   CKM_PER_USB0_CLKCTRL        = 0x01C,
   CKM_PER_TPTC0_CLKCTRL       = 0x024,
   CKM_PER_EMIF_CLKCTRL        = 0x028,
   CKM_PER_OCMCRAM_CLKCTRL     = 0x02C,
   CKM_PER_GPMC_CLKCTRL        = 0x030,
   CKM_PER_MCASP0_CLKCTRL      = 0x034,
   CKM_PER_UART5_CLKCTRL       = 0x038,
   CKM_PER_MMC0_CLKCTRL        = 0x03C,
   CKM_PER_ELM_CLKCTRL         = 0x040,
   CKM_PER_I2C2_CLKCTRL        = 0x044,
   CKM_PER_I2C1_CLKCTRL        = 0x048,
   CKM_PER_SPI0_CLKCTRL        = 0x04C,
   CKM_PER_SPI1_CLKCTRL        = 0x050,
   CKM_PER_L4LS_CLKCTRL        = 0x060,
   CKM_PER_L4FW_CLKCTRL        = 0x064,
   CKM_PER_MCASP1_CLKCTRL      = 0x068,
   CKM_PER_UART1_CLKCTRL       = 0x06C,
   CKM_PER_UART2_CLKCTRL       = 0x070,
   CKM_PER_UART3_CLKCTRL       = 0x074,
   CKM_PER_UART4_CLKCTRL       = 0x078,
   CKM_PER_TIMER7_CLKCTRL      = 0x07C,
   CKM_PER_TIMER2_CLKCTRL      = 0x080,
   CKM_PER_TIMER3_CLKCTRL      = 0x084,
   CKM_PER_TIMER4_CLKCTRL      = 0x088,
   CKM_PER_GPIO1_CLKCTRL       = 0x0AC,
   CKM_PER_GPIO2_CLKCTRL       = 0x0B0,
   CKM_PER_GPIO3_CLKCTRL       = 0x0B4,
   CKM_PER_TPCC_CLKCTRL        = 0x0BC,
   CKM_PER_DCAN0_CLKCTRL       = 0x0C0,
   CKM_PER_DCAN1_CLKCTRL       = 0x0C4,
   CKM_PER_EPWMSS1_CLKCTRL     = 0x0CC,
   CKM_PER_EMIF_FW_CLKCTRL     = 0x0D0,
   CKM_PER_EPWMSS0_CLKCTRL     = 0x0D4,
   CKM_PER_EPWMSS2_CLKCTRL     = 0x0D8,
   CKM_PER_L3_INSTR_CLKCTRL    = 0x0DC,
   CKM_PER_L3_CLKCTRL          = 0x0E0,
   CKM_PER_IEEE5000_CLKCTRL    = 0x0E4,
   CKM_PER_PRU_ICSS_CLKCTRL    = 0x0E8,
   CKM_PER_TIMER5_CLKCTRL      = 0x0EC,
   CKM_PER_TIMER6_CLKCTRL      = 0x0F0,
   CKM_PER_MMC1_CLKCTRL        = 0x0F4,
   CKM_PER_MMC2_CLKCTRL        = 0x0F8,
   CKM_PER_TPTC1_CLKCTRL       = 0x0FC,
   CKM_PER_TPTC2_CLKCTRL       = 0x100,
   CKM_PER_SPINLOCK_CLKCTRL    = 0x10C,
   CKM_PER_MAILBOX0_CLKCTRL    = 0x110,
   CKM_PER_L4HS_CLKSTCTRL      = 0x11C,
   CKM_PER_L4HS_CLKCTRL        = 0x120,
   CKM_PER_OCPWP_L3_CLKSTCTRL  = 0x12C,
   CKM_PER_OCPWP_CLKCTRL       = 0x130,
   CKM_PER_PRU_ICSS_CLKSTCTRL  = 0x140,
   CKM_PER_CPSW_CLKSTCTRL      = 0x144,
   CKM_PER_LCDC_CLKSTCTRL      = 0x148,
   CKM_PER_CLKDIV32K_CLKCTRL   = 0x14C,
   CKM_PER_CLK_24MHZ_CLKSTCTRL = 0x150,
	    // CKM_WKUP zone
   CKM_WKUP_CLKSTCTRL            = 0x00,
   CKM_WKUP_CONTROL_CLKCTRL      = 0x04,
   CKM_WKUP_GPIO0_CLKCTRL        = 0x08,
   CKM_WKUP_L4WKUP_CLKCTRL       = 0x0C,
   CKM_WKUP_TIMER0_CLKCTRL       = 0x10,
   CKM_WKUP_DEBUGSS_CLKCTRL      = 0x14,
   CKM_L3_AON_CLKSTCTRL          = 0x18,
   CKM_AUTOIDLE_DPLL_MPU         = 0x1C,
   CKM_IDLEST_DPLL_MPU           = 0x20,
   CKM_SSC_DELTAMSTEP_DPLL_MPU   = 0x24,
   CKM_SSC_MODFREQDIV_DPLL_MPU   = 0x28,
   CKM_CLKSEL_DPLL_MPU           = 0x2C,
   CKM_AUTOIDLE_DPLL_DDR         = 0x30,
   CKM_IDLEST_DPLL_DDR           = 0x34,
   CKM_SSC_DELTAMSTEP_DPLL_DDR   = 0x38,
   CKM_SSC_MODFREQDIV_DPLL_DDR   = 0x3C,
   CKM_CLKSEL_DPLL_DDR           = 0x40,
   CKM_AUTOIDLE_DPLL_DISP        = 0x44,
   CKM_IDLEST_DPLL_DISP          = 0x48,
   CKM_SSC_DELTAMSTEP_DPLL_DISP  = 0x4C,
   CKM_SSC_MODFREQDIV_DPLL_DISP  = 0x50,
   CKM_CLKSEL_DPLL_DISP          = 0x54,
   CKM_AUTOIDLE_DPLL_CORE        = 0x58,
   CKM_IDLEST_DPLL_CORE          = 0x5C,
   CKM_SSC_DELTAMSTEP_DPLL_CORE  = 0x60,
   CKM_SSC_MODFREQDIV_DPLL_CORE  = 0x64,
   CKM_CLKSEL_DPLL_CORE          = 0x68,
   CKM_AUTOIDLE_DPLL_PER         = 0x6C,
   CKM_IDLEST_DPLL_PER           = 0x70,
   CKM_SSC_DELTAMSTEP_DPLL_PER   = 0x74,
   CKM_SSC_MODFREQDIV_DPLL_PER   = 0x78,
   CKM_CLKDCOLDO_DPLL_PER        = 0x7C,
   CKM_DIV_M4_DPLL_CORE          = 0x80,
   CKM_DIV_M5_DPLL_CORE          = 0x84,
   CKM_CLKMODE_DPLL_MPU          = 0x88,
   CKM_CLKMODE_DPLL_PER          = 0x8C,
   CKM_CLKMODE_DPLL_CORE         = 0x90,
   CKM_CLKMODE_DPLL_DDR          = 0x94,
   CKM_CLKMODE_DPLL_DISP         = 0x98,
   CKM_CLKSEL_DPLL_PERIPH        = 0x9C,
   CKM_DIV_M2_DPLL_DDR           = 0xA0,
   CKM_DIV_M2_DPLL_DISP          = 0xA4,
   CKM_DIV_M2_DPLL_MPU           = 0xA8,
   CKM_DIV_M2_DPLL_PER           = 0xAC,
   CKM_WKUP_WKUP_M3_CLKCTRL      = 0xB0,
   CKM_WKUP_UART0_CLKCTRL        = 0xB4,
   CKM_WKUP_I2C0_CLKCTRL         = 0xB8,
   CKM_WKUP_ADC_TSC_CLKCTRL      = 0xBC,
   CKM_WKUP_SMARTREFLEX0_CLKCTRL = 0xC0,
   CKM_WKUP_TIMER1_CLKCTRL       = 0xC4,
   CKM_WKUP_SMARTREFLEX1_CLKCTRL = 0xC8,
   CKM_L4_WKUP_AON_CLKSTCTRL     = 0xCC,
   CKM_WKUP_WDT1_CLKCTRL         = 0xD4,
   CKM_DIV_M6_DPLL_CORE          = 0xD8
}CKM_MODULE_REG;


#define CONTROL_CONF_GPMC_MMODE   					(0x00000007u)
#define CONTROL_CONF_GPMC_MMODE_SHIFT   		(0x00000000u)

#define CONTROL_CONF_GPMC_PUDEN   					(0x00000008u)
#define CONTROL_CONF_GPMC_PUDEN_SHIFT   		(0x00000003u)

#define CONTROL_CONF_GPMC_PUTYPESEL   			(0x00000010u)
#define CONTROL_CONF_GPMC_PUTYPESEL_SHIFT   (0x00000004u)

#define CONTROL_CONF_GPMC_RSVD   						(0x000FFF80u)
#define CONTROL_CONF_GPMC_RSVD_SHIFT   			(0x00000007u)

#define CONTROL_CONF_GPMC_RXACTIVE   				(0x00000020u)
#define CONTROL_CONF_GPMC_RXACTIVE_SHIFT   	(0x00000005u)

#define CONTROL_CONF_GPMC_SLEWCTRL   				(0x00000040u)
#define CONTROL_CONF_GPMC_SLEWCTRL_SHIFT   	(0x00000006u)



/*-----------------------------------------------------------------------------
 *  Function prototype
 *-----------------------------------------------------------------------------*/
void ckmSetCLKModuleRegister(CKM_MODULE_REG module, unsigned int value);
unsigned int ckmGetCLKModuleRegister(CKM_MODULE_REG module);

#endif /* __CLOCK_MODULE__H */

