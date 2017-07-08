#include "add.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>



uint8_t add_byte(uint8_t code){
	uint8_t val = least_byte(code);																										// the value is at least byte of the opcode
	uint8_t result = cpuRegisters->A + val;			  			// result = A + src
	return result;
}

//need to get the value in the specify memory..
uint32_t add_shortmem	(uint32_t code){
	uint32_t val		 =	 least_byte(code);	 							// the address is at the least byte of the opcode
	uint32_t result = cpuRegisters->A + memory[val];
	return result;
}

uint32_t add_longmem		(uint32_t code){
	uint32_t addrs  = 	two_Middlebyte(code);
	printf("%x",addrs);
	uint32_t result =	cpuRegisters->A + memory[addrs];
	return result;
}
