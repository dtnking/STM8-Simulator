#include "sub.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void sub_byte (uint8_t *opcodePtr){
	raw_sub(get_valueByte(opcodePtr));
}

void sub_shortmem	(uint8_t *opcodePtr){
	raw_sub(memory[get_shortmem(opcodePtr)]);
}

void sub_longmem (uint8_t *opcodePtr){
	raw_sub(memory[get_longmem(opcodePtr)]);
}

void sub_x (uint8_t *opcodePtr){
	raw_sub(memory[get_x_value()]);
}

void sub_y (uint8_t *opcodePtr){
	raw_sub(memory[get_y_value()]);
}

void sub_x_shortset (uint8_t *opcodePtr){
	raw_sub(memory[get_x_shortset(opcodePtr)]);
}

void sub_y_shortset (uint8_t *opcodePtr){
	raw_sub(memory[get_y_shortset(opcodePtr)]);
}

void sub_x_longset (uint8_t *opcodePtr){
	raw_sub(memory[get_x_longset(opcodePtr)]);
}

void sub_y_longset (uint8_t *opcodePtr){
	raw_sub(memory[get_y_longset(opcodePtr)]);
}

void sub_shortoff_SP (uint8_t *opcodePtr){
	raw_sub(memory[get_shortoff_SP(opcodePtr)]);
}

void sub_shortptr_w(uint8_t *opcodePtr){
	raw_sub(memory[get_shortptr_w(opcodePtr)]);
}

void sub_longptr_w(uint8_t *opcodePtr){
	raw_sub(memory[get_longptr_w(opcodePtr)]);
}

void sub_shortptr_w_X(uint8_t *opcodePtr){
	raw_sub(memory[get_shortptr_w_X(opcodePtr)]);
}

void sub_longptr_w_X(uint8_t *opcodePtr){
	raw_sub(memory[get_longptr_w_X(opcodePtr)]);
}

void sub_shortptr_w_Y(uint8_t *opcodePtr){
	raw_sub(memory[get_shortptr_w_Y(opcodePtr)]);
}
