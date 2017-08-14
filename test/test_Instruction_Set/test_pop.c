#include "unity.h"
#include "pop.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>


void setUp(void){
  clearCCRflag();
}

void tearDown(void){}


void test_pop_A_given_the_incremented_SP_store_0xab_expected_Accumulator_store_0xab(void){
  set_SP(0x10,0x01);                      // Set SPH as 0x10 and SPL as 0x01;
  memory[0x1002] = 0xab;                  // Give the incremented SP a value of 0xab.
  uint8_t instrc[] = {0x84};
  pop_A(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xab,cpuRegisters->A);
}

void test_pop_CC_given_the_incremented_SP_store_0xeb_expected_Condition_code_store_0xeb(void){
  set_SP(0x21,0x12);
  memory[0x2113] = 0xeb;
  uint8_t instrc[] = {0x86};
  pop_CC(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xeb,cpuRegisters->CCR.CC);
}

void test_pop_longmen_given_the_incremented_SP_store_0xeb_expected_address_0x1000_store_0xeb(void){
  set_SP(0x21,0x12);
  memory[0x2113] = 0xeb;
  uint8_t instrc[] = {0x32,0x10,0x00};
  pop_longmem(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xeb,memory[0x1000]);
}
