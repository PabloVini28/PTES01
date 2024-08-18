	#include	"gpio.h"
	#include 	"interruption.h"
	#include 	"timers.h"
	#include 	"uart.h"
	#include 	"control_module.h"
	#include <stdio.h>
	#define DELAY_USE_INTERRUPT			1

	void disableWdt(void){
		HWREG(WDT_WSPR) = 0xAAAA;
		while((HWREG(WDT_WWPS) & (1<<4)));
		
		HWREG(WDT_WSPR) = 0x5555;
		while((HWREG(WDT_WWPS) & (1<<4)));
	}

	int main(void)
	{
		
		disableWdt();
		Init_module_gpio(GPIO1);

		cmSetCtrlModule(CM_conf_gpmc_a5,7);
		cmSetCtrlModule(CM_conf_gpmc_a6,7);
		cmSetCtrlModule(CM_conf_gpmc_a7,7);
		cmSetCtrlModule(CM_conf_gpmc_a8,7);

		//leds externos
		Init_pin_gpio(GPIO1, 21, OUTPUT);
		Init_pin_gpio(GPIO1, 22, OUTPUT);
		Init_pin_gpio(GPIO1, 23, OUTPUT);
		Init_pin_gpio(GPIO1, 24, OUTPUT);

		

		while(true){
			timerSetup(TIMER2);
			GpioSetPinValue(GPIO1, 21, HIGH);
			GpioSetPinValue(GPIO1, 22, HIGH);
			GpioSetPinValue(GPIO1, 23, HIGH);
			GpioSetPinValue(GPIO1, 24, HIGH);
			delay(100,TIMER2);
			GpioSetPinValue(GPIO1, 21, LOW);
			GpioSetPinValue(GPIO1, 22, LOW);
			GpioSetPinValue(GPIO1, 23, LOW);
			GpioSetPinValue(GPIO1, 24, LOW);
			delay(100,TIMER2);
		}
		return 0;
	}
		
