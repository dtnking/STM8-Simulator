#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "sbc.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}


//                TEST FOR OVERFLOW
/* ----------------------------------------------------
**          (expected)        |          (real)
**   (i)  127 - (-3) = 130    |         0111 1111   (127)
**                            |     -   1111 1101    (-3)
**                            |    ------------------
**                            |         1000 0010   (-126)
**                            |    ------------------
**  ( CCR flags = 0x45) ----> Overflow, Negative , Carry are set.
*/
void test_raw_SBC_overflow_given_0x7f_minus_fd_get_0x82_expect_overflow(void){
  cpuRegisters->A = 0x7f;
  raw_sbc(0xfd);
  TEST_ASSERT_EQUAL_HEX16(0x82,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x45,c|z|l|i0|h|i1|v);
}


/* ----------------------------------------------------------
**          (expected)         |          (real)
**  (ii)  -127 - 3 = -130      |         1000 0001   (-127)
**                             |     -   0000 0011      (3)
**                             |    ------------------
**                             |         0111 1110    (126)
**                             |    ------------------
**  ( CCR flags = 0x40) ----> Overflow is set.
*/
void test_raw_SBC_overflow_given_0x81_minus_0x03_get_0x7E_expected_overflow(void){
  cpuRegisters->A = 0x81;
  raw_sbc(0x03);
  TEST_ASSERT_EQUAL_HEX16(0x7e,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x40,c|z|l|i0|h|i1|v);
}


/* -----------------------------------------------------------
**            (expected)         |          (real)
**  (iii)   -1 - 120 = -121      |         1111 1111     (-1)
**                               |     -   0111 1000    (120)
**                               |    ------------------
**                               |         1000 0111   (-121)
**                               |    ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_SBC_overflow_given_0xff_minus_0x78_get_0x87_expected_no_overflow(void){
  cpuRegisters->A = 0xff;
  raw_sbc(0x78);
  TEST_ASSERT_EQUAL_HEX16(0x87,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* -----------------------------------------------------------
**            (expected)         |          (real)
**  (iv)    120 - 1 = 119        |         0111 1000    (120)
**                               |     -   0000 0001      (1)
**                               |    ------------------
**                               |         0111 0111   (119)
**                               |    ------------------
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_SBC_overflow_given_0x78_minus_0x01_get_0x77_expected_no_overflow(void){
  cpuRegisters->A = 0x78;
  raw_sbc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x77,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//                TEST FOR CARRY
/* ----------------------------------------------------
**  (i)
**          0000 0001 <-- not enought to minus, borrow 1 bit from bit 9(carry bit)
**      -   0001 0000
**      ---------------
**          1111 0001
**      ---------------
**
**  ( CCR flags = 0x05) ----> Negative, Carry are set.
 */
void test_raw_SBC_carry_given_0x01_minus_0x10_get_0xf1_expected_Carry_is_set(void){
  cpuRegisters->A = 0x01;
  raw_sbc(0x10);
  TEST_ASSERT_EQUAL_HEX16(0xf1,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x05,c|z|l|i0|h|i1|v);
}

/*
 **  (ii)
 **          0001 0000 <-- enought to minus, no need to borrow from bit 9(carry bit).
 **      -   0000 0001
 **      ---------------
 **          0000 1111
 **      ---------------
 **
 **  ( CCR flags = 0x00) ----> None of the CCR is set.
  */
void test_raw_SBC_carry_given_0x10_minus_0x01_get_0x0f_expected_no_carry(void){
  cpuRegisters->A = 0x10;
  raw_sbc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x0f,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}

/*
 **  (iii)
 **          0001 0000 <-- enought to minus, no need to borrow from bit 9(carry bit).
 **      -   0000 0001
 **      ---------------
 **          0000 1111
 **      -   0000 0001 <-- minus 1 (borrow bit is set)
 **      ---------------
 **          0000 1110
 **      ---------------
 **
 **  ( CCR flags = 0x00) ----> None of the CCR is set.
  */
void test_raw_SBC_carry_given_0x10_minus_0x01_with_borrow_bit_0x01_get_0x0e_expected_no_carry(void){
  cpuRegisters->A     = 0x10;
  cpuRegisters->CCR.bit.C = 0x01;
  raw_sbc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x0e,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}



//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        1111 1111
**        -   0000 0000
**       ------------------
**            1111 1111   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_SBC_zero_given_0xff_minus_0x00_get_0xff_expected_no_zero(void){
  cpuRegisters->A = 0xff;
  raw_sbc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* (ii)       0001 0000
**        -   0001 0000
**       ------------------
**            0000 0000   (zero)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_SBC_zero_given_0x10_minus_0x10_get_0x00_expected_zero(void){
  cpuRegisters->A = 0x10;
  raw_sbc(0x10);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}



//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        1000 0000
**        -   0000 0000
**       ------------------
**            1000 0000
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_SBC_negative_given_0x80_minus_0x00_get_0x80_expected_negative(void){
  cpuRegisters->A = 0x80;
  raw_sbc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x80,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}

/*
** (ii)       0000 0001
**        -   0000 0000
**       ------------------
**            0000 0001
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_SBC_negative_given_0x01_minus_0x00_get_0x01_expected_not_negative(void){
  cpuRegisters->A = 0x01;
  raw_sbc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}
