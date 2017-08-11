#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_get_valByte_given_byte_0x10_expect_returned_0x10(void){
  uint8_t instrc[] = {0x01,0x10};
  uint8_t result   = get_valueByte(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x10,result);
}

void test_get_shortmem_given_shortmem_0x10_expect_returned_0x10(void){
  uint8_t instrc[] = {0x01,0x10};
  uint8_t result   = get_shortmem(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x10,result);
}

void test_get_longmem_given_longmem_0x0110_expect_returned_0x10(void){
  uint8_t instrc[] = {0x11,0x01,0x10};
  uint8_t result   = get_longmem(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x10,result);
}

void test_get_xValue_given_XH_0x01_XL_0x10_expect_returned_0x0110(void){
  cpuRegisters->XH  = 0x01;
  cpuRegisters->XL  = 0x10;
  uint16_t result   = get_x_value();
  TEST_ASSERT_EQUAL_HEX16(0x0110,result);
}

void test_get_yValue_given_YH_0x10_YL_0x01_expect_returned_0x1001(void){
  cpuRegisters->YH  = 0x10;
  cpuRegisters->YL  = 0x01;
  uint16_t result   = get_y_value();
  TEST_ASSERT_EQUAL_HEX16(0x1001,result);
}

void test_get_xShortset_given_shortmem_0x10_and_XH_0x01_XL_0x10_expect_returned_0x0120(void){
  uint8_t instrc[]  = {0xAB,0x10};
  cpuRegisters->XH  = 0x01;
  cpuRegisters->XL  = 0x10;
  uint16_t result   = get_x_shortset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0120,result);
}

void test_get_yShortset_given_shortmem_0x10_and_YH_0x10_YL_0x01_expect_returned_0x1011(void){
  uint8_t instrc[]  = {0x90,0xAB,0x10};
  cpuRegisters->YH  = 0x10;
  cpuRegisters->YL  = 0x01;
  uint16_t result   = get_y_shortset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x1011,result);
}

void test_get_xLongset_given_longmem_0x0000_and_XH_0x01_XL_0x10_expect_returned_0x0110(void){
  uint8_t instrc[]  = {0xAB,0x00,0x00};
  cpuRegisters->XH  = 0x01;
  cpuRegisters->XL  = 0x10;
  uint16_t result   = get_x_longset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0110,result);
}

void test_get_yLongset_given_longmem_0x0000_and_YH_0x01_YL_0x10_expect_returned_0x0110(void){
  uint8_t instrc[]  = {0x90,0xAB,0x00,0x00};
  cpuRegisters->YH  = 0x01;
  cpuRegisters->YL  = 0x10;
  uint16_t result   = get_y_longset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0110,result);
}

void test_get_shortoff_SP_given_offset_0x22_and_SP_0x8888_expect_returned_0x88aa(void){
  set_SP(0x88,0x88);
  uint8_t instrc[]	= {0x1B,0x22};
  uint16_t result   = get_shortoff_SP(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x88aa,result);
}

void test_get_shortptr_W_given_shortptr_0x40_which_is_then_point_to_0x42e5_expect_returned_0x42e5(void){
  uint8_t instrc[] = {0x92,0xcb,0x40};
  memory[0x40]		 = 0x42;
	memory[0x41]		 = 0xe5;
  uint16_t result  = get_shortptr_w(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x42e5,result);
}

void test_get_longptr_W_given_longptr_0x1040_which_is_then_point_to_0xaaaa_expect_returned_0xaaaa(void){
  uint8_t instrc[] = {0x72,0xcb,0x10,0x40};
  memory[0x1040]	 = 0xaa;
	memory[0x1041]	 = 0xaa;
  uint16_t result  = get_longptr_w(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xaaaa,result);
}

void test_get_shortptr_w_X_given_shortptr_0x89_with_XH_0x00_XL_0x03_which_is_then_point_to_0x0801_expect_returned_0x0804(void){
  set_X(0x00,0x03);
  uint8_t instrc[] = {0x92,0xDB,0x89};
  memory[0x89]	 = 0x08;
	memory[0x8a]	 = 0x01;
  uint16_t result  = get_shortptr_w_X(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0804,result);
}

void test_get_longptr_w_X_given_longptr_0x1089_with_XH_0x01_XL_0x03_which_is_then_point_to_0x1801_expect_returned_0x1904(void){
  set_X(0x01,0x03);
  uint8_t instrc[] = {0x72,0xDB,0x10,0x89};
  memory[0x1089]	 = 0x18;
	memory[0x108a]	 = 0x01;
  uint16_t result  = get_longptr_w_X(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x1904,result);
}

void test_get_shortptr_w_Y_given_shortptr_0x22_with_YH_0x11_YL_0x11_which_is_then_point_to_0x3333_expect_returned_0x4444(void){
  set_Y(0x11,0x11);
  uint8_t instrc[] = {0x91,0xDB,0x22};
  memory[0x22]	 = 0x33;
	memory[0x23]	 = 0x33;
  uint16_t result  = get_shortptr_w_Y(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x4444,result);
}
