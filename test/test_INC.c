#include "unity.h"
#include "Memory.h"
#include "Simulator.h"
#include "INC.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_INC_A_given_A_0x01_expect_0x02(void){
    cpuRegisters->A = 0x01;
    uint8_t instrc[]={0x4C};
    inc_A(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x02,cpuRegisters->A);
}

void test_INC_shortmem_given_value_0x02_expect_0x03(void){
    memory[0x02]  = 0x02;
    uint8_t instrc[]={0x3C,0x02};
    inc_shortmem(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x03,memory[0x02]);
}

void test_INC_longmem_given_value_0xaa_expect_0xab(void){
    memory[0x1000]  = 0xaa;
    uint8_t instrc[]={0x72,0x5C,0x10,0x00};
    inc_longmem(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xab,memory[0x1000]);
}

void test_INC_X_given_value_0xaa_expect_0xab(void){
    set_X(0x11,0x10);
    memory[0x1110]  = 0xaa;
    uint8_t instrc[]={0x7C,0x02};
    inc_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xab,memory[0x1110]);
}

void test_INC_shortoff_X_given_value_0xa0_expect_0xa1(void){
    set_X(0x12,0x12);
    uint8_t instrc[]={0x6C,0x01};
    memory[0x1213]  = 0xa0;
    inc_shortoff_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xa1,memory[0x1213]);
}

void test_INC_longoff_X_given_value_0x09_expect_0x0a(void){
    set_X(0x34,0x34);
    uint8_t instrc[]={0x72,0x4C,0x10,0x10};
    memory[0x4444]  = 0x09;
    inc_longoff_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x0a,memory[0x4444]);
}

void test_INC_Y_given_value_0x05_expect_0x06(void){
    set_Y(0x12,0x10);
    memory[0x1210]  = 0x05;
    uint8_t instrc[]={0x90,0x7c};
    inc_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x06,memory[0x1210]);
}

void test_INC_shortoff_Y_given_value_0x7D_expect_0x7E(void){
    set_Y(0x23,0x23);
    uint8_t instrc[]={0x90,0x6C,0x22};
    memory[0x2345]  = 0x7D;
      inc_shortoff_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x7E,memory[0x2345]);
}

void test_INC_longoff_Y_given_value_0x99_expect_0x9a(void){
    set_Y(0x34,0x34);
    uint8_t instrc[]={0x90,0x4C,0x29,0x29};
    memory[0x5d5d]  = 0x99;
    inc_longoff_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x9a,memory[0x5d5d]);
}

void test_INC_shortoff_SP_given_value_0xaa_expect_0xab(void){
    set_SP(0x88,0x88);
    uint8_t instrc[]={0x0C,0x22};
    memory[0x88AA]  = 0xaa;
    inc_shortoff_SP(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xab,memory[0x88aa]);
}

void test_INC_shortptr_w_given_value_0x11_expect_0x12(void){
    uint8_t instrc[]={0x92,0x3C,0x40};
    memory[0x40]  = 0x42;
    memory[0x41]  = 0xe5;
    memory[0x42e5]  = 0x11;
    inc_shortptr_w(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x12,memory[0x42e5]);
}

void test_INC_longptr_w_given_value_0xaa_expect_0xab(void){
    uint8_t instrc[]={0x72,0x3C,0x10,0x40};
    memory[0x1040]  = 0x42;
    memory[0x1041]  = 0xe5;
    memory[0x42e5]  = 0x11;
    inc_longptr_w(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x12,memory[0x42e5]);
}

void test_INC_shortptr_w_X_given_value_0x40_expect_0x41(void){
    set_X(0x00,0x03);
    uint8_t instrc[]={0x92,0x6C,0x89};
    memory[0x89]  = 0x08;
    memory[0x8a]  = 0x01;
    memory[0x0804]  = 0x40;
    inc_shortptr_w_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x41,memory[0x0804]);
}

void test_INC_longptr_w_X_given_value_0x40_expect_0x41(void){
    set_X(0x01,0x03);
    uint8_t instrc[]={0x72,0x6C,0x10,0x89};
    memory[0x1089]  = 0x18;
    memory[0x108a]  = 0x01;
    memory[0x1904]  = 0x40;
    inc_longptr_w_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x41,memory[0x1904]);
}

void test_INC_shortptr_w_Y_given_value_0x40_expect_0x41(void){
    set_Y(0x11,0x11);
    uint8_t instrc[]={0x91,0x6C,0x89};
    memory[0x89]  = 0x18;
    memory[0x8a]  = 0x11;
    memory[0x2922]  = 0x80;
    inc_shortptr_w_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x81,memory[0x2922]);
}
