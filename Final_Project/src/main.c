#include "marmota.h"

void PiscaLed01();
void PiscaLed02();
void PiscaLed03();
void PiscaLed04();

unsigned int numero_pontos;

int main() {

    disableWdt();

    Init_module_gpio(GPIO1);

    cmSetCtrlModule(CM_conf_gpmc_ben1, 7); // led
    cmSetCtrlModule(CM_conf_gpmc_ad12, 7); // led
    cmSetCtrlModule(CM_conf_gpmc_a1, 7); // botão
    cmSetCtrlModule(CM_conf_gpmc_a0, 7); // bot
    cmSetCtrlModule(CM_conf_gpmc_a2,7); // botão
    cmSetCtrlModule(CM_conf_gpmc_a3,7); // botão

    Init_pin_gpio(GPIO1, 28, OUTPUT);
    Init_pin_gpio(GPIO1, 12, OUTPUT);
    Init_pin_gpio(GPIO1, 17, INPUT);
    Init_pin_gpio(GPIO1, 16, INPUT);
    Init_pin_gpio(GPIO1,18,INPUT);
    Init_pin_gpio(GPIO1,19,INPUT);

    Debounce(GPIO1);

    timerSetup(TIMER7);

    Interrupt_Setup(98);
    Interrupt_Setup(95);

    Pin_Interrup_Config(GPIO1, 17, type0); // tipo A = type0 B = type1
    Pin_Interrup_Config(GPIO1, 16, type0);
    Pin_Interrup_Config(GPIO1, 18, type0);
    Pin_Interrup_Config(GPIO1, 19, type0);

    while(true) {
    
        while(verificaStart()==1){
            PiscaLed01();
            PiscaLed02();
            PiscaLed03();
            PiscaLed04();
        }
    
    }
    return 0;
}


void PiscaLed01(){

    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH); // ponto 1
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(2000, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(2000, TIMER7);
}

void PiscaLed02(){
    
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(1000, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(1000, TIMER7);
}

void PiscaLed03(){
        
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(800, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(800, TIMER7);
}

void PiscaLed04(){
                
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH); 
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 28, HIGH);
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 28, LOW);
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 12, HIGH);
    delay(500, TIMER7);
    GpioSetPinValue(GPIO1, 12, LOW);
    delay(500, TIMER7);
}
