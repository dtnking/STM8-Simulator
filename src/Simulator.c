#include "Simulator.h"
#include "Memory.h"
#include "add.h"
#include <stdint.h>
#include <stdio.h>

uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2){
  uint16_t newVal1 = val1<<8;
  uint16_t result  = newVal1 + val2;
  return result;
}

void naked_add(uint8_t val){
  uint8_t result	= cpuRegisters->A + val;

  cpuRegisters->CCR.V = ((A7&M7|M7&(!R7)|R7&A7)^(A6&M6|M6&(!R6)|(!R6)&A6));
  cpuRegisters->CCR.H = (A3&M3|M3&(!R3)|A3&(!R3));
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = (!R7&!R6&!R5&!R4&!R3&!R2&!R1&!R0);
  cpuRegisters->CCR.C = (A7&M7|M7&(!R7)|A7&(!R7));
  cpuRegisters->A     = result;
}

void naked_addc(uint8_t val){
  uint8_t result	= cpuRegisters->A + val + cpuRegisters->CCR.C;

  cpuRegisters->CCR.V = ((A7&M7|M7&(!R7)|R7&A7)^(A6&M6|M6&(!R6)|(!R6)&A6));
  cpuRegisters->CCR.H = (A3&M3|M3&(!R3)|A3&(!R3));
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = (!R7&!R6&!R5&!R4&!R3&!R2&!R1&!R0);
  cpuRegisters->CCR.C = (A7&M7|M7&(!R7)|A7&(!R7));
  cpuRegisters->A     = result;
}
