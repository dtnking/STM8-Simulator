#include "unity.h"
#include "CCF.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>


void setUp(void){}

void tearDown(void){}

void test_CCF_given_Carry_flags_is_1_expected_complement_to_0(void){
  cpuRegisters->CCR.bit.C = 1;
  uint8_t instrc[] = {0x8c};
  ccf(instrc);
  TEST_ASSERT_EQUAL_HEX8(0,cpuRegisters->CCR.bit.C);
}

void test_CCF_given_Carry_flags_is_0_expected_complement_to_1(void){
  cpuRegisters->CCR.bit.C = 0;
  uint8_t instrc[] = {0x8c};
  ccf(instrc);
  TEST_ASSERT_EQUAL_HEX8(1,cpuRegisters->CCR.bit.C);
}
