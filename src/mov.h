#ifndef _MOV_H
#define _MOV_H
#include <stdint.h>

void mov_byte_longmem       (uint8_t *opcodePtr);
void mov_shortmem_shortmem  (uint8_t *opcodePtr);
void mov_longmem_longmem    (uint8_t *opcodePtr);

#endif // _MOV_H
