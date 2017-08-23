#include "JRXX.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdint.h>
#include <stdio.h>


void jrc(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.C == 1, 0);
}

void jreq(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.Z == 1, 0);
}

void jrf(uint8_t *opcodePtr){
  UPDATE_PC(2);
}

void jrh(uint8_t *opcodePtr){
  opcodePtr+=1;
  JRXX(cpuRegisters->CCR.bit.H == 1, 1);
}

void jrm(uint8_t *opcodePtr){
  opcodePtr+=1;
  JRXX(I == 1, 1);
}

void jrmi(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.N == 1, 0);
}

void jrnc(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.C == 0, 0);
}

void jrne(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.Z == 0, 0);
}

void jrnh(uint8_t *opcodePtr){
  opcodePtr+=1;
  JRXX(cpuRegisters->CCR.bit.H == 0, 1);
}

void jrnm(uint8_t *opcodePtr){
  opcodePtr+=1;
  JRXX(I == 0 , 1);
}

void jrnv(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.V == 0, 0);
}

void jrpl(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.N == 0, 0);
}

void jrsge(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.N ^ cpuRegisters->CCR.bit.V == 0, 0);
}

void jrsgt(uint8_t *opcodePtr){
  JRXX((cpuRegisters->CCR.bit.Z | (cpuRegisters->CCR.bit.N ^ cpuRegisters->CCR.bit.V)) == 0, 0);
}

void jrsle(uint8_t *opcodePtr){
  JRXX((cpuRegisters->CCR.bit.Z | (cpuRegisters->CCR.bit.N ^ cpuRegisters->CCR.bit.V)) == 1, 0);
}

void jrslt(uint8_t *opcodePtr){
  JRXX((cpuRegisters->CCR.bit.N ^ cpuRegisters->CCR.bit.V) == 1, 0);
}

void jrt(uint8_t *opcodePtr){
  set_PC(get_valueByte(opcodePtr)+ PC + 2);
}

void jruge(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.C == 0, 0);
}

void jrugt(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.C == 0 && cpuRegisters->CCR.bit.Z == 0, 0);
}

void jrule(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.C == 1 && cpuRegisters->CCR.bit.Z == 1, 0);
}

void jrult(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.C == 1, 0);
}

void jrv(uint8_t *opcodePtr){
  JRXX(cpuRegisters->CCR.bit.V == 1, 0);
}
