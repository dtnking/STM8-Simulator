#ifndef _SBC_H
#define _SBC_H
#include <stdint.h>

void    sbc_byte          (uint8_t *opcodePtr);
void    sbc_shortmem      (uint8_t *opcodePtr);
void    sbc_longmem       (uint8_t *opcodePtr);
void    sbc_x             (uint8_t *opcodePtr);
void    sbc_y             (uint8_t *opcodePtr);
void    sbc_x_shortset    (uint8_t *opcodePtr);
void    sbc_y_shortset    (uint8_t *opcodePtr);
void    sbc_x_longset     (uint8_t *opcodePtr);
void    sbc_y_longset     (uint8_t *opcodePtr);
void    sbc_shortoff_SP   (uint8_t *opcodePtr);
void    sbc_shortptr_w    (uint8_t *opcodePtr);
void    sbc_longptr_w     (uint8_t *opcodePtr);
void    sbc_shortptr_w_X  (uint8_t *opcodePtr);
void    sbc_longptr_w_X   (uint8_t *opcodePtr);
void    sbc_shortptr_w_Y  (uint8_t *opcodePtr);


#endif // _SBC_H
