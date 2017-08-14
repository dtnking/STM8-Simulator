#ifndef _POP_H
#define _POP_H
#include <stdint.h>

void  pop_A          (uint8_t *opcodePtr);
void  pop_CC         (uint8_t *opcodePtr);
void  pop_longmem    (uint8_t *opcodePtr);

#endif // _POP_H
