#include "unity.h"
#include "CLR.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}


void test_CLR_A_given_A_0x01_expected_A_clear_to_0x(void){
	cpuRegisters->A  = 0x01;							// Accumulator = 0x01.
	uint8_t instrc[] = {0x4F};						// Opcode : 0x4F
	clr_A(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0,cpuRegisters->A);
}

void test_CLR_shortmen_given_shortmem_0xaa_expected_shortmem_clear_to_0(void){
	memory[0x10]		 =	0xaa;								// store 0xaa into memory location 0x10.
	uint8_t instrc[] = {0x3F,0x10};					// Opcode : 0x3F10
	clr_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0, memory[0x10]);
}

void test_CLR_longmem_given_longmem_0x55_expected_longmem_clear_to_0(void){
	memory[0x1000]	 =	0x55;										// store 0x55 into memory location 0x1000.
	uint8_t instrc[] = {0x72,0x5F,0x10,0x00};				// Opcode : 0x725F1000
	clr_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX16 (0, memory[0x1000]);
}

void test_CLR_X_given_X_0x55_expected_X_clear_to_0(void){
	set_X(0x1110);														// Set Register X
	memory[0x1110] = 0x55;
	uint8_t instrc[] 	= {0x7F};									// 	Opcode : 7F
	clr_x(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[X]);
}

void test_CLR_Y_given_Y_0x05_expected_Y_clear_to_0(void){
	set_Y(0x1210);
	memory[0x1210]	= 0x05;
	uint8_t instrc[] 	= {0x90,0x7F};					// 	Opcode : 907F
	clr_y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[Y]);
}

/* 		Offset = number of address locations added to a base address
** 		in order to get to a specific absolute address.
**		Ex:		0x01 		+	 		0x1212 			= 				0x1213
**				(offset)	+			(base)			=		(specific absolute address)
*/
void test_CLR_shortoff_with_x_given_0xA0_expected_clear_to_0(void){
	set_X(0x1212);
	uint8_t instrc[] 	= {0x6F,0x01};			// 	Opcode : 6F01
	memory[0x1213] 		= 0xA0;							//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	clr_x_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x1213]);
}

void test_CLR_shortoff_with_y_given_0x7D_expected_clear_to_0(void){
	set_Y(0x2323);
	uint8_t instrc[] 	= {0x90,0x6F,0x22};		// 	Opcode : 90EB22
	memory[0x2345] 		= 0x7D; 								//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	clr_y_shortset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x2345]);
}

void test_CLR_longoff_with_X_given_0x09_expected_clear_to_0(void){
	set_X(0x3434);
	uint8_t instrc[] 	= {0x72,0x4F,0x10,0x10};
	memory[0x4444]		=	0x09;
	clr_x_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x4444]);
}

void test_CLR_longoff_with_Y_given_0x99_expected_clear_to_0(void){
	set_Y(0x3434);
	uint8_t instrc[] 	= {0x90,0x4F,0x29,0x29};
	memory[0x5d5d]		=	0x99;
	clr_y_longset(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x5d5d]);
}

void test_CLR_shortoff_SP_given_0xaa_expected_clear_to_0(void){
	set_SP(0x8888);
	uint8_t instrc[]	= {0x0F,0x22};
	memory[0x88AA]		=	0xaa;
	clr_shortoff_SP(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x88aa]);
}

void test_CLR_shortptr_w_given_0x11_expected_clear_to_0(void){
	uint8_t instrc[]	= {0x92,0x3F,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
	memory[0x42e5]		= 0x11;
	clr_shortptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x42e5]);
}

void test_CLR_longptr_w_given_0x11_expected_clear_to_0(void){
	uint8_t instrc[]	= {0x72,0x3F,0x10,0x40};
	memory[0x1040]		= 0x42;
	memory[0x1041]		= 0xe5;
	memory[0x42e5]		= 0x11;
	clr_longptr_w(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x42e5]);
}

void test_CLR_shortptr_w_X_given_0x40_expected_clear_to_0(void){
	set_X(0x0003);
	uint8_t instrc[]	= {0x92,0x6F,0x89};
	memory[0x89]			= 0x08;
	memory[0x8a]			= 0x01;
	memory[0x0804]		= 0x40;
	clr_shortptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x0804]);
}

void test_CLR_longptr_w_X_given_0x40_expected_clear_to_0(void){
	set_X(0x0103);
	uint8_t instrc[]	= {0x72,0x6F,0x10,0x89};
	memory[0x1089]		= 0x18;
	memory[0x108a]		= 0x01;
 	memory[0x1904]		= 0x40;
	clr_longptr_w_X(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x1904]);
}

void test_CLR_shortptr_w_Y_given_0x11_expected_clear_to_0(void){
	set_Y(0x1111);
	uint8_t instrc[]	= {0x91,0x6F,0x89};
	memory[0x89]			= 0x18;
	memory[0x8a]			= 0x11;
	memory[0x2922]		= 0x11;
	clr_shortptr_w_Y(instrc);

	TEST_ASSERT_EQUAL_HEX16(0,memory[0x2922]);
}
