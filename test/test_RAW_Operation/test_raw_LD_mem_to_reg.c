#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "LD.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

//      TEST FOR NEGATIVE
/*---------------------------------------
** (i)       1010 1010 (0xaa)
**           ^
**       Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_LD_negative_given_0xaa_expected_negative(void){
  raw_ld(0xaa);
  TEST_ASSERT_EQUAL_HEX16(0xaa,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* (ii)      0010 1010 (0x2a)
**           ^
**       Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_LD_negative_given_0x2a_expected_no_negative(void){
  raw_ld(0x2a);
  TEST_ASSERT_EQUAL_HEX16(0x2a,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//            TEST FOR ZERO
/* ----------------------------------------------------
** (i)        1111 1111 (Non-zero)
**             (0xff)-----^
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_LD_zero_given_0xff_expected_no_zero(void){
  raw_ld(0xff);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* (ii)       0000 0000 (zero)
**             (0x00)-----^
**
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_LD_zero_given_0x00_expected_zero(void){
  raw_ld(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}
