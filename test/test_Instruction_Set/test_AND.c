#include "unity.h"
#include "AND.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_AND_1_byte_given_A_0x23_with_0x23_expected_0x23(void){
	cpuRegisters->A  = 0x23;														// Accumulator = 0x23.
	uint8_t instrc[] = {0xAB,0x23};											// Opcode : 0xAB55
	and_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x23,cpuRegisters->A);
}

void test_AND_1_byte_given_A_0x23_with_0x00_expected_0x00(void){
	cpuRegisters->A  = 0x23;														// Accumulator = 0x23.
	uint8_t instrc[] = {0xAB,0x00};											// Opcode : 0xAB55
	and_byte(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x00,cpuRegisters->A);
}

void test_AND_shortmen_given_A_0x55_with_0x55_within_addrs_0x10_expected_0x55(void){
	cpuRegisters->A  = 0x55;															// Accumulator = 0x01.
	memory[0x10]		 =	0x55;															// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xBB,0x10};											  // Opcode : 0xBB10
	and_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, cpuRegisters->A);
}

void test_AND_shortmen_given_A_0x55_with_0x00_within_addrs_0x10_expected_0x00(void){
	cpuRegisters->A  = 0x55;															// Accumulator = 0x01.
	memory[0x10]		 =	0x00;															// store 0x55 into memory location 0x10.
	uint8_t instrc[] = {0xBB,0x10};											  // Opcode : 0xBB10
	and_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x00, cpuRegisters->A);
}

void test_AND_longmem_given_A_0x77_with_0x77_within_addrs_0x1000_expected_0x77(void){
	cpuRegisters->A  = 0x77;																// Accumulator = 0x01.
	memory[0x1000]	 =	0x77;																// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0xCB,0x10,0x00};									// Opcode : 0xCB1000
	and_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x77, cpuRegisters->A);
}

void test_AND_longmem_given_A_0x77_with_0x00_within_addrs_0x1000_expected_0x00(void){
	cpuRegisters->A  = 0x77;																// Accumulator = 0x01.
	memory[0x1000]	 =	0x00;																// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0xCB,0x10,0x00};									// Opcode : 0xCB1000
	and_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0x00, cpuRegisters->A);
}

void test_AND_X_given_A_0x99_with_X_having_value_0x99_expected_0x99(void){
	cpuRegisters->A 	= 0x99;
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x99;
	uint8_t instrc[] 	= {0xFB};									// 	Opcode : FB
	and_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x99,cpuRegisters->A);
}

void test_AND_X_given_A_0x99_with_X_having_value_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x99;
	set_X(0x11,0x10);
	memory[0x1110] 		= 0x00;
	uint8_t instrc[] 	= {0xFB};									// 	Opcode : FB
	and_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_Y_given_A_0xaa_with_Y_having_value_0xaa_expected_0xaa(void){
	cpuRegisters->A 	= 0xaa;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0xaa;
	uint8_t instrc[] 	= {0xFB};					// 	Opcode : 90FB
	and_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xaa,cpuRegisters->A);
}

void test_AND_Y_given_A_0xaa_with_Y_having_value_0x00_expected_0xaa(void){
	cpuRegisters->A 	= 0xaa;
	set_Y(0x12,0x10);
	memory[0x1210] 		= 0x00;
	uint8_t instrc[] 	= {0xF4};					// 	Opcode : 90F4
	and_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_AND_shortoff_with_x_given_A_0xab_and_the_value_of_the_address_0xab_expected_0xab(void){
	cpuRegisters->A 	= 0xab;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xE4,0x01};			// 	Opcode : E401
	memory[0x1213] 		= 0xab;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	and_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xab,cpuRegisters->A);
}

void test_AND_shortoff_with_x_given_A_0xab_and_the_value_of_the_address_0x00_expected_0xab(void){
	cpuRegisters->A 	= 0xab;
	set_X(0x12,0x12);
	uint8_t instrc[] 	= {0xE4,0x01};			// 	Opcode : EB41
	memory[0x1213] 		= 0x00;								//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	and_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_shortoff_with_y_given_A_0xAD_and_the_value_of_the_address_0xAD_expected_0xAD(void){
	cpuRegisters->A 	= 0xAD;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xE4,0x22};		// 	Opcode : 90E422
	memory[0x2345] 		= 0xAD; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	and_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xAD,cpuRegisters->A);
}


void test_AND_shortoff_with_y_given_A_0xAD_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0xAD;
	set_Y(0x23,0x23);
	uint8_t instrc[] 	= {0x90,0xE4,0x22};		// 	Opcode : 90E422
	memory[0x2345] 		= 0x00; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	and_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_longoff_with_X_given_A_0x09_and_the_value_of_the_address_0x09_expected_0x09(void){
	cpuRegisters->A 	= 0x09;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xD4,0x10,0x10};
	memory[0x4444]		=	0x09;
	and_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x09,cpuRegisters->A);
}

void test_AND_longoff_with_X_given_A_0x09_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x09;
	set_X(0x34,0x34);
	uint8_t instrc[] 	= {0xD4,0x10,0x10};
	memory[0x4444]		=	0x00;
	and_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_longoff_with_Y_given_A_0xFE_and_the_value_of_the_address_0xFE_expected_0x9a(void){
	cpuRegisters->A 	= 0xFE;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0x90,0xD4,0x29,0x29};
	memory[0x5d5d]		=	0xFE;
	and_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFE,cpuRegisters->A);
}

void test_AND_longoff_with_Y_given_A_0xFE_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0xFE;
	set_Y(0x34,0x34);
	uint8_t instrc[] 	= {0x90,0xD4,0x29,0x29};
	memory[0x5d5d]		=	0x00;
	and_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_AND_shortoff_SP_given_A_0xCD_and_the_value_of_the_SP_0xCD_expected_0xCD(void){
	cpuRegisters->A		= 0xCD;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x14,0x22};
	memory[0x88AA]		=	0xCD;
	and_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xCD,cpuRegisters->A);
}

void test_AND_shortoff_SP_given_A_0xCD_and_the_value_of_the_SP_0x00_expected_0x00(void){
	cpuRegisters->A		= 0xCD;
	set_SP(0x88,0x88);
	uint8_t instrc[]	= {0x14,0x22};
	memory[0x88AA]		=	0x00;
	and_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_shortptr_w_given_A_0xFF_and_the_value_of_the_address_0xFF_expected_0xFF(void){
	cpuRegisters->A		= 0xFF;
	uint8_t instrc[]	= {0x92,0xc4,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0xFF;
	and_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xFF,cpuRegisters->A);
}

void test_AND_shortptr_w_given_A_0xFF_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A		= 0xFF;
	uint8_t instrc[]	= {0x92,0xc4,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x00;
	and_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}

void test_AND_longptr_w_given_A_0xDE_and_the_value_of_the_address_0xDE_expected_0xDE(void){
	cpuRegisters->A		= 0xDE;
	uint8_t instrc[]	= {0x72,0xd4,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0xDE;
	and_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0xDE,cpuRegisters->A);
}

void test_AND_longptr_w_given_A_0xDE_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A		= 0xDE;
	uint8_t instrc[]	= {0x72,0xd4,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x00;
	and_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_shortptr_w_X_given_A_0x11_and_the_value_of_the_address_0x11_expected_0x11(void){
	cpuRegisters->A 	= 0x11;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xD4,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x11;
	and_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x11,cpuRegisters->A);
}


void test_AND_shortptr_w_X_given_A_0x11_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x11;
	set_X(0x00,0x03);
	uint8_t instrc[]	= {0x92,0xD4,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x00;
	and_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_longptr_w_X_given_A_0x40_and_the_value_of_the_address_0x40_expected_0x40(void){
	cpuRegisters->A 	= 0x40;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xD4,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0x40;
	and_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x40,cpuRegisters->A);
}

void test_AND_longptr_w_X_given_A_0x40_and_the_value_of_the_address_0x00_expected_0x00(void){
	cpuRegisters->A 	= 0x40;
	set_X(0x01,0x03);
	uint8_t instrc[]	= {0x72,0xD4,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0x00;
	and_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}


void test_AND_shortptr_w_Y_given_A_0x8_and_the_value_of_the_address_0x8_expected_0x08(void){
	cpuRegisters->A 	= 0x08;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xD4,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x08;
	and_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x08,cpuRegisters->A);
}

void test_AND_shortptr_w_Y_given_A_0x8_and_the_value_of_the_address_0x0_expected_0x00(void){
	cpuRegisters->A 	= 0x08;
	set_Y(0x11,0x11);
	uint8_t instrc[]	= {0x91,0xD4,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x00;
	and_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
}
