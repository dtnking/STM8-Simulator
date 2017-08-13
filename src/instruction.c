#include "instruction.h"
#include "Raw_Operation.h"
#include "add.h"
#include "adc.h"
#include "sub.h"
#include "sbc.h"
#include "OR.h"
#include "XOR.h"
#include "AND.h"
#include "LD.h"
#include "INC.h"
#include "mov.h"
#include "Memory.h"
#include <stdint.h>
#include <stdio.h>

typedef struct Opcode Opcode;
struct Opcode{
  void (*execute)(uint8_t *code);
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
  [0x0C] = {inc_shortoff_SP,2,1},

  //SUB
  [0xA0] = {sub_byte,2,1},
  [0xB0] = {sub_shortmem,2,1},
  [0xC0] = {sub_longmem,3,1},
  [0xF0] = {sub_x,1,1},
  [0xE0] = {sub_x_shortset,2,1},
  [0xD0] = {sub_x_longset,3,1},
  [0x10] = {sub_shortoff_SP,2,1},

  //SBC
  [0xA2] = {sbc_byte,2,1},
  [0xB2] = {sbc_shortmem,2,1},
  [0xC2] = {sbc_longmem,3,1},
  [0xF2] = {sbc_x,1,1},
  [0xE2] = {sbc_x_shortset,2,1},
  [0xD2] = {sbc_x_longset,3,1},
  [0x12] = {sbc_shortoff_SP,2,1},

  //OR
  [0xAA] = {or_byte,2,1},
  [0xBA] = {or_shortmem,2,1},
  [0xCA] = {or_longmem,3,1},
  [0xFA] = {or_x,1,1},
  [0xEA] = {or_x_shortset,2,1},
  [0xDA] = {or_x_longset,3,1},
  [0x1A] = {or_shortoff_SP,2,1},

  //XOR
  [0xA8] = {xor_byte,2,1},
  [0xB8] = {xor_shortmem,2,1},
  [0xC8] = {xor_longmem,3,1},
  [0xF8] = {xor_x,1,1},
  [0xE8] = {xor_x_shortset,2,1},
  [0xD8] = {xor_x_longset,3,1},
  [0x18] = {xor_shortoff_SP,2,1},

  //AND
  [0xA4] = {and_byte,2,1},
  [0xB4] = {and_shortmem,2,1},
  [0xC4] = {and_longmem,3,1},
  [0xF4] = {and_x,1,1},
  [0xE4] = {and_x_shortset,2,1},
  [0xD4] = {and_x_longset,3,1},
  [0x14] = {and_shortoff_SP,2,1},

  //LD Memory to Reg
  [0xA6] = {ldMemToReg_byte,2,1},
  [0xB6] = {ldMemToReg_shortmem,2,1},
  [0xC6] = {ldMemToReg_longmem,3,1},
  [0xF6] = {ldMemToReg_x,1,1},
  [0xE6] = {ldMemToReg_x_shortset,2,1},
  [0xD6] = {ldMemToReg_x_longset,3,1},
  [0x7B] = {ldMemToReg_shortoff_SP,2,1},

  //LD Reg to Memory
  [0xB7] = {ldRegToMem_shortmem,2,1},
  [0xC7] = {ldRegToMem_longmem,3,1},
  [0xF7] = {ldRegToMem_x,1,1},
  [0xE7] = {ldRegToMem_x_shortset,2,1},
  [0xD7] = {ldRegToMem_x_longset,3,1},
  [0x77] = {ldRegToMem_shortoff_SP,2,1},

  //LD Reg to Reg
  [0x97] = {ldRegToReg_A_to_XL,1,1},
  [0x9F] = {ldRegToReg_XL_to_A,1,1},
  [0x95] = {ldRegToReg_A_to_XH,1,1},
  [0x9E] = {ldRegToReg_XH_to_A,1,1},

  //MOV
  [0x35] = {mov_byte_longmem,4,1},
  [0x45] = {mov_shortmem_shortmem,3,1},
  [0x55] = {mov_longmem_longmem,5,1},
};

Opcode opcodeTable90[256] = {
  //ADD
  [0xFB] = {add_y,2,1},
  [0xEB] = {add_y_shortset,3,1},
  [0xDB] = {add_y_longset,4,1},

  //ADC
  [0xF9] = {adc_y,2,1},
  [0xE9] = {adc_y_shortset,3,1},
  [0xD9] = {adc_y_longset,4,1},

  //INC
  [0x7C] = {inc_Y,2,1},
  [0x6C] = {inc_shortoff_Y,3,1},
  [0x4C] = {inc_longoff_Y,4,1},

  //SUB
  [0xF0] = {sub_y,2,1},
  [0xE0] = {sub_y_shortset,3,1},
  [0xD0] = {sub_y_longset,4,1},

  //SBC
  [0xF2] = {sbc_y,2,1},
  [0xE2] = {sbc_y_shortset,3,1},
  [0xD2] = {sbc_y_longset,4,1},

  //OR
  [0xFA] = {or_y,2,1},
  [0xEA] = {or_y_shortset,3,1},
  [0xDA] = {or_y_longset,4,1},

  //XOR
  [0xF8] = {xor_y,2,1},
  [0xE8] = {xor_y_shortset,3,1},
  [0xD8] = {xor_y_longset,4,1},

  //AND
  [0xF4] = {and_y,2,1},
  [0xE4] = {and_y_shortset,3,1},
  [0xD4] = {and_y_longset,4,1},

  //LD Memory to Reg
  [0xF6] = {ldMemToReg_y,2,1},
  [0xE6] = {ldMemToReg_y_shortset,3,1},
  [0xD6] = {ldMemToReg_y_longset,4,1},

  //LD Reg to Memory
  [0xF7] = {ldRegToMem_y,2,1},
  [0xE7] = {ldRegToMem_y_shortset,3,1},
  [0xD7] = {ldRegToMem_y_longset,4,1},

  //LD Reg to Reg
  [0x97] = {ldRegToReg_A_to_YL,2,1},
  [0x9F] = {ldRegToReg_YL_to_A,2,1},
  [0x95] = {ldRegToReg_A_to_YH,2,1},
  [0x9E] = {ldRegToReg_YH_to_A,2,1},
};

Opcode opcodeTable92[256] = {
  //ADD
  [0xCB] = {add_shortptr_w,3,4},
  [0xDB] = {add_shortptr_w_X,3,4},

  //ADC
  [0xC9] = {adc_shortptr_w,3,4},
  [0xD9] = {adc_shortptr_w_X,3,4},

  //INC
  [0x3C] = {inc_shortptr_w,3,4},
  [0x6C] = {inc_shortptr_w_X,3,4},

  //SUB
  [0xC0] = {sub_shortptr_w,3,4},
  [0xD0] = {sub_shortptr_w_X,3,4},

  //SBC
  [0xC2] = {sbc_shortptr_w,3,4},
  [0xD2] = {sbc_shortptr_w_X,3,4},

  //OR
  [0xCA] = {or_shortptr_w,3,4},
  [0xDA] = {or_shortptr_w_X,3,4},

  //XOR
  [0xC8] = {xor_shortptr_w,3,4},
  [0xD8] = {xor_shortptr_w_X,3,4},

  //AND
  [0xC4] = {and_shortptr_w,3,4},
  [0xD4] = {and_shortptr_w_X,3,4},

  //LD Memory to REG
  [0xC6] = {ldMemToReg_shortptr_w,3,4},
  [0xD6] = {ldMemToReg_shortptr_w_X,3,4},

  //LD Reg to Memory
  [0xC7] = {ldRegToMem_shortptr_w,3,4},
  [0xD7] = {ldRegToMem_shortptr_w_X,3,4},


};

Opcode opcodeTable72[256] = {
  //ADD
  [0xCB] = {add_longptr_w,4,4},
  [0xDB] = {add_longptr_w_X,4,4},

  //ADC
  [0xC9] = {adc_longptr_w,4,4},
  [0xD9] = {adc_longptr_w_X,4,4},

  //INC
  [0x3C] = {inc_longptr_w,4,4},
  [0x6C] = {inc_longptr_w_X,4,4},

  //SUB
  [0xC0] = {sub_longptr_w,4,4},
  [0xD0] = {sub_longptr_w_X,4,4},

  //SBC
  [0xC2] = {sbc_longptr_w,4,4},
  [0xD2] = {sbc_longptr_w_X,4,4},

  //OR
  [0xCA] = {or_longptr_w,4,4},
  [0xDA] = {or_longptr_w_X,4,4},

  //XOR
  [0xC8] = {xor_longptr_w,4,4},
  [0xD8] = {xor_longptr_w_X,4,4},

  //AND
  [0xC4] = {and_longptr_w,4,4},
  [0xD4] = {and_longptr_w_X,4,4},

  //LD Memory to Reg
  [0xC6] = {ldMemToReg_longptr_w,4,4},
  [0xD6] = {ldMemToReg_longptr_w_X,4,4},

  //LD Reg to Memory
  [0xC7] = {ldRegToMem_longptr_w,4,4},
  [0xD7] = {ldRegToMem_longptr_w_X,4,4},
};

Opcode opcodeTable91[256] = {
  //ADD
  [0xDB] = {add_shortptr_w_Y,3,4},

  //ADC
  [0xD9] = {adc_shortptr_w_Y,3,4},

  //INC
  [0x6C] = {inc_shortptr_w_Y,3,4},

  //SUB
  [0xD0] = {sub_shortptr_w_Y,3,4},

  //SBC
  [0xD2] = {sbc_shortptr_w_Y,3,4},

  //OR
  [0xDA] = {or_shortptr_w_Y,3,4},

  //XOR
  [0xD8] = {xor_shortptr_w_Y,3,4},

  //AND
  [0xD4] = {and_shortptr_w_Y,3,4},

  //LD Memory to Reg
  [0xD6] = {ldMemToReg_shortptr_w_Y,3,4},

  //LD Reg to Memory
  [0xD7] = {ldRegToMem_shortptr_w_Y,3,4},
};


int isOpcodePrefix(uint8_t *code){
  uint8_t opcode = *code;
  if(opcode == 0x90 || opcode == 0x91 || opcode== 0x92 ||     \
     opcode == 0x72)
     return 1;
  return 0;
}

int instruction(uint8_t **codePtr){
  int (*execute)(uint8_t *code);
  uint8_t *code = *codePtr;
  if(!isOpcodePrefix(code)){
    opcodeTable[*code].execute(code);
    *codePtr += opcodeTable[*code].length;
    return opcodeTable[*code].length;
  }
  else{
    if(*code == 0x90){
      opcodeTable90[*(code+1)].execute(code);
      *codePtr += opcodeTable90[*(code+1)].length;
      return opcodeTable90[*(code+1)].length;
    }
    else if(*code == 0x91){
      opcodeTable91[*(code+1)].execute(code);
      *codePtr += opcodeTable91[*(code+1)].length;
      return opcodeTable91[*(code+1)].length;
    }
    else if(*code == 0x72){
      opcodeTable72[*(code+1)].execute(code);
      *codePtr += opcodeTable72[*(code+1)].length;
      return opcodeTable72[*(code+1)].length;
    }
    else if(*code == 0x92){
      opcodeTable92[*(code+1)].execute(code);
      *codePtr += opcodeTable92[*(code+1)].length;
      return opcodeTable92[*(code+1)].length;
    }
  }


}
