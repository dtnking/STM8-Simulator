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
  set_X(0x1001);
  TEST_ASSERT_EQUAL_HEX16(0x10,cpuRegisters->XH);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->XL);
}

void test_set_y_given_2_args_is_0x2a_0xa2_expected_YH_is_0x2a_and_YL_is_0xa2(void){
  set_Y(0x2aa2);
  TEST_ASSERT_EQUAL_HEX16(0x2a,cpuRegisters->YH);
  TEST_ASSERT_EQUAL_HEX16(0xa2,cpuRegisters->YL);
}

void test_set_SP_given_2_args_is_0xdd_0xff_expected_SPH_is_0xdd_and_SPL_is_0xff(void){
  set_SP(0xddff);
  TEST_ASSERT_EQUAL_HEX16(0xdd,cpuRegisters->SPH);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->SPL);
}

void test_set_PC_given_3_args_is_0x11_0x22_0x33_expected_PCE_is_0x11_PCH_is_0x22_and_PCL_is_0x33(void){
  set_PC(0x112233);
  TEST_ASSERT_EQUAL_HEX16(0x11,cpuRegisters->PCE);
  TEST_ASSERT_EQUAL_HEX16(0x22,cpuRegisters->PCH);
  TEST_ASSERT_EQUAL_HEX16(0x33,cpuRegisters->PCL);
}
