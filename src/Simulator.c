#include "Simulator.h"
#include "Memory.h"
#include "add.h"
#include <stdint.h>

uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2){
  uint16_t newVal1 = val1<<8;
  uint16_t result  = newVal1 + val2;
  return result;
}
