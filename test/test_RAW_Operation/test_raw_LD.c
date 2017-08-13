#include "unity.h"
#include "Memory.h"
#include "Raw_Operation.h"
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
  memory[0x03] = 0xaa;
  raw_ld(&memory[0x03],&cpuRegisters->A);      // memory to register
  TEST_ASSERT_EQUAL_HEX16(0xaa,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v); // c=carry, z=zero, l=negative, i0=interrupt0, i1=interrupt1, h=half-carry, v=overflow
}


/* (ii)      0010 1010 (0x2a)
**           ^
**       Negative (1 = Negative, 0 = Non-negative)
**
**  ( CCR flags = 0x00) ----> None of the CCR is set.
*/
void test_raw_LD_negative_given_0x2a_expected_no_negative(void){
  cpuRegisters->A = 0x2a;
  raw_ld(&cpuRegisters->A,&memory[0x02]);         // register to memory
  TEST_ASSERT_EQUAL_HEX16(0x2a,memory[0x02]);
  TEST_ASSERT_EQUAL_HEX16(0x00,c|z|l|i0|h|i1|v); // c=carry, z=zero, l=negative, i0=interrupt0, i1=interrupt1, h=half-carry, v=overflow
}


//            TEST FOR ZERO
/* ----------------------------------------------------
** (i)        1111 1111 (Non-zero)
**             (0xff)-----^
**
**  ( CCR flags = 0x04) ----> Negative is set.
*/
void test_raw_LD_zero_given_0xff_expected_no_zero(void){
  cpuRegisters->XH = 0xff;
  raw_ld(&cpuRegisters->XH,&cpuRegisters->A);     // register to register
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x04,c|z|l|i0|h|i1|v); // c=carry, z=zero, l=negative, i0=interrupt0, i1=interrupt1, h=half-carry, v=overflow
}


/* (ii)       0000 0000 (zero)
**             (0x00)-----^
**
**  ( CCR flags = 0x02) ----> Zero is set.
*/
void test_raw_LD_zero_given_0x00_expected_zero(void){
  cpuRegisters->A = 0x00;
  raw_ld(&cpuRegisters->A,&cpuRegisters->YH);       // register to register
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->YH);
  TEST_ASSERT_EQUAL_HEX16(0x02,c|z|l|i0|h|i1|v);    // c=carry, z=zero, l=negative, i0=interrupt0, i1=interrupt1, h=half-carry, v=overflow
}
