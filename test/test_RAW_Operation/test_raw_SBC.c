#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "sbc.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}


/*        0000 0001
**        0000 0000
**    -   0000 0001   (carry bit)
**    -------------------
**        0000 0000                ( CCR flags = 0x02 )
*/
void test_raw_SUBC_given_value_0x01_sub_with_0x00_and_carry_bit_is_1_expected_0x00_with_zero_flag_equal_to_1(void){
cpuRegisters->A = 0x01;
cpuRegisters->CCR.C = 1;
raw_sub(0x01);
TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}


/*        0000 0001
**        0000 0000
**    -   0000 0000   (carry bit)
**    -------------------
**        0000 0000                ( CCR flags = 0x00 )
*/
void test_raw_SUBC_given_value_0x01_sub_with_0x00_and_carry_bit_is_0_expected_0x01_with_all_CCR_flag_equal_to_0(void){
cpuRegisters->A = 0x01;
cpuRegisters->CCR.C = 0;
raw_sub(0x00);
TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


/*        0000 0000
**        0000 0000
**    -   0000 0001   (carry bit)
**    -------------------
**        1111 1111  (-1)          ( CCR flags = 0x05 )
*/
void test_raw_SUBC_given_value_0x00_sub_with_0x00_and_carry_bit_is_1_expected_0xff_with_negative_carry_flag_equal_to_1(void){
cpuRegisters->A = 0x00;
cpuRegisters->CCR.C = 1;
raw_sub(0x01);
TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
TEST_ASSERT_EQUAL_HEX16(0x05,c|z|l|i0|h|i1|v);
}
