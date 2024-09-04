#include "marmota.h"

extern unsigned int numero_pontos;
unsigned int flag_iniciar = 0;

void start(){
    numero_pontos = 0;
    HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_0) |= (1<<19);
    GpioSetPinValue(GPIO1, 28, LOW);
    GpioSetPinValue(GPIO1, 12, LOW);
    flag_iniciar = 1;
}

void reset(){
    numero_pontos = 0;
    GpioSetPinValue(GPIO1, 28, LOW);
    GpioSetPinValue(GPIO1, 12, LOW);
    flag_iniciar = false;
}

unsigned int verificaStart(){
    return flag_iniciar;
}

void MarmotaVerde(){
   
    if(GpioGetPinValue(GPIO1,28) == HIGH){
            GpioSetPinValue(GPIO1,28,LOW);
            numero_pontos++;
    }
    
}

void MarmotaVermelha(){
        if(GpioGetPinValue(GPIO1,12) == HIGH){
            GpioSetPinValue(GPIO1,12,LOW);
            numero_pontos++;
        }
    
}