#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdint.h>

unsigned char memory[20*KB];
Stm8Registers *cpuRegisters=(Stm8Registers *)&memory[0x7f00];


void clearCCRflag(){
  cpuRegisters->CCR.C   = 0;
  cpuRegisters->CCR.Z   = 0;
  cpuRegisters->CCR.N   = 0;
  cpuRegisters->CCR.I0  = 0;
  cpuRegisters->CCR.H   = 0;
  cpuRegisters->CCR.I1  = 0;
  cpuRegisters->CCR.V   = 0;
}

void set_X(uint8_t xh,uint8_t xl){
  cpuRegisters->XH = xh;
  cpuRegisters->XL = xl;
}

void set_Y(uint8_t yh,uint8_t yl){
  cpuRegisters->YH = yh;
  cpuRegisters->YL = yl;
}

void set_SP(uint8_t sph,uint8_t spl){
  cpuRegisters->SPH = sph;
  cpuRegisters->SPL = spl;
}

uint8_t get_valueByte(uint8_t *opcode){
  uint8_t val = opcode[1];                    // the value is at least byte of the opcode
  return val;
}

uint8_t get_shortmem(uint8_t *opcode){
  uint8_t addrs		  =	 opcode[1];	 							// the address is at the least byte of the opcode
  return addrs;
}

uint16_t get_longmem(uint8_t *opcode){
  uint16_t addrs		=	 combineTwoAddrs(opcode[1],opcode[2]);
  return addrs;
}

uint16_t get_x_value(void){
  uint16_t addrs		=	 combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return addrs;
}

uint16_t get_y_value(void){
  uint16_t addrs		=	 combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return addrs;
}

uint16_t get_x_shortset(uint8_t *opcode){
  uint8_t val 		= opcode[1];
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return addrs+val;
}

uint16_t get_y_shortset(uint8_t *opcode){
  uint8_t val 		= opcode[2];
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return addrs+val;
}

uint16_t get_x_longset(uint8_t *opcode){
  uint16_t addrsOffset = combineTwoAddrs(opcode[1],opcode[2]);
  uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return addrsOffset+addrsBase;
}

uint16_t get_y_longset(uint8_t *opcode){
  uint16_t addrsOffset = combineTwoAddrs(opcode[2],opcode[3]);
	uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return addrsOffset+addrsBase;
}

uint16_t get_shortoff_SP(uint8_t *opcode){
  uint8_t addrsSP			 = opcode[1];
  uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->SPH,cpuRegisters->SPL);
  return addrsBase+addrsSP;
}

uint16_t get_shortptr_w(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
	uint8_t val1=memory[addrsOfFirstPtr];
	uint8_t val2=memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2);
  return addrsOfSecondPtr;
}

uint16_t get_longptr_w(uint8_t *opcode){
  uint16_t addrsOfFirstPtr = combineTwoAddrs(opcode[2],opcode[3]);
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2);
  return addrsOfSecondPtr;
}

uint16_t get_shortptr_w_X(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
  uint8_t val1 = memory[addrsOfFirstPtr];
  uint8_t val2 = memory[addrsOfFirstPtr+1];
  uint16_t X	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
  return addrsOfSecondPtr;
}

uint16_t get_longptr_w_X(uint8_t *opcode){
  uint16_t addrsOfFirstPtr = combineTwoAddrs(opcode[2],opcode[3]);
  uint8_t val1 = memory[addrsOfFirstPtr];
  uint8_t val2 = memory[addrsOfFirstPtr+1];
  uint16_t X	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
  return addrsOfSecondPtr;
}

uint16_t get_shortptr_w_Y(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t Y	 = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + Y;
  return addrsOfSecondPtr;
}
