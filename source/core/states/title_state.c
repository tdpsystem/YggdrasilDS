#include <nds.h>
#include <stdio.h>

#include "core\states\title_state.h"
#include "core\state_machine.h"
#include "graphics\video.h"
#include "input\input.h"
#include "util\debug.h"

static void titleEnter(void) {
    videoClearConsole();

    debugPrint("Yggdrasil Saga\n");
    debugPrint("Title State\n");
    debugPrint("Press A\n");
}

static void titleUpdate(void) {
    if (inputIsPressed(KEY_A)) {
        stateChange(GAME_STATE_WORLD);
    }
}

static void titleRender(void) {

}

static void titleExit(void) {

}

GameState titleStateCreate(void) {
    GameState state;

    state.enter = titleEnter;
    state.update = titleUpdate;
    state.render = titleRender;
    state.exit = titleExit;

    return state;
}