#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "CLR.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

// Negative flag is always 0.
void test_raw_CLR_negative_given_0xab_get_0x00_expected_not_negative(void){
  cpuRegisters->A = 0xAB;
  raw_clr(&cpuRegisters->A);

  TEST_ASSERT_EQUAL_HEX16(0,cpuRegisters->CCR.bit.N);
}

// Zero flag is always set.
void test_raw_CLR_zero_given_0xab_get_0x00_expected_zero(void){
  cpuRegisters->A = 0xAB;
  raw_clr(&cpuRegisters->A);

  TEST_ASSERT_EQUAL_HEX16(1,cpuRegisters->CCR.bit.Z);
}
