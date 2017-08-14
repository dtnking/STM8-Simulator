#include "unity.h"
#include "JP.h"
#include "Raw_Operation.h"
#include "mem_Location.h"
#include <stdio.h>
#include <stdint.h>


void setUp(void){}

void tearDown(void){}

/*  Syntax : JP dst             e.g. JP test
**  Operation : PC <= dst
*/

// Asm : JP $1000         |  dst : longmem
void test_JP_longmem_given_longmem_is_0x1000_expected_PC_contain_0x1000(void){
  uint8_t instrc[] = {0xCC,0x10,0x00};
  jp_longmem(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x1000,pc);
}

// Asm : JP(X)           |  dst : (X)
void test_JP_X_given_X_is_0xabab_expected_PC_contain_0xabab(void){
  uint8_t instrc[] = {0xFC};
  set_X(0xab,0xab);
  jp_X(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xabab,pc);
}

// Asm : JP($10,X)        |  dst : (shortoff,X)
void test_JP_X_shortset_given_X_is_0xabab_with_offset_0x01_expected_PC_contain_0xabac(void){
  uint8_t instrc[] = {0xEC,0x01};
  set_X(0xab,0xab);
  jp_X_shortset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xabac,pc);
}

// Asm : JP($1000,X)      |  dst : (longoff,X)
void test_JP_X_longset_given_X_is_0xbaba_with_offset_0x0101_expected_PC_contain_0xbbbb(void){
  uint8_t instrc[] = {0xEC,0x01,0x01};
  set_X(0xba,0xba);
  jp_X_longset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xbbbb,pc);
}

// Asm : JP(Y)          |  dst : (Y)
void test_JP_Y_given_Y_is_0x1111_expected_PC_contain_0x1111(void){
  uint8_t instrc[] = {0x90,0xFC};
  set_Y(0x11,0x11);
  jp_Y(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x1111,pc);
}

// Asm : JP($10,Y)        |  dst : (shortoff,Y)
void test_JP_Y_shortset_given_Y_is_0xaabb_with_offset_0x02_expected_PC_contain_0xaabd(void){
  uint8_t instrc[] = {0x90,0xEC,0x02};
  set_Y(0xaa,0xbb);
  jp_Y_shortset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xaabd,pc);
}

// Asm : JP($1000,Y)       |  dst : (longoff,Y)
void test_JP_Y_longset_given_Y_is_0xbbaa_with_offset_0x1010_expected_PC_contain_0xcbba(void){
  uint8_t instrc[] = {0x90,0xDC,0x10,0x10};
  set_Y(0xbb,0xaa);
  jp_Y_longset(instrc);
  TEST_ASSERT_EQUAL_HEX16(0xcbba,pc);
}

// Asm : JP[$10.w]         |  dst : [shortptr.w]
void test_JP_shortptr_W_given_shortptr_point_to_0x42e5_expected_PC_contain_0x42e5(void){
  uint8_t instrc[]	= {0x92,0xCC,0x40};
	memory[0x40]			= 0x42;
	memory[0x41]			= 0xe5;
  jp_shortptr_W(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x42e5,pc);
}

// Asm : JP[$1000.w]         |  dst : [longptr.w]
void test_JP_longptr_W_given_longptr_point_to_0x42e5_expected_PC_contain_0x42e5(void){
  uint8_t instrc[]	= {0x72,0xCC,0x10,0x40};
	memory[0x1040]			= 0x42;
	memory[0x1041]			= 0xe5;
  jp_longptr_W(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x42e5,pc);
}

// Asm : JP([$10.w],X)         |  dst : ([shortptr.w],X)
void test_JP_shortptr_w_X_given_shortptr_point_to_0x0801_with_X_0x0010_expected_PC_contain_0x0811(void){
  set_X(0x00,0x10);
  uint8_t instrc[]	= {0x92,0xDC,0x89};
  memory[0x89]			= 0x08;
  memory[0x8a]			= 0x01;
  jp_shortptr_W_X(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x0811,pc);
}

// Asm : JP([$1000.w],X)         |  dst : ([longptr.w],X)
void test_JP_longptr_w_X_given_longptr_point_to_0x0801_with_X_0x1110_expected_PC_contain_0x1910(void){
  set_X(0x11,0x10);
  uint8_t instrc[]	= {0x72,0xDC,0x10,0x89};
  memory[0x1089]			= 0x08;
  memory[0x108a]			= 0x01;
  jp_longptr_W_X(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x1911,pc);
}

// Asm : JP([$10.w],Y)         |  dst : ([shortptr.w],Y)
void test_JP_shortptr_w_Y_given_shortptr_point_to_0x1111_with_Y_0x1111_expected_PC_contain_0x2222(void){
  set_Y(0x11,0x11);
  uint8_t instrc[]	= {0x91,0xDC,0x21};
  memory[0x21]			= 0x11;
  memory[0x22]			= 0x11;
  jp_shortptr_W_Y(instrc);
  TEST_ASSERT_EQUAL_HEX16(0x2222,pc);
}
