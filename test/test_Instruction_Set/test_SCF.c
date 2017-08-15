#include "unity.h"
#include "SCF.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_SCF_given_Carry_flags_is_0_expected_set_to_1(void){
  cpuRegisters->CCR.bit.C = 0;
  uint8_t instrc[] = {0x99};
  scf(instrc);
  TEST_ASSERT_EQUAL_HEX8(1,cpuRegisters->CCR.bit.C);
}

void test_CCF_given_Carry_flags_is_1_expected_set_to_1(void){
  cpuRegisters->CCR.bit.C = 1;
  uint8_t instrc[] = {0x99};
  scf(instrc);
  TEST_ASSERT_EQUAL_HEX8(1,cpuRegisters->CCR.bit.C);
}
