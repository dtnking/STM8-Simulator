#ifndef _SIMULATOR_H
#define _SIMULATOR_H

#define KB 								1024
#define least_byte(byte)  (byte & 0x00FF)


char memor[20*KB];

typedef unsigned char	uint8_t;

typedef struct Memory Memory;
struct Memory{
	uint8_t A;
	uint8_t Xh;
	uint8_t XL;
	uint8_t YH;
	uint8_t YL;
	uint8_t PCE;
	uint8_t PCH;
	uint8_t PCL;
};
Memory value;

static uint8_t *a = &memor[0x007F00];


#endif // _SIMULATOR_H
