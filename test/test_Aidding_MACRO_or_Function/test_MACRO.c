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

void test_GET_PC_given_PCE_0x01_PCH_0x02_PCH_0x03_expected_to_get_0x010203(void){
  cpuRegisters->PCE = 0x01;
  cpuRegisters->PCH = 0x02;
  cpuRegisters->PCL = 0x03;


  TEST_ASSERT_EQUAL_HEX(0x010203,GET_PC);
}

void test_UPDATE_PC_given_length_is_2_expected_PC_is_2(void){
  UPDATE_PC(2);

  TEST_ASSERT_EQUAL_HEX16(0x02,GET_PC);
}
