#include "LD.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

/*
** ###################< LOAD from memory to register >###########################
*/
void ldMemToReg_byte(uint8_t *opcodePtr){
	uint8_t byteVal = get_valueByte(opcodePtr);
	raw_ld(&byteVal, &cpuRegisters->A);
	UPDATE_PC(2);
}

void ldMemToReg_shortmem(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortmem(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(2);
}

void ldMemToReg_longmem(uint8_t *opcodePtr){
	raw_ld(&memory[get_longmem(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(3);
}

void ldMemToReg_x(uint8_t *opcodePtr){
	raw_ld(&memory[get_x_value()], &cpuRegisters->A);
	UPDATE_PC(1);
}

void ldMemToReg_y(uint8_t *opcodePtr){
	raw_ld(&memory[get_y_value()], &cpuRegisters->A);
	UPDATE_PC(2);
}

void ldMemToReg_x_shortset(uint8_t *opcodePtr){
	raw_ld(&memory[get_x_shortset(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(2);
}

void ldMemToReg_y_shortset(uint8_t *opcodePtr){
	raw_ld(&memory[get_y_shortset(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(3);
}

void ldMemToReg_x_longset(uint8_t *opcodePtr){
	raw_ld(&memory[get_x_longset(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(3);
}

void ldMemToReg_y_longset(uint8_t *opcodePtr){
	raw_ld(&memory[get_y_longset(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(4);
}

void ldMemToReg_shortoff_SP(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortoff_SP(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(2);
}

void ldMemToReg_shortptr_w(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortptr_w(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(3);
}

void ldMemToReg_longptr_w(uint8_t *opcodePtr){
	raw_ld(&memory[get_longptr_w(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(4);
}

void ldMemToReg_shortptr_w_X(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortptr_w_X(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(3);
}

void ldMemToReg_longptr_w_X(uint8_t *opcodePtr){
	raw_ld(&memory[get_longptr_w_X(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(4);
}

void ldMemToReg_shortptr_w_Y(uint8_t *opcodePtr){
	raw_ld(&memory[get_shortptr_w_Y(opcodePtr)], &cpuRegisters->A);
	UPDATE_PC(3);
}

/*
** ###################< LOAD from register to memory >###########################
*/
void ldRegToMem_shortmem(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortmem(opcodePtr)]);
	UPDATE_PC(2);
}

void ldRegToMem_longmem(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_longmem(opcodePtr)]);
	UPDATE_PC(3);
}

void ldRegToMem_x(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_x_value()]);
	UPDATE_PC(1);
}

void ldRegToMem_y(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_y_value()]);
	UPDATE_PC(2);
}

void ldRegToMem_x_shortset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_x_shortset(opcodePtr)]);
	UPDATE_PC(2);
}

void ldRegToMem_y_shortset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_y_shortset(opcodePtr)]);
	UPDATE_PC(3);
}

void ldRegToMem_x_longset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_x_longset(opcodePtr)]);
	UPDATE_PC(3);
}

void ldRegToMem_y_longset(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_y_longset(opcodePtr)]);
	UPDATE_PC(4);
}

void ldRegToMem_shortoff_SP(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortoff_SP(opcodePtr)]);
	UPDATE_PC(2);
}

void ldRegToMem_shortptr_w(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortptr_w(opcodePtr)]);
	UPDATE_PC(3);
}

void ldRegToMem_longptr_w(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_longptr_w(opcodePtr)]);
	UPDATE_PC(4);
}

void ldRegToMem_shortptr_w_X(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortptr_w_X(opcodePtr)]);
	UPDATE_PC(3);
}

void ldRegToMem_longptr_w_X(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_longptr_w_X(opcodePtr)]);
	UPDATE_PC(4);
}

void ldRegToMem_shortptr_w_Y(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&memory[get_shortptr_w_Y(opcodePtr)]);
	UPDATE_PC(3);
}


/*
** ###################< LOAD from register to register >###########################
*/
void ldRegToReg_A_to_XL(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&cpuRegisters->XL);
	UPDATE_PC(1);
}

void ldRegToReg_XL_to_A(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->XL,&cpuRegisters->A);
	UPDATE_PC(1);
}

void ldRegToReg_A_to_YL(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&cpuRegisters->YL);
	UPDATE_PC(2);
}

void ldRegToReg_YL_to_A(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->YL,&cpuRegisters->A);
	UPDATE_PC(2);
}

void ldRegToReg_A_to_XH(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&cpuRegisters->XH);
	UPDATE_PC(1);
}

void ldRegToReg_XH_to_A(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->XH,&cpuRegisters->A);
	UPDATE_PC(1);
}

void ldRegToReg_A_to_YH(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->A,&cpuRegisters->YH);
	UPDATE_PC(2);
}

void ldRegToReg_YH_to_A(uint8_t *opcodePtr){
	raw_ld(&cpuRegisters->YH,&cpuRegisters->A);
	UPDATE_PC(2);
}
