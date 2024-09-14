#include "gpio.h"
#include "clock_module.h"
#include "interruption.h"
#include "marmota.h"
unsigned int interrupts; 

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


void disableAzul(){
    HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<14);
    Pin_Interrup_Config(GPIO1,15,type0);
    Pin_Interrup_Config(GPIO1,16,type0);
    Pin_Interrup_Config(GPIO1,17,type0);
}
void disableBranca(){
    HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<15);
    Pin_Interrup_Config(GPIO1,14,type0);
    Pin_Interrup_Config(GPIO1,16,type0);
    Pin_Interrup_Config(GPIO1,17,type0);
}
void disableVerde(){
    HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<16);
    Pin_Interrup_Config(GPIO1,14,type0);
    Pin_Interrup_Config(GPIO1,15,type0);
    Pin_Interrup_Config(GPIO1,17,type0);
}
void disableVermelha(){
    HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<17);
    Pin_Interrup_Config(GPIO1,14,type0);
    Pin_Interrup_Config(GPIO1,15,type0);
    Pin_Interrup_Config(GPIO1,16,type0);
}

void gpioHandler(){
    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 14)) {
        
        if(GpioGetPinValue(GPIO2,2)==HIGH){
            MarmotaAzul();
        }
        disableAzul();
        gpioIsrHandler(GPIO1, type0, 14);
        interrupts++;   
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 15)) {
        
        if(GpioGetPinValue(GPIO2,1)==HIGH){
            MarmotaBranca();
        }
        disableBranca();
        gpioIsrHandler(GPIO1, type0, 15);
        interrupts++;
        
    }
    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 16)) {
        
        if(GpioGetPinValue(GPIO1,28)==HIGH){
            MarmotaVerde();
        }
        disableVerde();
        gpioIsrHandler(GPIO1, type0, 16);
        interrupts++;
        
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 17)) {
        
        if(GpioGetPinValue(GPIO1,12)==HIGH){
            MarmotaVermelha();
        }
        disableVermelha();
        gpioIsrHandler(GPIO1, type0,17);
        interrupts++;
        
    }
    
    if(HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 18)){
        gpioIsrHandler(GPIO1,type0,18);
        reset();
    }
    if(HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 19)){  
        gpioIsrHandler(GPIO1,type0,19);
        start();
    }
}