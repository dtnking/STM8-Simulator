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


void test_raw_adc_given_value_0x00_add_with_0x00_and_carry_bit_is_1_expected_0x01_with_all_CCR_flag_equal_0(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 1;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x01,cpuRegisters->A);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.H);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.C);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.N);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.V);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.Z);
  printf("%08x",cpuRegisters->CCR);
}

void test_raw_adc_given_value_0x00_add_with_0x00_and_carry_bit_is_0_expected_0x00_with_zero_flag_equal_1(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 0;
  raw_adc(0x00);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.H);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.C);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.N);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.V);
  TEST_ASSERT_EQUAL(1,cpuRegisters->CCR.Z);
  printf("%08x",cpuRegisters->CCR);
}

void test_raw_adc_given_value_0x81_add_with_0x01_and_carry_bit_is_1_expected_0x83_negative_overflow_flag_equal_1(void){
  cpuRegisters->A = 0x81;
  cpuRegisters->CCR.C = 1;
  raw_adc(0x01);
  TEST_ASSERT_EQUAL_HEX16(0x83,cpuRegisters->A);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.H);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.C);
  TEST_ASSERT_EQUAL(1,cpuRegisters->CCR.N);
  TEST_ASSERT_EQUAL(1,cpuRegisters->CCR.V);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.Z);
}

void test_raw_adc_given_value_0xff_add_with_0x00_and_carry_bit_is_1_expected_0x0_carry_zero_and_halfCarry_flag_equal_1(void){
  cpuRegisters->A = 0x00;
  cpuRegisters->CCR.C = 1;
  raw_adc(0xff);
  TEST_ASSERT_EQUAL_HEX16(0x00,cpuRegisters->A);
  TEST_ASSERT_EQUAL(1,cpuRegisters->CCR.H);
  TEST_ASSERT_EQUAL(1,cpuRegisters->CCR.C);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.N);
  TEST_ASSERT_EQUAL(0,cpuRegisters->CCR.V);
  TEST_ASSERT_EQUAL(1,cpuRegisters->CCR.Z);
}
