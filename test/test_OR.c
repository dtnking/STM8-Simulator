#include "unity.h"
#include "OR.h"
#include "Memory.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>
//*DOCUMENTATION
void setUp(void){}

void tearDown(void){}

void test_OR_1_byte_given_A_0xFF_OR_0xFF_expected_0xFF(void){
	cpuRegisters->A  = 0xFF;														// Accumulator = 0xFF.
	uint8_t instrc[] = {0xAB,0xFF};											// Opcode : 0xABFF
	or_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xFF,cpuRegisters->A);
}

void test_OR_1_byte_given_A_0x00_OR_0x00_expected_0x00(void){
	cpuRegisters->A  = 0x00;														// Accumulator = 0x00.
	uint8_t instrc[] = {0xAB,0x00};											// Opcode : 0xAB00
	or_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x00,cpuRegisters->A);
}

void test_OR_1_byte_given_A_0xFF_OR_0x00_expected_0xFF(void){
	cpuRegisters->A  = 0xFF;														// Accumulator = 0xFF.
	uint8_t instrc[] = {0xAB,0x00};											// Opcode : 0xAB00
	or_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xFF,cpuRegisters->A);
}

void test_OR_shortmen_given_A_0xFF_OR_0xFF_expected_0xFF(void){
	cpuRegisters->A  = 0xFF;															// Accumulator = 0xFF.
	memory[0x10]		 =	0xFF;															// store 0xFF into memory location 0x10.
	uint8_t instrc[] = {0xBB,0x10};											  // Opcode : 0xBB10
	or_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xFF, cpuRegisters->A);
}

void test_OR_shortmen_given_A_0x00_OR_0x00_expected_0x00(void){
	cpuRegisters->A  = 0x00;															// Accumulator = 0x00.
	memory[0x10]		 =	0x00;															// store 0x00 into memory location 0x10.
	uint8_t instrc[] = {0xBB,0x10};											  // Opcode : 0xBB10
	or_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x00, cpuRegisters->A);
}

void test_OR_shortmen_given_A_0xFF_OR_0x00_expected_0xFF(void){
	cpuRegisters->A  = 0xFF;															// Accumulator = 0xFF.
	memory[0x10]		 =	0x00;															// store 0x00 into memory location 0x10.
	uint8_t instrc[] = {0xBB,0x10};											  // Opcode : 0xBB10
	or_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xFF, cpuRegisters->A);
}

void test_OR_longmem_given_A_0xFF_OR_0xFF_expected_0xFF(void){
	cpuRegisters->A  = 0xFF;																// Accumulator = 0xFF.
	memory[0x1000]	 =	0xFF;															  // store 0xFF into memory location 0x1000.
	uint8_t instrc[] = {0xCB,0x10,0x00};									  // Opcode : 0xCB1000
	or_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0xFF, cpuRegisters->A);
}

void test_OR_longmem_given_A_0x00_OR_0x00_expected_0x00(void){
	cpuRegisters->A  = 0x00;																// Accumulator = 0x00.
	memory[0x1000]	 =	0x00;																// store 0x00 into memory location 0x1000.
	uint8_t instrc[] = {0xCB,0x10,0x00};									  // Opcode : 0xCB1000
	or_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x00, cpuRegisters->A);
}

void test_OR_longmem_given_A_0xFF_OR_0x00_expected_0xFF(void){
	cpuRegisters->A  = 0xFF;																// Accumulator = 0xFF.
	memory[0x1000]	 =	0x00;																// store 0x00 into memory location 0x1000.
	uint8_t instrc[] = {0xCB,0x10,0x00};									  // Opcode : 0xCB1000
	or_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0xFF, cpuRegisters->A);
}

void test_OR_X_given_A_0xFF_OR_X_having_value_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;                   // Accumulator = 0xFF.
	set_X(0x11,0x10);
	memory[0x1110] 		= 0xFF;                   // store 0xFF into memory location 0x1100.
	uint8_t instrc[] 	= {0xFB};									// 	Opcode : FB
	or_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_X_given_A_0x00_OR_X_having_value_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;                   // Accumulator = 0x00.
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x00;                   // store 0x00 into memory location 0x1110.
	uint8_t instrc[] 	= {0xFB};									// 	Opcode : FB
	or_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_X_given_A_0xFF_OR_X_having_value_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x00;
	uint8_t instrc[] 	= {0xFB};									// 	Opcode : FB
	or_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_Y_given_A_0xFF_OR_Y_having_value_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0xFF;
	uint8_t instrc[] 	= {0x90,0xFB};					// 	Opcode : 90FB
	or_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_Y_given_A_0x00_OR_Y_having_value_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0x00;
	uint8_t instrc[] 	= {0x90,0xFB};					// 	Opcode : 90FB
	or_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_Y_given_A_0xFF_OR_Y_having_value_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0x00;
	uint8_t instrc[] 	= {0x90,0xFB};					// 	Opcode : 90FB
	or_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortoff_with_x_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xEB,0x01};			// 	Opcode : EB01
	memory[0x1213] 		= 0xFF;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	or_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortoff_with_x_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xEB,0x01};			// 	Opcode : EB01
	memory[0x1213] 		= 0x00;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	or_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_shortoff_with_x_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xEB,0x01};			// 	Opcode : EB01
	memory[0x1213] 		= 0x00;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	or_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortoff_with_y_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xEB,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0xFF; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	or_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}


void test_OR_shortoff_with_y_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xEB,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0x00; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	or_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_shortoff_with_y_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xEB,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0xFF; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	or_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longoff_with_X_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xDB,0x10,0x10};
	memory[0x4444]		=	0xFF;
	or_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longoff_with_X_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xDB,0x10,0x10};
	memory[0x4444]		=	0x00;
	or_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_longoff_with_X_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xDB,0x10,0x10};
	memory[0x4444]		=	0x00;
	or_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longoff_with_Y_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0x90,0xDB,0x29,0x29};
	memory[0x5d5d]		=	0xFF;
	or_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longoff_with_Y_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0x90,0xDB,0x29,0x29};
	memory[0x5d5d]		=	0x00;
	or_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_longoff_with_Y_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0x90,0xDB,0x29,0x29};
	memory[0x5d5d]		=	0x00;
	or_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortoff_SP_given_A_0xFF_OR_the_value_of_the_SP_0xFF_expected_0xFF(void){
	cpuRegisters->A		= 0xFF;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x1B,0x22};
	memory[0x88AA]		=	0xFF;
	or_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortoff_SP_given_A_0x00_OR_the_value_of_the_SP_0x00_expected_0x00(void){
	cpuRegisters->A		= 0x00;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x1B,0x22};
	memory[0x88AA]		=	0x00;
	or_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_shortoff_SP_given_A_0xFF_OR_the_value_of_the_SP_0x00_expected_0xFF(void){
	cpuRegisters->A		= 0xFF;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x1B,0x22};
	memory[0x88AA]		=	0x00;
	or_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortptr_w_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A		= 0xFF;
	uint8_t instrc[]	= {0x92,0xcb,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0xFF;
	or_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortptr_w_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A		= 0x00;
	uint8_t instrc[]	= {0x92,0xcb,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x00;
	or_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_shortptr_w_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A		= 0xFF;
	uint8_t instrc[]	= {0x92,0xcb,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x00;
	or_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longptr_w_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A		= 0xFF;
	uint8_t instrc[]	= {0x72,0xcb,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0xFF;
	or_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longptr_w_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A		= 0x00;
	uint8_t instrc[]	= {0x72,0xcb,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x00;
	or_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_longptr_w_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A		= 0xFF;
	uint8_t instrc[]	= {0x72,0xcb,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x00;
	or_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortptr_w_X_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xDB,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0xFF;
	or_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}


void test_OR_shortptr_w_X_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xDB,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x00;
	or_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_shortptr_w_X_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xDB,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x00;
	or_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longptr_w_X_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xDB,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0xFF;
	or_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_longptr_w_X_given_A_0x00_OR_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xDB,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0x00;
	or_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_longptr_w_X_given_A_0xFF_OR_the_value_of_the_address_0x00_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xDB,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0x00;
	or_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortptr_w_Y_given_A_0xFF_OR_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xDB,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0xFF;
	or_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_OR_shortptr_w_Y_given_A_0x00_OR_the_value_of_the_address_0x0_expected_0x00(void){
	cpuRegisters->A 	= 0x00;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xDB,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x00;
	or_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_OR_shortptr_w_Y_given_A_0xFF_OR_the_value_of_the_address_0x0_expected_0xFF(void){
	cpuRegisters->A 	= 0xFF;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xDB,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x00;
	or_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}
