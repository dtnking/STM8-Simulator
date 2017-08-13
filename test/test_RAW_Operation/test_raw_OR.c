#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "OR.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        1010 1010
**      OR    1101 0101
**       ------------------
**            1111 1111
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_OR_negative_given_0xaa_OR_0x55_get_0xff_expected_negative(void){
  cpuRegisters->A = 0xaa;
  raw_or(0xd5);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/*
** (ii)       0000 0001
**      OR    0000 0001
**       ------------------
**            0000 0001
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_OR_negative_given_0x01_OR_0x01_get_0x01_expected_no_negative(void){
  cpuRegisters->A = 0x01;
  raw_or(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}



//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        1111 1111
**       OR   1111 1111
**       ------------------
**            1111 1111   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_OR_zero_given_0xFF_OR_0xFF_get_0xff_expected_no_zero(void){
  cpuRegisters->A = 0xff;
  raw_or(0xff);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* (ii)       0000 0000
**        OR  0000 0000
**       ------------------
**            0000 0000   (zero)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_OR_zero_given_0x00_OR_0x00_get_0x00_expected_zero(void){
  cpuRegisters->A = 0x00;
  raw_or(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}
