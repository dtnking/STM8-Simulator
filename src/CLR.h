#ifndef _CLR_H
#define _CLR_H
#include <stdint.h>

void    clr_byte          (uint8_t *opcodePtr);
void    clr_shortmem      (uint8_t *opcodePtr);
void    clr_longmem       (uint8_t *opcodePtr);
void    clr_x             (uint8_t *opcodePtr);
void    clr_y             (uint8_t *opcodePtr);
void    clr_x_shortset    (uint8_t *opcodePtr);
void    clr_y_shortset    (uint8_t *opcodePtr);
void    clr_x_longset     (uint8_t *opcodePtr);
void    clr_y_longset     (uint8_t *opcodePtr);
void    clr_shortoff_SP   (uint8_t *opcodePtr);
void    clr_shortptr_w    (uint8_t *opcodePtr);
void    clr_longptr_w     (uint8_t *opcodePtr);
void    clr_shortptr_w_X  (uint8_t *opcodePtr);
void    clr_longptr_w_X   (uint8_t *opcodePtr);
void    clr_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _CLR_H
