#include "unity.h"
#include "addw.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_addw_word_X_given_0x1010_add_with_X_0x1111_expected_X_eq_0x2121(void){
  set_X(0x1111);

  uint8_t instrc[] = {0x1C , 0x10, 0x10};
  addw_word_X(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2121,X);
}

void test_addw_longmem_X_given_0x33_within_longmem_add_with_X_0x3333_expected_X_eq_0x3366(void){
  set_X(0x3333);
  memory[0x3333] = 0x33;
  uint8_t instrc[] = {0x72,0xbb,0x33,0x33};
  addw_longmem_X(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x3366,X);
}

void test_addw_shortoff_X_given_SP_plus_offset_eq_0x33_then_add_with_X_0x5555_expected_X_eq_0x5588(void){
  set_X(0x5555);
  set_SP(0x1111);
  memory[0x1112] = 0x33;      // SP(0x1111) + offset(0x01) = 0x1112
  uint8_t instrc[] = {0x72,0xFB,0x01};
  addw_shortoff_SP_X(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x5588,X);
}

void test_addw_word_Y_given_0x1111_add_with_Y_0x2222_expected_Y_eq_0x3333(void){
  set_Y(0x2222);
  uint8_t instrc[] = {0x72, 0xA9 , 0x11, 0x11};
  addw_word_Y(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x3333,Y);
}

void test_addw_longmem_Y_given_0x11_within_longmem_add_with_Y_0x4444_expected_Y_eq_0x4455(void){
  set_Y(0x4444);
  memory[0x1212] = 0x11;
  uint8_t instrc[] = {0x72,0xb9,0x12,0x12};
  addw_longmem_Y(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x4455,Y);
}

void test_addw_shortoff_Y_given_SP_plus_offset_eq_0x44_then_add_with_Y_0x6666_expected_Y_eq_0x66aa(void){
  set_Y(0x6666);
  set_SP(0x1111);
  memory[0x1112] = 0x44;      // SP(0x1111) + offset(0x01) = 0x1112
  uint8_t instrc[] = {0x72,0xF9,0x01};
  addw_shortoff_SP_Y(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x66aa,Y);
}

void test_addw_byte_SP_given_0x02_add_with_SP_0x1111_expected_SP_eq_0x1113(void){
  set_SP(0x1111);

  uint8_t instrc[] = {0x5B,0x02};
  addw_byte_SP(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x1113,SP);
}
