#include "sub.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void sub_byte (uint8_t *opcodePtr){
	raw_sub(get_valueByte(opcodePtr));
	UPDATE_PC(2);
}

void sub_shortmem	(uint8_t *opcodePtr){
	raw_sub(memory[get_shortmem(opcodePtr)]);
	UPDATE_PC(2);
}

void sub_longmem (uint8_t *opcodePtr){
	raw_sub(memory[get_longmem(opcodePtr)]);
	UPDATE_PC(3);
}

void sub_x (uint8_t *opcodePtr){
	raw_sub(memory[get_x_value()]);
	UPDATE_PC(1);
}

void sub_y (uint8_t *opcodePtr){
	raw_sub(memory[get_y_value()]);
	UPDATE_PC(2);
}

void sub_x_shortset (uint8_t *opcodePtr){
	raw_sub(memory[get_x_shortset(opcodePtr)]);
	UPDATE_PC(2);
}

void sub_y_shortset (uint8_t *opcodePtr){
	raw_sub(memory[get_y_shortset(opcodePtr)]);
	UPDATE_PC(3);
}

void sub_x_longset (uint8_t *opcodePtr){
	raw_sub(memory[get_x_longset(opcodePtr)]);
	UPDATE_PC(3);
}

void sub_y_longset (uint8_t *opcodePtr){
	raw_sub(memory[get_y_longset(opcodePtr)]);
	UPDATE_PC(4);
}

void sub_shortoff_SP (uint8_t *opcodePtr){
	raw_sub(memory[get_shortoff_SP(opcodePtr)]);
	UPDATE_PC(2);
}

void sub_shortptr_w(uint8_t *opcodePtr){
	raw_sub(memory[get_shortptr_w(opcodePtr)]);
	UPDATE_PC(3);
}

void sub_longptr_w(uint8_t *opcodePtr){
	raw_sub(memory[get_longptr_w(opcodePtr)]);
	UPDATE_PC(4);
}

void sub_shortptr_w_X(uint8_t *opcodePtr){
	raw_sub(memory[get_shortptr_w_X(opcodePtr)]);
	UPDATE_PC(2);
}

void sub_longptr_w_X(uint8_t *opcodePtr){
	raw_sub(memory[get_longptr_w_X(opcodePtr)]);
	UPDATE_PC(3);
}

void sub_shortptr_w_Y(uint8_t *opcodePtr){
	raw_sub(memory[get_shortptr_w_Y(opcodePtr)]);
	UPDATE_PC(3);
}
