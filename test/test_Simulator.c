#include "unity.h"
#include "Simulator.h"
#include "add.h"
#include <stdio.h>





void setUp(void){}

void tearDown(void){}

// ADD A,#$55
void test_Add_1_byte_val_0x01_with_0x55_expected_0x56(void){
	a.Accumulator = 0x01;

	uint8_t result = add(0xAB55);

	TEST_ASSERT_EQUAL_INT8 (0x56, result );
}
asdb
