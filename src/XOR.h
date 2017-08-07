#ifndef _XOR_H
#define _XOR_H
#include <stdint.h>

void    xor_byte          (uint8_t *opcodePtr);
void    xor_shortmem      (uint8_t *opcodePtr);
void    xor_longmem       (uint8_t *opcodePtr);
void    xor_x             (uint8_t *opcodePtr);
void    xor_y             (uint8_t *opcodePtr);
void    xor_x_shortset    (uint8_t *opcodePtr);
void    xor_y_shortset    (uint8_t *opcodePtr);
void    xor_x_longset     (uint8_t *opcodePtr);
void    xor_y_longset     (uint8_t *opcodePtr);
void    xor_shortoff_SP   (uint8_t *opcodePtr);
void    xor_shortptr_w    (uint8_t *opcodePtr);
void    xor_longptr_w     (uint8_t *opcodePtr);
void    xor_shortptr_w_X  (uint8_t *opcodePtr);
void    xor_longptr_w_X   (uint8_t *opcodePtr);
void    xor_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _Xxor_H
