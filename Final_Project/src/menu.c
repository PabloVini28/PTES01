#include "uart.h"
#include "menu.h"

void chamaMenuPrincipal(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-                                                 -\n\r", 55);
    putString(UART0, "-               Jogo da Marmota                   -\n\r", 55);
    putString(UART0, "-                                                 -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
    
}

