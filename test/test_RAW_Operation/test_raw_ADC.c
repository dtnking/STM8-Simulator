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


//                TEST FOR OVERFLOW
/* ------------------------------------------------------
**          (expected)        |          (real)
**   (i)  127 + 3 + 1 = 131   |         0000 0001     (1) <---Carry value
**                            |         0111 1111   (127)
**                            |     +   0000 0011     (3)
**                            |    ------------------
**                            |         1000 0011   (-125)
**                            |    ------------------
**  ( CCR flags = 0x54) ----> Overflow, Negative , Half-Carry are set.
*/

void test_raw_ADC_overflow_given_positive_plus_positive_value_get_negative_value_expected_overflow(void){
  cpuRegisters->A = 0x7f;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x03);
  TEST_ASSERT_EQUAL_HEX16(0x83,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x54,c|z|l|i0|h|i1|v);
}

/* ----------------------------------------------------------
**          (expected)            |          (real)
**  (ii)  -127 + (-3) + 1 = -129  |         0000 0001      (1) <---Carry value
**                                |         1000 0001   (-127)
**                                |     +   1111 1101     (-3)
**                                |    ------------------
**                                |         0111 1111    (127)
**                                |    ------------------
**  ( CCR flags = 0x41) ----> Overflow, Carry are set.
*/
void test_raw_ADC_overflow_given_negative_plus_negative_value_get_positive_value_expected_overflow(void){
  cpuRegisters->A = 0x81;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0xFD);
  TEST_ASSERT_EQUAL_HEX16(0x7F,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x041,c|z|l|i0|h|i1|v);
}


/* -----------------------------------------------------------
**            (expected)         |          (real)
**  (iii)   -1 + 120 + 1 = 120   |         0000 0001      (1) <---Carry value
**                               |         1111 1111     (-1)
**                               |     +   0111 1000    (120)
**                               |    ------------------
**                               |         0111 1000    (120)
**                               |    ------------------
**  ( CCR flags = 0x11) ----> Half-Carry, Carry are set.
*/
void test_raw_ADC_overflow_given_negative_plus_positive_value_get_positive_value_expected_no_overflow(void){
  cpuRegisters->A = 0xff;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x78);
  TEST_ASSERT_EQUAL_HEX16(0x78,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x11,c|z|l|i0|h|i1|v);
}

/* -----------------------------------------------------------
**            (expected)         |          (real)
**  (iv)  61 + (-120) + 1 = -58  |         0000 0001      (1) <---Carry value
**                               |         0011 1101     (61)
**                               |     +   1000 1000   (-120)
**                               |    ------------------
**                               |         1100 0110    (-58)
**                               |    ------------------
**  ( CCR flags = 0x14) ----> Half-Carry, Negative are set.
*/
void test_raw_ADC_overflow_given_positive_plus_negative_value_get_negative_value_expected_no_overflow(void){
  cpuRegisters->A = 0x3D;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x88);
  TEST_ASSERT_EQUAL_HEX16(0xc6,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x14,c|z|l|i0|h|i1|v);
}


//            TEST FOR CARRY
/* ----------------------------------------------------
**  (i)     0000 0001 <---Carry value
**          1000 0000
**      +   1000 0000
**      ---------------
**        1 0000 0001
**      ---------------
**        ^
**      carry
**
**  ( CCR flags = 0x41) ----> Overflow, Carry are set.
 */
void test_raw_ADC_carry_given_value_0x80_plus_with_0x80_expected_Carry_is_set(void){
 cpuRegisters->A = 0x80;
 cpuRegisters->CCR.C = 0x01;
 raw_adc(0x80);
 TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
 TEST_ASSERT_EQUAL_HEX16(0x41,c|z|l|i0|h|i1|v);
 }


/*
** (ii)     0000 0001 <---Carry value
**          0000 0000
**      +   0000 0001
**      ---------------
**        0 0000 0010
**      ---------------
**        ^
**      carry
**
**  ( CCR flags = 0x00) ----> Overflow, Zero, Carry are set.
*/
void test_raw_ADC_carry_given_value_0x00_plus_with_0x01_expected_no_Carry(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x02,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//             TEST FOR HALF-CARRY    (check if there is a carry from nibble)
/* ----------------------------------------------------
** (i)         1  <- half carry
**          0000 0001 <---Carry value
**          0000 1000
**      +   0000 1000
**      ---------------
**          0001 0001
**      ---------------
**  ( CCR flags = 0x10) ----> Half-Carry is set.
*/
void test_raw_ADC_half_carry_given_value_0x08_plus_with_0x08_expected_Half_Carry_is_set(void){
  cpuRegisters->A = 0x08;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x08);
  TEST_ASSERT_EQUAL_HEX16(0x11,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x10,c|z|l|i0|h|i1|v);
}

/*
** (ii)        0  <- half carry
**          0000 0001 <---Carry value
**          0000 0000
**      +   0000 1000
**      ---------------
**          0000 1001
**      ---------------
**  ( CCR flags = 0x10) ----> None of the CCR is set.
*/
void test_raw_ADC_half_carry_given_value_0x00_plus_with_0x08_expected_no_Half_carry(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x08);
  TEST_ASSERT_EQUAL_HEX16(0x09,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}


//            TEST FOR ZERO
/* ----------------------------------------------------
/* (i)        0000 0001 <---Carry value
**            1111 1110
**        +   0000 0000
**       ------------------
**            1111 1111   (Non-zero)
**       ------------------
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_ADC_zero_given_value_0xfe_plus_with_0x00_expected_no_zero(void){
  cpuRegisters->A = 0xfe;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/* (ii)       0000 0000 <---Carry Value
**            0000 0000
**        +   0000 0000
**       ------------------
**            0000 0000   (zero)
**       ------------------
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_ADC_zero_given_value_0x00_plus_with_0x00_expected_zero(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 0x00;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
}

//          TEST FOR NEGATIVE
/* ----------------------------------------------------
** (i)        0000 0001 <---Carry value
**            1000 0000
**        +   0000 0000
**       ------------------
**            1000 0001
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_ADC_negative_given_value_0x80_plus_with_0x00_expected_negative(void){
  cpuRegisters->A = 0x80;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x81,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


/*
** (ii)       0000 0001 <---Carry value
**            0000 0001
**        +   0000 0001
**       ------------------
**            0000 0011
**       ------------------
**            ^
**        Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_ADC_negative_given_value_0x01_plus_with_0x01_expected_no_negative(void){
  cpuRegisters->A = 0x01;
  cpuRegisters->CCR.C = 0x01;
  raw_adc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x03,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
}
