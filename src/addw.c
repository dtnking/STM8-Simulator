#include "addw.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>

void addw_word_X(uint8_t *opcodePtr){
  raw_addw(get_longmem(opcodePtr),&cpuRegisters->XH,&cpuRegisters->XL);
  UPDATE_PC(3);
}

void addw_longmem_X(uint8_t *opcodePtr){
  raw_addw(memory[get_longmem(opcodePtr+1)],&cpuRegisters->XH,&cpuRegisters->XL);
  UPDATE_PC(4);
}

void addw_shortoff_SP_X(uint8_t *opcodePtr){
  raw_addw(memory[get_shortoff_SP(opcodePtr+1)],&cpuRegisters->XH,&cpuRegisters->XL);
  UPDATE_PC(3);
}

void addw_word_Y(uint8_t *opcodePtr){
  raw_addw(get_longmem(opcodePtr+1),&cpuRegisters->YH,&cpuRegisters->YL);
  UPDATE_PC(4);
}

void addw_longmem_Y(uint8_t *opcodePtr){
  raw_addw(memory[get_longmem(opcodePtr+1)],&cpuRegisters->YH,&cpuRegisters->YL);
  UPDATE_PC(4);
}

void addw_shortoff_SP_Y(uint8_t *opcodePtr){
  raw_addw(memory[get_shortoff_SP(opcodePtr+1)],&cpuRegisters->YH,&cpuRegisters->YL);
  UPDATE_PC(3);
}

void addw_byte_SP(uint8_t *opcodePtr){
  raw_addw(get_valueByte(opcodePtr),&cpuRegisters->SPH,&cpuRegisters->SPL);
  UPDATE_PC(2);
}
