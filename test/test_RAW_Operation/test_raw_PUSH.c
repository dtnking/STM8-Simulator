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

/*    Test if the Stack pointer Decremented
** ---------------------------------------------
**    condtion 1 : 0x0111 --(DEC)--> 0x0110
*/
void test_raw_PUSH_given_addrs_of_SP_0x0111_expected_decremented_by_1_equal_0x0110(void){
  set_SP(0x0111);                             // let SPH = 0x01, SPL = 0x10 => SP 0x0101.
  uint16_t addrsSP = raw_push(cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x0110,addrsSP);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->SPH);
  TEST_ASSERT_EQUAL_HEX16(0x10,cpuRegisters->SPL);
}

//   conditon 2 : 0x1000 --(DEC)--> 0x0111
void test_raw_POP_given_addrs_of_SP_0x1000_expected_decremented_by_1_equal_0x0fff(void){
  set_SP(0x1000);                             // let SPH = 0xaa, SPL = 0xff => SP 0xaaff.
  uint16_t addrsSP = raw_push(cpuRegisters->A);
  TEST_ASSERT_EQUAL_HEX16(0x0fff,addrsSP);
  TEST_ASSERT_EQUAL_HEX16(0x0f,cpuRegisters->SPH);
  TEST_ASSERT_EQUAL_HEX16(0xff,cpuRegisters->SPL);
}
