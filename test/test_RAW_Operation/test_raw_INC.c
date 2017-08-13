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
**   (i)  127 + 1 = 128      |        0111 1111   (127)
**                           |  INC   0000 0001     (1)
**                           |   ------------------
**                           |        1000 0000   (-128)
**                           |   ------------------
**  ( CCR flags = 0x44) ----> Overflow, Negative are set.
*/
void test_raw_INC_overflow_given_0x7f_increment_by_1_get_0x80_expected_overflow(void){
  memory[0x10] = 0x7f;
  raw_inc(&memory[0x10]);
  TEST_ASSERT_EQUAL_HEX16(0x80,memory[0x10]);
  TEST_ASSERT_EQUAL_HEX16(0x44,c|z|l|i0|h|i1|v);
}


/* ------------------------------------------------------
**          (expected)        |           (real)
**  (ii)  -128 + 1 = -127     |         1000 0000   (-128)
**                            |   INC   0000 0001      (1)
**                            |   ------------------
**                            |         1000 0001   (-127)
**                            |    ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_INC_overflow_given_0x80_increment_by_1_get_0x81_expected_no_overflow(void){
  cpuRegisters->A = 0x80;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x81,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* ------------------------------------------------------
**           (expected)        |           (real)
**  (iii) 12 + 1 = 13          |         0000 1100   (12)
**                             |   INC   0000 0001    (1)
**                             |   ------------------
**                             |         0000 1101   (13)
**                             |    ------------------
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_INC_overflow_given_0x0C_increment_by_1_get_0x0D_expected_no_overflow(void){
  cpuRegisters->A = 0x0C;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x0D,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        1111 1110
**      INC   0000 0001
**       ------------------
**            1111 1111   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_INC_zero_given_0xfe_increment_by_1_get_0xff_expect_non_zero(void){
  cpuRegisters->A = 0xfe;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}

/* (ii)       1111 1111
**      INC   0000 0001
**       ------------------
**          1 0000 0000   (zero,skipping the Carry bit)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_INC_zero_given_0xff_increment_by_1_get_0x00_expect_zero(void){
  cpuRegisters->A = 0xff;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}



//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        1000 0000
**       INC  0000 0001
**       ------------------
**            1000 0001
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_INC_given_0x80_increment_by_1_get_0x81_expect_Negative(void){
  cpuRegisters->A = 0x80;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x81,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}

/*
** (ii)       0000 0001
**       INC  0000 0001
**       ------------------
**            0000 0010
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_INC_given_0x01_increment_by_1_get_0x02_expect_Non_negative(void){
  cpuRegisters->A = 0x01;
  raw_inc(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}
