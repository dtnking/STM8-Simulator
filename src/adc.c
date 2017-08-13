#include "adc.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void adc_byte (uint8_t *opcodePtr){
	raw_adc(get_valueByte(opcodePtr));
}

void adc_shortmem (uint8_t *opcodePtr){
	raw_adc(memory[get_shortmem(opcodePtr)]);
}

void adc_longmem (uint8_t *opcodePtr){
	raw_adc(memory[get_longmem(opcodePtr)]);
}

void adc_x (uint8_t *opcodePtr){
	raw_adc(memory[get_x_value()]);
}

void adc_y (uint8_t *opcodePtr){
	raw_adc(memory[get_y_value()]);
}

void adc_x_shortset (uint8_t *opcodePtr){
	raw_adc(memory[get_x_shortset(opcodePtr)]);
}

void adc_y_shortset (uint8_t *opcodePtr){
	raw_adc(memory[get_y_shortset(opcodePtr)]);
}

void adc_x_longset (uint8_t *opcodePtr){
	raw_adc(memory[get_x_longset(opcodePtr)]);
}

void adc_y_longset (uint8_t *opcodePtr){
	raw_adc(memory[get_y_longset(opcodePtr)]);
}

void adc_shortoff_SP (uint8_t *opcodePtr){
	raw_adc(memory[get_shortoff_SP(opcodePtr)]);
}

void adc_shortptr_w(uint8_t *opcodePtr){
	raw_adc(memory[get_shortptr_w(opcodePtr)]);
}

void adc_longptr_w(uint8_t *opcodePtr){
	raw_adc(memory[get_longptr_w(opcodePtr)]);
}

void adc_shortptr_w_X(uint8_t *opcodePtr){
	raw_adc(memory[get_shortptr_w_X(opcodePtr)]);
}

void adc_longptr_w_X(uint8_t *opcodePtr){
	raw_adc(memory[get_longptr_w_X(opcodePtr)]);
}

void adc_shortptr_w_Y(uint8_t *opcodePtr){
	raw_adc(memory[get_shortptr_w_Y(opcodePtr)]);
}
