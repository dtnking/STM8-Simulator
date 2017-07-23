#ifndef _ADDC_H
#define _ADDC_H
#include <stdint.h>

void    adc_byte          (uint8_t *opcodePtr);
void    adc_shortmem      (uint8_t *opcodePtr);
void    adc_longmem       (uint8_t *opcodePtr);
void    adc_x             (uint8_t *opcodePtr);
void    adc_y             (uint8_t *opcodePtr);
void    adc_x_shortset    (uint8_t *opcodePtr);
void    adc_y_shortset    (uint8_t *opcodePtr);
void    adc_x_longset     (uint8_t *opcodePtr);
void    adc_y_longset     (uint8_t *opcodePtr);
void    adc_shortoff_SP   (uint8_t *opcodePtr);
void    adc_shortptr_w    (uint8_t *opcodePtr);
void    adc_longptr_w     (uint8_t *opcodePtr);
void    adc_shortptr_w_X  (uint8_t *opcodePtr);
void    adc_longptr_w_X   (uint8_t *opcodePtr);
void    adc_shortptr_w_Y  (uint8_t *opcodePtr);

#endif // _ADDC_H
