#include <nds.h>
#include <stdio.h>

#include "core/states/boot_state.h"
#include "core/state_machine.h"
#include "input/input.h"
#include "util/debug.h"

static void bootEnter(void) {
    stateChange(GAME_STATE_TITLE);
}

static void bootUpdate(void) {
}

static void bootRender(void) {
}

static void bootExit(void) {
}

GameState bootStateCreate(void) {
    GameState state;

    state.enter = bootEnter;
    state.update = bootUpdate;
    state.render = bootRender;
    state.exit = bootExit;

    return state;
}
