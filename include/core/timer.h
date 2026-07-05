#ifndef YGG_CORE_TIMER_H
#define YGG_CORE_TIMER_H

#include <nds.h>

void timerInit(void);
void timerUpdate(void);

u32 timerFrameCount(void);
u32 timerSeconds(void);

float timerDeltaTime(void);
float timerTotalTime(void);

#endif