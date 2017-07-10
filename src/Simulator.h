#ifndef _SIMULATOR_H
#define _SIMULATOR_H
#include <stdint.h>

//typedef unsigned char	uint8_t;
//typedef unsigned int  uint32_t;

#define least_byte(byte)        (byte & 0xFF)
#define two_Middlebyte(byte1,byte2)    ((byte1<<8 +byte2) & 0xFFFF)

uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2);
#endif // _SIMULATOR_H
