#ifndef _SIMULATOR_H
#define _SIMULATOR_H
#include <stdint.h>


void raw_add  (uint8_t val);
void raw_adc  (uint8_t val);
void raw_sub  (uint8_t val);
void raw_sbc  (uint8_t val);
void raw_inc  (uint8_t *addrs);
void raw_and  (uint8_t val);
void raw_or   (uint8_t val);
void raw_xor  (uint8_t val);
void raw_ld   (uint8_t *srcAddrss, uint8_t *dstAddrss);
void raw_mov  (uint8_t *srcAddrss, uint8_t *dstAddrss);

#endif // _SIMULATOR_H
