#include "Simulator.h"
#include "Memory.h"
#include "add.h"
#include <stdint.h>

uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2){
  uint16_t newVal1 = val1<<8;
  uint16_t result  = newVal1 + val2;
  return result;
}

void raw_add(uint8_t val){
  uint8_t result	    = cpuRegisters->A + val;

  cpuRegisters->CCR.H = A3&M3|M3&(!(R3))|A3&(!(R3));
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->CCR.C = A7&M7|M7&(!(R7))|A7&(!(R7));
  cpuRegisters->CCR.V = cpuRegisters->CCR.C ^ (A6&M6|M6&(!(R6))|(!(R6))&A6);
  cpuRegisters->A     = result;
}

void raw_adc(uint8_t val){
  uint8_t result	    = cpuRegisters->A + val + cpuRegisters->CCR.C;

  cpuRegisters->CCR.H = A3&M3|M3&(!(R3))|A3&(!(R3));
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->CCR.C = A7&M7|M7&(!(R7))|A7&(!(R7));
  cpuRegisters->CCR.V = cpuRegisters->CCR.C ^ (A6&M6|M6&(!(R6))|(!(R6))&A6);
  cpuRegisters->A     = result;
}

void raw_sub(uint8_t val){
  uint8_t result   	= cpuRegisters->A - val;

  cpuRegisters->CCR.V = ((!(A7)) & M7|(!(A7)) & R7|A7 & M7 & R7)^((!(A6)) & M6|(!(A6)) & R6|A6 & M6 & R6);
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->CCR.C = (!(A7))&M7|(!(A7))&(R7)|A7&M7&R7;
  cpuRegisters->A     = result;
}

void raw_sbc(uint8_t val){
  uint8_t result	    = cpuRegisters->A - val - cpuRegisters->CCR.C;

  cpuRegisters->CCR.V = ((!(A7)) & M7|(!(A7)) & R7|A7 & M7 & R7)^((!(A6)) & M6|(!(A6)) & R6|A6 & M6 & R6);
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->CCR.C = (!(A7))&M7|(!(A7))&(R7)|A7&M7&R7;
  cpuRegisters->A     = result;
}

void raw_inc(uint8_t *valptr){
  uint8_t result = *valptr + 0x01;
  uint8_t val     = *valptr;
  *valptr         = result;

  cpuRegisters->CCR.V = (A7&M7|M7&(!(R7))|(!(R7))&A7)^(A6&M6|M6&(!(R6))|(!(R6))&A6);
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
}

void raw_and(uint8_t val){
  uint8_t result = cpuRegisters->A & val;
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->A     = result;
}

void raw_or(uint8_t val){
  uint8_t result = cpuRegisters->A | val;
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->A     = result;
}

void raw_xor(uint8_t val){
  uint8_t result = cpuRegisters->A ^ val;
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->A     = result;
}

void raw_ldA(uint8_t val){
  uint8_t result = val;
  cpuRegisters->CCR.N = R7;
  cpuRegisters->CCR.Z = result==0?1:0;
  cpuRegisters->A     = result;
}
