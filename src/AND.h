#ifndef _AND_H
#define _AND_H
#include <stdint.h>

void    and_byte          (uint8_t *opcodePtr);
void    and_shortmem      (uint8_t *opcodePtr);
void    and_longmem       (uint8_t *opcodePtr);
void    and_x             (uint8_t *opcodePtr);
void    and_y             (uint8_t *opcodePtr);
void    and_x_shortset    (uint8_t *opcodePtr);
void    and_y_shortset    (uint8_t *opcodePtr);
void    and_x_longset     (uint8_t *opcodePtr);
void    and_y_longset     (uint8_t *opcodePtr);
void    and_shortoff_SP   (uint8_t *opcodePtr);
void    and_shortptr_w    (uint8_t *opcodePtr);
void    and_longptr_w     (uint8_t *opcodePtr);
void    and_shortptr_w_X  (uint8_t *opcodePtr);
void    and_longptr_w_X   (uint8_t *opcodePtr);
void    and_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _AND_H
