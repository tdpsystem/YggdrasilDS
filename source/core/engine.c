#include <nds.h>

#include "core/engine.h"
#include "core/game.h"
#include "core/timer.h"
#include "core/asset_manager.h"

#include "graphics/video.h"
#include "graphics/oam_renderer.h"
#include "graphics/background_renderer.h"
#include "graphics/sprite_renderer.h"

#include "input/input.h"

#include "util/debug.h"

static bool engineRunning = true;

void engineInit(void) {
    engineRunning = true;

    videoInit();
    debugInit();
    inputInit();
    timerInit();

    oamRendererInit();
    backgroundRendererInit();
    spriteRendererInit();

    assetManagerInit();

    gameInit();
}

void engineUpdate(void) {
    inputUpdate();
    timerUpdate();

    gameUpdate();
}

void engineRender(void)
{
    videoBeginFrame();

    backgroundRendererBeginFrame();
    spriteRendererBeginFrame();
    oamRendererBeginFrame();

    gameRender();

    backgroundRendererEndFrame();
    spriteRendererEndFrame();
    oamRendererEndFrame();

    videoEndFrame();
}

void engineRequestQuit(void) {
    assetManagerShutdown();
    engineRunning = false;
}

bool engineIsRunning(void) {
    return engineRunning;
}
