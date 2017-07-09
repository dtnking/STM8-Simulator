#ifndef _MEMORY_H
#define _MEMORY_H

#define KB 		1024

typedef unsigned char	uint8_t;
typedef unsigned int  uint32_t;
char memory[20*KB];

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
  uint8_t CCR;
};

extern Stm8Registers *cpuRegisters;

#endif // _MEMORY_H
