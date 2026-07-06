#include "util/debug.h"

#include <nds.h>
#include <stdio.h>
#include <stdarg.h>

static bool debugEnabled = true;

void debugInit(void) {
#ifndef NDEBUG
    debugEnabled = true;
#else
    debugEnabled = false;
#endif
}

void debugClear(void) {
    if (!debugEnabled) {
        return;
    }

    consoleClear();
}

void debugPrint(const char *text) {
    if (!debugEnabled || text == NULL) {
        return;
    }

    iprintf("%s", text);
}

void debugPrintf(const char *format, ...) {
    if (!debugEnabled || format == NULL) {
        return;
    }

    va_list args;
    va_start(args, format);
    viprintf(format, args);
    va_end(args);
}

void debugSetEnabled(bool enabled) {
    debugEnabled = enabled;
}

bool debugIsEnabled(void) {
    return debugEnabled;
}
