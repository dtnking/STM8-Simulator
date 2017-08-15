#include "CCF.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void ccf(uint8_t *opcodePtr){
  cpuRegisters->CCR.bit.C = ~cpuRegisters->CCR.bit.C;
}
