#include "OR.h"
#include "Raw_Operation.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

void or_byte (uint8_t *opcodePtr){
	raw_or(get_valueByte(opcodePtr));
}

void or_shortmem	(uint8_t *opcodePtr){
	raw_or(memory[get_shortmem(opcodePtr)]);
}

void or_longmem (uint8_t *opcodePtr){
	raw_or(memory[get_longmem(opcodePtr)]);
}

void or_x (uint8_t *opcodePtr){
	raw_or(memory[get_x_value()]);
}

void or_y (uint8_t *opcodePtr){
	raw_or(memory[get_y_value()]);
}

void or_x_shortset (uint8_t *opcodePtr){
	raw_or(memory[get_x_shortset(opcodePtr)]);
}

void or_y_shortset (uint8_t *opcodePtr){
	raw_or(memory[get_y_shortset(opcodePtr)]);
}

void or_x_longset (uint8_t *opcodePtr){
	raw_or(memory[get_x_longset(opcodePtr)]);
}

void or_y_longset (uint8_t *opcodePtr){
	raw_or(memory[get_y_longset(opcodePtr)]);
}

void or_shortoff_SP (uint8_t *opcodePtr){
	raw_or(memory[get_shortoff_SP(opcodePtr)]);
}

void or_shortptr_w(uint8_t *opcodePtr){
	raw_or(memory[get_shortptr_w(opcodePtr)]);
}

void or_longptr_w(uint8_t *opcodePtr){
	raw_or(memory[get_longptr_w(opcodePtr)]);
}

void or_shortptr_w_X(uint8_t *opcodePtr){
	raw_or(memory[get_shortptr_w_X(opcodePtr)]);
}

void or_longptr_w_X(uint8_t *opcodePtr){
	raw_or(memory[get_longptr_w_X(opcodePtr)]);
}

void or_shortptr_w_Y(uint8_t *opcodePtr){
	raw_or(memory[get_shortptr_w_Y(opcodePtr)]);
}
