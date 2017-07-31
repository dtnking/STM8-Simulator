#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H
#include <stdint.h>

int isOpcodePrefix(uint8_t *code);
uint8_t instruction(uint8_t **codePtr);

#endif // _INSTRUCTION_H
