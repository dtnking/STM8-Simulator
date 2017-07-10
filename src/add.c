#include "add.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>

void add_byte (uint8_t *opcodePtr){
	uint8_t val = opcodePtr[1];											// the value is at least byte of the opcode
	cpuRegisters->A = cpuRegisters->A + val;			  			// result = A + src
}

//need to get the value in the specify memory..
void add_shortmem	(uint8_t *opcodePtr){
	uint8_t addrs		=	 opcodePtr[1];	 							// the address is at the least byte of the opcode
	cpuRegisters->A	= cpuRegisters->A + memory[addrs];
}

//
void add_longmem (uint8_t *opcodePtr){
	uint16_t addrs  = combineTwoAddrs(opcodePtr[1],opcodePtr[2]);
	cpuRegisters->A =	cpuRegisters->A + memory[addrs];
}

void add_x (uint8_t *opcodePtr){
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
	cpuRegisters->A = cpuRegisters->A + memory[addrs];
}

void add_y (uint8_t *opcodePtr){
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
	cpuRegisters->A = cpuRegisters->A + memory[addrs];
}

void add_x_shortset (uint8_t *opcodePtr){
	uint8_t val 		= opcodePtr[1];
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
	cpuRegisters->A = cpuRegisters->A + memory[addrs+val];
}

void add_y_shortset (uint8_t *opcodePtr){
	uint8_t val 		= opcodePtr[2];
	uint16_t addrs 	= combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
	cpuRegisters->A = cpuRegisters->A + memory[addrs+val];
}

void add_x_longset (uint8_t *opcodePtr){
	uint16_t addrsOffset = combineTwoAddrs(opcodePtr[1],opcodePtr[2]);
	uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
	cpuRegisters->A			 =	cpuRegisters->A + memory[addrsOffset+addrsBase];
}

void add_y_longset (uint8_t *opcodePtr){
	uint16_t addrsOffset = combineTwoAddrs(opcodePtr[1],opcodePtr[2]);
	uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
	cpuRegisters->A			 =	cpuRegisters->A + memory[addrsOffset+addrsBase];
}

void add_shortoff_SP (uint8_t *opcodePtr){
	uint8_t addrsSP			 = opcodePtr[1];
	uint16_t addrsBase	 = combineTwoAddrs(cpuRegisters->SPH,cpuRegisters->SPL);
	cpuRegisters->A			 = cpuRegisters->A + memory[addrsBase+addrsSP];
}

// short pointer to long pointer
void add_shortptr_w(uint8_t *opcodePtr){
	uint8_t addrsOfFirstPtr = opcodePtr[2];
	uint8_t val1=memory[addrsOfFirstPtr];
	uint8_t val2=memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2);
	cpuRegisters->A = cpuRegisters->A + memory[addrsOfSecondPtr];
}

void add_longptr_w(uint8_t *opcodePtr){
	uint16_t addrsOfFirstPtr = combineTwoAddrs(opcodePtr[2],opcodePtr[3]);
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2);
	cpuRegisters->A = cpuRegisters->A + memory[addrsOfSecondPtr];
}

void add_shortptr_w_X(uint8_t *opcodePtr){
	uint8_t addrsOfFirstPtr = opcodePtr[2];
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t X	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
	cpuRegisters->A = cpuRegisters->A + memory[addrsOfSecondPtr];
}

void add_longptr_w_X(uint8_t *opcodePtr){
	uint16_t addrsOfFirstPtr = combineTwoAddrs(opcodePtr[2],opcodePtr[3]);
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t X	 = combineTwoAddrs(cpuRegisters->XH,cpuRegisters->XL);
	printf("%x\n",X);
	printf("%x\n",combineTwoAddrs(val1,val2));
	printf("%x\n",combineTwoAddrs(val1,val2)+X);
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + X;
	cpuRegisters->A = cpuRegisters->A + memory[addrsOfSecondPtr];
}

void add_shortptr_w_Y(uint8_t *opcodePtr){
	uint8_t addrsOfFirstPtr = opcodePtr[2];
	uint8_t val1 = memory[addrsOfFirstPtr];
	uint8_t val2 = memory[addrsOfFirstPtr+1];
	uint16_t Y	 = combineTwoAddrs(cpuRegisters->YH,cpuRegisters->YL);
	uint16_t addrsOfSecondPtr = combineTwoAddrs(val1,val2) + Y;
	cpuRegisters->A = cpuRegisters->A + memory[addrsOfSecondPtr];
}
