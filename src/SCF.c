#include "SCF.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void scf(uint8_t *opcodePtr){
  cpuRegisters->CCR.bit.C = 1;
}
