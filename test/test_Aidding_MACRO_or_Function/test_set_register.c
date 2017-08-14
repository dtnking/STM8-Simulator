#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_set_x_given_2_args_is_0x10_0x01_expected_XH_is_0x10_and_XL_is_0x01(void){
  set_X(0x10,0x01);
  TEST_ASSERT_EQUAL_HEX16(0x10,cpuRegisters->XH);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->XL);
}

void test_set_y_given_2_args_is_0x2a_0xa2_expected_YH_is_0x2a_and_YL_is_0xa2(void){
  set_Y(0x2a,0xa2);
  TEST_ASSERT_EQUAL_HEX16(0x2a,cpuRegisters->YH);
  TEST_ASSERT_EQUAL_HEX16(0xa2,cpuRegisters->YL);
}

void test_set_SP_given_2_args_is_0xdd_0xff_expected_SPH_is_0xdd_and_SPL_is_0xff(void){
  set_SP(0xdd,0xff);
  TEST_ASSERT_EQUAL_HEX16(0xdd,cpuRegisters->SPH);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->SPL);
}