#include "gpio.h"
#include "clock_module.h"

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
        ckmSetCLKModuleRegister(CKM_PER_GPIO3_CLKCTRL, aux);
        break;        
    default:
        break;
    }

    return 1;

}

int Init_pin_gpio(gpioMod mod , unsigned char pino , Direction dir){

    unsigned int aux = 0;
    switch (mod)
    {
    case GPIO0:
        aux = HWREG(SOC_GPIO_0_REGS+GPIO_OE);
        break;
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
    
    switch (mod)
    {
    case GPIO0:
        HWREG(SOC_GPIO_0_REGS+GPIO_OE) = aux;
        break;
    case GPIO1:
        HWREG(SOC_GPIO_1_REGS+GPIO_OE) = aux;
        break;
    case GPIO2:
        HWREG(SOC_GPIO_2_REGS+GPIO_OE) = aux;
        break;
    case GPIO3:
        HWREG(SOC_GPIO_3_REGS+GPIO_OE) = aux;
        break;
    default:
        break;
    }
    return 1;
}

unsigned int Get_direction_pin_gpio(gpioMod mod , unsigned char pino){
    
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
    
        if((aux & (1<<pino)) != 0){
            return INPUT;
        }else{
            return OUTPUT;
        }
}

void GpioSetPinValue(gpioMod mod , ucPinNumber pino, Level estado){

    switch (mod)
    {
    case GPIO1:
        if(estado == HIGH){
            HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = (1<<pino);
        }else{
            HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = (1<<pino);
        }
        break;
    case GPIO2:
        if(estado == HIGH){
            HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = (1<<pino);
        }else{
            HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = (1<<pino);
        }
        break;
    case GPIO3:
        if(estado == HIGH){
            HWREG(SOC_GPIO_3_REGS+GPIO_SETDATAOUT) = (1<<pino);
        }else{
            HWREG(SOC_GPIO_3_REGS+GPIO_CLEARDATAOUT) = (1<<pino);
        }
        break;            
    default:
        break;
    }
}

unsigned int GpioGetPinValue(gpioMod mod, ucPinNumber pino){

    switch (mod)
    {
    case GPIO1:
        if(((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<pino))) != 0){
		    return HIGH;
	    }else{
            return LOW;  
        }    
        break;
    case GPIO2:
        if(((HWREG(SOC_GPIO_2_REGS+GPIO_DATAIN) & (1<<pino))) != 0){
            return HIGH;
        }else{
            return LOW;  
        }    
        break;
    case GPIO3:
        if(((HWREG(SOC_GPIO_3_REGS+GPIO_DATAIN) & (1<<pino))) != 0){
            return HIGH;
        }else{
            return LOW;  
        }    
        break;        
    
    default:
        return LOW; 
    }
}

int gpioIsrHandler(gpioMod mod , GroupInterrup tipo, ucPinNumber pino){

    switch (mod)
    {
    case GPIO0:
        if(tipo == type0){
            HWREG(SOC_GPIO_0_REGS+GPIO_IRQSTATUS_0) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_0_REGS+GPIO_IRQSTATUS_1) |= (1<<pino);
        }
        break;
    case GPIO1:
        if(tipo == type0){
            HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_0) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_1) |= (1<<pino);
        }
        break;
    case GPIO2:
        if(tipo == type0){
            HWREG(SOC_GPIO_2_REGS+GPIO_IRQSTATUS_0) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_2_REGS+GPIO_IRQSTATUS_1) |= (1<<pino);
        }
        break;        
    case GPIO3:
        if(tipo == type0){
            HWREG(SOC_GPIO_3_REGS+GPIO_IRQSTATUS_0) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_3_REGS+GPIO_IRQSTATUS_1) |= (1<<pino);
        }
        break;
    default:
        break;
    }

    return 1;

}

int Pin_Interrup_Config(gpioMod  mod, ucPinNumber pino, GroupInterrup tipo){

    switch (mod)
    {
    case GPIO0:
        if(tipo == type0){
            HWREG(SOC_GPIO_0_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pino);
            HWREG(SOC_GPIO_0_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_0_REGS+GPIO_IRQSTATUS_SET_1) |= (1<<pino);
            HWREG(SOC_GPIO_0_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }     
        break;
    case GPIO1:
        if(tipo == type0){
            HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pino);
            HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) |= (1<<pino);

        }else{
            HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_SET_1) |= (1<<pino);
            HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }     
        break;
    case GPIO2:
        if(tipo == type0){
            HWREG(SOC_GPIO_2_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pino);
            HWREG(SOC_GPIO_2_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_2_REGS+GPIO_IRQSTATUS_SET_1) |= (1<<pino);
            HWREG(SOC_GPIO_2_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }     
        break;
    case GPIO3:
        if(tipo == type0){
            HWREG(SOC_GPIO_3_REGS+GPIO_IRQSTATUS_SET_0) |= (1<<pino);
            HWREG(SOC_GPIO_3_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }else{
            HWREG(SOC_GPIO_3_REGS+GPIO_IRQSTATUS_SET_1) |= (1<<pino);
            HWREG(SOC_GPIO_3_REGS+GPIO_RISINGDETECT) |= (1<<pino);
        }     
        break;        
    
    default:
        break;
    }

    return 1;
    
}

void Debounce(gpioMod mod){
 
    switch (mod)
    {
    case GPIO0:
        HWREG(SOC_GPIO_0_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<16);
        HWREG(SOC_GPIO_0_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<17);
        HWREG(SOC_GPIO_0_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<18);
        HWREG(SOC_GPIO_0_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<19);
        break;
    case GPIO1:
        HWREG(SOC_GPIO_1_REGS+GPIO_DEBOUNCENABLE) &= (0x3f<<14); // 0011 1111
        HWREG(SOC_GPIO_1_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<16);
        HWREG(SOC_GPIO_1_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<17);
        HWREG(SOC_GPIO_1_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<18);
        HWREG(SOC_GPIO_1_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<19);
        break;   
    case GPIO2:
        HWREG(SOC_GPIO_2_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<16);
        HWREG(SOC_GPIO_2_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<17);
        HWREG(SOC_GPIO_2_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<18);
        HWREG(SOC_GPIO_2_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<19);
        break;
    case GPIO3:
        HWREG(SOC_GPIO_3_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<16);
        HWREG(SOC_GPIO_3_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<17);
        HWREG(SOC_GPIO_3_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<18);
        HWREG(SOC_GPIO_3_REGS+GPIO_DEBOUNCENABLE) &= (0xf<<19);
        break;    
    default:
        break;
    }
}

