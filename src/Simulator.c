#include "Simulator.h"
#include "Memory.h"
#include "add.h"
#include <stdint.h>

uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2){
  uint16_t newVal1 = val1<<8;
  uint16_t result  = newVal1 + val2;
  return result;
}

void naked_add(uint8_t val){
  uint8_t result	= cpuRegisters->A + val;

  cpuRegisters->CCR.H = (A3&M3|M3&(!R3)|A3&(!R3));
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = (!R7&!R6&!R5&!R4&!R3&!R2&!R1&!R0);
  cpuRegisters->CCR.C = (A7&M7|M7&(!R7)|A7&(!R7));
  cpuRegisters->A     = result;



  printf("%x\n",cpuRegisters->A);
  printf("%x\n",(val&0x80));
  printf("A7 = %x\n",A7);
	printf("M7 = %x\n",M7);
	printf("R7 = %x\n",R7);
}
