#include "unity.h"
#include "instruction.h"
#include "Simulator.h"
#include "Memory.h"
#include "add.h"

void setUp(void){}

void tearDown(void){}

void test_instruction_table(void){
  uint8_t *code = memory;
  int length = 0;
  memory[0] = 0xAB;             //add_byte
  memory[1] = 0x23;
  memory[2] = 0XBB;             //add_shortmem
  memory[3] = 0x10;
  memory[4] = 0xCB;             //add_longmem
  memory[5] = 0x10;
  memory[6] = 0x00;

  cpuRegisters->A  = 0x01;
  length = instruction(&code);
	TEST_ASSERT_EQUAL_HEX8 (0x24,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

  cpuRegisters->A  = 0x02;
  memory[0x10]		 =	0x55;
  length = instruction(&code);
	TEST_ASSERT_EQUAL_HEX8 (0x57,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (2,length);

  cpuRegisters->A  = 0x03;
  memory[0x1000]	 =	0x10;
  length = instruction(&code);
  TEST_ASSERT_EQUAL_HEX8 (0x13,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (3,length);
}
