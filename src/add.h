#ifndef _ADD_H
#define _ADD_H

typedef unsigned char     uint8_t;
typedef unsigned int      uint32_t;

uint32_t    add_byte          (uint32_t code);
uint32_t    add_shortmem      (uint32_t code);
uint32_t    add_shortmem      (uint32_t code);
uint32_t    add_longmem       (uint32_t code);
uint32_t    add_x             (uint32_t code);
uint32_t    add_y             (uint32_t code);
uint32_t    add_x_offset      (uint32_t code);
uint32_t    add_y_offset      (uint32_t code);
#endif // _ADD_H
