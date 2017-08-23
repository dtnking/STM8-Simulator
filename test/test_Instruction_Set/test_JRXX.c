#include "unity.h"
#include "JRXX.h"
#include "SCF.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_jrc_given_correct_condition_expected_PC_eq_0x11(void){
  cpuRegisters->CCR.bit.C = 1;
  uint8_t instrc[] = {0x25,0x11};
  jrc(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x11, GET_PC);
}

void test_jrc_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x25,0x11};
  jrc(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jreq_given_correct_condition_expected_PC_eq_0x12(void){
  cpuRegisters->CCR.bit.Z = 1;
  uint8_t instrc[] = {0x27,0x12};
  jreq(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x12, GET_PC);
}

void test_jreq_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x27,0x12};
  jreq(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrf_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x21,0x13};
  jrf(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrh_given_correct_condition_expected_PC_eq_0x14(void){
  cpuRegisters->CCR.bit.H = 1;
  uint8_t instrc[] = {0x90,0x29,0x14};
  jrh(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x14, GET_PC);
}

void test_jrh_given_false_condition_expected_PC_eq_0x3(void){
  uint8_t instrc[] = {0x90,0x29,0x14};
  jrh(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x3, GET_PC);
}

void test_jrm_given_correct_condition_expected_PC_eq_0x15(void){
  cpuRegisters->CCR.bit.I0 = 1;
  cpuRegisters->CCR.bit.I1 = 1;
  uint8_t instrc[] = {0x90,0x2D,0x15};
  jrm(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x15, GET_PC);
}

void test_jrm_given_false_condition_expected_PC_eq_0x3(void){
  uint8_t instrc[] = {0x90,0x2D,0x15};
  jrm(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x3, GET_PC);
}

void test_jrmi_given_correct_condition_expected_PC_eq_0x16(void){
  cpuRegisters->CCR.bit.N = 1;
  uint8_t instrc[] = {0x2B,0x16};
  jrmi(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x16, GET_PC);
}

void test_jrmi_given_false_condition_xpected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x2B,0x16};
  jrmi(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrnc_given_correct_condition_expected_PC_eq_0x17(void){
  uint8_t instrc[] = {0x24,0x17};
  jrnc(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x17, GET_PC);
}

void test_jrnc_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.C = 1;
  uint8_t instrc[] = {0x24,0x17};
  jrnc(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrne_given_correct_condition_expected_PC_eq_0x18(void){
  uint8_t instrc[] = {0x26,0x18};
  jrne(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x18, GET_PC);
}

void test_jrne_given_false_condition_xpected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.Z = 1;
  uint8_t instrc[] = {0x26,0x18};
  jrne(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrnh_given_correct_condition_expected_PC_eq_0x19(void){
  uint8_t instrc[] = {0x90,0x28,0x19};
  jrnh(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x19, GET_PC);
}

void test_jrnh_given_false_condition_expected_PC_eq_0x3(void){
  cpuRegisters->CCR.bit.H = 1;
  uint8_t instrc[] = {0x90,0x28,0x19};
  jrnh(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x3, GET_PC);
}

void test_jrnm_given_correct_condition_expected_PC_eq_0x1a(void){
  uint8_t instrc[] = {0x90,0x28,0x19};
  jrnm(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x19, GET_PC);
}


void test_jrnm_given_false_condition_expected_PC_eq_0x3(void){
  cpuRegisters->CCR.bit.I0 = 1;
  cpuRegisters->CCR.bit.I1 = 1;
  uint8_t instrc[] = {0x90,0x2C,0x1a};
  jrnm(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x3, GET_PC);
}

void test_jrnv_given_correct_condition_expected_PC_eq_0x1b(void){
  uint8_t instrc[] = {0x2C,0x1b};
  jrnv(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x1b, GET_PC);
}

void test_jrnv_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.V = 1;
  uint8_t instrc[] = {0x2C,0x1b};
  jrnv(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrpl_given_correct_condition_expected_PC_eq_0x1c(void){
  uint8_t instrc[] = {0x2A,0x1c};
  jrpl(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x1c, GET_PC);
}

void test_jrpl_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.N = 1;
  uint8_t instrc[] = {0x2A,0x1c};
  jrpl(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrsge_givencorrect_condition_expected_PC_eq_0x1d(void){
  cpuRegisters->CCR.bit.N = 1;
  cpuRegisters->CCR.bit.V = 1;
  uint8_t instrc[] = {0x2E,0x1d};
  jrsge(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x1d, GET_PC);
}

void test_jrsge_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.V = 1;
  uint8_t instrc[] = {0x2E,0x1d};
  jrsge(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrsgt_given_correct_condition_expected_PC_eq_0x1e(void){
  cpuRegisters->CCR.bit.N = 1;
  cpuRegisters->CCR.bit.V = 1;
  uint8_t instrc[] = {0x2C,0x1e};
  jrsgt(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x1e, GET_PC);
}

void test_jrsgt_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.V = 1;
  cpuRegisters->CCR.bit.Z = 1;
  uint8_t instrc[] = {0x2C,0x1e};
  jrsgt(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrsle_given_correct_condition_expected_PC_eq_0x1f(void){
  cpuRegisters->CCR.bit.N = 1;
  cpuRegisters->CCR.bit.Z = 1;
  uint8_t instrc[] = {0x2D,0x1F};
  jrsle(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x1f, GET_PC);
}

void test_jrsle_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x2D,0x1F};
  jrsle(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrslt_given_correct_condition_expected_PC_eq_0x20(void){
  cpuRegisters->CCR.bit.N = 1;
  cpuRegisters->CCR.bit.V = 0;
  uint8_t instrc[] = {0x2F,0x20};
  jrslt(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x20, GET_PC);
}

void test_jrslt_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x2F,0x20};
  jrslt(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jruge_given_correct_condition_expected_PC_eq_0x22(void){
  uint8_t instrc[] = {0x24,0x22};
  jruge(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x22, GET_PC);
}

void test_jruge_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.C = 1;
  uint8_t instrc[] = {0x24,0x22};
  jruge(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrugt_given_correct_condition_expected_PC_eq_0x23(void){
  uint8_t instrc[] = {0x22,0x23};
  jrugt(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x23, GET_PC);
}

void test_jrugt_given_false_condition_expected_PC_eq_0x2(void){
  cpuRegisters->CCR.bit.C = 1;
  cpuRegisters->CCR.bit.Z = 1;
  uint8_t instrc[] = {0x22,0x23};
  jrugt(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrule_given_correct_condition_expected_PC_eq_0x24(void){
  cpuRegisters->CCR.bit.C = 1;
  cpuRegisters->CCR.bit.Z = 1;
  uint8_t instrc[] = {0x23,0x24};
  jrule(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x24, GET_PC);
}

void test_jrule_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x23,0x24};
  jrule(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrult_given_correct_condition_expected_PC_eq_0x25(void){
  cpuRegisters->CCR.bit.C = 1;
  uint8_t instrc[] = {0x25,0x25};
  jrult(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x25, GET_PC);
}

void test_jrult_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x25,0x24};
  jrult(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}

void test_jrv_given_correct_condition_expected_PC_eq_0x25(void){
  cpuRegisters->CCR.bit.V = 1;
  uint8_t instrc[] = {0x29,0x25};
  jrv(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x25, GET_PC);
}

void test_jrv_given_false_condition_expected_PC_eq_0x2(void){
  uint8_t instrc[] = {0x29,0x25};
  jrv(instrc);

  TEST_ASSERT_EQUAL_HEX16(0x2, GET_PC);
}
