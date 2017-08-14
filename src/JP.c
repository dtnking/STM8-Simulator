#include "JP.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void jp_longmem(uint8_t *opcodePtr){
  uint32_t addrs = get_longmem(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_X(uint8_t *opcodePtr){
  uint32_t addrs = get_x_value();
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_X_shortset(uint8_t *opcodePtr){
  uint32_t addrs = get_x_shortset(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_X_longset(uint8_t *opcodePtr){
  uint32_t addrs = get_x_longset(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_Y(uint8_t *opcodePtr){
  uint32_t addrs = get_y_value();
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_Y_shortset(uint8_t *opcodePtr){
  uint32_t addrs = get_y_shortset(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_Y_longset(uint8_t *opcodePtr){
  uint32_t addrs = get_y_longset(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_shortptr_W(uint8_t *opcodePtr){
  uint32_t addrs = get_shortptr_w(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_longptr_W(uint8_t *opcodePtr){
  uint32_t addrs = get_longptr_w(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_shortptr_W_X(uint8_t *opcodePtr){
  uint32_t addrs = get_shortptr_w_X(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_longptr_W_X(uint8_t *opcodePtr){
  uint32_t addrs = get_longptr_w_X(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}

void jp_shortptr_W_Y(uint8_t *opcodePtr){
  uint32_t addrs = get_shortptr_w_Y(opcodePtr);
  set_PC(GET_HMSB(addrs),GET_MSB(addrs),GET_LSB(addrs));
}
