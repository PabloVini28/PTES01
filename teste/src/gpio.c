#include "gpio.h"
#include "clock_module.h"
#define TOGGLE 0x01u

int Init_module_gpio(gpioMod mod){

    unsigned int aux = (1<<18) | (1<<2);
    switch (mod)
    {
    case GPIO1:
        ckmSetCLKModuleRegister(CKM_PER_GPIO1_CLKCTRL, aux);
        break;
    case GPIO2:
        ckmSetCLKModuleRegister(CKM_PER_GPIO2_CLKCTRL, aux);
        break;
    case GPIO3:
        ckmSetCLKModuleRegister(CKM_PER_GPIO2_CLKCTRL, aux);
        break;        
    default:
        break;
    }

}

int Init_pin_gpio(gpioMod mod , unsigned char pino , Direction dir){

    unsigned int aux = 0;
    switch (mod)
    {
    case GPIO1:
        aux = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
        break;
    case GPIO2:
        aux = HWREG(SOC_GPIO_2_REGS+GPIO_OE);
        break;
    case GPIO3:
        aux = HWREG(SOC_GPIO_3_REGS+GPIO_OE);
        break;        
    default:
        break;
    }

    if(dir == OUTPUT){
        aux &= ~(1<<pino);
    }else{
        aux |= (1<<pino);
    }

    return aux;

}

void GpioSetPinValue(gpioMod mod , ucPinNumber pino , Level estado){
    unsigned led = 0;

    switch (mod)
    {
    case GPIO1:
        led ^= TOGGLE;
        if(led){
            HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = (1<<pino);
        }
        else{
            HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = (1<<pino);
        }
        break;
    case GPIO2:
        led ^= TOGGLE;
        if(led){
            HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = (1<<pino);
        }
        else{
            HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = (1<<pino);
        }
        break;
    case GPIO3:
        led ^= TOGGLE;
        if(led){
            HWREG(SOC_GPIO_3_REGS+GPIO_SETDATAOUT) = (1<<pino);
        }
        else{
            HWREG(SOC_GPIO_3_REGS+GPIO_CLEARDATAOUT) = (1<<pino);
        }
        break;
    default:

        break;
    }

}