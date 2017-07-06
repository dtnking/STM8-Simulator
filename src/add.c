#include "add.h"
#include "Simulator.h"




uint8_t add(uint8_t code){
	uint8_t val = nxt_byte(code);
	uint8_t getAddrsValue = a.Accumulator;
	uint8_t result = getAddrsValue+ val;
	return result;
}