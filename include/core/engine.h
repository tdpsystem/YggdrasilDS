#ifndef YGG_CORE_ENGINE_H
#define YGG_CORE_ENGINE_H

#include <stdbool.h>

void engineInit(void);

void engineUpdate(void);

void engineRender(void);

void engineRequestQuit(void);

bool engineIsRunning(void);

#endif
