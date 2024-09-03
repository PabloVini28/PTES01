#include "marmota.h"

extern unsigned int numero_pontos;
bool flag_iniciar = false;

void start(){
    numero_pontos = 0;
    GpioSetPinValue(GPIO1, 28, LOW);
    GpioSetPinValue(GPIO1, 12, LOW);
    flag_iniciar = true;
}

void reset(){
    numero_pontos = 0;
    GpioSetPinValue(GPIO1, 28, LOW);
    GpioSetPinValue(GPIO1, 12, LOW);
    flag_iniciar = false;
}

bool verificaStart(){
    return flag_iniciar;
}

void MarmotaVerde(){
    if((SOC_GPIO_1_REGS+GPIO_IRQSTATUS_RAW_0) & (1 << 16)){
        gpioIsrHandler(GPIO1,type0,16);
        if(GpioGetPinValue(GPIO1,28) == HIGH){
            GpioSetPinValue(GPIO1,28,LOW);
            numero_pontos++;
        }
    }
}

void MarmotaVermelha(){
    if((SOC_GPIO_1_REGS+GPIO_IRQSTATUS_RAW_0) & (1 << 17)){
        gpioIsrHandler(GPIO1,type0,17);
        if(GpioGetPinValue(GPIO1,12) == HIGH){
            GpioSetPinValue(GPIO1,12,LOW);
            numero_pontos++;
        }
    }
}