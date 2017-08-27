#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>


#define ERR_SYSTEM_ERROR          10
#define ERR_INVALID_INSTRUCTION   20
#define ERR_INVALID_OPERAND       21

typedef struct Exception Exception;
typedef struct Exception* ExceptionPtr;
struct Exception {
  char *msg;
  int  errorCode;
  void *data;
};

char* message;
int errorcode;

Exception *createException(char *msg, int errorCode);
void freeException(Exception *e);
void dumpErrorMessage(Exception *e);

void throwException(int errorCode, char *message, ...);


#endif // _EXCEPTION_H
