#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}

// ADD A,#$55		value of Accumulator + given value
void test_Add_1_byte_given_A_0x01_with_0x55_expected_0x56(void){
	cpuRegisters->A = 0x01;																// Accumulator = 0x01.
	uint32_t instrc = 0xAB55;															// Opcode : 0xAB55
	uint8_t result 	= add_byte(instrc);
	TEST_ASSERT_EQUAL_HEX8 (0x56, result);
}

// ADD A,$10		value of Accumulator + value of a short memory
void test_Add_shortmen_given_A_0x01_with_0x55_within_addrs_0x10_expected_0x56(void){
	cpuRegisters->A = 0x01;																// Accumulator = 0x01.
	memory[0x10]		=	0x55;																// store 0x55 into memory location 0x10.
	uint32_t instrc = 0xBB10;															// Opcode : 0xBB10
	uint32_t result = add_shortmem(instrc);
	TEST_ASSERT_EQUAL_HEX8 (0x56, result);
}

// ADD A,$1000		value of Accumulator + value of a long memory
void test_Add_longmem_given_A_0x01_with_0x55_within_addrs_0x1000_expected_0x56(void){
	cpuRegisters->A = 0x01;																// Accumulator = 0x01.
	memory[0x1000]	=	0x55;																// store 0x55 into memory location 0x1000.
	uint32_t instrc = 0xCB1000;														// Opcode : 0xCB1000
	uint32_t result = add_longmem(instrc);
	TEST_ASSERT_EQUAL_HEX16 (0x56, result);
}

// ADD A,(X)		value of register index X + value of Accumulator
void test_Add_X_given_A_0x01_with_X_having_value_0x55_expected_0x56(void){
	cpuRegisters->A 	= 0x01;
	cpuRegisters->XH 	= 0x11;
	cpuRegisters->XL 	= 0x10;
	memory[0x1110] 		= 0x55;
	uint32_t instrc 	= 0xFB;						// 	Opcode : FB
	uint32_t result 	= add_x(instrc);
	TEST_ASSERT_EQUAL_HEX16(0x56,result);
}

// ADD A,(Y)		value of index register Y + value of Accumulator
void test_Add_Y_given_A_0x01_with_Y_having_value_0x05_expected_0x06(void){
	cpuRegisters->A 	= 0x01;
	cpuRegisters->YH 	= 0x12;
	cpuRegisters->YL 	= 0x10;
	memory[0x1210] 		= 0x05;
	uint32_t instrc 	= 0x90FB;					// 	Opcode : 90FB
	uint32_t result 	= add_y(instrc);
	TEST_ASSERT_EQUAL_HEX16(0x06,result);
}

/* 		Offset = number of address locations added to a base address
** 		in order to get to a specific absolute address.
**		Ex:		0x01 		+	 		0x1212 			= 				0x1213
**				(offset)	+			(base)			=		(specific absolute address)
 */
void test_Add_shortoff_with_x_given_A_0x01_and_the_value_of_the_address_0x10_expected_0x11(void){
	cpuRegisters->A 	= 0x01;
	cpuRegisters->XH 	= 0x12;
	cpuRegisters->XL 	= 0x12;
	uint32_t instrc 	= 0xEB01;			// 	Opcode : EB01
	(uint32_t*)memory[0x1213];
	memory[0x1213] 		= 0xA0;				//	X: 0x1212   offset: 0x01   (X + offset = 0x1213)
	uint32_t result 	= add_x_offset(instrc);
	TEST_ASSERT_EQUAL_HEX16(0xA1,result);
}

void test_Add_shortoff_with_y_given_A_0x01_and_the_value_of_the_address_0xAD_expected_0xAE(void){
	cpuRegisters->A 	= 0x01;
	cpuRegisters->YH 	= 0x23;
	cpuRegisters->YL 	= 0x23;
	uint32_t instrc 	= 0x90EB22;		// 	Opcode : 90EB22
	memory[0x2345] 		= 0x7D; 			//	Y: 0x2323   offset: 0x22   (Y + offset = 0x2345)
	printf("test : %x\n",memory[0x2323+0x22]);
	uint32_t result 	= add_y_offset(instrc);
	TEST_ASSERT_EQUAL_HEX16(0x7E,result);
}
