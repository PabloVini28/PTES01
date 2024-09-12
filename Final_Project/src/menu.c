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

void chamaMenuReset(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-               Reset Ativado                     -\n\r", 55);
    putString(UART0, "-     Pressione Start para uma nova rodada        -\n\r", 55);
    putString(UART0, "-               Pontuação = 0                     -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

void matouMarmotaVermelha(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-               Marmota Vermelha                  -\n\r", 55);
    putString(UART0, "-               Pontuação += 1                    -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

void matouMarmotaVerde(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-               Marmota Verde                     -\n\r", 55);
    putString(UART0, "-               Pontuação += 1                    -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

void matouMarmotaAzul(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-               Marmota Azul                      -\n\r", 55);
    putString(UART0, "-               Pontuação += 1                    -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

void matouMarmotaBranca(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-               Marmota Branca                   -\n\r", 55);
    putString(UART0, "-               Pontuação += 1                    -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

void PontuacaoMaxima(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-                 Parabéns!                       -\n\r", 55);
    putString(UART0, "-               Pontuação = 16                    -\n\r", 55);
    putString(UART0, "-         Você é o mestre da Marmota!             -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

void PerdePonto(){
    putString(UART0, "\n\r\n\r",8);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "-                 Que pena!                       -\n\r", 55);
    putString(UART0, "-               Pontuação -= 1                    -\n\r", 55);
    putString(UART0, "---------------------------------------------------\n\r", 55);
    putString(UART0, "\n\r\n\r",8);
}

