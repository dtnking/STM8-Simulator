#ifndef _JRXX_H
#define _JRXX_H
#include <stdint.h>


// check condition and opcode prefix,
// condition is needed to determine PC = PC + lgth(False) or PC <= PC + dst(True)
// opcode prefix is needed to determine the length of the opcode if the condition is false
#define JRXX(condition,opcodePrefix)   condition? set_PC(get_valueByte(opcodePtr) + PC + (opcodePrefix?3:2)): UPDATE_PC(opcodePrefix? 3:2)


void  jrc       (uint8_t *opcodePtr);
void  jreq      (uint8_t *opcodePtr);
void  jrf       (uint8_t *opcodePtr);
void  jrh       (uint8_t *opcodePtr);
void  jrm       (uint8_t *opcodePtr);
void  jrmi      (uint8_t *opcodePtr);
void  jrnc      (uint8_t *opcodePtr);
void  jrne      (uint8_t *opcodePtr);
void  jrnh      (uint8_t *opcodePtr);
void  jrnm      (uint8_t *opcodePtr);
void  jrnv      (uint8_t *opcodePtr);
void  jrpl      (uint8_t *opcodePtr);
void  jrsge     (uint8_t *opcodePtr);
void  jrsgt     (uint8_t *opcodePtr);
void  jrsle     (uint8_t *opcodePtr);
void  jrslt     (uint8_t *opcodePtr);
void  jrt       (uint8_t *opcodePtr);
void  jruge     (uint8_t *opcodePtr);
void  jrugt     (uint8_t *opcodePtr);
void  jrule     (uint8_t *opcodePtr);
void  jrult     (uint8_t *opcodePtr);
void  jrv       (uint8_t *opcodePtr);

#endif // _JRXX_H
