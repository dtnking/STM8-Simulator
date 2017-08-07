#ifndef _LD_H
#define _LD_H
#include <stdint.h>

void    ldA_byte          (uint8_t *opcodePtr);
void    ldA_shortmem      (uint8_t *opcodePtr);
void    ldA_longmem       (uint8_t *opcodePtr);
void    ldA_x             (uint8_t *opcodePtr);
void    ldA_y             (uint8_t *opcodePtr);
void    ldA_x_shortset    (uint8_t *opcodePtr);
void    ldA_y_shortset    (uint8_t *opcodePtr);
void    ldA_x_longset     (uint8_t *opcodePtr);
void    ldA_y_longset     (uint8_t *opcodePtr);
void    ldA_shortoff_SP   (uint8_t *opcodePtr);
void    ldA_shortptr_w    (uint8_t *opcodePtr);
void    ldA_longptr_w     (uint8_t *opcodePtr);
void    ldA_shortptr_w_X  (uint8_t *opcodePtr);
void    ldA_longptr_w_X   (uint8_t *opcodePtr);
void    ldA_shortptr_w_Y  (uint8_t *opcodePtr);


#endif // _LD_H
