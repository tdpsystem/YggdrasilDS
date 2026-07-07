#include <nds.h>

#include "core/states/world_state.h"
#include "core/state_machine.h"

#include "graphics/entity_renderer.h"
#include "graphics/player_renderer.h"
#include "graphics/tile_renderer.h"
#include "graphics/video.h"

#include "input/input.h"
#include "util/debug.h"
#include "world/world.h"

static World world;

static void worldStateEnter(void) {
    videoClearConsole();

    tileRendererInit();
    playerRendererInit();

    worldInit(&world);

    debugPrint("World State\n");
    debugPrint("Move with D-Pad\n");
    debugPrint("X = Menu\n");
    debugPrint("Y = Battle\n");
}

static void worldStateUpdate(void) {
    worldUpdate(&world);

    if (inputIsPressed(KEY_X)) {
        stateChange(GAME_STATE_MENU);
    }

    if (inputIsPressed(KEY_Y)) {
        stateChange(GAME_STATE_BATTLE);
    }
}

static void worldStateRender(void) {
    worldRender(&world);
}

static void worldStateExit(void) {
}

GameState worldStateCreate(void) {
    GameState state;

    state.enter = worldStateEnter;
    state.update = worldStateUpdate;
    state.render = worldStateRender;
    state.exit = worldStateExit;

    return state;
}
