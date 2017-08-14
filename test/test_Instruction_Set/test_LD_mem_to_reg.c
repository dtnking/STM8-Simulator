#include "unity.h"
#include "LD.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

/*
**    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
**    X  Syntax : LD dst,src        e.g. LD A,#$15	 X
**		X	 Operation : dst <= src                			 X	
**    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
*/


/*    Load byte directly to register
**  =======================================
**   |   Name   : byte     |
**   | Location : -        |     [Accumulator]
**   |  Value   : 0x55     |---------^
*/
void test_LD_mem_to_reg_byte_0x55_expected_0x55(void){
	uint8_t instrc[] = {0xB6,0x55};			 // Opcode : 0xB610
	ldMemToReg_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, cpuRegisters->A);
}


/*    Load byte from short memory to register
**  =======================================
**   |   Name   : shortMem |
**   | Location : 0x10     |     [Accumulator]
**   |  Value   : 0x55     |---------^
*/
void test_LD_mem_to_reg_shortmen_0x55_expected_0x55(void){
	memory[0x10]		 =	0x55;						// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xB6,0x10};			// Opcode : 0xB610
	ldMemToReg_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, cpuRegisters->A);
}


/*   Load byte from long memory to register
** =======================================
**   |   Name   : LongMem |
**   | Location : 0x1000  |     [Accumulator]
**   |  Value   : 0xCC    |---------^
*/
void test_LD_mem_to_reg_longmen_0xCC_expected_0xCC(void){
	memory[0x1000]	 =	0xCC;								  // store 0xCC into register location 0x1000.
	uint8_t instrc[] = {0xB6,0x10,0x00};		  // Opcode : 0xB61000
	ldMemToReg_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xCC, cpuRegisters->A);
}


/*   Load byte from X to register
** =======================================
**   |   Name   : X      |
**   | Location : 0x1110 |     [Accumulator]
**   |  Value   : 0xDD   |--(load)----^
*/
void test_LD_mem_to_reg_X_0xDD_expected_0xDD(void){
  set_X(0x11,0x10);
  memory[0x1110] 		= 0xDD;         // store 0xDD into register location 0x1110.
	uint8_t instrc[]  = {0xF6};				 // Opcode : 0xF6
	ldMemToReg_x(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xDD, cpuRegisters->A);
}


/*   Load byte from Y to register
** =======================================
**   |   Name   : Y      |
**   | Location : 0x1210 |     [Accumulator]
**   |  Value   : 0xEE   |--(load)----^
*/
void test_LD_mem_to_reg_Y_0xEE_expected_0xEE(void){
  set_Y(0x12,0x10);
  memory[0x1210] 		= 0xEE;         // store 0xEE into register location 0x1210.
	uint8_t instrc[]  = {0x90,0xF6};	 // Opcode : 0x90F6
	ldMemToReg_y(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xEE, cpuRegisters->A);
}


/*   Load byte from shortoff_X to register
** =========================================
**   |   Name   : ShortOff X      |
**   | Location : 0x1212 + 0x01   |     [Accumulator]
**   |  Value   : 0xFF            |--(load)----^
*/
void test_LD_mem_to_reg_shortoff_X_0xFF_expected_0xFF(void){
  set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xE6,0x01};		 // Opcode : 0xE601
  memory[0x1213] 		= 0xFF;            // store 0xFF into register location 0x1213.
  ldMemToReg_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xFF, cpuRegisters->A);
}


/*   Load byte from shortoff_Y to register
** =========================================
**   |   Name   : ShortOff Y      |
**   | Location : 0x2323 + 0x22   |     [Accumulator]
**   |  Value   : 0x7D            |--(load)----^
*/
void test_LD_mem_to_reg_shortoff_Y_0x7D_expected_0x7D(void){
  set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xE6,0x22};			// Opcode : 0x90E622
  memory[0x2345] 		= 0x7D;               // store 0x7D into register location 0x2345.
  ldMemToReg_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x7D, cpuRegisters->A);
}


/*   Load byte from longoff_X to register
** =========================================
**   |   Name   : LongOff X        |
**   | Location : 0x2323 + 0x1111  |     [Accumulator]
**   |  Value   : 0xBB             |--(load)----^
*/
void test_LD_mem_to_reg_longoff_X_0xBB_expected_0xBB(void){
  set_X(0x23,0x23);
	uint8_t instrc[] 	= {0xD6,0x11,0x11};			 // Opcode : 0xD61111
  memory[0x3434] 		= 0xBB;                   // store 0xBB into register location 0x3434.
  ldMemToReg_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xBB, cpuRegisters->A);
}


/*   Load byte from longoff_Y to register
** =========================================
**   |   Name   : LongOff Y        |
**   | Location : 0x3434 + 0x2222  |     [Accumulator]
**   |  Value   : 0x12             |---(load)--^
*/
void test_LD_mem_to_reg_longoff_Y_0x12_expected_0x12(void){
  set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0x90,0xD6,0x22,0x22};		// Opcode : 0x90D62222
  memory[0x5656] 		= 0x12;                 // store 0x12 into register location 0x5656.
  ldMemToReg_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x12, cpuRegisters->A);
}


/*   Load byte from shortoff_SP to register
** =========================================
**   |   Name   : ShortOff SP      |
**   | Location : 0x8888 + 0x22    |      [Accumulator]
**   |  Value   : 0xac             |--(load)---^
*/
void test_LD_mem_to_reg_shortoff_SP_0xac_expected_0xac(void){
  set_SP(0x88,0x88);
	uint8_t instrc[] 	= {0x7B,0x22};				// Opcode : 0x7B22
  memory[0x88aa] 		= 0xac;               // store 0xac into register location 0x88aa.
  ldMemToReg_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xac, cpuRegisters->A);
}


/*         Load byte from shortptr_W to register
** =======================================================
**   |   Name   : Shortptr W                               |
**   | Location : (0x40 hold 0x42)+(0x40+1 hold 0xe5)      |
**   |                       [^--(combine)-------^]=0x42e5 |       [Accumulator]
**   |  Value   : 0x11                                     |--(load)----^
*/
void test_LD_mem_to_reg_shortptr_W_0x11_expected_0x11(void){
  uint8_t instrc[]	= {0x92,0xc6,0x40};      // Opcode : 0x92c640
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x11;
	ldMemToReg_shortptr_w(instrc);           // store 0x11 into register location 0x42e5.

	TEST_ASSERT_EQUAL_HEX8 (0x11, cpuRegisters->A);
}


/*         Load byte from longptr_W to register
** ===========================================================
**   |   Name   : Longptr W                                   |
**   | Location : (0x1040 hold 0x42)+(0x1040+1 hold 0xe5)     |
**   |                          [^--(combine)-------^]=0x42e5 |       [Accumulator]
**   |  Value   : 0x13                                        |--(load)----^
*/
void test_LD_mem_to_reg_longptr_W_0x13_expected_0x13(void){
  uint8_t instrc[]	= {0x72,0xc6,0x10,0x40};    // Opcode : 0xc7261040
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x13;                // store 0x13 into register location 0x42e5.
	ldMemToReg_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x13, cpuRegisters->A);
}


/*         Load byte from shortptr_W_X to register
** =======================================================================
**   |   Name   : shortptr W X                                           |
**   | Location : (0x89 hold 0x08)+(0x89+1 hold 0x01)                    |
**   |                         [^--(combine)----^]=0x0801 + 0x03[offset] |        [Accumulator]
**   |  Value   : 0x40                                                   |--(load)----^
*/
void test_LD_mem_to_reg_shortptr_W_X_0x40_expected_0x40(void){
  set_X(0x00,0x03);
  uint8_t instrc[] = {0x92,0xd6,0x89};       // Opcode : 0x92d689
	memory[0x89]		 = 0x08;
	memory[0x8a]		 = 0x01;
	memory[0x0804]	 = 0x40;              // store 0x40 into register location 0x0804.
	ldMemToReg_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x40, cpuRegisters->A);
}


/*         Load byte from longptr_W_X to register
** ==========================================================================
**   |   Name   : Longptr W X                                                |
**   | Location : (0x1089 hold 0x18)+(0x1089+1 hold 0x01)                    |
**   |                          [^--(combine)-------^]=0x1801 + 0x10[offset] |       [Accumulator]
**   |  Value   : 0x42                                                       |--(load)----^
*/
void test_LD_mem_to_reg_longptr_W_X_0x42_expected_0x42(void){
  set_X(0x00,0x10);
  uint8_t instrc[] = {0x72,0xd6,0x10,0x89};    // Opcode : 0x72d61089
	memory[0x1089]	 = 0x18;
	memory[0x108a]	 = 0x01;
	memory[0x1811]	 = 0x42;                // store 0x42 into register location 0x1811.
	ldMemToReg_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x42, cpuRegisters->A);
}


/*         Load byte from shortptr_W_Y to register
** ========================================================================
**   |   Name   : shortptr W Y                                            |
**   | Location : (0x89 hold 0x08)+(0x89+1 hold 0x01)                     |
**   |                         [^--(combine)----^]=0x0801 + 0x1111[offset]|        [Accumulator]
**   |  Value   : 0xaa                                                    |--(load)----^
*/
void test_LD_mem_to_reg_shortptr_W_Y_0xaa_expected_0xaa(void){
  set_Y(0x11,0x11);
  uint8_t instrc[] = {0x91,0xd6,0x89};         // Opcode : 0x91d689
	memory[0x89]		 = 0x08;
	memory[0x8a]		 = 0x01;
	memory[0x1912]	 = 0xaa;                // store 0xaa into memory location 0x1912.
	ldMemToReg_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xaa, cpuRegisters->A);
}
