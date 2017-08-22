#include "CLR.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void clr_A (uint8_t *opcodePtr){
	raw_clr(&cpuRegisters->A);
	UPDATE_PC(1);
}

void clr_shortmem	(uint8_t *opcodePtr){
	raw_clr(&memory[get_shortmem(opcodePtr)]);
	UPDATE_PC(2);
}

void clr_longmem (uint8_t *opcodePtr){
	raw_clr(&memory[get_longmem(opcodePtr+1)]);
	UPDATE_PC(4);
}

void clr_x (uint8_t *opcodePtr){
	raw_clr(&memory[get_x_value()]);
	UPDATE_PC(1);
}

void clr_y (uint8_t *opcodePtr){
	raw_clr(&memory[get_y_value()]);
	UPDATE_PC(2);
}

void clr_x_shortset (uint8_t *opcodePtr){
	raw_clr(&memory[get_x_shortset(opcodePtr)]);
	UPDATE_PC(2);
}

void clr_y_shortset (uint8_t *opcodePtr){
	raw_clr(&memory[get_y_shortset(opcodePtr)]);
	UPDATE_PC(3);
}

void clr_x_longset (uint8_t *opcodePtr){
	raw_clr(&memory[get_x_longset(opcodePtr+1)]);
	UPDATE_PC(4);
}

void clr_y_longset (uint8_t *opcodePtr){
	raw_clr(&memory[get_y_longset(opcodePtr)]);
	UPDATE_PC(4);
}

void clr_shortoff_SP (uint8_t *opcodePtr){
	raw_clr(&memory[get_shortoff_SP(opcodePtr)]);
	UPDATE_PC(2);
}

void clr_shortptr_w(uint8_t *opcodePtr){
	raw_clr(&memory[get_shortptr_w(opcodePtr)]);
	UPDATE_PC(3);
}

void clr_longptr_w(uint8_t *opcodePtr){
	raw_clr(&memory[get_longptr_w(opcodePtr)]);
	UPDATE_PC(4);
}

void clr_shortptr_w_X(uint8_t *opcodePtr){
	raw_clr(&memory[get_shortptr_w_X(opcodePtr)]);
	UPDATE_PC(3);
}

void clr_longptr_w_X(uint8_t *opcodePtr){
	raw_clr(&memory[get_longptr_w_X(opcodePtr)]);
	UPDATE_PC(4);
}

void clr_shortptr_w_Y(uint8_t *opcodePtr){
	raw_clr(&memory[get_shortptr_w_Y(opcodePtr)]);
	UPDATE_PC(3);
}
