#ifndef _SIMULATOR_H
#define _SIMULATOR_H

typedef unsigned char	uint8_t;
#define nxt_byte(p)  (p & 0x00FF)


typedef struct Memory Memory;
struct Memory{
	uint8_t Accumulator;
};

Memory a;

	

#endif // _SIMULATOR_H
