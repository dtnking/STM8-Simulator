#include "DEC.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void dec_A(uint8_t *opcodePtr){
  raw_dec(&cpuRegisters->A);
}

void dec_shortmem(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortmem(opcodePtr)]);
}

void dec_longmem(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_dec(&memory[get_longmem(code)]);
}

void dec_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_x_value()]);
}

void dec_shortoff_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_x_shortset(opcodePtr)]);
}

void dec_longoff_X(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_dec(&memory[get_x_longset(code)]);
}

void dec_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_y_value()]);
}

void dec_shortoff_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_y_shortset(opcodePtr)]);
}

void dec_longoff_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_y_longset(opcodePtr)]);
}

void dec_shortoff_SP(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortoff_SP(opcodePtr)]);
}

void dec_shortptr_w(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortptr_w(opcodePtr)]);
}

void dec_longptr_w(uint8_t *opcodePtr){
  raw_dec(&memory[get_longptr_w(opcodePtr)]);
}

void dec_shortptr_w_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortptr_w_X(opcodePtr)]);
}

void dec_longptr_w_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_longptr_w_X(opcodePtr)]);
}

void dec_shortptr_w_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortptr_w_Y(opcodePtr)]);
}
