#ifndef _INC_H
#define _INC_H
#include<stdint.h>

void    inc_A             (uint8_t *opcodePtr);
void    inc_byte          (uint8_t *opcodePtr);
void    inc_shortmem      (uint8_t *opcodePtr);
void    inc_longmem       (uint8_t *opcodePtr);
void    inc_x             (uint8_t *opcodePtr);
void    inc_y             (uint8_t *opcodePtr);
void    inc_x_shortset    (uint8_t *opcodePtr);
void    inc_y_shortset    (uint8_t *opcodePtr);
void    inc_x_longset     (uint8_t *opcodePtr);
void    inc_y_longset     (uint8_t *opcodePtr);
void    inc_shortoff_SP   (uint8_t *opcodePtr);
void    inc_shortptr_w    (uint8_t *opcodePtr);
void    inc_longptr_w     (uint8_t *opcodePtr);
void    inc_shortptr_w_X  (uint8_t *opcodePtr);
void    inc_longptr_w_X   (uint8_t *opcodePtr);
void    inc_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _INC_H
