#ifndef _OR_H
#define _OR_H
#include <stdint.h>

void    or_byte          (uint8_t *opcodePtr);
void    or_shortmem      (uint8_t *opcodePtr);
void    or_longmem       (uint8_t *opcodePtr);
void    or_x             (uint8_t *opcodePtr);
void    or_y             (uint8_t *opcodePtr);
void    or_x_shortset    (uint8_t *opcodePtr);
void    or_y_shortset    (uint8_t *opcodePtr);
void    or_x_longset     (uint8_t *opcodePtr);
void    or_y_longset     (uint8_t *opcodePtr);
void    or_shortoff_SP   (uint8_t *opcodePtr);
void    or_shortptr_w    (uint8_t *opcodePtr);
void    or_longptr_w     (uint8_t *opcodePtr);
void    or_shortptr_w_X  (uint8_t *opcodePtr);
void    or_longptr_w_X   (uint8_t *opcodePtr);
void    or_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _OR_H
