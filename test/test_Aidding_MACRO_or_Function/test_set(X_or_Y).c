#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
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
