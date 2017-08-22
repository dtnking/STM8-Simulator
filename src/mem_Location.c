#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdint.h>

unsigned char memory[20*KB];
Stm8Registers *cpuRegisters = (Stm8Registers *)&memory[0x7f00];


void clearCCRflag(){
  cpuRegisters->CCR.bit.C  = 0;
  cpuRegisters->CCR.bit.Z  = 0;
  cpuRegisters->CCR.bit.N  = 0;
  cpuRegisters->CCR.bit.I0 = 0;
  cpuRegisters->CCR.bit.H  = 0;
  cpuRegisters->CCR.bit.I1 = 0;
  cpuRegisters->CCR.bit.V  = 0;
}


uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2){
  uint16_t newVal1 = val1<<8;
  uint16_t result  = newVal1 + val2;
  return result;
}

uint32_t combineThreeAddrs(uint8_t val1, uint8_t val2, uint8_t val3){
  uint32_t newVal1 = val1 << 16;
  uint32_t newVal2 = val2 << 8;
  uint32_t result = newVal1 + newVal2 + val3;
  return result;
}

void set_X(uint16_t xAddress){
  cpuRegisters->XH = GET_MSB(xAddress);
  cpuRegisters->XL = GET_LSB(xAddress);
}

void set_Y(uint16_t yAddress){
  cpuRegisters->YH = GET_MSB(yAddress);
  cpuRegisters->YL = GET_LSB(yAddress);
}

void set_SP(uint16_t spAddress){
  cpuRegisters->SPH = GET_MSB(spAddress);
  cpuRegisters->SPL = GET_LSB(spAddress);
}

void set_PC(uint32_t pcAddress){
  cpuRegisters->PCE = GET_HMSB(pcAddress);
  cpuRegisters->PCH = GET_MSB(pcAddress);
  cpuRegisters->PCL = GET_LSB(pcAddress);
}

uint8_t get_valueByte(uint8_t *opcode){
  uint8_t val = opcode[1];                    // the value is at least byte of the opcode
  return val;
}

uint8_t get_shortmem(uint8_t *opcode){
  uint8_t addrs	=	opcode[1];	 							// the address is at the least byte of the opcode
  return addrs;
}

uint16_t get_longmem(uint8_t *opcode){
  uint16_t addrs = combineTwoAddrs(opcode[1],opcode[2]);
  return addrs;
}

uint16_t get_x_value(void){
  uint16_t addrs = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return addrs;
}

uint16_t get_y_value(void){
  uint16_t addrs = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return addrs;
}

uint16_t get_x_shortset(uint8_t *opcode){
  uint8_t offset = opcode[1];
	uint16_t addrs = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return addrs+offset;
}

uint16_t get_y_shortset(uint8_t *opcode){
  uint8_t offset = opcode[2];
	uint16_t addrs = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return addrs+offset;
}

uint16_t get_x_longset(uint8_t *opcode){
  uint16_t offset = combineTwoAddrs(opcode[1],opcode[2]);
  uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
  return offset+addrsBase;
}

uint16_t get_y_longset(uint8_t *opcode){
  uint16_t offset = combineTwoAddrs(opcode[2],opcode[3]);
	uint16_t addrsBase = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
  return offset+addrsBase;
}

uint16_t get_shortoff_SP(uint8_t *opcode){
  uint8_t offset		 = opcode[1];
  uint16_t addrsBase = combineTwoAddrs(cpuRegisters->SPH,cpuRegisters->SPL);
  return addrsBase+offset;
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
  uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
  return addrsOfSecondPtr;
}

uint16_t get_longptr_w_X(uint8_t *opcode){
  uint16_t addrsOfFirstPtr = combineTwoAddrs(opcode[2],opcode[3]);
  uint8_t val1 = memory[addrsOfFirstPtr];
  uint8_t val2 = memory[addrsOfFirstPtr+1];
  uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
  return addrsOfSecondPtr;
}

uint16_t get_shortptr_w_Y(uint8_t *opcode){
  uint8_t addrsOfFirstPtr = opcode[2];
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + Y;
  return addrsOfSecondPtr;
}
