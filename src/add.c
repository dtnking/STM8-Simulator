#include "add.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>



uint32_t add_byte(uint32_t code){
	uint32_t val = least_byte(code);											// the value is at least byte of the opcode
	uint32_t result = cpuRegisters->A + val;			  			// result = A + src
	return result;
}

//need to get the value in the specify memory..
uint32_t add_shortmem	(uint32_t code){
	uint32_t val		=	 least_byte(code);	 							// the address is at the least byte of the opcode
	uint32_t result	= cpuRegisters->A + memory[val];
	return result;
}

//
uint32_t add_longmem		(uint32_t code){
	uint32_t addrs  = 	two_Middlebyte(code);
	uint32_t result =	cpuRegisters->A + memory[addrs];
	return result;
}

uint32_t add_x (uint32_t code){
	uint32_t addrs 	= combineTwo(cpuRegisters->XH,cpuRegisters->XL);
	uint32_t result = cpuRegisters->A + memory[addrs];
	return result;
}

uint32_t add_y (uint32_t code){
	uint32_t addrs 	= combineTwo(cpuRegisters->YH,cpuRegisters->YL);
	uint32_t result = cpuRegisters->A + memory[addrs];
	return result;
}

uint32_t add_x_offset(uint32_t code){
	uint32_t val 		= least_byte(code);
	uint32_t addrs 	= combineTwo(cpuRegisters->XH,cpuRegisters->XL);
	uint32_t result = cpuRegisters->A + memory[addrs+val];
	return result;
}

uint32_t add_y_offset(uint32_t code){
	uint32_t val 		= least_byte(code);
	uint32_t addrs 	= combineTwo(cpuRegisters->YH,cpuRegisters->YL);
	uint32_t result = cpuRegisters->A + memory[addrs+val];
	printf("%x\n",memory[addrs+val]);
	printf("%x\n",val);
	printf("%x\n",addrs);
	return result;
}
