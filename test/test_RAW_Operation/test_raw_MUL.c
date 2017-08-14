#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "MUL.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_raw_MUL_given_0x7f_mul_0x03_expected_0x17D(void){
  cpuRegisters->A = 0x7f;
  uint16_t result = raw_mul(0x03);
  TEST_ASSERT_EQUAL_HEX16(0x17D,result);
}

void test_raw_MUL_given_0xaa_mul_0xbb_expected_0x7c2e(void){
  cpuRegisters->A = 0xaa;
  uint16_t result = raw_mul(0xbb);
  TEST_ASSERT_EQUAL_HEX16(0x7c2e,result);
}
