#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "adc.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}


//                TEST FOR OVERFLOW
/* ------------------------------------------------------
**          (expected)       |         (real)
**   (i)  -128 - 1 = -129    |        1000 0000   (-128)
**                           |  DEC   0000 0001      (1)
**                           |   ------------------
**                           |        0111 1111    (127)
**                           |   ------------------
**  ( CCR flags = 0x40) ----> Overflow is set.
*/
void test_raw_DEC_overflow_given_0x80_decrement_by_1_get_0x7f_expected_overflow(void){
  memory[0x10] = 0x80;
  raw_dec(&memory[0x10]);
  TEST_ASSERT_EQUAL_HEX16(0x7f,memory[0x10]);
  TEST_ASSERT_EQUAL_HEX16(0x40,c|z|l|i0|h|i1|v);
}


/* ------------------------------------------------------
**          (expected)        |           (real)
**  (ii)  -127 - 1 = -128     |         1000 0001   (-127)
**                            |   DEC   0000 0001      (1)
**                            |   ------------------
**                            |         1000 0000   (-128)
**                            |    ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_DEC_overflow_given_0x81_decrement_by_1_get_0x80_expected_no_overflow(void){
  cpuRegisters->A = 0x81;
  raw_dec(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x80,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* ------------------------------------------------------
**           (expected)        |           (real)
**  (iii) 13 - 1 = 12          |         0000 1101   (13)
**                             |   DEC   0000 0001    (1)
**                             |   ------------------
**                             |         0000 1100   (12)
**                             |    ------------------
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_DEC_overflow_given_0x0D_decrement_by_1_get_0xC_expected_no_overflow(void){
  cpuRegisters->A = 0x0D;
  raw_dec(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x0C,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        1111 1111
**      DEC   0000 0001
**       ------------------
**            1111 1110   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_DEC_zero_given_0xff_decrement_by_1_get_0xfe_expect_non_zero(void){
  cpuRegisters->A = 0xff;
  raw_dec(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0xfe,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}

/* (ii)       0000 0001
**      DEC   0000 0001
**       ------------------
**            0000 0000   (zero)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_DEC_zero_given_0x01_decrement_by_1_get_0x00_expect_zero(void){
  cpuRegisters->A = 0x01;
  raw_dec(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}



//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        1000 0001
**       DEC  0000 0001
**       ------------------
**            1000 0000
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_DEC_given_0x81_decrement_by_1_get_0x80_expect_Negative(void){
  cpuRegisters->A = 0x81;
  raw_dec(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x80,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}

/*
** (ii)       0000 0011
**       DEC  0000 0001
**       ------------------
**            0000 0010
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_DEC_given_0x03_decrement_by_1_get_0x02_expect_Non_negative(void){
  cpuRegisters->A = 0x03;
  raw_dec(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}
