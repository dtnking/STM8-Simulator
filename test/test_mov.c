#include "unity.h"
#include "mov.h"
#include "Raw_Operation.h"
#include "Memory.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

/*  An immediate byte to a direct memory location
** ------------------------------------------------
**  |              |              | Location : 0x1000 |
**  | Value : 0x55 |----(mov)---> | Value    : xx     |
*/
void test_MOV_byte_to_longmem_given_byte_is_0x55_expected_longmem_contain_0x55(void){
	uint8_t instrc[] = {0xB6,0x55,0x10,0x00};			 // Opcode : 0x35551000
	mov_byte_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x55, memory[0x1000]);
}

/*  A direct memory location to another direct memory location
**  (from $00 to $FF)
** -------------------------------------------------------------
**  | Location : 0x55 |              | Location : 0x10 |
**  | Value    : 0xaa |----(mov)---> | Value    : xx   |
*/
void test_MOV_shortmem1_to_shortmem2_given_shortmem1_contain_0xaa_expected_shortmem2_contain_0xaa(void){
	uint8_t instrc[] = {0xB6,0x55,0x10};			 // Opcode : 0x455510
  memory[0x55] = 0xaa;
	mov_shortmem_shortmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0xAA, memory[0x10]);
}


/*  A direct memory location to another direct memory location
**  (from $0000 to $FFFF)
** -------------------------------------------------------------
**  | Location : 0x1000 |              | Location : 0x1234 |
**  | Value    : 0x3a   |----(mov)---> | Value    : xx     |
*/
void test_MOV_longmem1_to_longmem2_given_longmem1_contain_0x3a_expected_longmem2_contain_0x3a(void){
	uint8_t instrc[] = {0xB6,0x10,0x10,0x12,0x34};			 // Opcode : 0x5510101234
  memory[0x1010] = 0x3a;
	mov_longmem_longmem(instrc);

	TEST_ASSERT_EQUAL_HEX8 (0x3A, memory[0x1234]);
}
