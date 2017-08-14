#include "unity.h"
#include "DEC.h"
#include "mem_Location.h"
#include "Raw_Operation.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

/*
**    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
**    X     Syntax :  DEC dst                 X
**    X     Operation : dst <= dst - 1        X
**    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxX
*/

void test_DEC_A_given_A_0x01_expect_0x00(void){
    cpuRegisters->A = 0x01;
    uint8_t instrc[]={0x4A};
    dec_A(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x00,cpuRegisters->A);
}

void test_DEC_shortmem_given_value_0x02_expect_0x01(void){
    memory[0x02]  = 0x02;
    uint8_t instrc[]={0x3A,0x02};
    dec_shortmem(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x01,memory[0x02]);
}

void test_DEC_longmem_given_value_0xaa_expect_0xa9(void){
    memory[0x1000]  = 0xaa;
    uint8_t instrc[]={0x72,0x5A,0x10,0x00};
    dec_longmem(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xa9,memory[0x1000]);
}

void test_DEC_X_given_value_0xaa_expect_0xa9(void){
    set_X(0x11,0x10);
    memory[0x1110]  = 0xaa;
    uint8_t instrc[]={0x7A,0x02};
    dec_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xa9,memory[0x1110]);
}

void test_DEC_shortoff_X_given_value_0xa0_expect_0x9f(void){
    set_X(0x12,0x12);
    uint8_t instrc[]={0x6C,0x01};
    memory[0x1213]  = 0xa0;
    dec_shortoff_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x9f,memory[0x1213]);
}

void test_DEC_longoff_X_given_value_0x09_expect_0x08(void){
    set_X(0x34,0x34);
    uint8_t instrc[]={0x72,0x4C,0x10,0x10};
    memory[0x4444]  = 0x09;
    dec_longoff_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x08,memory[0x4444]);
}

void test_DEC_Y_given_value_0x05_expect_0x04(void){
    set_Y(0x12,0x10);
    memory[0x1210]  = 0x05;
    uint8_t instrc[]={0x90,0x7c};
    dec_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x04,memory[0x1210]);
}

void test_DEC_shortoff_Y_given_value_0x7D_expect_0x7C(void){
    set_Y(0x23,0x23);
    uint8_t instrc[]={0x90,0x6C,0x22};
    memory[0x2345]  = 0x7D;
      dec_shortoff_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x7C,memory[0x2345]);
}

void test_DEC_longoff_Y_given_value_0x99_expect_0x98(void){
    set_Y(0x34,0x34);
    uint8_t instrc[]={0x90,0x4C,0x29,0x29};
    memory[0x5d5d]  = 0x99;
    dec_longoff_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x98,memory[0x5d5d]);
}

void test_DEC_shortoff_SP_given_value_0xaa_expect_0xa9(void){
    set_SP(0x88,0x88);
    uint8_t instrc[]={0x0C,0x22};
    memory[0x88AA]  = 0xaa;
    dec_shortoff_SP(instrc);
    TEST_ASSERT_EQUAL_HEX8(0xa9,memory[0x88aa]);
}

void test_DEC_shortptr_w_given_value_0x11_expect_0x10(void){
    uint8_t instrc[]={0x92,0x3C,0x40};
    memory[0x40]  = 0x42;
    memory[0x41]  = 0xe5;
    memory[0x42e5]  = 0x11;
    dec_shortptr_w(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x10,memory[0x42e5]);
}

void test_DEC_longptr_w_given_value_0x11_expect_0x10(void){
    uint8_t instrc[]={0x72,0x3C,0x10,0x40};
    memory[0x1040]  = 0x42;
    memory[0x1041]  = 0xe5;
    memory[0x42e5]  = 0x11;
    dec_longptr_w(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x10,memory[0x42e5]);
}

void test_DEC_shortptr_w_X_given_value_0x40_expect_0x3f(void){
    set_X(0x00,0x03);
    uint8_t instrc[]={0x92,0x6C,0x89};
    memory[0x89]  = 0x08;
    memory[0x8a]  = 0x01;
    memory[0x0804]  = 0x40;
    dec_shortptr_w_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x3f,memory[0x0804]);
}

void test_DEC_longptr_w_X_given_value_0x40_expect_0x3f(void){
    set_X(0x01,0x03);
    uint8_t instrc[]={0x72,0x6C,0x10,0x89};
    memory[0x1089]  = 0x18;
    memory[0x108a]  = 0x01;
    memory[0x1904]  = 0x40;
    dec_longptr_w_X(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x3f,memory[0x1904]);
}

void test_DEC_shortptr_w_Y_given_value_0x80_expect_0x7f(void){
    set_Y(0x11,0x11);
    uint8_t instrc[]={0x91,0x6C,0x89};
    memory[0x89]  = 0x18;
    memory[0x8a]  = 0x11;
    memory[0x2922]  = 0x80;
    dec_shortptr_w_Y(instrc);
    TEST_ASSERT_EQUAL_HEX8(0x7f,memory[0x2922]);
}
