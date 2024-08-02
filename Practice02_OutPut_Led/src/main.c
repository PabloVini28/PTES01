#include	"hw_types.h"
#include	"soc_AM335x.h"

#define TIME															1000000
#define TOGGLE          												(0x01u)

//configuração do GPIO1
#define CM_PER_GPIO1                                                    0XAC // 
#define CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE   						(0x2u) //Table 8-59. 
#define CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK  					(0x00040000u)

// endereços de registradores para configurar os pinos do modo de controle
#define CM_conf_gpmc_ben1      	 								0x878
#define conf_gpmc_ad13                                          0x834
#define conf_gpmc_ad12                                          0x830
#define GPMC_A1                                                 0X844

// manipular diretamente os registradores GPIO correspondentes( entrada, saida, setar, limpar)
#define GPIO_OE                 								0x134 
#define GPIO_CLEARDATAOUT       								0x190 
#define GPIO_SETDATAOUT         								0x194 

unsigned int led0_e;
unsigned int led1_e;
unsigned int led2_e;
unsigned int led3_e;

static void delay(int);
static void iniciaLed_e();
static void ativaLed0_e();
static void ativaLed1_e();
static void ativaLed2_e();
static void ativaLed3_e();

int _main(void){

	watchdog();
  	led0_e = 0;
	led1_e = 0;
	led2_e = 0;
	led3_e = 0;
  	
  	iniciaLed_e();
  	
  	int i;
  	for(i = 0; i <= 16; i++){
    	if (i == 1){
    	ativaLed0_e();
		delay(i);
	}if (i == 2){
		ativaLed0_e();
		ativaLed1_e();
		delay(i);
	}if (i == 3){
		ativaLed0_e();
		delay(i);
	}if (i == 4){
		ativaLed2_e();
		ativaLed0_e();
		ativaLed1_e();
		delay(i);
	}if (i == 5){
    	ativaLed0_e();
		delay(i);
	}if (i == 6){
		ativaLed0_e();
		ativaLed1_e();
		delay(i);
	}if (i == 7){
		ativaLed0_e();
		delay(i);
	}
	if(i == 8){
		ativaLed0_e();
		ativaLed1_e();
		ativaLed2_e();
		ativaLed3_e();
		delay(i);
	}
	if(i == 9){
		ativaLed0_e();
		delay(i);
	}
	if(i == 10){
		ativaLed0_e();
		ativaLed1_e();
		delay(i);
	}
	if(i == 11){
		ativaLed0_e();
		delay(i);
	}
	if(i == 12){
		ativaLed0_e();
		ativaLed1_e();
		ativaLed2_e();
		delay(i);
	}
	if(i == 13){
		ativaLed0_e();
		delay(i);
	}
	if(i == 14){
		ativaLed0_e();
		ativaLed1_e();
		delay(i);
	}
	if(i == 15){
		ativaLed0_e();
		delay(i);
	}
	if(i == 16){
		ativaLed0_e();
		ativaLed1_e();
		ativaLed2_e();
		ativaLed3_e();
		delay(i);
		i = 0;
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

void iniciaLed_e( ){
	
	unsigned int val_temp; 	
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO1) |= CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK| CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;// configuração de clock
	
	/*-----------------------------------------------------------------------------
	 * MULTIPLEXAR O PINO NO MODULO DE CONTROLE GPI01
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_ben1) |= 7;
	HWREG(SOC_CONTROL_REGS+conf_gpmc_ad13) |= 7;
	HWREG(SOC_CONTROL_REGS+conf_gpmc_ad12) |= 7;
	HWREG(SOC_CONTROL_REGS+GPMC_A1) |= 7;
 
	/*-----------------------------------------------------------------------------
	 *  DEFINE OS PINOS COMO SAÍDA
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<28);  
	val_temp &= ~(1<<13);    
	val_temp &= ~(1<<12);  
	val_temp &= ~(1<<17);                                                   
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;
	
}

void ativaLed0_e(){
		led0_e ^= TOGGLE;

		if(led0_e){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<28;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<28;
		}
}

void ativaLed1_e(){
	led1_e ^= TOGGLE;

		if(led1_e){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<13;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<13;
		}
}

void ativaLed2_e(){
	led2_e ^= TOGGLE;

		if(led2_e){
			HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<12;
		}else{
			HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<12;
		}
}

void ativaLed3_e(){
	led3_e ^= TOGGLE;

	if(led3_e){
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1 << 17;
	}else{
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1 << 17;
	}
}

