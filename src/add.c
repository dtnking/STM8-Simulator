#include "add.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>

void add_byte (uint8_t *opcodePtr){
	raw_add(get_valueByte(opcodePtr));
	printf("abc\n");
}

void add_shortmem	(uint8_t *opcodePtr){
	raw_add(memory[get_shortmem(opcodePtr)]);
	printf("cba\n");
}

void add_longmem (uint8_t *opcodePtr){
	raw_add(memory[get_longmem(opcodePtr)]);
}

void add_x (uint8_t *opcodePtr){
	raw_add(memory[get_x_value()]);
}

void add_y (uint8_t *opcodePtr){
	raw_add(memory[get_y_value()]);
}

void add_x_shortset (uint8_t *opcodePtr){
	raw_add(memory[get_x_shortset(opcodePtr)]);
}

void add_y_shortset (uint8_t *opcodePtr){
	raw_add(memory[get_y_shortset(opcodePtr)]);
}

void add_x_longset (uint8_t *opcodePtr){
	raw_add(memory[get_x_longset(opcodePtr)]);
}

void add_y_longset (uint8_t *opcodePtr){
	raw_add(memory[get_y_longset(opcodePtr)]);
}

void add_shortoff_SP (uint8_t *opcodePtr){
	raw_add(memory[get_shortoff_SP(opcodePtr)]);
}

void add_shortptr_w(uint8_t *opcodePtr){
	raw_add(memory[get_shortptr_w(opcodePtr)]);
}

void add_longptr_w(uint8_t *opcodePtr){
	raw_add(memory[get_longptr_w(opcodePtr)]);
}

void add_shortptr_w_X(uint8_t *opcodePtr){
	raw_add(memory[get_shortptr_w_X(opcodePtr)]);
}

void add_longptr_w_X(uint8_t *opcodePtr){
	raw_add(memory[get_longptr_w_X(opcodePtr)]);
}

void add_shortptr_w_Y(uint8_t *opcodePtr){
	raw_add(memory[get_shortptr_w_Y(opcodePtr)]);
}
