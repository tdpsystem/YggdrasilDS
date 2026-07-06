#include <nds.h>
#include <stdio.h>

#include "core\states\battle_state.h"
#include "core\state_machine.h"
#include "graphics\video.h"
#include "input\input.h"
#include "util\debug.h"

static void battleEnter(void) {
    videoClearConsole();

    debugPrint("Battle State\n");
    debugPrint("Press B to flee\n");
}

static void battleUpdate(void) {
    if (inputIsPressed(KEY_B)) {
        stateChange(GAME_STATE_WORLD);
    }
}

static void battleRender(void) {
}

static void battleExit(void) {
}

GameState battleStateCreate(void) {
    GameState state;

    state.enter = battleEnter;
    state.update = battleUpdate;
    state.render = battleRender;
    state.exit = battleExit;

    return state;
}
