#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "addw.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

// 2 byte = 1 word

//                TEST FOR OVERFLOW
/* --------------------------------------------------------------------
**          (expected)         |                 (real)
**   (i)  32767 + 3 = 32770    |         0111 1111 1111 1111   (32767)
**                             |     +   0000 0000 0000 0011       (3)
**                             |    -------------------------
**                             |         1000 0000 0000 0010   (-32766)
**                             |    -------------------------
**  ( CCR flags = 0x54) ----> Overflow, Negative , Half-Carry are set.
*/

void test_raw_ADDW_overflow_given_0x7fff_plus_0x03_get_0x8002_expected_overflow(void){
  set_X(0x7fff);
  raw_addw(0x0003,&cpuRegisters->XH,&cpuRegisters->XL);
  TEST_ASSERT_EQUAL_HEX16(0x8002,X);
  TEST_ASSERT_EQUAL_HEX16(0x54,c|z|l|i0|h|i1|v);
}


/* -----------------------------------------------------------------------
**          (expected)            |                (real)
**  (ii)  -32767 + (-3) = -32770  |         1000 0000 0000 0001   (-32767)
**                                |     +   1111 1111 1111 1101       (-3)
**                                |    -------------------------
**                                |         0111 1111 1111 1110    (32766)
**                                |    -------------------------
**  ( CCR flags = 0x41) ----> Overflow, Carry are set.
*/
void test_raw_ADDW_overflow_given_0x8001_plus_0xfd_get_0x7ffE_expected_overflow(void){
  set_X(0x8001);
  raw_addw(0xfffd,&cpuRegisters->XH,&cpuRegisters->XL);
  TEST_ASSERT_EQUAL_HEX16(0x7ffe,X);
  TEST_ASSERT_EQUAL_HEX16(0x041,c|z|l|i0|h|i1|v);
}

/* ----------------------------------------------------------------------
**            (expected)         |                (real)
**  (iii)   -1 + 32760 = 32759   |         1111 1111 1111 1111       (-1)
**                               |     +   0111 1111 1111 1000    (32760)
**                               |    ---------------------------
**                               |         0111 1111 1111 0111    (32759)
**                               |    ---------------------------
**  ( CCR flags = 0x11) ----> Half-Carry, Carry are set.
*/
void test_raw_ADDW_overflow_given_0xffff_plus_0x7ff8_get_0x7ff7_expected_no_overflow(void){
  set_X(0xffff);
  raw_addw(0x7ff8,&cpuRegisters->XH,&cpuRegisters->XL);
  TEST_ASSERT_EQUAL_HEX16(0x7ff7,X);
  TEST_ASSERT_EQUAL_HEX16(0x011,c|z|l|i0|h|i1|v);
}

/* -----------------------------------------------------------
**            (expected)          |                  (real)
**  (iv)   1 + (-32760) = -32759  |         0000 0000 0000 0001        (1)
**                                |     +   1000 0000 0000 1000   (-32760)
**                                |    --------------------------
**                                |         1000 0000 0000 1001   (-32759)
**                                |    --------------------------
**  ( CCR flags = 0x11) ----> Negative is set.
*/
void test_raw_ADDW_overflow_given_0x01_plus_0x8008_get_0x8009_expected_no_overflow(void){
  set_X(0x0001);
  raw_addw(0x8008,&cpuRegisters->XH,&cpuRegisters->XL);
  TEST_ASSERT_EQUAL_HEX16(0x8009,X);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
}


//                TEST FOR CARRY
/* ----------------------------------------------------
**  (i)     1000 0000 0000 0000
**      +   1000 0000 0000 0000
**      -------------------------
**        1 0000 0000 0000 0000
**      -------------------------
**        ^
**      carry
**
**  ( CCR flags = 0x43) ----> Overflow, Zero, Carry are set.
 */
void test_raw_ADDW_carry_given_value_0x8000_plus_0x8000_get_0x0000_expected_Carry_is_set(void){
 set_X(0x8000);
 raw_addw(0x8000,&cpuRegisters->XH,&cpuRegisters->XL);
 TEST_ASSERT_EQUAL_HEX16(0,X);
 TEST_ASSERT_EQUAL_HEX16(0x43,c|z|l|i0|h|i1|v);
 }

 /*
 ** (ii)     0000 0000 0000 0000
 **      +   0000 0000 0000 0001
 **      ------------------------
 **        0 0000 0000 0000 0001
 **      ------------------------
 **        ^
 **      carry
 **
 **  ( CCR flags = 0x00) ----> Overflow, Zero, Carry are set.
 */
 void test_raw_ADDW_carry_given_value_0x00_plus_0x01_get_0x01_expected_no_Carry(void){
   set_X(0x0000);
   raw_addw(0x0001,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0x01,X);
   TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
 }


 //             TEST FOR HALF-CARRY
 /* ----------------------------------------------------
 ** (i)              1  <- half carry
 **          0000 0000 1000 0000
 **      +   0000 0000 1000 0000
 **      ------------------------
 **          0000 0001 0000 0000
 **      ------------------------
 **  ( CCR flags = 0x10) ----> Half-Carry is set.
 */
 void test_raw_ADDW_half_carry_given_value_0x08_plus_0x08_get_0x10_expected_Half_Carry_is_set(void){
   set_X(0x80);
   raw_addw(0x0080,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0x100,X);
   TEST_ASSERT_EQUAL_HEX16(0x10,c|z|l|i0|h|i1|v);
 }


 /*
 ** (ii)              0  <- half carry
 **          0000 0000 0000 0000
 **      +   0000 0000 0000 1000
 **      ------------------------
 **          0000 0000 0000 1000
 **      ------------------------
 **  ( CCR flags = 0x10) ----> None of the CCR is set.
 */
 void test_raw_ADDW_half_carry_given_value_0x00_plus_0x08_get_0x08_expected_no_Half_carry(void){
   set_X(0x00);
   raw_addw(0x0008,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0x08,X);
   TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
 }

 //            TEST FOR ZERO
 /* ----------------------------------------------------
 /* (i)        1111 1111 1111 1111
 **        +   0000 0000 0000 0000
 **       -------------------------
 **            1111 1111 1111 11111  (Non-zero)
 **       -------------------------
 **  ( CCR flags = 0x04) ----> Negative is set.
 */
 void test_raw_ADDW_zero_given_value_0xffff_plus_0x00_get_0xffff_expected_non_zero(void){
   set_X(0xffff);
   raw_addw(0x0000,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0xffff,X);
   TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
 }


 /* (ii)       0000 0000 0000 0000
 **        +   0000 0000 0000 0000
 **       -------------------------
 **            0000 0000 0000 0000  (zero)
 **       -------------------------
 **  ( CCR flags = 0x02) ----> Zero is set.
 */
 void test_raw_ADDW_zero_given_value_0x00_plus_0x00_get_0x00_expected_zero(void){
   set_X(0x00);
   raw_addw(0x0000,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0x00,X);
   TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);
 }


 //          TEST FOR NEGATIVE
 /* ----------------------------------------------------
 ** (i)        1000 0000 0000 0000
 **        +   0000 0000 0000 0000
 **       -------------------------
 **            1000 0000 0000 0000
 **       -------------------------
 **            ^
 **        Negative (1 = Negative, 0 = Non-negative)
 **
 **  ( CCR flags = 0x04) ----> Negative is set.
 */
 void test_raw_ADDW_negative_given_value_0x8000_plus_0x00_get_0x8000_expected_negative(void){
   set_X(0x8000);
   raw_addw(0x0000,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0x8000,X);
   TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v);
 }


 /*
 ** (ii)       0000 0000 0000 0001
 **        +   0000 0000 0000 0001
 **       ---------------------------
 **            0000 0000 0000 0010
 **       ---------------------------
 **            ^
 **        Negative (1 = Negative, 0 = Non-negative)
 **
 **  ( CCR flags = 0x00) ----> None of the CCR is set.
 */
 void test_raw_ADDW_negative_given_value_0x01_plus_0x01_get_0x02_expected_no_negative(void){
   set_X(0x01);
   raw_addw(0x0001,&cpuRegisters->XH,&cpuRegisters->XL);
   TEST_ASSERT_EQUAL_HEX16(0x02,X);
   TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v);
 }
