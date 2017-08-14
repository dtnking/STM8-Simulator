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
  set_X(0x10,0xaa);                 //set XH and XL
  uint16_t newAddrss = combineTwoAddrs(cpuRegisters->XH, cpuRegisters->XL);
  TEST_ASSERT_EQUAL_HEX16(0x10aa,newAddrss);
}

void test_combineThreeAddrs_given_0xaa_0xbb_0xcc_expected_0xaabbcc(void){
  uint32_t newAddrss = combineThreeAddrs(0xaa, 0xbb, 0xcc);
  TEST_ASSERT_EQUAL_HEX32(0xaabbcc,newAddrss);
}

void test_combineThreeAddrs_given_SPE_SPH_SPL_0x01_0x02_0x03_expected_0x010203(void){
  set_PC(0x01,0x02,0x03);
  uint32_t newAddrss = combineThreeAddrs(cpuRegisters->PCE,cpuRegisters->PCH,cpuRegisters->PCL);
  TEST_ASSERT_EQUAL_HEX32(0x010203,newAddrss);
}
