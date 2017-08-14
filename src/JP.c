#include "JP.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void jp_longmem(uint8_t *opcodePtr){
  raw_jp(get_longmem(opcodePtr));
}
