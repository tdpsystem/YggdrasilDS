#include "core/timer.h"

static u32 timerFrames = 0;
static u32 timerSecs = 0;

static float timerDelta = 1.0f / 60.0f;
static float timerTotal = 0.0f;

void timerInit(void) {
    timerFrames = 0;
    timerSecs = 0;

    timerDelta = 1.0f / 60.0f;
    timerTotal = 0.0f;
}

void timerUpdate(void) {
    timerFrames++;

    timerDelta = 1.0f / 60.0f;
    timerTotal += timerDelta;

    timerSecs = timerFrames / 60;
}

u32 timerFrameCount(void) {
    return timerFrames;
}

u32 timerSeconds(void) {
    return timerSecs;
}

float timerDeltaTime(void) {
    return timerDelta;
}

float timerTotalTime(void) {
    return timerTotal;
}
