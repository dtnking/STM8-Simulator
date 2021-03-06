#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "sbc.h"
#include <stdio.h>
#include <stdint.h>
void setUp(void)
{
}

void tearDown(void)
{
}

/*
**    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
**    X  Syntax : SBC A,src          e.g. SBC A,#$15  X
**    X  Operation : A <= A- src - C              	  X
**    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/

// 	sbc A,#$55		value of Accumulator - given value
void test_sbc_1_byte_given_A_0x55_with_0x01_expected_0x53(void){
	cpuRegisters->A  = 0x55;														// Accumulator = 0x01.
  cpuRegisters->CCR.bit.C = 0x1;
	uint8_t instrc[] = {0xA2,0x01};											// Opcode : 0xAB55
	sbc_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x53,cpuRegisters->A);
}

// 	sbc A,$10		value of Accumulator - value of a short memory
void test_sbc_shortmen_given_A_0x55_with_0x01_within_addrs_0x10_expected_0x53(void){
	cpuRegisters->A  = 0x55;																// Accumulator = 0x01.
  cpuRegisters->CCR.bit.C = 0x1;
	memory[0x10]		 =	0x01;																// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xB2,0x10};											// Opcode : 0xBB10
	sbc_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x53, cpuRegisters->A);
}

// 	sbc A,$1000		value of Accumulator - value of a long memory
void test_sbc_longmem_given_A_0x10_with_0x08_within_addrs_0x1000_expected_0x07(void){
	cpuRegisters->A  = 0x10;																// Accumulator = 0x01.
  cpuRegisters->CCR.bit.C = 0x1;
	memory[0x1000]	 =	0x08;																// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0xC2,0x10,0x00};									// Opcode : 0xCB1000
	sbc_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x07, cpuRegisters->A);
}

// 	sbc A,(X)		value of register index X - value of Accumulator
void test_sbc_X_given_A_0x55_with_X_having_value_0x54_expected_0x00(void){
	cpuRegisters->A 	= 0x55;
  cpuRegisters->CCR.bit.C = 0x1;
	set_X(0x1110);
	memory[0x1110] 		= 0x54;
	uint8_t instrc[] 	= {0xF2};									// 	Opcode : FB
	sbc_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

// 	sbc A,(Y)		value of index register Y - value of Accumulator
void test_sbc_Y_given_A_0x01_with_Y_having_value_0x05_expected_0xfb(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.bit.C = 0x1;
	set_Y(0x1210);
	memory[0x1210] 		= 0x05;
	uint8_t instrc[] 	= {0x90,0xF2};					// 	Opcode : 90FB
	sbc_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xfb,cpuRegisters->A);
}

/* 		sbc A,($10,X)
** 		Offset = number of address locations added to a base address
** 		in order to get to a specific absolute address.
**		Ex:		0x01 		-	 		0x1212 			= 				0x1213
**				(offset)	-			(base)			=		(specific absolute address)
 */
void test_sbc_shortoff_with_x_given_A_0xA0_and_the_value_of_the_address_0x02_expected_0x9d(void){
	cpuRegisters->A 	= 0xA0;
  cpuRegisters->CCR.bit.C = 0x1;
	set_X(0x1212);
	uint8_t instrc[] 	= {0xE2,0x01};			// 	Opcode : EB01
	memory[0x1213] 		= 0x02;								//	X: 0x1212   offset: 0x01   (X - offset = 0x1213)
	sbc_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x9d,cpuRegisters->A);
}

//		sbc A,($10,Y)
void test_sbc_shortoff_with_y_given_A_0xAD_and_the_value_of_the_address_0x01_expected_0xAb(void){
	cpuRegisters->A 	= 0xAD;
  cpuRegisters->CCR.bit.C = 0x1;
	set_Y(0x2323);
	uint8_t instrc[] 	= {0x90,0xE2,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0x01; 								//	Y: 0x2323   offset: 0x22   (Y - offset = 0x2345)
	sbc_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xAb,cpuRegisters->A);
}

//		sbc A,($1000,X)
void test_sbc_longoff_with_X_given_A_0x02_and_the_value_of_the_address_0x01_expected_0x00(void){
	cpuRegisters->A 	= 0x02;
  cpuRegisters->CCR.bit.C = 0x1;
	set_X(0x3434);
	uint8_t instrc[] 	= {0xD2,0x10,0x10};
	memory[0x4444]		=	0x01;
	sbc_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

//		sbc A,($1000,Y)
void test_sbc_longoff_with_Y_given_A_0x02_and_the_value_of_the_address_0x1_expected_0x00(void){
	cpuRegisters->A 	= 0x2;
  cpuRegisters->CCR.bit.C = 0x1;
	set_Y(0x5d5d);
	uint8_t instrc[] 	= {0x90,0xD2,0x29,0x29};
	memory[0x8686]		=	0x01;
	sbc_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

// 	sbc A,($10,SP)
void test_sbc_shortoff_SP_given_A_0xAB_and_the_value_of_the_SP_0xA0_expected_0x0a(void){
	cpuRegisters->A		= 0xAB;
  cpuRegisters->CCR.bit.C = 0x1;
	set_SP(0x8888);
	uint8_t instrc[]	= {0x12,0x22};
	memory[0x88AA]		=	0xa0;
	sbc_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x0a,cpuRegisters->A);
}

// 		sbc A,($10.w)
void test_sbc_shortptr_w_given_A_0xAB_and_the_value_of_the_address_0x11_expected_0x99(void){
	cpuRegisters->A		= 0xAB;
  cpuRegisters->CCR.bit.C = 0x1;
	uint8_t instrc[]	= {0x92,0xc2,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x11;
	sbc_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x99,cpuRegisters->A);
}

// 		sbc A,($1000.w)
void test_sbc_longptr_w_given_A_0x11_and_the_value_of_the_address_0x01_expected_0x0f(void){
	cpuRegisters->A		= 0x11;
  cpuRegisters->CCR.bit.C = 0x1;
	uint8_t instrc[]	= {0x72,0xc2,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x01;
	sbc_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x0f,cpuRegisters->A);
}

// 		sbc A,[($10.w),X]
void test_sbc_shortptr_w_X_given_A_0xFF_and_the_value_of_the_address_0x01_expected_0xFd(void){
	cpuRegisters->A 	= 0xFF;
  cpuRegisters->CCR.bit.C = 0x1;
	set_X(0x0003);
	uint8_t instrc[]	= {0x92,0xD2,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x01;
	sbc_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFd,cpuRegisters->A);
}

// 		sbc A,[($1000.w),X]
void test_sbc_longptr_w_X_given_A_0x90_and_the_value_of_the_address_0x05_expected_0x8a(void){
	cpuRegisters->A 	= 0x90;
  cpuRegisters->CCR.bit.C = 0x1;
	set_X(0x0103);
	uint8_t instrc[]	= {0x72,0xD2,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
	memory[0x1904]		= 0x05;
	sbc_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x8a,cpuRegisters->A);
}

// 		sbc A,[($10.w),Y]
void test_sbc_shortptr_w_Y_given_A_0x8B_and_the_value_of_the_address_0x08_expected_0x82(void){
	cpuRegisters->A 	= 0x8B;
  cpuRegisters->CCR.bit.C = 0x1;
	set_Y(0x1111);
	uint8_t instrc[]	= {0x91,0xD2,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x08;
	sbc_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x82,cpuRegisters->A);
}
