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


/*        1111 1111
**    +   0000 0001
**    -------------------
**      1 0000 0000               ( CCR flags = 0x02 )
 */
void test_raw_INC_given_value_0xff_expected_0x00_zero_flag_equal_1(void){
  cpuRegisters->A = 0xff;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}


/*        1111 1111
**    +   0000 0001
**    -------------------
**      1 0000 0000               ( CCR flags = 0x04 )
 */
void test_raw_INC_given_value_0xff_expected_0x00_negative_flag_equal_1(void){
  cpuRegisters->A = 0xff;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}
