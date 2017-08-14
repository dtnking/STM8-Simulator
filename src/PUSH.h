#ifndef _PUSH_H
#define _PUSH_H
#include <stdint.h>

void  push_A          (uint8_t *opcodePtr);
void  push_CC         (uint8_t *opcodePtr);
void  push_longmem    (uint8_t *opcodePtr);
void  push_byte       (uint8_t *opcodePtr);

#endif // _PUSH_H
