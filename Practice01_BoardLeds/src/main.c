#include	"hw_types.h"
#include	"soc_AM335x.h"

#define TIME															1000000
#define TOGGLE          												(0x01u)
//registradores de configuração do clock
#define CM_PER_GPIO1													0xAC 
#define CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE   						(0x2u)
#define CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK  					(0x00040000u)

// endereçõs de registradores para configurar os pinos do modo de controle
#define CM_conf_gpmc_a5         								0x0854
#define CM_conf_gpmc_a6         								0x0818
#define CM_conf_gpmc_a7         								0x081C
#define CM_conf_gpmc_a8         								0x0820

// manipular diretamente os registradores GPIO correspondentes( entrada, saida, setar, limpar)
#define GPIO_OE                 								0x134 
#define GPIO_CLEARDATAOUT       								0x190 
#define GPIO_SETDATAOUT         								0x194

//variaveis temporarias para controlar o comportamento do leds
unsigned int flagBlink0;
unsigned int flagBlink1;
unsigned int flagBlink2;
unsigned int flagBlink3;

static void delay(int);
static void ledInit_i();
static void ledToggle0();
static void ledToggle1();
static void ledToggle2();
static void ledToggle3();


int _main(void){

	flagBlink0=0;	
  	flagBlink1=0;
  	flagBlink2=0;
  	flagBlink3=0;
  	
  	ledInit_i();
  	
  	int i;
  	for(i = 0; i <= 16; i++){
    	if (i == 1){
    		ledToggle0();
			delay(i);
	}if (i == 2){
    	ledToggle0();
		ledToggle1(); 
		delay(i);
	}if (i == 3){
		ledToggle0();
		delay(i);
	}if (i == 4){
    	ledToggle0();
		ledToggle1();
		ledToggle2();
		delay(i);
	}if (i == 5){
    	ledToggle0(); 
		delay(i);
	}if (i == 6){
    	ledToggle0();
		ledToggle1();
		delay(i);
	}if (i == 7){
    	ledToggle0();
		delay(i);
	}if (i == 8){
    	ledToggle0();
		ledToggle1();
		ledToggle2();
		ledToggle3();
		delay(i);
	}if (i == 9){
    	ledToggle0();
		delay(i);
	}if (i == 10){
    	ledToggle0();
		ledToggle1();
		delay(i);
	}if (i == 11){
		ledToggle0();
		delay(i);
	}if (i == 12){
    	ledToggle0();
		ledToggle1();
		ledToggle2();
		delay(i);
	}if (i == 13){
    	ledToggle0();
		delay(i);
	}if (i == 14){
    	ledToggle0();
		ledToggle1();
		delay(i);
	}if (i == 15){
    	ledToggle0();
		delay(i);
	}if(i == 16){
		i= 0;
		ledToggle0();
		ledToggle1();
		ledToggle2();
		ledToggle3();
		delay(i);
	}
	}
	return(0);
}

void delay(int i){
	volatile unsigned int ra;
	if(i < 3){
		for(ra = 0; ra < TIME; ra ++);
	}else if(i >= 3 && i < 8){
		for(ra = 0; ra < (TIME * 2); ra ++);
	}else if(i >= 8 && i < 12){
		for(ra = 0; ra < (TIME * 4); ra ++);
	}else if(i >= 12 && i < 16){
		for(ra = 0; ra < (TIME * 6); ra ++);
	}
}


void ledInit_i( ){
	
	unsigned int val_temp; 	
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO1) |= CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK | CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE; // configuração de clock
	
	/*-----------------------------------------------------------------------------
	 * MULTIPLEXAR O PINO NO MODULO DE CONTROLE GPI01
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a5) |= 7; 
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a6) |= 7;
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a7) |= 7;
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a8) |= 7;
 
	/*-----------------------------------------------------------------------------
	 *  DEFINE OS PINOS COMO SAÍDA
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<21);                                   
	val_temp &= ~(1<<22);
	val_temp &= ~(1<<23);
	val_temp &= ~(1<<24);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;
	
}


void ledToggle0(){
		flagBlink0 ^= TOGGLE;
		
		if(flagBlink0){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<21;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<21;
		}
}
void ledToggle1(){
		flagBlink1 ^= TOGGLE;
		
		if(flagBlink1){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<22;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<22;
		}
}
void ledToggle2(){
		flagBlink2 ^= TOGGLE;

		if(flagBlink2){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<23;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<23;
		}
}
void ledToggle3(){
		flagBlink3 ^= TOGGLE;
		
		if(flagBlink3){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<24;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<24;
		}
}
