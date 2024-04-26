#include	"hw_types.h"
#include	"soc_AM335x.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define TIME															1000000
#define TOGGLE          												(0x01u)
//registradores de configuração do clock

#define CM_PER_GPIO2                                                    0XB0 // 
#define CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE   						(0x2u) //Table 8-59. CM_PER_GPIO2_CLKCTRL Register 
#define CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK  					(0x00040000u)//Table 8-59. CM_PER_GPIO2_CLKCTRL 

// endereçõs de registradores para configurar os pinos do modo de controle
#define CM_conf_gpmc_ben1      	 								0x0878
#define CM_conf_gpmc_a5         								0x0854// Table 9-8. CONTROL_MODULE REGISTERS (((
#define CM_conf_gpmc_a6         								0x0818// Table 9-8. CONTROL_MODULE REGISTERS (( pode usar do 
#define CM_conf_gpmc_a7         								0x081C// Table 9-8. CONTROL_MODULE REGISTERS ((
#define CM_conf_gpmc_a8         								0x0820// Table 9-8. CONTROL_MODULE REGISTERS ((((
#define CM_conf_gpmc_ad11                                       0x0820
#define CM_conf_gpmc_ad12         								0x0830

// endereços de registradores para configurar o watchdog
#define WDT1 													0x44E35000
#define WDT_WSPR 												0x48 // temporizador watchdog / Registro de proteção de serviço de gravação do cronômetro de vigilância 
#define WDT_WWPS												0x34 // Escrever registro de status postado / Este registrador contém os bits de postagem de gravação para todos os registradores funcionais graváveis.
#define W_PEND_WSPR												(1<< 0x4u)


// manipular diretamente os registradores GPIO correspondentes( entrada, saida, setar, limpar)
#define GPIO_OE                 								0x134 //controla a capacidade de saída/entrada para cada pino - Table 25-5. GPIO Registers
#define GPIO_CLEARDATAOUT       								0x190 // limpar dados de saida - Table 25-5. GPIO Registers
#define GPIO_SETDATAOUT         								0x194 // setar dados de saida - - Table 25-5. GPIO Registers

//variaveis temporarias para controlar o comportamento do leds
unsigned int flagBlink0_e;
unsigned int flagBlink1_e;
unsigned int flagBlink2_e;
unsigned int flagBlink3_e;

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
static void delay(int);
static void ledInit_e();
static void ledToggle0_e();
static void ledToggle1_e();
static void ledToggle2_e();
static void ledToggle3_e();
static void watchdog();

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int _main(void){

	watchdog();
  	
  	flagBlink0_e = 0;
  	flagBlink1_e = 0;
	flagBlink2_e = 0;
  	flagBlink3_e = 0;
  	
  	ledInit_e();
  	
  	int i;
  	for(i = 0; i <= 16; i++){
    	if (i == 1){
    	ledToggle0_e();
		delay(i);
	}if (i == 2){
		ledToggle0_e();
		ledToggle1_e();
		delay(i);
	}if (i == 3){
		ledToggle0_e();
		int x= 3;
		delay(x);
	}if (i == 4){
		ledToggle0_e();
		ledToggle1_e();
		ledToggle2_e();
		int x= 3;
		delay(x);
	}if (i == 5){
    		ledToggle0_e();
		int x= 3;
		delay(x);
	}if (i == 6){
		ledToggle0_e();
		ledToggle1_e();
		int x= 3;
		delay(x);
	}if (i == 7){
		ledToggle0_e();
		int x= 3;
		delay(x);
	}if (i == 8){
    	ledToggle0_e();
		ledToggle1_e();
		ledToggle2_e();
		ledToggle3_e();
		int x= 3;
		delay(x);
	}if (i == 9){
		ledToggle0_e();
		int x= 3;
		delay(x);
	}if (i == 10){
		ledToggle0_e();
		ledToggle1_e();
		int x= 3;
		delay(x);
	}if (i == 11){
		ledToggle0_e();
		int x= 3;
		delay(x);
	}if (i == 12){
		ledToggle0_e();
		ledToggle1_e();
		ledToggle2_e();
		int x= 3;
		delay(x);
	}if (i == 13){
		ledToggle0_e();
		int x= 3;
		delay(x);
	}if (i == 14){
		ledToggle0_e();
		ledToggle1_e();
		int x= 3;
		delay(x);
	}if (i == 15){
		ledToggle0_e();
		int x= 3;
		delay(x);
	}if(i == 16){
		i= 0;
		ledToggle0_e();
		ledToggle1_e();
		ledToggle2_e();
		ledToggle3_e();
		int x= 3;
		delay(x);
	}
	}
	return(0);
}
/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/
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



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledInit
 *  Description:  
 * =====================================================================================
 */

void ledInit_e( ){
	
	unsigned int val_temp; 	
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO2) |= CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK | CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE; // configuração de clock
	
	/*-----------------------------------------------------------------------------
	 * MULTIPLEXAR O PINO NO MODULO DE CONTROLE GPI02
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_ad11) |= 7; 
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_ad12) |= 7;		
 
	/*-----------------------------------------------------------------------------
	 *  DEFINE OS PINOS COMO SAÍDA
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_2_REGS+GPIO_OE);
	val_temp &= ~(1<<6);                                                            //25.4.10 GPIO_OE Register
	val_temp &= ~(1<<7);
	val_temp &= ~(1<<8);
	val_temp &= ~(1<<9);
	HWREG(SOC_GPIO_2_REGS+GPIO_OE) = val_temp;
	
}/* -----  configura o clock e o modo de operação do módulo GPIO2, configura o pino GPIO2_6 ----- */

void ledToggle0_e(){
		flagBlink0_e ^= TOGGLE;

		if(flagBlink0_e){
			HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<6;
		}else{
			HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<6;
		}
}


void ledToggle1_e(){
		flagBlink1_e ^= TOGGLE;
		
		if(flagBlink1_e){
			HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<7;
		}else{
			HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<7;
		}
}

void ledToggle2_e(){
		flagBlink2_e ^= TOGGLE;
		
		if(flagBlink2_e){
			HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<8;
		}else{
			HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<8;
		}
}

void ledToggle3_e(){
		flagBlink3_e ^= TOGGLE;
		
		if(flagBlink3_e){
			HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<9;
		}else{
			HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<9;
		}
}
	
void watchdog(){
	//Table 20-119. WDT_WWPS Register Field Descriptions
	HWREG(WDT1+WDT_WSPR) = 0xAAAA; //reconfigura o registrador 

	while((HWREG(WDT1+WDT_WWPS) & W_PEND_WSPR) != 0x0){}; // garante o loop 

	HWREG(WDT1+WDT_WSPR) = 0x5555;

	while((HWREG(WDT1+WDT_WWPS) & W_PEND_WSPR) != 0x0){};

}

