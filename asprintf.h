

#ifndef INSANE_ASPRINTF_H
#define INSANE_ASPRINTF_H

#ifndef __cplusplus
#include <stdarg.h>
#else
#include <cstdarg>
extern "C"
{
#endif

#define insane_free(ptr) { free(ptr); ptr = 0; }

int vasprintf(char **strp, const char *fmt, va_list ap);
int asprintf(char **strp, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
