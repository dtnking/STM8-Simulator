#include "unity.h"
#include "Simulator.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include "add.h"
#include "adc.h"
#include "sub.h"
#include "sbc.h"
#include "INC.h"
#include "XOR.h"
#include "OR.h"
#include "mov.h"
#include "AND.h"
#include "LD.h"


void setUp(void){}

void tearDown(void){}

void test_instruction_table(void){
  uint8_t *code = memory;
  int length = 0;
  memory[0] = 0xAB;             //add_byte(using opcodeTable)
  memory[1] = 0x23;
  memory[2] = 0XBB;             //add_shortmem(using opcodeTable)
  memory[3] = 0x30;
  memory[4] = 0xCB;             //add_longmem(using opcodeTable)
  memory[5] = 0x10;
  memory[6] = 0x00;
  memory[7] = 0x90;             //sub_y(using opcodeTable90)
  memory[8] = 0xF0;
  memory[9] = 0x92;             //ld Reg to Mem(using opcodeTable92)
  memory[10]= 0xC7;
  memory[11]= 0x23;

// test for instruction add 1 byte directly into Accumulator expected counter pointer +2
  cpuRegisters->A  = 0x01;
  length = instruction(&code);
	TEST_ASSERT_EQUAL_HEX8 (0x24,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

// test for instruction add with shortmemory expected counter pointer +2
  cpuRegisters->A  = 0x02;
  memory[0x30]		 =	0x55;
  length = instruction(&code);
	TEST_ASSERT_EQUAL_HEX8 (0x57,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

// test for instruction add with longmemory expected counter pointer +3
  cpuRegisters->A  = 0x03;
  memory[0x1000]	 =	0x10;
  length = instruction(&code);
  TEST_ASSERT_EQUAL_HEX8 (0x13,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (3,length);

// test for instruction subtract with offset Y expected counter pointer +2
  cpuRegisters->A 	= 0x0b;
	set_Y(0x22,0x20);
	memory[0x2220] 		= 0x05;
  length = instruction(&code);
  TEST_ASSERT_EQUAL_HEX8 (0x06,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

// test for instruction load from Register to Memory expected counter pointer +3
	memory[0x23]			= 0x42;
	memory[0x24]			= 0xe5;
	cpuRegisters->A 	= 0x11;
  length = instruction(&code);
  TEST_ASSERT_EQUAL_HEX8 (0x11,memory[0x42e5]);
  TEST_ASSERT_EQUAL_INT (3,length);


}
