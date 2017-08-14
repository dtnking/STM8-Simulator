#include "unity.h"
#include "PUSH.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>


void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

/*
**    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
**    X  Syntax : PUSH src              e.g.:PUSH A   X
**    X   Operation: (SP--) <= dst              			X
**    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/

void test_push_A_given_the_Accumulator_store_0xab_expected_the_decremented_SP_store_0xab(void){
  set_SP(0x10,0x01);                      // Set SPH as 0x10 and SPL as 0x01;
  cpuRegisters->A = 0xab;                 // Give the Accumulator a value of 0xab.
  uint8_t instrc[] = {0x88};
  push_A(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xab,memory[0x1000]);
}

void test_push_CC_given_the_Condition_Code_store_0xeb_expected_the_decremented_SP_store_0xeb(void){
  set_SP(0x21,0x12);
  cpuRegisters->CCR.CC = 0xeb;
  uint8_t instrc[] = {0x8A};
  push_CC(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xeb,memory[0x2111]);
}

void test_push_longmen_given_the_address_0x1000_store_0xee_expected_decremented_SP_store_0xee(void){
  set_SP(0x21,0x12);
  memory[0x1000] = 0xee;
  uint8_t instrc[] = {0x3B,0x10,0x00};
  push_longmem(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xee,memory[0x2111]);
}

void test_push_byte_given_a_byte_0x55_expected_decremented_SP_store_0xe55(void){
  set_SP(0x21,0x12);
  uint8_t instrc[] = {0x4B,0x55};
  push_byte(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x55,memory[0x2111]);
}
