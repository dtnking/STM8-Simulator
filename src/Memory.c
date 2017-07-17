#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdint.h>


Stm8Registers *cpuRegisters=(Stm8Registers *)&memory[0x7f00];

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
  return memory[addrs];
}

uint8_t get_longmem(uint8_t *opcode){
  uint16_t addrs		=	 combineTwoAddrs(opcode[1],opcode[2]);
  return memory[addrs];
}

uint8_t get_x(void){
  uint16_t addrs		=	 combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return memory[addrs];
}

uint8_t get_y(void){
  uint16_t addrs		=	 combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return memory[addrs];
}

uint8_t get_x_shortset(uint8_t *opcode){
  uint8_t val 		= opcode[1];
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return memory[addrs+val];
}

uint8_t get_y_shortset(uint8_t *opcode){
  uint8_t val 		= opcode[2];
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return memory[addrs+val];
}

uint8_t get_x_longset(uint8_t *opcode){
  uint16_t addrsOffset = combineTwoAddrs(opcode[1],opcode[2]);
  uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return memory[addrsOffset+addrsBase];
}

uint8_t get_y_longset(uint8_t *opcode){
  uint16_t addrsOffset = combineTwoAddrs(opcode[1],opcode[2]);
	uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return memory[addrsOffset+addrsBase];
}

uint8_t get_shortoff_SP(uint8_t *opcode){
  uint8_t addrsSP			 = opcode[1];
  uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->SPH,cpuRegisters->SPL);
  return memory[addrsBase+addrsSP];
}

uint8_t get_shortptr_w(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
	uint8_t val1=memory[addrsOfFirstPtr];
	uint8_t val2=memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2);
  return memory[addrsOfSecondPtr];
}

uint8_t get_longptr_w(uint8_t *opcode){
  uint16_t addrsOfFirstPtr = combineTwoAddrs(opcode[2],opcode[3]);
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2);
  return memory[addrsOfSecondPtr];
}

uint8_t get_shortptr_w_X(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
  uint8_t val1 = memory[addrsOfFirstPtr];
  uint8_t val2 = memory[addrsOfFirstPtr+1];
  uint16_t X	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
  return memory[addrsOfSecondPtr];
}

uint8_t get_longptr_w_X(uint8_t *opcode){
  uint16_t addrsOfFirstPtr = combineTwoAddrs(opcode[2],opcode[3]);
  uint8_t val1 = memory[addrsOfFirstPtr];
  uint8_t val2 = memory[addrsOfFirstPtr+1];
  uint16_t X	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
  return memory[addrsOfSecondPtr];
}

uint8_t get_shortptr_w_Y(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t Y	 = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + Y;
  return memory[addrsOfSecondPtr];
}
