#include "marmota.h"
#include "uart.h"

extern unsigned int numero_pontos;
extern unsigned int flag_iniciar;
unsigned int flag_reset = 0;

void str(unsigned int num){
    /*char resultado[3];
    resultado[0] = num/10;
    resultado[1] = num%10;
    resultado[0] += '0';
    resultado[1] += '0';
    putString(UART0,resultado,3);
    */
   putCh(UART0,(numero_pontos/10)+'0');
   putCh(UART0,numero_pontos%10 + '0');
}

void start(){
    HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<19);
    Pin_Interrup_Config(GPIO1,18,type0);
    numero_pontos = 0;
    GpioSetPinValue(GPIO1, 28, LOW);
    GpioSetPinValue(GPIO1, 12, LOW);
    chamaMenuPrincipal();
    flag_iniciar = 1;
    flag_reset = 0;
}

void reset(){
    HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<18);
    Pin_Interrup_Config(GPIO1,19,type0);
    numero_pontos = 0;
    GpioSetPinValue(GPIO1, 28, LOW);
    GpioSetPinValue(GPIO1, 12, LOW);
    chamaMenuReset();
    flag_iniciar = 0;
    flag_reset = 1;
    imprimirPontuacao();
}

void imprimirPontuacao() {
    putString(UART0, "Pontuação =", 15);
    str(numero_pontos);
    putString(UART0, "\n\r\n\r", 5);
}

unsigned int verificaStart(){
    return flag_iniciar;
}

void MarmotaVerde(){
   
    if(GpioGetPinValue(GPIO1,28) == HIGH){
            GpioSetPinValue(GPIO1,28,LOW);
            matouMarmotaVerde();
            numero_pontos++;
    }
    
}

void MarmotaVermelha(){
        if(GpioGetPinValue(GPIO1,12) == HIGH){
            GpioSetPinValue(GPIO1,12,LOW);
            matouMarmotaVermelha();
            numero_pontos++;
        }
    
}

void MarmotaAmarela(){
    if(GpioGetPinValue(GPIO2,1) == HIGH){
        GpioSetPinValue(GPIO2,1,LOW);
        matouMarmotaAmarela();
        numero_pontos++;
    }
}

void MarmotaAzul(){
    if(GpioGetPinValue(GPIO2,2) == HIGH){
        GpioSetPinValue(GPIO2,2,LOW);
        matouMarmotaAzul();
        numero_pontos++;
    }
}
