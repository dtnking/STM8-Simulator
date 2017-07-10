#ifndef _ADD_H
#define _ADD_H
#include <stdint.h>

void    add_byte          (uint8_t *opcodePtr);
void    add_shortmem      (uint8_t *opcodePtr);
void    add_longmem       (uint8_t *opcodePtr);
void    add_x             (uint8_t *opcodePtr);
void    add_y             (uint8_t *opcodePtr);
void    add_x_shortset    (uint8_t *opcodePtr);
void    add_y_shortset    (uint8_t *opcodePtr);
void    add_x_longset     (uint8_t *opcodePtr);
void    add_y_longset     (uint8_t *opcodePtr);
void    add_shortoff_SP   (uint8_t *opcodePtr);
#endif // _ADD_H
