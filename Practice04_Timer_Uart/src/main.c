#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"

#define DELAY_USE_INTERRUPT 1

void disableWdt(void) {
    HWREG(WDT_WSPR) = 0xAAAA;
    while((HWREG(WDT_WWPS) & (1<<4)));

    HWREG(WDT_WSPR) = 0x5555;
    while((HWREG(WDT_WWPS) & (1<<4)));
}

int main() {
    disableWdt();

    char buffer[4];  // Buffer para 3 dígitos + 1 caractere nulo

    // Solicitar ao usuário uma entrada
    putString(UART0, "Digite os ms - maximo 3 digitos: ", 34);
    uartGetString(UART0, buffer, 3);
    putString(UART0, "\n\r", 2);

    buffer[3] = '\0';  // Assegure que a string esteja terminada com '\0'

    // Verificar se todos os caracteres são dígitos
    for (int i = 0; i < 3; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            putString(UART0, "Entrada invalida. Por favor, insira apenas digitos.\n\r", 50);
            return 1;
        }
    }

    unsigned int ms = (buffer[0] - '0') * 100 + (buffer[1] - '0') * 10 + (buffer[2] - '0');

    timerSetup(TIMER7);
    Init_pin_gpio(GPIO1, 28, OUTPUT);

    while (true) {
        GpioSetPinValue(GPIO1, 28, HIGH);  
        delay(ms, TIMER7); 
        GpioSetPinValue(GPIO1, 28, LOW);  
        delay(ms, TIMER7); 
    }

    return 0;
}
