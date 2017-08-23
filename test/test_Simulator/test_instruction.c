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
#include "DEC.h"
#include "JRXX.h"
#include "LD.h"
#include "JP.h"
#include "MUL.h"
#include "pop.h"
#include "PUSH.h"
#include "CCF.h"
#include "SCF.h"
#include "CLR.h"

void setUp(void){}

void tearDown(void){}

void test_instruction_table(void){
  PC = 0;

  int length = 0;
  memory[0x00] = 0xAB;             //add_byte(using opcodeTable)
  memory[0x01] = 0x23;
  memory[0x02] = 0XBB;             //add_shortmem(using opcodeTable)
  memory[0x03] = 0x30;
  memory[0x04] = 0xCB;             //add_longmem(using opcodeTable)
  memory[0x05] = 0x10;
  memory[0x06] = 0x00;
  memory[0x07] = 0x90;             //sub_y(using opcodeTable90)
  memory[0x08] = 0xF0;
  memory[0x09] = 0x92;             //ld Reg to Mem(using opcodeTable92)
  memory[0x0a] = 0xC7;
  memory[0x0b] = 0x23;
  memory[0x0c] = 0x72;            //dec_longoff_X(using opcodeTable72)
  memory[0x0d] = 0x4A;
  memory[0x0e] = 0x11;
  memory[0x0f] = 0x11;
  memory[0x10] = 0x91;             // jp_shortptr_w_Y( using opcodeTable 91)
  memory[0x11] = 0xDC;
  memory[0x12] = 0x21;



// test for instruction add 1 byte directly into Accumulator expected PC +2
  cpuRegisters->A  = 0x01;
  length = Simulator();
	TEST_ASSERT_EQUAL_HEX8 (0x24,cpuRegisters->A);

// test for instruction add with shortmemory expected PC +2
  cpuRegisters->A  = 0x02;
  memory[0x30]		 =	0x55;
  length = Simulator();
	TEST_ASSERT_EQUAL_HEX8 (0x57,cpuRegisters->A);

// test for instruction add with longmemory expected PC +3
  cpuRegisters->A  = 0x03;
  memory[0x1000]	 =	0x10;
  length = Simulator();
  TEST_ASSERT_EQUAL_HEX8 (0x13,cpuRegisters->A);

// test for instruction subtract with offset Y expected PC +2
  cpuRegisters->A 	= 0x0b;
	set_Y(0x2220);
	memory[0x2220] 		= 0x05;
  length = Simulator();
  TEST_ASSERT_EQUAL_HEX8 (0x06,cpuRegisters->A);

// test for instruction load from Register to Memory expected PC +3
	memory[0x23]			= 0x42;
	memory[0x24]			= 0xe5;
	cpuRegisters->A 	= 0x11;
  length = Simulator();
  TEST_ASSERT_EQUAL_HEX8 (0x11,memory[0x42e5]);

// test for instruction dec_longoff_X expected PC +4
  set_X(0x3434);
  memory[0x4545]  = 0x10;
  length = Simulator();
  TEST_ASSERT_EQUAL_HEX8 (0x0f,memory[0x4545]);

// test for instruction jp_shortptr_w_Y expected PC to jump to memory 0x02 and
// execute instruction add with shortmem, then PC + 4
  set_Y(0x0001);
  cpuRegisters->A  = 0x02;
  memory[0x21] = 0x00;
  memory[0x22] = 0x01;
  Simulator();   // this simulate is doing the JP instruction, PC is pointed to a memory 0x02
  Simulator();   // After JP instruction is executed, the Simulator will executed the instruction where PC is pointed
  TEST_ASSERT_EQUAL_HEX8 (0x57,cpuRegisters->A);
  TEST_ASSERT_EQUAL_INT (4,length);
}
