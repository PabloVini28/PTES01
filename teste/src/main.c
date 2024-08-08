#include	"gpio.h"
#include 	"interruption.h"
#include 	"timers.h"
#include 	"uart.h"
#include 	"control_module.h"
#define DELAY_USE_INTERRUPT			1

void ledON(gpioMod, ucPinNumber, ucPinNumber);
void ledOFF(gpioMod,  ucPinNumber, ucPinNumber );
int button_press(gpioMod, ucPinNumber);


void disableWdt(void){
	HWREG(WDT_WSPR) = 0xAAAA;
	while((HWREG(WDT_WWPS) & (1<<4)));
	
	HWREG(WDT_WSPR) = 0x5555;
	while((HWREG(WDT_WWPS) & (1<<4)));
}

void ISR_Handler(void){
	/*interrupt handling*/
}

int main(void)
{
	/*-----------------------------------------------------------------------------
	 *  Desable WatchDog
	 *-----------------------------------------------------------------------------*/
	disableWdt();
	unsigned char led = 13, button = 15;
	/*-----------------------------------------------------------------------------
	 *  initialize GPIO modules
	 *-----------------------------------------------------------------------------*/
	
	Init_module_gpio(GPIO1);
	cmSetCtrlModule(CM_conf_gpmc_ben1,7);
	Init_pin_gpio(GPIO1,10,OUTPUT);
	GpioSetPinValue(GPIO1,10,HIGH);
	
	/*-----------------------------------------------------------------------------
	 *  Configure GPIO pin and multiplexing
	 *-----------------------------------------------------------------------------*/
	
	//Init_pin_gpio(GPIO1,button,INPUT);
	//Init_pin_gpio(GPIO1,led,OUTPUT);

	return 0;

} // end of function main

