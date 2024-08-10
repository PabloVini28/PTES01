#ifndef GPIO_H_
#define GPIO_H_

#include "clock_module.h"
#include "control_module.h"
#include "pad.h"
#include "soc_AM335x.h"
#include "hw_types.h"

/**
 * @brief Clock Modules Domaines bases: TRM 2.1
 **/
typedef enum _CKM_MODULE{
   CKM_PER     = SOC_CM_PER_REGS,
   CKM_WKUP    = SOC_CM_WKUP_REGS,
   CKM_DPLL    = SOC_CM_DPLL_REGS,
   CKM_MPU     = SOC_CM_MPU_REGS,
   CKM_DEVICE  = SOC_CM_DEVICE_REGS,
   CKM_RTC     = SOC_CM_RTC_REGS,
   CKM_GFX     = SOC_CM_GFX_REGS,
   CKM_CEFUSE  = SOC_CM_CEFUSE_REGS
}CKM_MODULE;

#define GPIO_REVISION           0x000
#define GPIO_SYSCONFIG          0x010
#define GPIO_EOI                0x020
#define GPIO_IRQSTATUS_RAW_0    0x024
#define GPIO_IRQSTATUS_RAW_1    0x028
#define GPIO_IRQSTATUS_0        0x02C
#define GPIO_IRQSTATUS_1        0x030
#define GPIO_IRQSTATUS_SET_0    0x034
#define GPIO_IRQSTATUS_SET_1    0x038
#define GPIO_IRQSTATUS_CLR_0    0x03C
#define GPIO_IRQSTATUS_CLR_1    0x040
#define GPIO_IRQWAKEN_0         0x044
#define GPIO_IRQWAKEN_1         0x048
#define GPIO_SYSSTATUS          0x114
#define GPIO_CTRL               0x130
#define GPIO_OE                 0x134
#define GPIO_DATAIN             0x138
#define GPIO_DATAOUT            0x13C
#define GPIO_LEVELDETECT0       0x140
#define GPIO_LEVELDETECT1       0x144
#define GPIO_RISINGDETECT       0x148
#define GPIO_FALLINGDETECT      0x14C
#define GPIO_DEBOUNCENABLE      0x150
#define GPIO_DEBOUNCINGTIME     0x154
#define GPIO_CLEARDATAOUT       0x190
#define GPIO_SETDATAOUT         0x194

typedef enum _pinNum{
	PIN1=0,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	PIN16,
	PIN17,
	PIN18,
	PIN19,
	PIN20,
	PIN21,
	PIN22,
	PIN23,
	PIN24,
	PIN25,
	PIN26,
	PIN27,
	PIN28,
	PIN29,
	PIN30,
	PIN31,
}pinNum;


/*-----------------------------------------------------------------------------
 *  GPIO pin number type (0-31)
 *-----------------------------------------------------------------------------*/
typedef unsigned char ucPinNumber;


typedef enum GroupInterrup{
    type0 = 0,
    type1
}GroupInterrup;	/* ----------  end of enum GroupInterrup  ---------- */

typedef enum Level{
	LOW,
	HIGH
}Level;				/* ----------  end of enum pinLevel  ---------- */


typedef enum gpioMod{
	GPIO0,
	GPIO1,
	GPIO2,
	GPIO3
}gpioMod;				/* ----------  end of enum gpioMod  ---------- */

typedef enum Direction{
	OUTPUT,
	INPUT
}Direction;				/* ----------  end of enum pinDirection  ---------- */

int Init_module_gpio(gpioMod);
int Init_pin_gpio(gpioMod , unsigned char , Direction);
static void Set_direction_pin_gpio(gpioMod, Direction, unsigned char);
unsigned int Get_direction_pin_gpio(gpioMod , unsigned char);
void GpioSetPinValue(gpioMod , ucPinNumber , Level);
unsigned int GpioGetPinValue(gpioMod , ucPinNumber);
int gpioIsrHandler(gpioMod , GroupInterrup , ucPinNumber);
int Pin_Interrup_Config(gpioMod , ucPinNumber , GroupInterrup);

/*-----------------------------------------------------------------------------
 *  Function prototype
 *-----------------------------------------------------------------------------*/

	
#endif /*GPIO_H_ */
