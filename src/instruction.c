#include "instruction.h"
#include "Simulator.h"

#include "add.h"
#include "adc.h"
#include "sub.h"
#include "sbc.h"
#include "INC.h"
#include <stdint.h>
#include <stdio.h>

typedef struct Opcode Opcode;
struct Opcode{
  int (*execute)(uint8_t *code);
  int length;
  int cycle;
};


Opcode opcodeTable[256] = {
  //ADD
  [0xAB] = {add_byte,2,1},
  [0xBB] = {add_shortmem,2,1},
  [0xCB] = {add_longmem,3,1},
  [0xFB] = {add_x,1,1},
  [0xEB] = {add_x_shortset,2,1},
  [0xDB] = {add_x_longset,3,1},
  [0x1B] = {add_shortoff_SP,2,1},

};


int isOpcodePrefix(uint8_t *code){
  uint8_t opcode = *code;
  if(opcode == 0x90 || opcode == 0x91 || opcode== 0x92 ||     \
     opcode == 0x72)
     return 1;
  return 0;
}

uint8_t instruction(uint8_t **codePtr){
  int (*execute)(uint8_t *code);
  uint8_t *code = *codePtr;
  if(!isOpcodePrefix(code)){
    opcodeTable[*code].execute(code);
    *codePtr += opcodeTable[*code].length;
  }
  return opcodeTable[*code].length;
}
