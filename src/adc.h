#ifndef _ADDC_H
#define _ADDC_H
#include <stdint.h>

void    addc_byte          (uint8_t *opcodePtr);
void    addc_shortmem      (uint8_t *opcodePtr);
void    addc_longmem       (uint8_t *opcodePtr);
void    addc_x             (uint8_t *opcodePtr);
void    addc_y             (uint8_t *opcodePtr);
void    addc_x_shortset    (uint8_t *opcodePtr);
void    addc_y_shortset    (uint8_t *opcodePtr);
void    addc_x_longset     (uint8_t *opcodePtr);
void    addc_y_longset     (uint8_t *opcodePtr);
void    addc_shortoff_SP   (uint8_t *opcodePtr);
void    addc_shortptr_w    (uint8_t *opcodePtr);
void    addc_longptr_w     (uint8_t *opcodePtr);
void    addc_shortptr_w_X  (uint8_t *opcodePtr);
void    addc_longptr_w_X   (uint8_t *opcodePtr);
void    addc_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _ADDC_H
