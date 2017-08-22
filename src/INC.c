#include "INC.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void inc_A(uint8_t *opcodePtr){
  raw_inc(&cpuRegisters->A);
  UPDATE_PC(1);
}

void inc_shortmem(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortmem(opcodePtr)]);
  UPDATE_PC(2);
}

void inc_longmem(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_inc(&memory[get_longmem(code)]);
  UPDATE_PC(4);
}

void inc_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_x_value()]);
  UPDATE_PC(1);
}

void inc_shortoff_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_x_shortset(opcodePtr)]);
  UPDATE_PC(2);
}

void inc_longoff_X(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_inc(&memory[get_x_longset(code)]);
  UPDATE_PC(4);
}

void inc_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_y_value()]);
  UPDATE_PC(2);
}

void inc_shortoff_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_y_shortset(opcodePtr)]);
  UPDATE_PC(3);
}

void inc_longoff_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_y_longset(opcodePtr)]);
  UPDATE_PC(4);
}

void inc_shortoff_SP(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortoff_SP(opcodePtr)]);
  UPDATE_PC(2);
}

void inc_shortptr_w(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortptr_w(opcodePtr)]);
  UPDATE_PC(3);
}

void inc_longptr_w(uint8_t *opcodePtr){
  raw_inc(&memory[get_longptr_w(opcodePtr)]);
  UPDATE_PC(4);
}

void inc_shortptr_w_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortptr_w_X(opcodePtr)]);
  UPDATE_PC(3);
}

void inc_longptr_w_X(uint8_t *opcodePtr){
  raw_inc(&memory[get_longptr_w_X(opcodePtr)]);
  UPDATE_PC(4);
}

void inc_shortptr_w_Y(uint8_t *opcodePtr){
  raw_inc(&memory[get_shortptr_w_Y(opcodePtr)]);
  UPDATE_PC(3);
}
