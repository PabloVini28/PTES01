#include	"hw_types.h"
#include	"soc_AM335x.h"

#define TIME															1000000
#define TOGGLE          												(0x01u)


//configuração do GPIO1
#define CM_PER_GPIO1                                                    0XAC // 
#define CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE   						(0x2u) //Table 8-59. 
#define CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK  					(0x00040000u)

#define CM_PER_GPIO2                                                    0xB0
#define CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE   						(0x2u) //Table 8-59.
#define CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK  					(0x00040000u)

// endereços de registradores para configurar os pinos do modo de controle
#define CM_conf_gpmc_ben1      	 								0x878 //led
#define GPMC_A1                                                 0x844 // botao
#define GPMC_A0                                                 0x840 // botao
#define GPMC_AD15                                               0x83C //led
#define GPMC_CLK                                                0x88C // led substituto

#define WDT1 													0x44E35000
#define WDT_WSPR 												0x48
#define WDT_WWPS												0x34
#define W_PEND_WSPR												(1<<0x4u)

// manipular diretamente os registradores GPIO correspondentes( entrada, saida, setar, limpar)
#define GPIO_OE                 								0x134 
#define GPIO_CLEARDATAOUT       								0x190 
#define GPIO_SETDATAOUT         								0x194 
#define GPIO_DATAIN                                             0x138

unsigned int led0_e;
unsigned int botao_0;

static void delay(int);
static void iniciaLed_e_GPIO1();
static void iniciaLed_e2();
static void iniciaBotao();
static void verificaBotaoAnd();
static void verificaBotaoOr();
static void watchdog();

int _main(void){

	watchdog();
  	iniciaLed_e_GPIO1();
	iniciaLed_e2();
	iniciaBotao();

	while(1){
		verificaBotaoAnd();
		verificaBotaoOr();
		delay(0);
	}	
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

void iniciaLed_e_GPIO1( ){
	
	unsigned int val_temp; 	
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO1) |= CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK| CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;// configuração de clock
	
	/*-----------------------------------------------------------------------------
	 * MULTIPLEXAR O PINO NO MODULO DE CONTROLE GPI01
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_ben1) |= 7;
 
	/*-----------------------------------------------------------------------------
	 *  DEFINE OS PINOS COMO SAÍDA
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<28);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;
	
}
void iniciaLed_e2(){
	unsigned int val_temp; 	
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO2) |= CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK| CM_PER_GPIO2_CLKCTRL_MODULEMODE_ENABLE;// configuração de clock
	
	/*-----------------------------------------------------------------------------
	 * MULTIPLEXAR O PINO NO MODULO DE CONTROLE GPI01
	 *-----------------------------------------------------------------------------*/
 	HWREG(SOC_CONTROL_REGS+GPMC_CLK) |= 7;
 
	/*-----------------------------------------------------------------------------
	 *  DEFINE OS PINOS COMO SAÍDA
	 *-----------------------------------------------------------------------------*/
	val_temp = HWREG(SOC_GPIO_2_REGS+GPIO_OE);
	val_temp &= ~(1<<2);
	HWREG(SOC_GPIO_2_REGS+GPIO_OE) = val_temp;
}

void iniciaBotao(){

	unsigned int val_temp;
	//HWREG(SOC_CONTROL_REGS+CM_PER_GPIO1) |= CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK|//CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE;

	HWREG(SOC_CONTROL_REGS+GPMC_A1) |= 7;
	HWREG(SOC_CONTROL_REGS+GPMC_A0) |= 7;

	val_temp=(SOC_CONTROL_REGS+GPIO_OE);
	val_temp |= (1<<17);
	val_temp |= (1<<16);
	HWREG(SOC_CONTROL_REGS+GPIO_OE) = val_temp;

}

void verificaBotaoAnd(){

	if(((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<16))) != 0){
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<28;
	}
	if(((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<17))) != 0){
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<28;
	}
	if((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<16)) == 0){
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<28;
	}
	if((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<17)) == 0){
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<28;
	}

}

void verificaBotaoOr(){

	if(((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<16))) != 0 || ((HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & (1<<17))) != 0){
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<15;
	}else{
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<15;
	}
}


	
void watchdog(){
	
	HWREG(WDT1+WDT_WSPR) = 0xAAAA; //reconfigura o registrador 

	while((HWREG(WDT1+WDT_WWPS) & W_PEND_WSPR) != 0x0){}; // garante o loop 

	HWREG(WDT1+WDT_WSPR) = 0x5555;

	while((HWREG(WDT1+WDT_WWPS) & W_PEND_WSPR) != 0x0){};

}

