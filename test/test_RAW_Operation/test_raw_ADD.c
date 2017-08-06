#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "add.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

//                TEST FOR OVERFLOW
/* ----------------------------------------------------
**          (expected)     |          (real)
**   (i)  127 + 3 = 130    |         0111 1111   (127)
**                         |     +   0000 0011     (3)
**                         |    ------------------
**                         |         1000 0010   (-126)
**                         |    ------------------
**  ( CCR flags = 0x54) ----> Overflow, Negative , Half-Carry are set.
*/

void test_raw_overflow_given_positive_plus_positive_value_get_negative_value_expected_overflow(void){
  cpuRegisters->A = 0x7f;
  raw_add(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x80,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x54,c|z|l|i0|h|i1|v);
}

/* ----------------------------------------------------------
**          (expected)         |          (real)
**  (ii)  -127 + (-3) = -130   |         1000 0001   (-127)
**                             |     +   1111 1101     (-3)
**                             |    ------------------
**                             |         0111 1110    (124)
**                             |    ------------------
**  ( CCR flags = 0x41) ----> Overflow, Carry are set.
*/
void test_raw_overflow_given_negative_plus_negative_value_get_positive_value_expected_overflow(void){
  cpuRegisters->A = 0x81;
  raw_add(0xFD);
  TEST_ASSERT_EQUAL_HEX16(0x7E,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x041,c|z|l|i0|h|i1|v);
}


/* -----------------------------------------------------------
**            (expected)         |          (real)
**  (iii)   -1 + 120 = 119       |         1111 1111     (-1)
**                               |     +   0111 1111    (120)
**                               |    ------------------
**                               |         0111 0111    (119)
**                               |    ------------------
**  ( CCR flags = 0x11) ----> Half-Carry, Carry are set.
*/
void test_raw_overflow_given_negative_plus_positive_value_get_positive_value_expected_no_overflow(void){
  cpuRegisters->A = 0xff;
  raw_add(0x78);
  TEST_ASSERT_EQUAL_HEX16(0x77,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x011,c|z|l|i0|h|i1|v);
}



//                TEST FOR CARRY
/* ----------------------------------------------------
**  (i)     1000 0000
**      +   1000 0000
**      ---------------
**        1 0000 0000
**      ---------------
**        ^
**      carry
**
**  ( CCR flags = 0x43) ----> Overflow, Zero, Carry are set.
 */
void test_raw_carry_given_value_0x80_plus_with_0x80_expected_Carry_is_set(void){
 cpuRegisters->A = 0x80;
 raw_add(0x80);
 TEST_ASSERT_EQUAL_HEX16(0,cpuRegisters->A);
 TEST_ASSERT_EQUAL_HEX16(0x43,c|z|l|i0|h|i1|v);
 }


/*
** (ii)     0000 0000
**      +   0000 0001
**      ---------------
**        0 0000 0001
**      ---------------
**        ^
**      carry
**
**  ( CCR flags = 0x00) ----> Overflow, Zero, Carry are set.
*/
void test_raw_carry_given_value_0x00_plus_with_0x01_expected_no_Carry(void){
  cpuRegisters->A = 0x00;
  raw_add(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//             TEST FOR HALF-CARRY
/* ----------------------------------------------------
** (i)         1  <- half carry
**          0000 1000
**      +   0000 1000
**      ---------------
**          0001 0000
**      ---------------
**  ( CCR flags = 0x10) ----> Half-Carry is set.
*/
void test_raw_half_carry_given_value_0x08_plus_with_0x08_expected_Half_Carry_is_set(void){
  cpuRegisters->A = 0x08;
  raw_add(0x08);
  TEST_ASSERT_EQUAL_HEX16(0x10,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x10,c|z|l|i0|h|i1|v);
}

/*
** (ii)        0  <- half carry
**          0000 0000
**      +   0000 1000
**      ---------------
**          0000 1000
**      ---------------
**  ( CCR flags = 0x10) ----> None of the CCR is set.
*/
void test_raw_half_carry_given_value_0x00_plus_with_0x08_expected_no_Half_carry(void){
  cpuRegisters->A = 0x00;
  raw_add(0x08);
  TEST_ASSERT_EQUAL_HEX16(0x08,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        1111 1111
**        +   0000 0000
**       ------------------
**            1111 1111   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_zero_given_value_0xff_plus_with_0x00_expected_no_zero(void){
  cpuRegisters->A = 0xff;
  raw_add(0x00);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* (ii)       0000 0000
**        +   0000 0000
**       ------------------
**            0000 0000   (zero)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_zero_given_value_0x00_plus_with_0x00_expected_zero(void){
  cpuRegisters->A = 0x00;
  raw_add(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}

//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        1000 0000
**        +   0000 0000
**       ------------------
**            1000 0000
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_negative_given_value_0x80_plus_with_0x00_expected_negative(void){
  cpuRegisters->A = 0x80;
  raw_add(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x80,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/*
** (ii)       0000 0001
**        +   0000 0001
**       ------------------
**            0000 0010
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_negative_given_value_0x01_plus_with_0x01_expected_no_negative(void){
  cpuRegisters->A = 0x01;
  raw_add(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x02,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}
