#include "AND.h"
#include "Raw_Operation.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

void and_byte (uint8_t *opcodePtr){
	raw_and(get_valueByte(opcodePtr));
}

void and_shortmem	(uint8_t *opcodePtr){
	raw_and(memory[get_shortmem(opcodePtr)]);
}

void and_longmem (uint8_t *opcodePtr){
	raw_and(memory[get_longmem(opcodePtr)]);
}

void and_x (uint8_t *opcodePtr){
	raw_and(memory[get_x_value()]);
}

void and_y (uint8_t *opcodePtr){
	raw_and(memory[get_y_value()]);
}

void and_x_shortset (uint8_t *opcodePtr){
	raw_and(memory[get_x_shortset(opcodePtr)]);
}

void and_y_shortset (uint8_t *opcodePtr){
	raw_and(memory[get_y_shortset(opcodePtr)]);
}

void and_x_longset (uint8_t *opcodePtr){
	raw_and(memory[get_x_longset(opcodePtr)]);
}

void and_y_longset (uint8_t *opcodePtr){
	raw_and(memory[get_y_longset(opcodePtr)]);
}

void and_shortoff_SP (uint8_t *opcodePtr){
	raw_and(memory[get_shortoff_SP(opcodePtr)]);
}

void and_shortptr_w(uint8_t *opcodePtr){
	raw_and(memory[get_shortptr_w(opcodePtr)]);
}

void and_longptr_w(uint8_t *opcodePtr){
	raw_and(memory[get_longptr_w(opcodePtr)]);
}

void and_shortptr_w_X(uint8_t *opcodePtr){
	raw_and(memory[get_shortptr_w_X(opcodePtr)]);
}

void and_longptr_w_X(uint8_t *opcodePtr){
	raw_and(memory[get_longptr_w_X(opcodePtr)]);
}

void and_shortptr_w_Y(uint8_t *opcodePtr){
	raw_and(memory[get_shortptr_w_Y(opcodePtr)]);
}
