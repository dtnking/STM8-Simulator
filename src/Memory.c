#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdint.h>


Stm8Registers *cpuRegisters=(Stm8Registers *)&memory[0x7f00];
