#ifndef _MEMORY_H
#define _MEMORY_H
#include <stdint.h>

#define KB 		1024
//typedef unsigned char	uint8_t;
unsigned char memory[20*KB];

typedef struct flags flags;
struct flags{
  uint8_t V;
  uint8_t I1;
  uint8_t H;
  uint8_t I0;
  uint8_t N;
  uint8_t Z;
  uint8_t C;
};

typedef struct Stm8Registers Stm8Registers;
struct Stm8Registers {
  uint8_t A;
  uint8_t PCE;
  uint8_t PCH;
  uint8_t PCL;
  uint8_t XH;
  uint8_t XL;
  uint8_t YH;
  uint8_t YL;
  uint8_t SPH;
  uint8_t SPL;
  flags CCR;
};

Stm8Registers *cpuRegisters;

uint8_t get_valueByte(uint8_t *opcode);
uint8_t get_shortmem(uint8_t *opcode);
uint8_t get_longmem(uint8_t *opcode);
uint8_t get_x(void);
uint8_t get_y(void);
uint8_t get_x_shortset(uint8_t *opcode);
uint8_t get_y_shortset(uint8_t *opcode);
uint8_t get_x_longset(uint8_t *opcode);
uint8_t get_y_longset(uint8_t *opcode);
uint8_t get_shortoff_SP(uint8_t *opcode);
uint8_t get_shortptr_w(uint8_t *opcode);
uint8_t get_longptr_w(uint8_t *opcode);
uint8_t get_shortptr_w_X(uint8_t *opcode);
uint8_t get_longptr_w_X(uint8_t *opcode);
uint8_t get_shortptr_w_Y(uint8_t *opcode);


#endif // _MEMORY_H
