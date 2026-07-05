#include <nds.h>
#include <stdio.h>

#include "core\states\world_state.h"
#include "core\state_machine.h"
#include "graphics\video.h"
#include "input\input.h"
#include "util\debug.h"

static void worldEnter(void) {
    videoClearConsole();

    debugPrint("World State\n");
    debugPrint("Press X for Menu\n");
    debugPrint("Press Y for Battle\n");
}

static void worldUpdate(void) {
    if (inputIsPressed(KEY_X)) {
        stateChange(GAME_STATE_MENU);
    }
    if (inputIsPressed(KEY_Y)) {
        stateChange(GAME_STATE_BATTLE);
    }
}

static void worldRender(void) {

}

static void worldExit(void) {

}

GameState worldStateCreate(void) {
    GameState state;

    state.enter = worldEnter;
    state.update = worldUpdate;
    state.render = worldRender;
    state.exit = worldExit;

    return state;
}