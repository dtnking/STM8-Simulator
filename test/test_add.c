#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

// 	ADD A,#$55		value of Accumulator + given value
void test_Add_1_byte_given_A_0x01_with_0x55_expected_0x56(void){
	cpuRegisters->A  = 0x01;																// Accumulator = 0x01.
	uint8_t instrc[] = {0xAB,0x55};											// Opcode : 0xAB55
	add_byte((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x56,cpuRegisters->A);
}

// 	ADD A,$10		value of Accumulator + value of a short memory
void test_Add_shortmen_given_A_0x01_with_0x55_within_addrs_0x10_expected_0x56(void){
	cpuRegisters->A  = 0x01;																// Accumulator = 0x01.
	memory[0x10]		 =	0x55;																// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xBB,0x10};											// Opcode : 0xBB10
	add_shortmem((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x56, cpuRegisters->A);
}

// 	ADD A,$1000		value of Accumulator + value of a long memory
void test_Add_longmem_given_A_0x01_with_0x55_within_addrs_0x1000_expected_0x56(void){
	cpuRegisters->A  = 0x01;																// Accumulator = 0x01.
	memory[0x1000]	 =	0x55;																// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0xCB,0x10,0x00};									// Opcode : 0xCB1000
	add_longmem((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x56, cpuRegisters->A);
}

// 	ADD A,(X)		value of register index X + value of Accumulator
void test_Add_X_given_A_0x01_with_X_having_value_0x55_expected_0x56(void){
	cpuRegisters->A 	= 0x01;
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x55;
	uint8_t instrc[] 	= {0xFB};									// 	Opcode : FB
	add_x((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x56,cpuRegisters->A);
}

// 	ADD A,(Y)		value of index register Y + value of Accumulator
void test_Add_Y_given_A_0x01_with_Y_having_value_0x05_expected_0x06(void){
	cpuRegisters->A 	= 0x01;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0x05;
	uint8_t instrc[] 	= {0xFB};					// 	Opcode : 90FB
	add_y((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x06,cpuRegisters->A);
}

/* 		ADD A,($10,X)
** 		Offset = number of address locations added to a base address
** 		in order to get to a specific absolute address.
**		Ex:		0x01 		+	 		0x1212 			= 				0x1213
**				(offset)	+			(base)			=		(specific absolute address)
 */
void test_Add_shortoff_with_x_given_A_0x01_and_the_value_of_the_address_0x10_expected_0x11(void){
	cpuRegisters->A 	= 0x01;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xEB,0x01};			// 	Opcode : EB01
	memory[0x1213] 		= 0xA0;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	add_x_shortset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0xA1,cpuRegisters->A);
}

//		ADD A,($10,Y)
void test_Add_shortoff_with_y_given_A_0x01_and_the_value_of_the_address_0xAD_expected_0xAE(void){
	cpuRegisters->A 	= 0x01;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0xEB,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0x7D; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	add_y_shortset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x7E,cpuRegisters->A);
}

//		ADD A,($1000,X)
void test_Add_longoff_with_X_given_A_0x01_and_the_value_of_the_address_0x09_expected_0x0a(void){
	cpuRegisters->A 	= 0x01;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xDB,0x10,0x10};
	memory[0x4444]		=	0x09;
	add_x_longset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x0a,cpuRegisters->A);
}

//		ADD A,($1000,Y)
void test_Add_longoff_with_Y_given_A_0x01_and_the_value_of_the_address_0x99_expected_0x9a(void){
	cpuRegisters->A 	= 0x01;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0xDB,0x29,0x29};
	memory[0x5d5d]		=	0x99;
	add_y_longset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x9a,cpuRegisters->A);
}

// 	ADD A,($10,SP)
void test_Add_shortoff_SP_given_A_0x01_and_the_value_of_the_SP_0xaa_expected_0xab(void){
	cpuRegisters->A		= 0x01;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x1B,0x22};
	memory[0x88AA]		=	0xaa;
	add_shortoff_SP((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0xab,cpuRegisters->A);
}

// 		ADD A,($10.w)
void test_Add_shortptr_w_given_A_0x01_and_the_value_of_the_address_0x11_expected_0x12(void){
	cpuRegisters->A		= 0x01;
	uint8_t instrc[]	= {0xcb,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x11;
	add_shortptr_w((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x12,cpuRegisters->A);
}

// 		ADD A,($1000.w)
void test_Add_longptr_w_given_A_0x01_and_the_value_of_the_address_0x11_expected_0x12(void){
	cpuRegisters->A		= 0x01;
	uint8_t instrc[]	= {0xcb,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x11;
	add_longptr_w((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x12,cpuRegisters->A);
}

// 		ADD A,[($10.w),X]
void test_Add_shortptr_w_X_given_A_0x01_and_the_value_of_the_address_0x40_expected_0x41(void){
	cpuRegisters->A 	= 0x01;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0xDB,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x40;
	add_shortptr_w_X((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x41,cpuRegisters->A);
}

// 		ADD A,[($1000.w),X]
void test_Add_longptr_w_X_given_A_0x01_and_the_value_of_the_address_0x40_expected_0x41(void){
	cpuRegisters->A 	= 0x01;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0xDB,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0x40;
	add_longptr_w_X((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x41,cpuRegisters->A);
}

// 		ADD A,[($10.w),Y]
void test_Add_shortptr_w_Y_given_A_0x00_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x0;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0xDB,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x0;
	add_shortptr_w_Y((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x0,cpuRegisters->A);
}
