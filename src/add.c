#include "add.h"
#include "Simulator.h"

uint8_t add(uint8_t code){
	uint8_t val = least_byte(code);
	uint8_t result = value.A + val;			// result = A + src
	return result;
}
