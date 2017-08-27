#include <malloc.h>
#include <stdarg.h>
#include "Exception.h"
#include "CException.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


void throwException(int errorCode, char *message,...) {
  va_list args;
  char *buffer;
  int length;
  Exception *e;

  va_start(args, message);
  e = malloc(sizeof(Exception));

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length + 1);
  vsnprintf(buffer, length + 1, message, args);

  e->msg = buffer;
  e->errorCode = errorCode;

  Throw(e);
}


void freeException(Exception *e) {
    if(e) {
    if(e->msg)
      free(e->msg);
    free(e);
  }
}

void dumpErrorMessage(Exception *e) {
  printf("%s\n\t",e->msg);
  message = e->msg;
  errorcode = e->errorCode;

}
