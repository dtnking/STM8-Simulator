#include "INC.h"
#include "Simulator.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>

void inc_A(uint8_t *opcodePtr){
  raw_inc(&cpuRegisters->A);
}

void inc_shortmem(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortmem(opcodePtr)]);
}

void inc_longmem(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_inc(&memory[get_longmem(code)]);
}

void inc_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_x_value()]);
}

void inc_shortoff_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_x_shortset(opcodePtr)]);
}

void inc_longoff_X(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_inc(&memory[get_x_longset(code)]);
}

void inc_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_y_value()]);
}

void inc_shortoff_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_y_shortset(opcodePtr)]);
}

void inc_longoff_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_y_longset(opcodePtr)]);
}

void inc_shortoff_SP(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortoff_SP(opcodePtr)]);
}

void inc_shortptr_w(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortptr_w(opcodePtr)]);
}

void inc_longptr_w(uint8_t *opcodePtr){
  raw_inc(&memory[get_longptr_w(opcodePtr)]);
}

void inc_shortptr_w_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortptr_w_X(opcodePtr)]);
}

void inc_longptr_w_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_longptr_w_X(opcodePtr)]);
}

void inc_shortptr_w_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortptr_w_Y(opcodePtr)]);
}
