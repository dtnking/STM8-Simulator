#include "XOR.h"
#include "Raw_Operation.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

void xor_byte (uint8_t *opcodePtr){
	raw_xor(get_valueByte(opcodePtr));
}

void xor_shortmem	(uint8_t *opcodePtr){
	raw_xor(memory[get_shortmem(opcodePtr)]);
}

void xor_longmem (uint8_t *opcodePtr){
	raw_xor(memory[get_longmem(opcodePtr)]);
}

void xor_x (uint8_t *opcodePtr){
	raw_xor(memory[get_x_value()]);
}

void xor_y (uint8_t *opcodePtr){
	raw_xor(memory[get_y_value()]);
}

void xor_x_shortset (uint8_t *opcodePtr){
	raw_xor(memory[get_x_shortset(opcodePtr)]);
}

void xor_y_shortset (uint8_t *opcodePtr){
	raw_xor(memory[get_y_shortset(opcodePtr)]);
}

void xor_x_longset (uint8_t *opcodePtr){
	raw_xor(memory[get_x_longset(opcodePtr)]);
}

void xor_y_longset (uint8_t *opcodePtr){
	raw_xor(memory[get_y_longset(opcodePtr)]);
}

void xor_shortoff_SP (uint8_t *opcodePtr){
	raw_xor(memory[get_shortoff_SP(opcodePtr)]);
}

void xor_shortptr_w(uint8_t *opcodePtr){
	raw_xor(memory[get_shortptr_w(opcodePtr)]);
}

void xor_longptr_w(uint8_t *opcodePtr){
	raw_xor(memory[get_longptr_w(opcodePtr)]);
}

void xor_shortptr_w_X(uint8_t *opcodePtr){
	raw_xor(memory[get_shortptr_w_X(opcodePtr)]);
}

void xor_longptr_w_X(uint8_t *opcodePtr){
	raw_xor(memory[get_longptr_w_X(opcodePtr)]);
}

void xor_shortptr_w_Y(uint8_t *opcodePtr){
	raw_xor(memory[get_shortptr_w_Y(opcodePtr)]);
}
