#ifndef _MEMORY_H
#define _MEMORY_H
#include <stdint.h>

#define KB 		1024

//define CCR


// define bits of R (Result)
#define R0        (result & 0x1)
#define R1        (result & 0x2)     >>  1
#define R2        (result & 0x4)     >>  2
#define R3        (result & 0x8)     >>  3
#define R4        (result & 0x10)    >>  4
#define R5        (result & 0x20)    >>  5
#define R6        (result & 0x40)    >>  6
#define R7        (result & 0x80)    >>  7

// define bits of A (Accumulator)
#define A0        ((cpuRegisters->A) & 0x1)
#define A1        ((cpuRegisters->A) & 0x2)     >>  1
#define A2        ((cpuRegisters->A) & 0x4)     >>  2
#define A3        ((cpuRegisters->A) & 0x8)     >>  3
#define A4        ((cpuRegisters->A) & 0x10)    >>  4
#define A5        ((cpuRegisters->A) & 0x20)    >>  5
#define A6        ((cpuRegisters->A) & 0x40)    >>  6
#define A7        ((cpuRegisters->A) & 0x80)    >>  7

// define bits of M (value)
#define M0        (val & 0x1)
#define M1        (val & 0x2)     >>  1
#define M2        (val & 0x4)     >>  2
#define M3        (val & 0x8)     >>  3
#define M4        (val & 0x10)    >>  4
#define M5        (val & 0x20)    >>  5
#define M6        (val & 0x40)    >>  6
#define M7        (val & 0x80)    >>  7
//typedef unsigned char	uint8_t;
unsigned char memory[20*KB];

typedef struct flags flags;
struct flags{
  uint8_t C:1;
  uint8_t Z:1;
  uint8_t N:1;
  uint8_t I0:1;
  uint8_t H:1;
  uint8_t I1:1;
  uint8_t V:1;
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
uint16_t get_longmem(uint8_t *opcode);
uint16_t get_x_value(void);
uint16_t get_y_value(void);
uint16_t get_x_shortset(uint8_t *opcode);
uint16_t get_y_shortset(uint8_t *opcode);
uint16_t get_x_longset(uint8_t *opcode);
uint16_t get_y_longset(uint8_t *opcode);
uint16_t get_shortoff_SP(uint8_t *opcode);
uint16_t get_shortptr_w(uint8_t *opcode);
uint16_t get_longptr_w(uint8_t *opcode);
uint16_t get_shortptr_w_X(uint8_t *opcode);
uint16_t get_longptr_w_X(uint8_t *opcode);
uint16_t get_shortptr_w_Y(uint8_t *opcode);
void    set_X(uint8_t xh,uint8_t xl);
void    set_Y(uint8_t yh,uint8_t yl);
void    set_SP(uint8_t sph,uint8_t spl);
void    clearCCRflag();




#endif // _MEMORY_H
