#include "MUL.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void mul_X(uint8_t *opcodePtr){
  uint16_t result = raw_mul(cpuRegisters->XL);
  set_X(result);  // the result is store into the index register X(XH,XL)
  UPDATE_PC(1);
}

void mul_Y(uint8_t *opcodePtr){
  uint16_t result = raw_mul(cpuRegisters->YL);
  set_Y(result);  // the result is store into the index register Y(YH,YL)
  UPDATE_PC(2);
}
