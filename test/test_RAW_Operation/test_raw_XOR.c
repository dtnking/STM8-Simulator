#include "unity.h"
#include "Memory.h"
#include "Raw_Operation.h"
#include "XOR.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        0010 1010
**      XOR   1101 0101
**       ------------------
**            1111 1111
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_XOR_negative_given_0x2a_XOR_0x55_get_0xff_expected_negative(void){
  cpuRegisters->A = 0x2a;
  raw_xor(0xd5);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/*
** (ii)       0000 0001
**      XOR   0000 0000
**       ------------------
**            0000 0001
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_XOR_negative_given_0x01_XOR_0x00_get_0x01_expected_no_negative(void){
  cpuRegisters->A = 0x01;
  raw_xor(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        1111 1111
**       XOR  0000 0000
**       ------------------
**            1111 1111   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_XOR_zero_given_0xFF_XOR_0x00_get_0xff_expected_no_zero(void){
  cpuRegisters->A = 0xff;
  raw_xor(0x00);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}

/* (ii)       0000 0000
**        XOR 0000 0000
**       ------------------
**            0000 0000   (zero)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_XOR_zero_given_0x00_XOR_0x00_get_0x00_expected_zero(void){
  cpuRegisters->A = 0x00;
  raw_xor(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}
