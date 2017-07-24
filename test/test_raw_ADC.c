#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "adc.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}


/*        0000 0000
**        0000 0000
**    +   0000 0001  (carry bit)
**    -------------------
**        0000 0001                ( CCR flags = 0x00 )
 */
void test_raw_adc_given_value_0x00_add_with_0x00_and_carry_bit_is_1_expected_0x01_with_all_CCR_flag_equal_0(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 1;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|n|i0|h|i1|v);
}


/*        0000 0000
**        0000 0000
**    +   0000 0000  (carry bit)
**    -------------------
**        0000 0000                ( CCR flags = 0x02 )
 */
void test_raw_adc_given_value_0x00_add_with_0x00_and_carry_bit_is_0_expected_0x00_with_zero_flag_equal_1(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 0;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|n|i0|h|i1|v);
}


/*        1000 0001
**        0000 0001
**    +   0000 0001  (carry bit)
**    -------------------
**        1000 0011                ( CCR flags = 0x04 )
 */
void test_raw_adc_given_value_0x81_add_with_0x01_and_carry_bit_is_1_expected_0x83_negative_flag_equal_1(void){
  cpuRegisters->A = 0x81;
  cpuRegisters->CCR.C = 1;
  raw_adc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x83,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|n|i0|h|i1|v);
}


/*        0000 0000
**        1111 1111
**    +   0000 0001  (carry bit)
**    -------------------
**      1 0000 0000                ( CCR flags = 0x13 )
 */
void test_raw_adc_given_value_0xff_add_with_0x00_and_carry_bit_is_1_expected_0x0_carry_zero_and_halfCarry_flag_equal_1(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 1;
  raw_adc(0xff);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x13,c|z|n|i0|h|i1|v);
}


/*    (TEST FOR SIGNED VALUE OVERFLOW)
**        0000 0000
**        1111 1111
**    +   0000 0001  (carry bit)
**    -------------------
**      1 0000 0000                ( CCR flags = 0x13 )
 */
void test_raw_adc_given_value_0xff_add_with_0x00_and_carry_bit_is_1_expected_0x0_carry_zero_and_halfCarry_flag_equal_1(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 1;
  raw_adc(0xff);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x13,c|z|n|i0|h|i1|v);
}
