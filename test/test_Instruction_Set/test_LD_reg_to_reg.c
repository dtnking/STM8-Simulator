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

/*    Load byte from Accumulator to XL
**  ====================================
**   |   Name   : A to XL     |
**   | Location : Accumulator |        [XL]
**   |  Value   : 0x55        |---------^
*/
void test_LD_reg_to_reg_A_to_XL_0x55_expected_0x55(void){
	cpuRegisters->A	 =	0x55;				// store 0x55 into Accumulator.
	uint8_t instrc[] = {0x97};			// Opcode : 0x97
	ldRegToReg_A_to_XL(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, cpuRegisters->XL);
}


/*    Load byte from XL to Accumulator
**  ====================================
**   |   Name   : XL to A     |
**   | Location : XL          |     [Accumulator]
**   |  Value   : 0x11        |---------^
*/
void test_LD_reg_to_reg_XL_to_A_0x11_expected_0x11(void){
	cpuRegisters->XL =	0x55;					// store 0x55 into XL.
	uint8_t instrc[] = {0x9F};			  // Opcode : 0x9F
	ldRegToReg_XL_to_A(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, cpuRegisters->A);
}


/*    Load byte from Accumulator to YL
**  ====================================
**   |   Name   : A to YL     |
**   | Location : Accumulator |        [YL]
**   |  Value   : 0x33        |---------^
*/
void test_LD_reg_to_reg_A_to_YL_0x33_expected_0x33(void){
	cpuRegisters->A	 =	0x33;				// store 0x33 into Accumulator.
	uint8_t instrc[] = {0x97};			// Opcode : 0x97
	ldRegToReg_A_to_YL(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x33, cpuRegisters->YL);
}


/*    Load byte from YL to Accumulator
**  ====================================
**   |   Name   : YL to A     |
**   | Location : YL          |     [Accumulator]
**   |  Value   : 0x22        |---------^
*/
void test_LD_reg_to_reg_YL_to_A_0x22_expected_0x22(void){
	cpuRegisters->YL =	0x22;					// store 0x22 into YL.
	uint8_t instrc[] = {0x9F};			  // Opcode : 0x9F
	ldRegToReg_YL_to_A(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x22, cpuRegisters->A);
}


/*    Load byte from Accumulator to XH
**  ====================================
**   |   Name   : A to XH     |
**   | Location : Accumulator |        [XH]
**   |  Value   : 0xaa        |---------^
*/
void test_LD_reg_to_reg_A_to_XH_0xaa_expected_0xaa(void){
	cpuRegisters->A	 =	0xaa;				// store 0xaa into Accumulator.
	uint8_t instrc[] = {0x95};			// Opcode : 0x95
	ldRegToReg_A_to_XH(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xaa, cpuRegisters->XH);
}


/*    Load byte from XH to Accumulator
**  ====================================
**   |   Name   : XH to A     |
**   | Location : XH          |     [Accumulator]
**   |  Value   : 0xbb        |---------^
*/
void test_LD_reg_to_reg_XH_to_A_0xbb_expected_0xbb(void){
	cpuRegisters->XH =	0xbb;					// store 0xbb into XH.
	uint8_t instrc[] = {0x9E};			  // Opcode : 0x9E
	ldRegToReg_XH_to_A(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xbb, cpuRegisters->A);
}


/*    Load byte from Accumulator to YH
**  ====================================
**   |   Name   : A to YH     |
**   | Location : Accumulator |        [YH]
**   |  Value   : 0xcc        |---------^
*/
void test_LD_reg_to_reg_A_to_YH_0xcc_expected_0xcc(void){
	cpuRegisters->A	 =	0xcc;				// store 0xcc into Accumulator.
	uint8_t instrc[] = {0x95};			// Opcode : 0x95
	ldRegToReg_A_to_YH(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xcc, cpuRegisters->YH);
}


/*    Load byte from YH to Accumulator
**  ====================================
**   |   Name   : YH to A     |
**   | Location : YH          |     [Accumulator]
**   |  Value   : 0xdd        |---------^
*/
void test_LD_reg_to_reg_YH_to_A_0xdd_expected_0xdd(void){
	cpuRegisters->YH =	0xdd;					// store 0xdd into YH.
	uint8_t instrc[] = {0x9E};			  // Opcode : 0x9E
	ldRegToReg_YH_to_A(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xdd, cpuRegisters->A);
}
