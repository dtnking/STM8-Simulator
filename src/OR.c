#include "OR.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void or_byte (uint8_t *opcodePtr){
	raw_or(get_valueByte(opcodePtr));
	UPDATE_PC(2);
}

void or_shortmem	(uint8_t *opcodePtr){
	raw_or(memory[get_shortmem(opcodePtr)]);
	UPDATE_PC(2);
}

void or_longmem (uint8_t *opcodePtr){
	raw_or(memory[get_longmem(opcodePtr)]);
	UPDATE_PC(3);
}

void or_x (uint8_t *opcodePtr){
	raw_or(memory[get_x_value()]);
	UPDATE_PC(1);
}

void or_y (uint8_t *opcodePtr){
	raw_or(memory[get_y_value()]);
	UPDATE_PC(2);
}

void or_x_shortset (uint8_t *opcodePtr){
	raw_or(memory[get_x_shortset(opcodePtr)]);
	UPDATE_PC(2);
}

void or_y_shortset (uint8_t *opcodePtr){
	raw_or(memory[get_y_shortset(opcodePtr)]);
	UPDATE_PC(3);
}

void or_x_longset (uint8_t *opcodePtr){
	raw_or(memory[get_x_longset(opcodePtr)]);
	UPDATE_PC(3);
}

void or_y_longset (uint8_t *opcodePtr){
	raw_or(memory[get_y_longset(opcodePtr)]);
	UPDATE_PC(4);
}

void or_shortoff_SP (uint8_t *opcodePtr){
	raw_or(memory[get_shortoff_SP(opcodePtr)]);
	UPDATE_PC(2);
}

void or_shortptr_w(uint8_t *opcodePtr){
	raw_or(memory[get_shortptr_w(opcodePtr)]);
	UPDATE_PC(3);
}

void or_longptr_w(uint8_t *opcodePtr){
	raw_or(memory[get_longptr_w(opcodePtr)]);
	UPDATE_PC(4);
}

void or_shortptr_w_X(uint8_t *opcodePtr){
	raw_or(memory[get_shortptr_w_X(opcodePtr)]);
	UPDATE_PC(3);
}

void or_longptr_w_X(uint8_t *opcodePtr){
	raw_or(memory[get_longptr_w_X(opcodePtr)]);
	UPDATE_PC(4);
}

void or_shortptr_w_Y(uint8_t *opcodePtr){
	raw_or(memory[get_shortptr_w_Y(opcodePtr)]);
	UPDATE_PC(3);
}
