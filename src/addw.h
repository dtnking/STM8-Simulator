#ifndef _ADDW_H
#define _ADDW_H
#include <stdint.h>

void   addw_word_X          (uint8_t *opcodePtr);
void   addw_longmem_X       (uint8_t *opcodePtr);
void   addw_shortoff_SP_X   (uint8_t *opcodePtr);
void   addw_word_Y          (uint8_t *opcodePtr);
void   addw_longmem_Y       (uint8_t *opcodePtr);
void   addw_shortoff_SP_Y   (uint8_t *opcodePtr);
void   addw_byte_SP         (uint8_t *opcodePtr);

#endif // _ADDW_H
