#include "addc.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

void addc_byte (uint8_t *opcodePtr){
	naked_addc(get_valueByte(opcodePtr));
}

void addc_shortmem	(uint8_t *opcodePtr){
	naked_addc(get_shortmem(opcodePtr));
}

void addc_longmem (uint8_t *opcodePtr){
	naked_addc(get_longmem(opcodePtr));
}

void addc_x (uint8_t *opcodePtr){
	naked_addc(get_x());
}

void addc_y (uint8_t *opcodePtr){
	naked_addc(get_y());
}

void addc_x_shortset (uint8_t *opcodePtr){
	naked_addc(get_x_shortset(opcodePtr));
}

void addc_y_shortset (uint8_t *opcodePtr){
	naked_addc(get_y_shortset(opcodePtr));
}

void addc_x_longset (uint8_t *opcodePtr){
	naked_addc(get_x_longset(opcodePtr));
}

void addc_y_longset (uint8_t *opcodePtr){
	naked_addc(get_y_longset(opcodePtr));
}

void addc_shortoff_SP (uint8_t *opcodePtr){
	naked_addc(get_shortoff_SP(opcodePtr));
}

void addc_shortptr_w(uint8_t *opcodePtr){
	naked_addc(get_shortptr_w(opcodePtr));
}

void addc_longptr_w(uint8_t *opcodePtr){
	naked_addc(get_longptr_w(opcodePtr));
}

void addc_shortptr_w_X(uint8_t *opcodePtr){
	naked_addc(get_shortptr_w_X(opcodePtr));
}

void addc_longptr_w_X(uint8_t *opcodePtr){
	naked_addc(get_longptr_w_X(opcodePtr));
}

void addc_shortptr_w_Y(uint8_t *opcodePtr){
	naked_addc(get_shortptr_w_Y(opcodePtr));
}
