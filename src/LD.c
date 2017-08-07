#include "LD.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

// LOAD from memory to register
void ldMemToReg_byte(uint8_t *opcodePtr){
	raw_ld(get_valueByte(opcodePtr));
}

void ldMemToReg_shortmem(uint8_t *opcodePtr){
	raw_ld(memory[get_shortmem(opcodePtr)]);
}

void ldMemToReg_longmem(uint8_t *opcodePtr){
	raw_ld(memory[get_longmem(opcodePtr)]);
}

void ldMemToReg_x(uint8_t *opcodePtr){
	raw_ld(memory[get_x_value()]);
}

void ldMemToReg_y(uint8_t *opcodePtr){
	raw_ld(memory[get_y_value()]);
}

void ldMemToReg_x_shortset(uint8_t *opcodePtr){
	raw_ld(memory[get_x_shortset(opcodePtr)]);
}

void ldMemToReg_y_shortset(uint8_t *opcodePtr){
	raw_ld(memory[get_y_shortset(opcodePtr)]);
}

void ldMemToReg_x_longset(uint8_t *opcodePtr){
	raw_ld(memory[get_x_longset(opcodePtr)]);
}

void ldMemToReg_y_longset(uint8_t *opcodePtr){
	raw_ld(memory[get_y_longset(opcodePtr)]);
}

void ldMemToReg_shortoff_SP(uint8_t *opcodePtr){
	raw_ld(memory[get_shortoff_SP(opcodePtr)]);
}

void ldMemToReg_shortptr_w(uint8_t *opcodePtr){
	raw_ld(memory[get_shortptr_w(opcodePtr)]);
}

void ldMemToReg_longptr_w(uint8_t *opcodePtr){
	raw_ld(memory[get_longptr_w(opcodePtr)]);
}

void ldMemToReg_shortptr_w_X(uint8_t *opcodePtr){
	raw_ld(memory[get_shortptr_w_X(opcodePtr)]);
}

void ldMemToReg_longptr_w_X(uint8_t *opcodePtr){
	raw_ld(memory[get_longptr_w_X(opcodePtr)]);
}

void ldMemToReg_shortptr_w_Y(uint8_t *opcodePtr){
	raw_ld(memory[get_shortptr_w_Y(opcodePtr)]);
}
