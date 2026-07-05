#include "graphics/video.h"
#include "util/debug.h"

void videoInit(void)
{
    consoleDemoInit();
}

void videoBeginFrame(void)
{
}

void videoEndFrame(void)
{
    swiWaitForVBlank();
}

void videoClearConsole(void)
{
    debugClear();
}