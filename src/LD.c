#include "LD.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

// LOAD from memory to register
void ldMemToReg_byte(uint8_t *opcodePtr){
	uint8_t byteVal = get_valueByte(opcodePtr);
	raw_ld(&byteVal, &cpuRegisters->A);
}

void ldMemToReg_shortmem(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortmem(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_longmem(uint8_t *opcodePtr){
	raw_ld(&memory[get_longmem(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_x(uint8_t *opcodePtr){
	raw_ld(&memory[get_x_value()], &cpuRegisters->A);
}

void ldMemToReg_y(uint8_t *opcodePtr){
	raw_ld(&memory[get_y_value()], &cpuRegisters->A);
}

void ldMemToReg_x_shortset(uint8_t *opcodePtr){
	raw_ld(&memory[get_x_shortset(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_y_shortset(uint8_t *opcodePtr){
	raw_ld(&memory[get_y_shortset(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_x_longset(uint8_t *opcodePtr){
	raw_ld(&memory[get_x_longset(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_y_longset(uint8_t *opcodePtr){
	raw_ld(&memory[get_y_longset(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_shortoff_SP(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortoff_SP(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_shortptr_w(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortptr_w(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_longptr_w(uint8_t *opcodePtr){
	raw_ld(&memory[get_longptr_w(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_shortptr_w_X(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortptr_w_X(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_longptr_w_X(uint8_t *opcodePtr){
	raw_ld(&memory[get_longptr_w_X(opcodePtr)], &cpuRegisters->A);
}

void ldMemToReg_shortptr_w_Y(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortptr_w_Y(opcodePtr)], &cpuRegisters->A);
}

/*
** ################### LOAD from register to memory ###########################
*/
void ldRegToMem_shortmem(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortmem(opcodePtr)]);
}

void ldRegToMem_longmem(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_longmem(opcodePtr)]);
}

void ldRegToMem_x(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_x_value()]);
}

void ldRegToMem_y(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_y_value()]);
}

void ldRegToMem_x_shortset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_x_shortset(opcodePtr)]);
}

void ldRegToMem_y_shortset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_y_shortset(opcodePtr)]);
}

void ldRegToMem_x_longset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_x_longset(opcodePtr)]);
}

void ldRegToMem_y_longset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_y_longset(opcodePtr)]);
}

void ldRegToMem_shortoff_SP(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortoff_SP(opcodePtr)]);
}

void ldRegToMem_shortptr_w(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortptr_w(opcodePtr)]);
}

void ldRegToMem_longptr_w(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_longptr_w(opcodePtr)]);
}

void ldRegToMem_shortptr_w_X(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortptr_w_X(opcodePtr)]);
}

void ldRegToMem_longptr_w_X(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_longptr_w_X(opcodePtr)]);
}

void ldRegToMem_shortptr_w_Y(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortptr_w_Y(opcodePtr)]);
}
