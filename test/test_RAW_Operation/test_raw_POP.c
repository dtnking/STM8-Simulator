#include "unity.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include "pop.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

/*    Test if the Stack pointer Incremented
** ---------------------------------------------
**    condtion 1 : 0x0110 --(INC)--> 0x0111
*/
void test_raw_POP_given_addrs_of_SP_0x0110_expected_incremented_by_1_equal_0x0111(void){
  set_SP(0x0110);                             // let SPH = 0x01, SPL = 0x10 => SP 0x0110.
  uint16_t addrsSP = raw_pop(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x0111,addrsSP);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->SPH);
  TEST_ASSERT_EQUAL_HEX16(0x11,cpuRegisters->SPL);
}

//   conditon 2 : 0xaaff --(INC)--> 0xab00
void test_raw_POP_given_addrs_of_SP_0xaaff_expected_incremented_by_1_equal_0xab00(void){
  set_SP(0xaaff);                             // let SPH = 0xaa, SPL = 0xff => SP 0xaaff.
  uint16_t addrsSP = raw_pop(&cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0xab00,addrsSP);
  TEST_ASSERT_EQUAL_HEX16(0xab,cpuRegisters->SPH);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->SPL);
}
