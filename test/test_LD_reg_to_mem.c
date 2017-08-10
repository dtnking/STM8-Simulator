#include "unity.h"
#include "LD.h"
#include "Memory.h"
#include "Simulator.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}


/*    Load byte from Accumulator to shortMemory
**  =======================================
**   |   Name   : shortMem        |
**   | Location : Accumulator     |     memory [10]
**   |  Value   : 0x55            |---------^
*/
void test_LD_reg_to_mem_shortmen_0x55_expected_0x55(void){
	cpuRegisters->A	 =	0x55;							// store 0x55 into Accumulator
	uint8_t instrc[] = {0xB7,0x10};				 // Opcode : 0xB710
	ldRegToMem_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, memory[0x10]);
}


/*   Load byte from Accumulator to longMemory
** =======================================
**   |   Name   : LongMem      |
**   | Location : Accumulator  |     memory[0x1000]
**   |  Value   : 0xCC         |---------^
*/
void test_LD_reg_to_mem_longmen_0xCC_expected_0xCC(void){
	cpuRegisters->A		 =	0xCC;                 // store 0xCC into Accumulator
	uint8_t instrc[] = {0xB7,0x10,0x00};				// Opcode : 0xB71000
	ldRegToMem_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xCC, memory[0x1000]);
}


/*   Load byte from Accumulator to X
** =======================================
**   |   Name   : X           |
**   | Location : Accumulator |        memory[0x1110]
**   |  Value   : 0xDD        |--(load)----^
*/
void test_LD_reg_to_mem_X_0xDD_expected_0xDD(void){
  set_X(0x11,0x10);
  cpuRegisters->A	 	= 0xDD;            // store 0xDD into Accumulator
	uint8_t instrc[]  = {0xF7};					 // Opcode : 0xF7
	ldRegToMem_x(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xDD, memory[0x1110]);
}


/*   Load byte from Accumulator to Y
** =======================================
**   |   Name   : Y           |
**   | Location : Accumulator |         memory[0x1210]
**   |  Value   : 0xEE        |--(load)----^
*/
void test_LD_reg_to_mem_Y_0xEE_expected_0xEE(void){
  set_Y(0x12,0x10);
  cpuRegisters->A	 	= 0xEE;            // store 0xEE into Accumulator.
	uint8_t instrc[]  = {0xF6};					 // Opcode : 0xF7
	ldRegToMem_y(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xEE, memory[0x1210]);
}


/*   Load byte from Accumulator to shortoff_X
** =========================================
**   |   Name   : ShortOff X      |
**   | Location : Accumulator     |     memory[0x1212+0x01]
**   |  Value   : 0xFF            |--(load)----^
*/
void test_LD_reg_to_mem_shortoff_X_0xFF_expected_0xFF(void){
  set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xE7,0x01};				// Opcode : 0xE701
  cpuRegisters->A 	= 0xFF;               // store 0xFF into Accumulator.
  ldRegToMem_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xFF, memory[0x1213]);
}


/*   Load byte from Accumulator to shortoff_Y
** =========================================
**   |   Name   : ShortOff Y      |
**   | Location : Accumulator     |     memory[0x2323+0x22]
**   |  Value   : 0x7D            |--(load)----^
*/
void test_LD_reg_to_mem_shortoff_Y_0x7D_expected_0x7D(void){
  set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0xE7,0x22};				// Opcode : 0xE722
  cpuRegisters->A 	= 0x7D;               // store 0x7D into Accumulator.
  ldRegToMem_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x7D, memory[0x2345]);
}


/*   Load byte from Accumulator to longoff_X
** =========================================
**   |   Name   : LongOff X        |
**   | Location : Accumulator      |     memory[0x2323+0x1111]
**   |  Value   : 0xBB             |--(load)----^
*/
void test_LD_reg_to_mem_longoff_X_0xBB_expected_0xBB(void){
  set_X(0x23,0x23);
	uint8_t instrc[] 	= {0xD7,0x11,0x11};				// Opcode : 0xD71111
  cpuRegisters->A		= 0xBB;                   // store 0xBB into Accumulator.
  ldRegToMem_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xBB, memory[0x3434]);
}


/*   Load byte from Accumulator to longoff_Y
** =========================================
**   |   Name   : LongOff Y        |
**   | Location : Accumulator      |     memory[0x3434+0x2222]
**   |  Value   : 0x12             |---(load)--^
*/
void test_LD_reg_to_mem_longoff_Y_0x12_expected_0x12(void){
  set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0xD7,0x22,0x22};				 // Opcode : 0xD72222
  cpuRegisters->A		= 0x12;                    // store 0x12 into Accumulator.
  ldRegToMem_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x12, memory[0x5656]);
}


/*   Load byte from  Accumulator to shortOff_SP
** =========================================
**   |   Name   : ShortOff SP      |
**   | Location : 0x8888 + 0x22    |     memory[0x8888+0x22]
**   |  Value   : 0xac             |--(load)---^
*/
void test_LD_reg_to_mem_shortoff_SP_0xac_expected_0xac(void){
  set_SP(0x88,0x88);
	uint8_t instrc[] 	= {0x6B,0x22};				// Opcode : 0x6B22
  cpuRegisters->A		= 0xac;                // store 0xac into Accumulator
  ldRegToMem_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xac,memory[0x88aa]);
}


/*  Load byte from  Accumulator to shortptr_W
** ===========================================
**   |   Name   : Shortptr W        |
**   | Location :  Accumulator      |      memory[0x42e5]
**   |  Value   : 0x11              |--(load)------^
*/
void test_LD_reg_to_mem_shortptr_W_0x11_expected_0x11(void){
  uint8_t instrc[]	= {0xc7,0x40};           // Opcode : 0xc740
	memory[0x40]			= 0x42;                  // (0x40 hold 0x42)+(0x40+1 hold 0xe5)
	memory[0x41]			= 0xe5;                  //             [^--(combine)-------^]= 0x42e5
	cpuRegisters->A 	= 0x11;                  // store 0x11 into Accumulator
	ldRegToMem_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x11, memory[0x42e5]);
}

/*  Load byte from Accumulator to Longptr_W
** =============================================
**   |   Name   : Longptr W         |
**   | Location : Accumulator       |      memory[0x42e5]
**   |  Value   : 0x13              |--(load)-----^
*/
void test_LD_reg_to_mem_longptr_W_0x13_expected_0x13(void){
  uint8_t instrc[]	= {0xc7,0x10,0x40};      // Opcode : 0xc71040
	memory[0x1040]		= 0x42;                  // (0x1040 hold 0x42)+(0x1040+1 hold 0xe5)
	memory[0x1041]		= 0xe5;                  //               [^--(combine)-------^]= 0x42e5
	cpuRegisters->A 	= 0x13;                  // store 0x13 into register location 0x42e5.
	ldRegToMem_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x13, memory[0x42e5]);
}


/*      Load byte from Accumulator to shortptr_W_X
** ========================================
**   |   Name   : shortptr W X       |
**   | Location : Accumulator        |     memory[0x0804]
**   |  Value   : 0x40               |--(load)----^
*/
void test_LD_reg_to_mem_shortptr_W_X_0x40_expected_0x40(void){
  set_X(0x00,0x03);
  uint8_t instrc[] = {0xd7,0x89};         // Opcode : 0xd789
	memory[0x89]		 = 0x08;                // (0x89 hold 0x08)+(0x89+1 hold 0x01)
	memory[0x8a]		 = 0x01;                //               [^--(combine)----^]=0x0801 + 0x03[offset]
	cpuRegisters->A	 = 0x40;                // store 0x40 into Accumulator.
	ldRegToMem_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x40,memory[0x0804]);
}

/*   Load byte from Accumulator to Longptr_W_X
** =============================================
**   |   Name   : Longptr W X   |
**   | Location : Accumulator   |      memory[0x1811]
**   |  Value   : 0x42          |--(load)----^
*/
void test_LD_reg_to_mem_longptr_W_X_0x42_expected_0x42(void){
  set_X(0x00,0x10);
  uint8_t instrc[] = {0xd7,0x10,0x89};     // Opcode : 0xd71089
	memory[0x1089]	 = 0x18;                 // (0x1089 hold 0x18)+(0x1089+1 hold 0x01)
	memory[0x108a]	 = 0x01;                 //                [^--(combine)-------^]=0x1801 + 0x10[offset]
	cpuRegisters->A	 = 0x42;                 // store 0x42 in Accumulator.
	ldRegToMem_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x42, memory[0x1811]);
}

/*   Load byte from shortptr_W_Y to register
** ==========================================
**   |   Name   : shortptr W Y   |
**   | Location : Accumulator    |     memory[0x1912]
**   |  Value   : 0xaa           |--(load)----^
*/
void test_LD_reg_to_mem_shortptr_W_Y_0xaa_expected_0xaa(void){
  set_Y(0x11,0x11);
  uint8_t instrc[] = {0xd7,0x89};       // Opcode : 0xd789
	memory[0x89]		 = 0x08;              // (0x89 hold 0x08)+(0x89+1 hold 0x01)
	memory[0x8a]		 = 0x01;              //             [^--(combine)----^]=0x0801 + 0x1111[offset]
	cpuRegisters->A	 = 0xaa;              // store 0xaa into Accumulator.
	ldRegToMem_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xaa, memory[0x1912]);
}
