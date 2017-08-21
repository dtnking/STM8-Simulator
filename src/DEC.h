#ifndef _DEC_H
#define _DEC_H
#include <stdint.h>

void    dec_A             (uint8_t *opcodePtr);
void    dec_shortmem      (uint8_t *opcodePtr);
void    dec_longmem       (uint8_t *opcodePtr);
void    dec_X             (uint8_t *opcodePtr);
void    dec_Y             (uint8_t *opcodePtr);
void    dec_shortoff_X    (uint8_t *opcodePtr);
void    dec_shortoff_Y    (uint8_t *opcodePtr);
void    dec_longoff_X     (uint8_t *opcodePtr);
void    dec_longoff_Y     (uint8_t *opcodePtr);
void    dec_shortoff_SP   (uint8_t *opcodePtr);
void    dec_shortptr_w    (uint8_t *opcodePtr);
void    dec_longptr_w     (uint8_t *opcodePtr);
void    dec_shortptr_w_X  (uint8_t *opcodePtr);
void    dec_longptr_w_X   (uint8_t *opcodePtr);
void    dec_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _DEC_H
