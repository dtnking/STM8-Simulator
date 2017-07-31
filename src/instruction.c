#include "instruction.h"
#include "Simulator.h"

#include "add.h"
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

  //ADC
  [0xA9] = {adc_byte,2,1},
  [0xB9] = {adc_shortmem,2,1},
  [0xC9] = {adc_longmem,3,1},
  [0xF9] = {adc_x,1,1},
  [0xE9] = {adc_x_shortset,2,1},
  [0xD9] = {adc_x_longset,3,1},
  [0x19] = {adc_shortoff_SP,2,1},

  //INC
  [0x4C] = {inc_A,1,1},
  [0x3C] = {inc_shortmem,2,1},
  [0x7C] = {inc_X,1,1},
  [0x6C] = {inc_shortoff_X,2,1},
  [0x0C]

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
