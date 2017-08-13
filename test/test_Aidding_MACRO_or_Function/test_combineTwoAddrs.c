#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_combineTwoAddrs_given_0x01_0x10_expected_0x0110(void){
  uint16_t newAddrss = combineTwoAddrs(0x01, 0x10);
  TEST_ASSERT_EQUAL_HEX16(0x0110,newAddrss);
}

void test_combineTwoAddrs_given_XH_0x10_and_XL_0xaa_expected_0x10aa(void){
  cpuRegisters->XH   = 0x10;
  cpuRegisters->XL   = 0xaa;
  uint16_t newAddrss = combineTwoAddrs(cpuRegisters->XH, cpuRegisters->XL);
  TEST_ASSERT_EQUAL_HEX16(0x10aa,newAddrss);
}
