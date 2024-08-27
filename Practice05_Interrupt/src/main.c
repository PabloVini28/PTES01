#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"
#include "menu.h"

#define DELAY_USE_INTERRUPT 1 // macro para habilitar ou desabilitar o uso de interrupção no delay


int main() {

    disableWdt();

    Init_module_gpio(GPIO1);

    cmSetCtrlModule(CM_conf_gpmc_ben1,7);
    cmSetCtrlModule(CM_conf_gpmc_a0,7);
    cmSetCtrlModule(CM_conf_gpmc_a1,7);

    Init_pin_gpio(GPIO1,28,OUTPUT);
    Init_pin_gpio(GPIO1,16,INPUT);
    Init_pin_gpio(GPIO1,17,INPUT);

    timerSetup(TIMER7);

    Interrupt_Setup(98);
    Pin_Interrup_Config(GPIO1,16,type0); // tipo A = type0 B = type1
    Pin_Interrup_Config(GPIO1,17,type0); // tipo A = type0 B
        
    

    return 0;
}
