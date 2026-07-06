#include <nds.h>
#include <stdio.h>

#include "core\states\menu_state.h"
#include "core\state_machine.h"
#include "graphics\video.h"
#include "input\input.h"
#include "util\debug.h"

static void menuEnter(void) {
    videoClearConsole();

    debugPrint("Menu State\n");
    debugPrint("Press B to return\n");
}

static void menuUpdate(void) {
    if (inputIsPressed(KEY_B)) {
        stateChange(GAME_STATE_WORLD);
    }
}

static void menuRender(void) {
}

static void menuExit(void) {
}

GameState menuStateCreate(void) {
    GameState state;

    state.enter = menuEnter;
    state.update = menuUpdate;
    state.render = menuRender;
    state.exit = menuExit;

    return state;
}
