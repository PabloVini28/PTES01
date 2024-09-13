#include "marmota.h"
#include "uart.h"


extern unsigned int flag_iniciar;
unsigned int flag_reset = 0;
extern unsigned int flag_reset_acionado;

void str(unsigned int num){
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

    if(flag_reset_acionado == 0){
        HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<18);
        Pin_Interrup_Config(GPIO1,19,type0);
        numero_pontos = 0;
        GpioSetPinValue(GPIO1, 28, LOW);
        GpioSetPinValue(GPIO1, 12, LOW);
        //chamaMenuReset();
        flag_iniciar = 0;
        flag_reset = 1;
        flag_reset_acionado = 1;
    }
}

void imprimirPontuacao() {
    
    if(numero_pontos == 16){
        PontuacaoMaxima();
        acionaBuzzer();
        chamaMenuReset();
    }
    else{
        putString(UART0, "Pontuação =", 15);
        str(numero_pontos);
        putString(UART0, "\n\r\n\r", 5);
        chamaMenuReset();
    }
    reset();
}

unsigned int verificaStart(){
    return flag_iniciar;
}

void MarmotaVerde(){
   
    if(GpioGetPinValue(GPIO1,28) == HIGH){
        HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<16);
        Pin_Interrup_Config(GPIO1,14,type0);
        Pin_Interrup_Config(GPIO1,15,type0);
        Pin_Interrup_Config(GPIO1,17,type0);
        
            GpioSetPinValue(GPIO1,28,LOW);
            matouMarmotaVerde();
            numero_pontos++;
    }
    
}

void MarmotaVermelha(){
        if(GpioGetPinValue(GPIO1,12) == HIGH){
            HWREG(SOC_GPIO_1_REGS+GPIO_RISINGDETECT) &= ~(1<<17);
            Pin_Interrup_Config(GPIO1,14,type0);
            Pin_Interrup_Config(GPIO1,15,type0);
            Pin_Interrup_Config(GPIO1,16,type0);

            GpioSetPinValue(GPIO1,12,LOW);
            matouMarmotaVermelha();
            numero_pontos++;
        }
    
}

void MarmotaBranca(){
    if(GpioGetPinValue(GPIO2,1) == HIGH){
        HWREG(SOC_GPIO_1_REGS+GPIO_FALLINGDETECT) &= ~(1<<15);
        Pin_Interrup_Config(GPIO1,14,type0);
        Pin_Interrup_Config(GPIO1,16,type0);
        Pin_Interrup_Config(GPIO1,17,type0);
        Pin_Interrup_Config(GPIO1,18,type0);
        Pin_Interrup_Config(GPIO1,19,type0);
        GpioSetPinValue(GPIO2,1,LOW);
        matouMarmotaBranca();
        numero_pontos++;
    }
}

void MarmotaAzul(){
    if(GpioGetPinValue(GPIO2,2) == HIGH){
        HWREG(SOC_GPIO_2_REGS+GPIO_RISINGDETECT) &= ~(1<<14);
        Pin_Interrup_Config(GPIO1,15,type0);
        Pin_Interrup_Config(GPIO1,16,type0);
        Pin_Interrup_Config(GPIO1,17,type0);
        GpioSetPinValue(GPIO2,2,LOW);
        matouMarmotaAzul();
        numero_pontos++;
    }
}

void acionaBuzzer(){
    GpioSetPinValue(GPIO1, 13, HIGH);
    for(int i = 0; i < 100000000; i++);
    GpioSetPinValue(GPIO1, 13, LOW);
}

void decrementa_ponto(){
    if (numero_pontos > 0)
    {
        numero_pontos--;
    }    
}