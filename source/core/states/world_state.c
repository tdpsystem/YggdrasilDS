#include <nds.h>
#include <stdio.h>

#include "core\states\world_state.h"
#include "core\state_machine.h"
#include "graphics\video.h"
#include "graphics\camera.h"
#include "input\input.h"
#include "util\debug.h"
#include "world\player.h"

static Camera gameCamera;
static Player player;

static void worldEnter(void)
{
    videoClearConsole();

    cameraInit(&gameCamera);
    playerInit(&player);

    cameraSetPosition(
        &gameCamera,
        playerX(&player),
        playerY(&player)
    );

    debugPrint("World State\n");
    debugPrint("Move with D-Pad\n");
}

static void worldUpdate(void)
{
    playerUpdate(&player);

    cameraSetTarget(
        &gameCamera,
        playerX(&player),
        playerY(&player)
    );

    cameraUpdate(&gameCamera);

    if (inputIsPressed(KEY_X))
    {
        stateChange(GAME_STATE_MENU);
    }

    if (inputIsPressed(KEY_Y))
    {
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