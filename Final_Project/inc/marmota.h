#ifndef MARMOTA_H
#define MARMOTA_H

#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"
#include "menu.h"

extern unsigned int numero_pontos;

void decrementa_ponto();
void start();
void reset();
void str(unsigned int num);
unsigned int verificaStart();
void MarmotaVerde();
void MarmotaVermelha();
void MarmotaBranca();
void MarmotaAzul();
void imprimirPontuacao();
void acionaBuzzer();
void PontuacaoMaxima();



#endif