#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void raw_add(uint8_t val){
  uint8_t result	    = cpuRegisters->A + val;

  cpuRegisters->CCR.bit.H = A3&M3|M3&(!(R3))|A3&(!(R3));
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->CCR.bit.C = A7&M7|M7&(!(R7))|A7&(!(R7));
  cpuRegisters->CCR.bit.V = cpuRegisters->CCR.bit.C ^ (A6&M6|M6&(!(R6))|(!(R6))&A6);
  cpuRegisters->A     = result;
}

void raw_adc(uint8_t val){
  uint8_t result	    = cpuRegisters->A + val + cpuRegisters->CCR.bit.C;

  cpuRegisters->CCR.bit.H = A3&M3|M3&(!(R3))|A3&(!(R3));
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->CCR.bit.C = A7&M7|M7&(!(R7))|A7&(!(R7));
  cpuRegisters->CCR.bit.V = cpuRegisters->CCR.bit.C ^ (A6&M6|M6&(!(R6))|(!(R6))&A6);
  cpuRegisters->A     = result;
}

void raw_sub(uint8_t val){
  uint8_t result   	= cpuRegisters->A - val;

  cpuRegisters->CCR.bit.V = ((!(A7)) & M7|(!(A7)) & R7|A7 & M7 & R7)^((!(A6)) & M6|(!(A6)) & R6|A6 & M6 & R6);
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->CCR.bit.C = (!(A7))&M7|(!(A7))&(R7)|A7&M7&R7;
  cpuRegisters->A     = result;
}

void raw_sbc(uint8_t val){
  uint8_t result	    = cpuRegisters->A - val - cpuRegisters->CCR.bit.C;

  cpuRegisters->CCR.bit.V = ((!(A7)) & M7|(!(A7)) & R7|A7 & M7 & R7)^((!(A6)) & M6|(!(A6)) & R6|A6 & M6 & R6);
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->CCR.bit.C = (!(A7))&M7|(!(A7))&(R7)|A7&M7&R7;
  cpuRegisters->A     = result;
}

void raw_inc(uint8_t *valptr){
  uint8_t result = *valptr + 0x01;
  uint8_t val    = 0x01;

  cpuRegisters->CCR.bit.V = (x7&M7|M7&(!(R7))|(!(R7))&x7)^(x6&M6|M6&(!(R6))|(!(R6))&x6);
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  *valptr        = result;
}

void raw_dec(uint8_t *valptr){
  uint8_t result = *valptr - 0x01;
  uint8_t val    = 0x01;

  cpuRegisters->CCR.bit.V = (x7&M7|M7&(!(R7))|(!(R7))&x7)^(x6&M6|M6&(!(R6))|(!(R6))&x6);
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  *valptr        = result;
}

void raw_and(uint8_t val){
  uint8_t result = cpuRegisters->A & val;
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->A     = result;
}

void raw_or(uint8_t val){
  uint8_t result = cpuRegisters->A | val;
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->A     = result;
}

void raw_xor(uint8_t val){
  uint8_t result = cpuRegisters->A ^ val;
  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  cpuRegisters->A     = result;
}

void raw_ld(uint8_t *srcAddrss, uint8_t *dstAddrss){
  uint8_t result = *srcAddrss;

  cpuRegisters->CCR.bit.N = R7;
  cpuRegisters->CCR.bit.Z = result==0?1:0;
  *dstAddrss = result;
}

void raw_mov(uint8_t *srcAddrss, uint8_t *dstAddrss){
  uint8_t result = *srcAddrss;
  *dstAddrss = result;
}

void raw_pop(uint8_t *dstAddrss){
  uint16_t stack = combineTwoAddrs(cpuRegisters->SPH,cpuRegisters->SPL);   // Combine SPH and SPL into one address(SP).
  uint8_t *stackPtr = &memory[stack] + 1;                                  // The stack pointer is incremented by 1.
  *dstAddrss = *stackPtr;                                                  // Place the data byte from the stack to dstAddrss.
}
