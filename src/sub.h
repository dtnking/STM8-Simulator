#ifndef _SUB_H
#define _SUB_H
#include <stdint.h>

void    sub_byte          (uint8_t *opcodePtr);
void    sub_shortmem      (uint8_t *opcodePtr);
void    sub_longmem       (uint8_t *opcodePtr);
void    sub_x             (uint8_t *opcodePtr);
void    sub_y             (uint8_t *opcodePtr);
void    sub_x_shortset    (uint8_t *opcodePtr);
void    sub_y_shortset    (uint8_t *opcodePtr);
void    sub_x_longset     (uint8_t *opcodePtr);
void    sub_y_longset     (uint8_t *opcodePtr);
void    sub_shortoff_SP   (uint8_t *opcodePtr);
void    sub_shortptr_w    (uint8_t *opcodePtr);
void    sub_longptr_w     (uint8_t *opcodePtr);
void    sub_shortptr_w_X  (uint8_t *opcodePtr);
void    sub_longptr_w_X   (uint8_t *opcodePtr);
void    sub_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _SUB_H
