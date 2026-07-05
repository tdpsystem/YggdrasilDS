#ifndef YGG_UTIL_DEBUG_H
#define YGG_UTIL_DEBUG_H

#include <stdbool.h>

void debugInit(void);
void debugClear(void);

void debugPrint(const char *text);
void debugPrintf(const char *format, ...);

void debugSetEnabled(bool enabled);
bool debugIsEnabled(void);

#endif