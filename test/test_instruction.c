#include "unity.h"
#include "instruction.h"
#include "Simulator.h"
#include "Memory.h"
#include "add.h"
#include "adc.h"
#include "sub.h"
#include "sbc.h"
#include "INC.h"
#include "Memory.h"

void setUp(void){}

void tearDown(void){}

void test_instruction_table(void){
  uint8_t *code = memory;
  int length = 0;
  memory[0] = 0xAB;             //add_byte
  memory[1] = 0x23;
  memory[2] = 0XBB;             //add_shortmem
  memory[3] = 0x30;
  memory[4] = 0xCB;             //add_longmem
  memory[5] = 0x10;
  memory[6] = 0x00;
  memory[7] = 0x90;             //sub_y
  memory[8] = 0xF0;
  memory[9] = 0x92;             //sub_shortptr_w
  memory[10]= 0xC0;
  memory[11]= 0x40;

  cpuRegisters->A  = 0x01;
  length = instruction(&code);
	TEST_ASSERT_EQUAL_HEX8 (0x24,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

  cpuRegisters->A  = 0x02;
  memory[0x30]		 =	0x55;
  length = instruction(&code);
	TEST_ASSERT_EQUAL_HEX8 (0x57,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

  cpuRegisters->A  = 0x03;
  memory[0x1000]	 =	0x10;
  length = instruction(&code);
  TEST_ASSERT_EQUAL_HEX8 (0x13,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (3,length);

  /*cpuRegisters->A 	= 0x01;
	set_Y(0x22,0x20);
	memory[0x2020] 		= 0x05;
  length = instruction(&code);
  TEST_ASSERT_EQUAL_HEX8 (0x06,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);*/
}
