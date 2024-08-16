	#include	"gpio.h"
	#include 	"interruption.h"
	#include 	"timers.h"
	#include 	"uart.h"
	#include 	"control_module.h"
	#include <stdio.h>
	#define DELAY_USE_INTERRUPT			1

	#define DELAY_MS(ms) for(unsigned int i = 0; i < (ms * 100000); i++)

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
		Init_module_gpio(GPIO2);

		cmSetCtrlModule(CM_conf_gpmc_ad12,7);
		cmSetCtrlModule(CM_conf_gpmc_ben1,7); 
		cmSetCtrlModule(CM_conf_gpmc_a0,7); 
		cmSetCtrlModule(CM_conf_gpmc_a1,7); 

		cmSetCtrlModule(CM_conf_gpmc_clk,7);
		cmSetCtrlModule(CM_conf_gpmc_advn_ale,7);

		//leds externos
		Init_pin_gpio(GPIO1, 12, OUTPUT);
		Init_pin_gpio(GPIO1, 28, OUTPUT);
		Init_pin_gpio(GPIO1, 16, OUTPUT);
		Init_pin_gpio(GPIO1, 17, OUTPUT);

		Init_pin_gpio(GPIO2, 1,INPUT);
		Init_pin_gpio(GPIO2, 2,INPUT);

		while(1){
			
				// leds externos
				if((GpioGetPinValue(GPIO2, 1) == 0) && (GpioGetPinValue(GPIO2, 2) == 0)){
					GpioSetPinValue(GPIO1, 12, LOW);
					GpioSetPinValue(GPIO1,28,LOW);
					GpioSetPinValue(GPIO1, 16, LOW);
					GpioSetPinValue(GPIO1, 17, LOW);
				}

				if((GpioGetPinValue(GPIO2, 1) == 1) && (GpioGetPinValue(GPIO2, 2) == 1)){
					GpioSetPinValue(GPIO1, 12, HIGH);
					GpioSetPinValue(GPIO1,28,HIGH);
					GpioSetPinValue(GPIO1, 16, LOW);
					GpioSetPinValue(GPIO1, 17, HIGH);
				}
				else if((GpioGetPinValue(GPIO2, 1) == 1) | (GpioGetPinValue(GPIO2, 2) == 1)){
					GpioSetPinValue(GPIO1, 28, HIGH);
					GpioSetPinValue(GPIO1, 16, HIGH);
					GpioSetPinValue(GPIO1,17,LOW);
					GpioSetPinValue(GPIO1,12,LOW);
				}
		}
		return 0;
	}
		
