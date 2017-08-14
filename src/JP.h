#ifndef _JP_H
#define _JP_H
#include <stdint.h>

void    jp_longmem       (uint8_t *opcodePtr);
void    jp_X             (uint8_t *opcodePtr);
void    jp_Y             (uint8_t *opcodePtr);
void    jp_X_shortset    (uint8_t *opcodePtr);
void    jp_Y_shortset    (uint8_t *opcodePtr);
void    jp_X_longset     (uint8_t *opcodePtr);
void    jp_Y_longset     (uint8_t *opcodePtr);
void    jp_shortptr_W    (uint8_t *opcodePtr);
void    jp_longptr_W     (uint8_t *opcodePtr);
void    jp_shortptr_W_X  (uint8_t *opcodePtr);
void    jp_longptr_W_X   (uint8_t *opcodePtr);
void    jp_shortptr_W_Y  (uint8_t *opcodePtr);

#endif // _JP_H
