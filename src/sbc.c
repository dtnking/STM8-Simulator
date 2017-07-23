#include "sbc.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>

void sbc_byte (uint8_t *opcodePtr){
	raw_sbc(get_valueByte(opcodePtr));
}

void sbc_shortmem	(uint8_t *opcodePtr){
	raw_sbc(memory[get_shortmem(opcodePtr)]);
}

void sbc_longmem (uint8_t *opcodePtr){
	raw_sbc(memory[get_longmem(opcodePtr)]);
}

void sbc_x (uint8_t *opcodePtr){
	raw_sbc(memory[get_x_value()]);
}

void sbc_y (uint8_t *opcodePtr){
	raw_sbc(memory[get_y_value()]);
}

void sbc_x_shortset (uint8_t *opcodePtr){
	raw_sbc(memory[get_x_shortset(opcodePtr)]);
}

void sbc_y_shortset (uint8_t *opcodePtr){
	raw_sbc(memory[get_y_shortset(opcodePtr)]);
}

void sbc_x_longset (uint8_t *opcodePtr){
	raw_sbc(memory[get_x_longset(opcodePtr)]);
}

void sbc_y_longset (uint8_t *opcodePtr){
	raw_sbc(memory[get_y_longset(opcodePtr)]);
}

void sbc_shortoff_SP (uint8_t *opcodePtr){
	raw_sbc(memory[get_shortoff_SP(opcodePtr)]);
}

void sbc_shortptr_w(uint8_t *opcodePtr){
	raw_sbc(memory[get_shortptr_w(opcodePtr)]);
}

void sbc_longptr_w(uint8_t *opcodePtr){
	raw_sbc(memory[get_longptr_w(opcodePtr)]);
}

void sbc_shortptr_w_X(uint8_t *opcodePtr){
	raw_sbc(memory[get_shortptr_w_X(opcodePtr)]);
}

void sbc_longptr_w_X(uint8_t *opcodePtr){
	raw_sbc(memory[get_longptr_w_X(opcodePtr)]);
}

void sbc_shortptr_w_Y(uint8_t *opcodePtr){
	raw_sbc(memory[get_shortptr_w_Y(opcodePtr)]);
}
