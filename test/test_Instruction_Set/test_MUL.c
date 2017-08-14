#include "unity.h"
#include "MUL.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_MUL_X_given_0x02_mul_0xab_expect_X_contain_0x156(void){
  cpuRegisters->A  = 0x02;
  cpuRegisters->XL = 0xab;
  uint8_t instrc[] = {0x42};
  mul_X(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x0156,X);
}

void test_MUL_Y_given_0x31_mul_0xba_expect_Y_contain_0x239a(void){
  cpuRegisters->A  = 0x31;
  cpuRegisters->YL = 0xba;
  uint8_t instrc[] = {0x09,0x42};
  mul_Y(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x239a,Y);
}
