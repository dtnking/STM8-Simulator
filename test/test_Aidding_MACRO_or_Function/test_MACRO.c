#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>


void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_MACRO_getMSB_given_0xabcd_expected_result_0xab(void){
  uint8_t result = GET_MSB(0xabcd);
  TEST_ASSERT_EQUAL_HEX16(0xab,result);
}

void test_MACRO_getLSB_given_0xabcd_expected_result_0xcd(void){
  uint8_t result = GET_LSB(0xabcd);
  TEST_ASSERT_EQUAL_HEX16(0xcd,result);
}

void test_MACRO_getHMSB_given_0x11abcd_expected_result_0x11(void){
  uint8_t result = GET_HMSB(0x11abcd);
  TEST_ASSERT_EQUAL_HEX16(0x11,result);
}
