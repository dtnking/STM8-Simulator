#ifndef _SIMULATOR_H
#define _SIMULATOR_H
#include <stdint.h>

#define least_byte(byte)        (byte & 0xFF)
#define two_Middlebyte(byte1,byte2)    ((byte1<<8 +byte2) & 0xFFFF)

uint16_t combineTwoAddrs(uint8_t val1, uint8_t val2);

void raw_add(uint8_t val);
void raw_adc(uint8_t val);
void raw_sub(uint8_t val);
void raw_sbc(uint8_t val);
void raw_inc(uint8_t *addrs);
void raw_and(uint8_t val);
void raw_or (uint8_t val);
void raw_xor(uint8_t val);
void raw_ld(uint8_t *srcAddrss, uint8_t *dstAddrss);

#endif // _SIMULATOR_H
