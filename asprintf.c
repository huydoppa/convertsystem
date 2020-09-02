#include "asprintf.h"

int asprintf(char **strp, const char *fmt, ...)
{
  int r;
  va_list ap;
  va_start(ap, fmt);
  r = vasprintf(strp, fmt, ap);
  va_end(ap);
  return(r);
}
