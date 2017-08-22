#include "XOR.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void xor_byte (uint8_t *opcodePtr){
	raw_xor(get_valueByte(opcodePtr));
	UPDATE_PC(2);
}

void xor_shortmem	(uint8_t *opcodePtr){
	raw_xor(memory[get_shortmem(opcodePtr)]);
	UPDATE_PC(2);
}

void xor_longmem (uint8_t *opcodePtr){
	raw_xor(memory[get_longmem(opcodePtr)]);
	UPDATE_PC(3);
}

void xor_x (uint8_t *opcodePtr){
	raw_xor(memory[get_x_value()]);
	UPDATE_PC(1);
}

void xor_y (uint8_t *opcodePtr){
	raw_xor(memory[get_y_value()]);
	UPDATE_PC(2);
}

void xor_x_shortset (uint8_t *opcodePtr){
	raw_xor(memory[get_x_shortset(opcodePtr)]);
	UPDATE_PC(2);
}

void xor_y_shortset (uint8_t *opcodePtr){
	raw_xor(memory[get_y_shortset(opcodePtr)]);
	UPDATE_PC(3);
}

void xor_x_longset (uint8_t *opcodePtr){
	raw_xor(memory[get_x_longset(opcodePtr)]);
	UPDATE_PC(3);
}

void xor_y_longset (uint8_t *opcodePtr){
	raw_xor(memory[get_y_longset(opcodePtr)]);
	UPDATE_PC(4);
}

void xor_shortoff_SP (uint8_t *opcodePtr){
	raw_xor(memory[get_shortoff_SP(opcodePtr)]);
	UPDATE_PC(2);
}

void xor_shortptr_w(uint8_t *opcodePtr){
	raw_xor(memory[get_shortptr_w(opcodePtr)]);
	UPDATE_PC(3);
}

void xor_longptr_w(uint8_t *opcodePtr){
	raw_xor(memory[get_longptr_w(opcodePtr)]);
	UPDATE_PC(4);
}

void xor_shortptr_w_X(uint8_t *opcodePtr){
	raw_xor(memory[get_shortptr_w_X(opcodePtr)]);
	UPDATE_PC(3);
}

void xor_longptr_w_X(uint8_t *opcodePtr){
	raw_xor(memory[get_longptr_w_X(opcodePtr)]);
	UPDATE_PC(4);
}

void xor_shortptr_w_Y(uint8_t *opcodePtr){
	raw_xor(memory[get_shortptr_w_Y(opcodePtr)]);
	UPDATE_PC(3);
}
