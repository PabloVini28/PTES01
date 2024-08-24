#include "clock_module.h"
#include "soc_AM335x.h"

void ckmSetCLKModuleRegister(CKM_MODULE_REG module, unsigned int value){
    unsigned int addr_temp = SOC_CONTROL_REGS + module;
    addr_temp |= value;
}

unsigned int ckmGetCLKModuleRegister(CKM_MODULE_REG module){
    unsigned int addr_temp = SOC_CONTROL_REGS + module;
    return addr_temp;
}