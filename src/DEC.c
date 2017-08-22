#include "DEC.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void dec_A(uint8_t *opcodePtr){
  raw_dec(&cpuRegisters->A);
  UPDATE_PC(1);
}

void dec_shortmem(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortmem(opcodePtr)]);
  UPDATE_PC(2);
}

void dec_longmem(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_dec(&memory[get_longmem(code)]);
  UPDATE_PC(4);
}

void dec_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_x_value()]);
  UPDATE_PC(1);
}

void dec_shortoff_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_x_shortset(opcodePtr)]);
  UPDATE_PC(2);
}

void dec_longoff_X(uint8_t *opcodePtr){
  uint8_t *code = opcodePtr+1;
  raw_dec(&memory[get_x_longset(code)]);
  UPDATE_PC(4);
}

void dec_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_y_value()]);
  UPDATE_PC(2);
}

void dec_shortoff_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_y_shortset(opcodePtr)]);
  UPDATE_PC(3);
}

void dec_longoff_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_y_longset(opcodePtr)]);
  UPDATE_PC(4);
}

void dec_shortoff_SP(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortoff_SP(opcodePtr)]);
  UPDATE_PC(2);
}

void dec_shortptr_w(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortptr_w(opcodePtr)]);
  UPDATE_PC(3);
}

void dec_longptr_w(uint8_t *opcodePtr){
  raw_dec(&memory[get_longptr_w(opcodePtr)]);
  UPDATE_PC(4);
}

void dec_shortptr_w_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortptr_w_X(opcodePtr)]);
  UPDATE_PC(3);
}

void dec_longptr_w_X(uint8_t *opcodePtr){
  raw_dec(&memory[get_longptr_w_X(opcodePtr)]);
  UPDATE_PC(4);
}

void dec_shortptr_w_Y(uint8_t *opcodePtr){
  raw_dec(&memory[get_shortptr_w_Y(opcodePtr)]);
  UPDATE_PC(3);
}
