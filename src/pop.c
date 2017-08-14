#include "pop.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void pop_A(uint8_t *opcodePtr){
  raw_pop(&cpuRegisters->A);
}

void pop_CC(uint8_t *opcodePtr){
  raw_pop(&cpuRegisters->CCR.CC);      // condition code register
}

void pop_longmem(uint8_t *opcodePtr){
  raw_pop(&memory[get_longmem(opcodePtr)]);
}
