#include <nds.h>

#include "core/engine.h"
#include "core/game.h"
#include "core/timer.h"
#include "core/asset_manager.h"
#include "graphics/video.h"
#include "input/input.h"
#include "util/debug.h"

static bool engineRunning = true;

void engineInit(void) {
    engineRunning = true;

    videoInit();
    debugInit();
    inputInit();
    timerInit();

    assetManagerInit();

    gameInit();
}

void engineUpdate(void) {
    inputUpdate();
    timerUpdate();

    gameUpdate();
}

void engineRender(void) {
    videoBeginFrame();

    gameRender();

    videoEndFrame();
}

void engineRequestQuit(void) {
    assetManagerShutdown();
    engineRunning = false;
}

bool engineIsRunning(void) {
    return engineRunning;
}
