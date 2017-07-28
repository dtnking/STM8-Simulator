#include "unity.h"
#include "instruction.h"
#include "Simulator.h"
#include "Memory.h"
#include "add.h"

void setUp(void){}

void tearDown(void){}

void test_instruction(void){
  uint8_t *code = memory;
  memory[0] = 0xAB;
  memory[1] = 0x23;
  memory[2] = 0xBB;
  memory[3] = 0x90;
  memory[4] = 0xcb;
  memory[5] = 0x10;
  memory[6] = 0x65;
  instruction(&code);
  instruction(&code);
  instruction(&code);
}
