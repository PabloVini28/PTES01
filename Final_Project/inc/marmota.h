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
unsigned int verificaStart();
void MarmotaVerde();
void MarmotaVermelha();


#endif