#include "LD.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

void ldA_byte(uint8_t *opcodePtr){
	raw_ldA(get_valueByte(opcodePtr));
}

void ldA_shortmem(uint8_t *opcodePtr){
	raw_ldA(memory[get_shortmem(opcodePtr)]);
}

void ldA_longmem(uint8_t *opcodePtr){
	raw_ldA(memory[get_longmem(opcodePtr)]);
}

void ldA_x(uint8_t *opcodePtr){
	raw_ldA(memory[get_x_value()]);
}

void ldA_y(uint8_t *opcodePtr){
	raw_ldA(memory[get_y_value()]);
}

void ldA_x_shortset(uint8_t *opcodePtr){
	raw_ldA(memory[get_x_shortset(opcodePtr)]);
}

void ldA_y_shortset(uint8_t *opcodePtr){
	raw_ldA(memory[get_y_shortset(opcodePtr)]);
}

void ldA_x_longset(uint8_t *opcodePtr){
	raw_ldA(memory[get_x_longset(opcodePtr)]);
}

void ldA_y_longset(uint8_t *opcodePtr){
	raw_ldA(memory[get_y_longset(opcodePtr)]);
}

void ldA_shortoff_SP(uint8_t *opcodePtr){
	raw_ldA(memory[get_shortoff_SP(opcodePtr)]);
}

void ldA_shortptr_w(uint8_t *opcodePtr){
	raw_ldA(memory[get_shortptr_w(opcodePtr)]);
}

void ldA_longptr_w(uint8_t *opcodePtr){
	raw_ldA(memory[get_longptr_w(opcodePtr)]);
}

void ldA_shortptr_w_X(uint8_t *opcodePtr){
	raw_ldA(memory[get_shortptr_w_X(opcodePtr)]);
}

void ldA_longptr_w_X(uint8_t *opcodePtr){
	raw_ldA(memory[get_longptr_w_X(opcodePtr)]);
}

void ldA_shortptr_w_Y(uint8_t *opcodePtr){
	raw_ldA(memory[get_shortptr_w_Y(opcodePtr)]);
}
