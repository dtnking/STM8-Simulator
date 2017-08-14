#include "PUSH.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void push_A(uint8_t *opcodePtr){
  raw_push(cpuRegisters->A);
}

void push_CC(uint8_t *opcodePtr){
  raw_push(cpuRegisters->CCR.CC);      // condition code register
}

void push_longmem(uint8_t *opcodePtr){
  raw_push(memory[get_longmem(opcodePtr)]);
}

void push_byte(uint8_t *opcodePtr){
  raw_push(get_valueByte(opcodePtr));
}
