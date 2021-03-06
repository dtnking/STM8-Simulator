#include "mov.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void mov_byte_longmem(uint8_t *opcodePtr){
  uint8_t byteVal = get_valueByte(opcodePtr);
  raw_mov(&byteVal,&memory[get_longmem(opcodePtr+1)]);
  UPDATE_PC(4);
}

void mov_shortmem_shortmem(uint8_t *opcodePtr){
  raw_mov(&memory[get_shortmem(opcodePtr)],&memory[get_shortmem(opcodePtr+1)]);
  UPDATE_PC(3);
}

void mov_longmem_longmem(uint8_t *opcodePtr){
  raw_mov(&memory[get_longmem(opcodePtr)],&memory[get_longmem(opcodePtr+2)]);
  UPDATE_PC(5);
}
