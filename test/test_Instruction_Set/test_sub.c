#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "sub.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

// 	sub A,#$55		value of Accumulator - given value
void test_SUB_1_byte_given_A_0x55_with_0x01_expected_0x54(void){
	cpuRegisters->A  = 0x55;																// Accumulator = 0x01.
	uint8_t instrc[] = {0xA0,0x01};											// Opcode : 0xA001
	sub_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x54,cpuRegisters->A);
}

// 	sub A,$10		value of Accumulator - value of a short memory
void test_sub_shortmen_given_A_0x55_with_0x01_within_addrs_0x10_expected_0x54(void){
	cpuRegisters->A  = 0x55;																// Accumulator = 0x01.
	memory[0x10]		 =	0x01;																// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xB0,0x10};											// Opcode : 0xB010
	sub_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x54, cpuRegisters->A);
}

// 	sub A,$1000		value of Accumulator - value of a long memory
void test_sub_longmem_given_A_0x10_with_0x08_within_addrs_0x1000_expected_0x08(void){
	cpuRegisters->A  = 0x10;																// Accumulator = 0x01.
	memory[0x1000]	 =	0x08;																// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0xC0,0x10,0x00};									// Opcode : 0xC01000
	sub_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x08, cpuRegisters->A);
}

// 	sub A,(X)		value of register index X - value of Accumulator
void test_sub_X_given_A_0x55_with_X_having_value_0x55_expected_0x00(void){
	cpuRegisters->A 	= 0x55;
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x55;
	uint8_t instrc[] 	= {0xF0};									// 	Opcode : F0
	sub_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

// 	sub A,(Y)		value of index register Y - value of Accumulator
void test_sub_Y_given_A_0x01_with_Y_having_value_0x05_expected_0xfc(void){
	cpuRegisters->A 	= 0x01;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0x05;
	uint8_t instrc[] 	= {0x90,0xF0};					// 	Opcode : 90F0
	sub_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xfc,cpuRegisters->A);
}

/* 		sub A,($10,X)
** 		Offset = number of address locations added to a base address
** 		in order to get to a specific absolute address.
**		Ex:		0x01 		-	 		0x1212 			= 				0x1213
**				(offset)	-			(base)			=		(specific absolute address)
 */
void test_sub_shortoff_with_x_given_A_0xA0_and_the_value_of_the_address_0x02_expected_0x9E(void){
	cpuRegisters->A 	= 0xA0;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xE0,0x01};			// 	Opcode : E001
	memory[0x1213] 		= 0x02;								//	X: 0x1212   offset: 0x01   (X - offset = 0x1213)
	sub_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x9E,cpuRegisters->A);
}

//		sub A,($10,Y)
void test_sub_shortoff_with_y_given_A_0xAD_and_the_value_of_the_address_0x01_expected_0xAC(void){
	cpuRegisters->A 	= 0xAD;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xE0,0x22};		// 	Opcode : 90E022
	memory[0x2345] 		= 0x01; 								//	Y: 0x2323   offset: 0x22   (Y - offset = 0x2345)
	sub_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xAC,cpuRegisters->A);
}

//		sub A,($1000,X)
void test_sub_longoff_with_X_given_A_0x02_and_the_value_of_the_address_0x01_expected_0x01(void){
	cpuRegisters->A 	= 0x02;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xD0,0x10,0x10};
	memory[0x4444]		=	0x01;
	sub_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
}

//		sub A,($1000,Y)
void test_sub_longoff_with_Y_given_A_0x01_and_the_value_of_the_address_0x1_expected_0x00(void){
	cpuRegisters->A 	= 0x01;
	set_Y(0x5d,0x5d);
	uint8_t instrc[] 	= {0x90,0xD0,0x29,0x29};
	memory[0x8686]		=	0x01;
	sub_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

// 	sub A,($10,SP)
void test_sub_shortoff_SP_given_A_0xAB_and_the_value_of_the_SP_0xA0_expected_0x0b(void){
	cpuRegisters->A		= 0xAB;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x10,0x22};
	memory[0x88AA]		=	0xa0;
	sub_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x0B,cpuRegisters->A);
}

// 		sub A,($10.w)
void test_sub_shortptr_w_given_A_0xAB_and_the_value_of_the_address_0x11_expected_0x9A(void){
	cpuRegisters->A		= 0xAB;
	uint8_t instrc[]	= {0x92,0xc0,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x11;
	sub_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x9A,cpuRegisters->A);
}

// 		sub A,($1000.w)
void test_sub_longptr_w_given_A_0x11_and_the_value_of_the_address_0x01_expected_0x10(void){
	cpuRegisters->A		= 0x11;
	uint8_t instrc[]	= {0x72,0xc0,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x01;
	sub_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x10,cpuRegisters->A);
}

// 		sub A,[($10.w),X]
void test_sub_shortptr_w_X_given_A_0xFF_and_the_value_of_the_address_0x01_expected_0xFE(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xD0,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x01;
	sub_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFE,cpuRegisters->A);
}

// 		sub A,[($1000.w),X]
void test_sub_longptr_w_X_given_A_0x90_and_the_value_of_the_address_0x05_expected_0x8B(void){
	cpuRegisters->A 	= 0x90;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xD0,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
	memory[0x1904]		= 0x05;
	sub_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x8B,cpuRegisters->A);
}

// 		sub A,[($10.w),Y]
void test_sub_shortptr_w_Y_given_A_0x8B_and_the_value_of_the_address_0x08_expected_0x83(void){
	cpuRegisters->A 	= 0x8B;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xD0,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x08;
	sub_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x83,cpuRegisters->A);
}
