#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "adc.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

// 	adc A,#$55		value of Accumulator + given value
void test_adc_1_byte_given_A_0x01_with_0x55_expected_0x57(void){
	cpuRegisters->A  = 0x01;																// Accumulator = 0x01.
  cpuRegisters->CCR.C = 0x1;
	uint8_t instrc[] = {0xA9,0x55};											// Opcode : 0xAB55
	adc_byte((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x57,cpuRegisters->A);
}

// 	adc A,$10		value of Accumulator + value of a short memory
void test_adc_shortmen_given_A_0x01_with_0x55_within_addrs_0x10_expected_0x57(void){
	cpuRegisters->A  = 0x01;																// Accumulator = 0x01.
  cpuRegisters->CCR.C = 0x1;
	memory[0x10]		 =	0x55;																// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xB9,0x10};											// Opcode : 0xBB10
	adc_shortmem((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x57, cpuRegisters->A);
}

// 	adc A,$1000		value of Accumulator + value of a long memory
void test_adc_longmem_given_A_0x01_with_0x55_within_addrs_0x1000_expected_0x57(void){
	cpuRegisters->A  = 0x01;																// Accumulator = 0x01.
  cpuRegisters->CCR.C = 0x1;
	memory[0x1000]	 =	0x55;																// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0xC9,0x10,0x00};									// Opcode : 0xCB1000
	adc_longmem((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x57, cpuRegisters->A);
}

// 	adc A,(X)		value of register index X + value of Accumulator
void test_adc_X_given_A_0x01_with_X_having_value_0x55_expected_0x57(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x55;
	uint8_t instrc[] 	= {0xF9};									// 	Opcode : FB
	adc_x((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x57,cpuRegisters->A);
}

// 	adc A,(Y)		value of index register Y + value of Accumulator
void test_adc_Y_given_A_0x01_with_Y_having_value_0x05_expected_0x07(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0x05;
	uint8_t instrc[] 	= {0x90,0xF9};					// 	Opcode : 90FB
	adc_y((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x07,cpuRegisters->A);
}

/* 		adc A,($10,X)
** 		Offset = number of address locations added to a base address
** 		in order to get to a specific absolute address.
**		Ex:		0x01 		+	 		0x1212 			= 				0x1213
**				(offset)	+			(base)			=		(specific absolute address)
 */
void test_adc_shortoff_with_x_given_A_0x01_and_the_value_of_the_address_0x10_expected_0xA2(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xE9,0x01};			// 	Opcode : EB01
	memory[0x1213] 		= 0xA0;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	adc_x_shortset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0xA2,cpuRegisters->A);
}

//		adc A,($10,Y)
void test_adc_shortoff_with_y_given_A_0x01_and_the_value_of_the_address_0xAD_expected_0x7F(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xE9,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0x7D; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	adc_y_shortset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x7F,cpuRegisters->A);
}

//		adc A,($1000,X)
void test_adc_longoff_with_X_given_A_0x01_and_the_value_of_the_address_0x09_expected_0x0b(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xD9,0x10,0x10};
	memory[0x4444]		=	0x09;
	adc_x_longset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x0b,cpuRegisters->A);
}

//		adc A,($1000,Y)
void test_adc_longoff_with_Y_given_A_0x01_and_the_value_of_the_address_0x99_expected_0x9b(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0xD9,0x29,0x29};
	memory[0x5d5d]		=	0x99;
	adc_y_longset((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x9b,cpuRegisters->A);
}

// 	adc A,($10,SP)
void test_adc_shortoff_SP_given_A_0x01_and_the_value_of_the_SP_0xaa_expected_0xac(void){
	cpuRegisters->A		= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x19,0x22};
	memory[0x88AA]		=	0xaa;
	adc_shortoff_SP((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0xac,cpuRegisters->A);
}

// 		adc A,($10.w)
void test_adc_shortptr_w_given_A_0x01_and_the_value_of_the_address_0x11_expected_0x13(void){
	cpuRegisters->A		= 0x01;
  cpuRegisters->CCR.C = 0x1;
	uint8_t instrc[]	= {0x92,0xc9,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x11;
	adc_shortptr_w((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x13,cpuRegisters->A);
}

// 		adc A,($1000.w)
void test_adc_longptr_w_given_A_0x01_and_the_value_of_the_address_0x11_expected_0x13(void){
	cpuRegisters->A		= 0x01;
  cpuRegisters->CCR.C = 0x1;
	uint8_t instrc[]	= {0x72,0xc9,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x11;
	adc_longptr_w((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x13,cpuRegisters->A);
}

// 		adc A,[($10.w),X]
void test_adc_shortptr_w_X_given_A_0x01_and_the_value_of_the_address_0x40_expected_0x42(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xD9,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x40;
	adc_shortptr_w_X((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x42,cpuRegisters->A);
}

// 		adc A,[($1000.w),X]
void test_adc_longptr_w_X_given_A_0x01_and_the_value_of_the_address_0x40_expected_0x42(void){
	cpuRegisters->A 	= 0x01;
  cpuRegisters->CCR.C = 0x1;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xD9,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
	memory[0x1904]		= 0x40;
	adc_longptr_w_X((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x42,cpuRegisters->A);
}

// 		adc A,[($10.w),Y]
void test_adc_shortptr_w_Y_given_A_0x80_and_the_value_of_the_address_0x80_expected_0x1(void){
	cpuRegisters->A 	= 0x80;
  cpuRegisters->CCR.C = 0x1;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xD9,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x80;
	adc_shortptr_w_Y((uint8_t *)&instrc);

	TEST_ASSERT_EQUAL_HEX16(0x1,cpuRegisters->A);
}
