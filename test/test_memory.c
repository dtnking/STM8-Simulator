#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_get_valByte_given_opcode_0x0110_expect_returned_value_is_0x10(void){
  uint8_t instrc[] = {0x01,0x10};
  uint8_t result   = get_valueByte((uint8_t *)&instrc);
  TEST_ASSERT_EQUAL_HEX16(0x10,result);
}

void test_get_shortmem_given_opcode_0x0110_expect_returned_value_is_0x10(void){
  uint8_t instrc[] = {0x01,0x10};
  uint8_t result   = get_shortmem((uint8_t *)&instrc);
  TEST_ASSERT_EQUAL_HEX16(0x10,result);
}

void test_get_longmem_given_opcode_0x0110_expect_returned_value_is_0x10(void){
  uint8_t instrc[] = {0x11,0x01,0x10};
  uint8_t result   = get_longmem((uint8_t *)&instrc);
  TEST_ASSERT_EQUAL_HEX16(0x10,result);
}

void test_get_xValue_given_XH_0x01_XL_0x10_expect_returned_value_is_0x0110(void){
  cpuRegisters->XH  = 0x01;
  cpuRegisters->XL  = 0x10;
  uint16_t result   = get_x_value();
  TEST_ASSERT_EQUAL_HEX16(0x0110,result);
}

void test_get_yValue_given_YH_0x10_YL_0x01_expect_returned_value_is_0x1001(void){
  cpuRegisters->YH  = 0x10;
  cpuRegisters->YL  = 0x01;
  uint16_t result   = get_y_value();
  TEST_ASSERT_EQUAL_HEX16(0x1001,result);
}

void test_get_xShortset_given_opcode_0xAB10_and_XH_0x01_XL_0x10_expect_returned_value_is_0x0120(void){
  uint8_t instrc[] = {0xAB,0x10};
  cpuRegisters->XH  = 0x01;
  cpuRegisters->XL  = 0x10;
  uint16_t result   = get_x_shortset((uint8_t *)&instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0120,result);
}

void test_get_yShortset_given_opcode_0xABBB10_and_YH_0x10_YL_0x01_expect_returned_value_is_0x1011(void){
  uint8_t instrc[] = {0x90,0xAB,0x10};
  cpuRegisters->YH  = 0x10;
  cpuRegisters->YL  = 0x01;
  uint16_t result   = get_y_shortset((uint8_t *)&instrc);
  TEST_ASSERT_EQUAL_HEX16(0x1011,result);
}

void test_get_xLongset_given_opcode_0xAB0000_and_XH_0x01_XL_0x10_expect_returned_value_is_0x0110(void){
  uint8_t instrc[] = {0xAB,0x00,0x00};
  cpuRegisters->XH  = 0x01;
  cpuRegisters->XL  = 0x10;
  uint16_t result   = get_x_longset((uint8_t *)&instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0110,result);
}
