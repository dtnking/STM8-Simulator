#ifndef _LD_H
#define _LD_H
#include <stdint.h>

// LOAD from Memory to Register
void    ldMemToReg_byte          (uint8_t *opcodePtr);
void    ldMemToReg_shortmem      (uint8_t *opcodePtr);
void    ldMemToReg_longmem       (uint8_t *opcodePtr);
void    ldMemToReg_x             (uint8_t *opcodePtr);
void    ldMemToReg_y             (uint8_t *opcodePtr);
void    ldMemToReg_x_shortset    (uint8_t *opcodePtr);
void    ldMemToReg_y_shortset    (uint8_t *opcodePtr);
void    ldMemToReg_x_longset     (uint8_t *opcodePtr);
void    ldMemToReg_y_longset     (uint8_t *opcodePtr);
void    ldMemToReg_shortoff_SP   (uint8_t *opcodePtr);
void    ldMemToReg_shortptr_w    (uint8_t *opcodePtr);
void    ldMemToReg_longptr_w     (uint8_t *opcodePtr);
void    ldMemToReg_shortptr_w_X  (uint8_t *opcodePtr);
void    ldMemToReg_longptr_w_X   (uint8_t *opcodePtr);
void    ldMemToReg_shortptr_w_Y  (uint8_t *opcodePtr);


// LOAD from Register to Memory
void    ldRegToMem_byte          (uint8_t *opcodePtr);
void    ldRegToMem_shortmem      (uint8_t *opcodePtr);
void    ldRegToMem_longmem       (uint8_t *opcodePtr);
void    ldRegToMem_x             (uint8_t *opcodePtr);
void    ldRegToMem_y             (uint8_t *opcodePtr);
void    ldRegToMem_x_shortset    (uint8_t *opcodePtr);
void    ldRegToMem_y_shortset    (uint8_t *opcodePtr);
void    ldRegToMem_x_longset     (uint8_t *opcodePtr);
void    ldRegToMem_y_longset     (uint8_t *opcodePtr);
void    ldRegToMem_shortoff_SP   (uint8_t *opcodePtr);
void    ldRegToMem_shortptr_w    (uint8_t *opcodePtr);
void    ldRegToMem_longptr_w     (uint8_t *opcodePtr);
void    ldRegToMem_shortptr_w_X  (uint8_t *opcodePtr);
void    ldRegToMem_longptr_w_X   (uint8_t *opcodePtr);
void    ldRegToMem_shortptr_w_Y  (uint8_t *opcodePtr);


// LOAD from Register to Register
void    ldRegToReg_A_to_XL       (uint8_t *opcodePtr);
void    ldRegToReg_XL_to_A       (uint8_t *opcodePtr);
void    ldRegToReg_A_to_YL       (uint8_t *opcodePtr);
void    ldRegToReg_YL_to_A       (uint8_t *opcodePtr);
void    ldRegToReg_A_to_XH       (uint8_t *opcodePtr);
void    ldRegToReg_XH_to_A       (uint8_t *opcodePtr);
void    ldRegToReg_A_to_YH       (uint8_t *opcodePtr);
void    ldRegToReg_YH_to_A       (uint8_t *opcodePtr);

#endif // _LD_H
