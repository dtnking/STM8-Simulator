#include "unity.h"
#include "Simulator.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include "add.h"
#include "adc.h"
#include "sub.h"
#include "sbc.h"
#include "INC.h"
#include "XOR.h"
#include "OR.h"
#include "mov.h"
#include "AND.h"
#include "LD.h"
#include "DEC.h"
#include "JP.h"
#include "MUL.h"
#include "pop.h"
#include "PUSH.h"
#include "CCF.h"
#include "SCF.h"
#include "CLR.h"
#include <stdio.h>
#include <stdint.h>


void setUp(void){
  clearCCRflag();
}

void tearDown(void){}

void test_opcodePrefix_given_opcode_0x90_expected_return_1(void){
  uint8_t instrc[]={0x90};
  uint8_t *code = instrc;
  int retVal = isOpcodePrefix(code);
  TEST_ASSERT_EQUAL_INT(1,retVal);
}

void test_opcodePrefix_given_opcode_0x91_expected_return_1(void){
  uint8_t instrc[]={0x91};
  uint8_t *code = instrc;
  int retVal = isOpcodePrefix(code);
  TEST_ASSERT_EQUAL_INT(1,retVal);
}

void test_opcodePrefix_given_opcode_0x92_expected_return_1(void){
  uint8_t instrc[]={0x92};
  uint8_t *code = instrc;
  int retVal = isOpcodePrefix(code);
  TEST_ASSERT_EQUAL_INT(1,retVal);
}

void test_opcodePrefix_given_opcode_0x72_expected_return_1(void){
  uint8_t instrc[]={0x72};
  uint8_t *code = instrc;
  int retVal = isOpcodePrefix(code);
  TEST_ASSERT_EQUAL_INT(1,retVal);
}

void test_opcodePrefix_given_opcode_0xAB_expected_return_0(void){
  uint8_t instrc[]={0xAB};
  uint8_t *code = instrc;
  int retVal = isOpcodePrefix(code);
  TEST_ASSERT_EQUAL_INT(0,retVal);
}

void test_opcodePrefix_given_opcode_0x94_expected_return_0(void){
  uint8_t instrc[]={0x94};
  uint8_t *code = instrc;
  int retVal = isOpcodePrefix(code);
  TEST_ASSERT_EQUAL_INT(0,retVal);
}
