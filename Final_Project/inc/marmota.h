#ifndef MARMOTA_H
#define MARMOTA_H

#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"
#include "menu.h"

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