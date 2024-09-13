#include "marmota.h"

void PiscaLed01();
void PiscaLed02();
void PiscaLed03();
void PiscaLed04();

unsigned int numero_pontos = 0;
unsigned int flag_iniciar;
unsigned int flag_reset_acionado = 0;

int main() {

    disableWdt();

    Init_module_gpio(GPIO1);
    Init_module_gpio(GPIO2);

    cmSetCtrlModule(CM_conf_gpmc_ben1, 7); // led
    cmSetCtrlModule(CM_conf_gpmc_ad12, 7); // led
    cmSetCtrlModule(CM_conf_gpmc_clk,7); // led
    cmSetCtrlModule(CM_conf_gpmc_advn_ale,7) ; // led
    cmSetCtrlModule(CM_conf_gpmc_ad13,7); // buzzer

    cmSetCtrlModule(CM_conf_gpmc_a1, 7); // botão
    cmSetCtrlModule(CM_conf_gpmc_a0, 7); // botão
    cmSetCtrlModule(CM_conf_gpmc_a2,7); // botão
    cmSetCtrlModule(CM_conf_gpmc_a3,7); // botão
    cmSetCtrlModule(CM_conf_gpmc_ad14,7); // botão
    cmSetCtrlModule(CM_conf_gpmc_ad15,7); // botão
    
    Init_pin_gpio(GPIO1,28, OUTPUT); //p9 ; 12 
    Init_pin_gpio(GPIO1,12, OUTPUT); //p8 ; 12
    Init_pin_gpio(GPIO2,1,OUTPUT); //p8 ; 18
    Init_pin_gpio(GPIO2,2,OUTPUT); // p8 ; 7
    Init_pin_gpio(GPIO1,13,OUTPUT); // p8 ; 

    Init_pin_gpio(GPIO1,14,INPUT); //p8 ; 16  azul
    Init_pin_gpio(GPIO1,15,INPUT); //p8 ; 15 branca = amarela
    Init_pin_gpio(GPIO1,16,INPUT); //p9 ; 15 verde
    Init_pin_gpio(GPIO1,17, INPUT); //p9 ; 23  marmota vermelha
    Init_pin_gpio(GPIO1,18,INPUT); //p9 ; 14  reset
    Init_pin_gpio(GPIO1,19,INPUT); //p9 ; 16 start

    Debounce(GPIO1);

    timerSetup(TIMER7);

    Interrupt_Setup(98);
    Interrupt_Setup(95);

    Pin_Interrup_Config(GPIO1,14,type0);
    Pin_Interrup_Config(GPIO1,15,type0);
    Pin_Interrup_Config(GPIO1,16,type0);
    Pin_Interrup_Config(GPIO1,17,type0); // tipo A = type0 B = type1
    Pin_Interrup_Config(GPIO1,19,type0);
    flag_iniciar = 0;
    
    while(true) {
        if(verificaStart()){
            flag_reset_acionado = 0;
            PiscaLed01();
            PiscaLed02();
            PiscaLed03();
            PiscaLed04();
            imprimirPontuacao();
        }  
            
    }
    return 0;
}

void PiscaLed01(){

    
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO2,1,HIGH);
    delay(1000,TIMER7);
    GpioSetPinValue(GPIO2,1,LOW);
    delay(1000,TIMER7);
    GpioSetPinValue(GPIO2,2,HIGH);
    delay(1000,TIMER7);
    GpioSetPinValue(GPIO2,2,LOW);
    delay(1000,TIMER7);
}

void PiscaLed02(){
    
    delay(800, TIMER7);
    GpioSetPinValue(GPIO2, 1, HIGH);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO2, 1, LOW);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(800,TIMER7);
    GpioSetPinValue(GPIO1,28,HIGH);
    delay(800,TIMER7);
    GpioSetPinValue(GPIO1,28,LOW);
    delay(800,TIMER7);
    GpioSetPinValue(GPIO2,2,HIGH);
    delay(800,TIMER7);
    GpioSetPinValue(GPIO2,2,LOW);
    delay(800,TIMER7);
}

void PiscaLed03(){
        
    delay(600, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(600, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(600, TIMER7);
    GpioSetPinValue(GPIO2, 2, HIGH);
    delay(600, TIMER7);
    GpioSetPinValue(GPIO2, 2, LOW);
    delay(600, TIMER7);
    GpioSetPinValue(GPIO2,1,HIGH);
    delay(600,TIMER7);
    GpioSetPinValue(GPIO2,1,LOW);
    delay(600,TIMER7);
    GpioSetPinValue(GPIO1,28,HIGH);
    delay(600,TIMER7);
    GpioSetPinValue(GPIO1,28,LOW);
    delay(600,TIMER7);
}

void PiscaLed04(){
                
    delay(400, TIMER7);
    GpioSetPinValue(GPIO2, 2, HIGH); 
    delay(400, TIMER7);
    GpioSetPinValue(GPIO2, 2, LOW);
    delay(400, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(400, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(400, TIMER7);
    GpioSetPinValue(GPIO1,28,HIGH);
    delay(400,TIMER7);
    GpioSetPinValue(GPIO1,28,LOW);
    delay(400,TIMER7);
    GpioSetPinValue(GPIO2,1,HIGH);
    delay(400,TIMER7);
    GpioSetPinValue(GPIO2,1,LOW);
    delay(400,TIMER7);
}
