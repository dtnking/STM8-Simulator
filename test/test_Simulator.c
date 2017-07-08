#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}


// ADD A,#$55
void test_Add_1_byte_given_A_0x01_with_0x55_expected_0x56(void){
	cpuRegisters->A = 0x01;																// Accumulator = 0x01.
	uint8_t result = add_byte(0xAB55);										// Opcode 0xAB55
	TEST_ASSERT_EQUAL_HEX8 (0x56, result );
}

// ADD A,$10
void test_Add_shortmen_given_A_0x01_with_0x55_within_addrs_0x10_expected_0x56(void){
	cpuRegisters->A = 0x01;																// Accumulator = 0x01.
	memory[0x10]=0x55;																		// store 0x55 into memory location 0x10.

	uint32_t result = add_shortmem(0xBB10);								// Opcode 0xBB10
	TEST_ASSERT_EQUAL_HEX8 (0x56, result);
}

// ADD A,$1000
void test_Add_longmem_given_A_0x01_with_0x55_within_addrs_0x1000_expected_0x56(void){
	cpuRegisters->A = 0x01;																// Accumulator = 0x01.
	memory[0x1000]=0x55;																	// store 0x55 into memory location 0x1000.

	uint32_t result = add_longmem(0xCB1000);							// Opcode 0xCB1000
	TEST_ASSERT_EQUAL_HEX16 (0x56, result);
}
