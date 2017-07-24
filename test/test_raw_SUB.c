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


/*        0000 0001
**    -   0000 0000
**    -------------------
**        0000 0001                ( CCR flags = 0x00 )
 */

void test_raw_SUB_given_value_0x01_sub_with_0x01_expected_0x01_with_all_CCR_flag_equal_to_0(void){
  cpuRegisters->A = 0x01;
  raw_sub(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|n|i0|h|i1|v);
}


/*        0000 0000
**    -   0000 0001
**    -------------------
**        1111 1111  (-1)            ( CCR flags = 0x05 )
 */
void test_raw_SUB_given_value_0x00_sub_with_0x01_expected_0xff_with_carry_negative_flag_equal_to_1(void){
  cpuRegisters->A = 0x00;
  raw_sub(0x01);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x05,c|z|n|i0|h|i1|v);
}


/*        0000 0001
**    -   0000 0001
**    -------------------
**        0000 0000                 ( CCR flags = 0x02 )
 */
void test_raw_SUB_given_value_0x01_sub_with_0x01_expected_0x00_with_zero_flag_equal_to_1(void){
  cpuRegisters->A = 0x01;
  raw_sub(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|n|i0|h|i1|v);
}
