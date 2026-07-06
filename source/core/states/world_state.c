#include <nds.h>
#include <stdio.h>

#include "core\states\world_state.h"
#include "core\state_machine.h"
#include "graphics\video.h"
#include "graphics\camera.h"
#include "graphics\tile_renderer.h"
#include "graphics\tilemap.h"
#include "graphics/entity_renderer.h"
#include "input\input.h"
#include "util\debug.h"
#include "world\player.h"

static Camera gameCamera;
static Player player;
static TileMap worldMap;

static void worldEnter(void) {
    videoClearConsole();

    cameraInit(&gameCamera);
    playerInit(&player);

    tileRendererInit();
    entityRendererInit();
    tileMapInit(&worldMap);

    for (int y = 0; y < TILEMAP_HEIGHT; y++)
    {
        for (int x = 0; x < TILEMAP_WIDTH; x++)
        {
            if (x == 0 || y == 0 || x == TILEMAP_WIDTH - 1 || y == TILEMAP_HEIGHT - 1)
            {
                tileMapSet(&worldMap, x, y, 1);
            }
            else if ((x + y) % 2 == 0)
            {
                tileMapSet(&worldMap, x, y, 2);
            }
            else
            {
                tileMapSet(&worldMap, x, y, 0);
            }
        }
    }

    cameraSetPosition(
        &gameCamera,
        playerX(&player),
        playerY(&player)
    );

    debugPrint("World State\n");
    debugPrint("Move with D-Pad\n");
}

static void worldUpdate(void) {
    playerUpdate(&player);

    cameraSetTarget(
        &gameCamera,
        playerX(&player),
        playerY(&player)
    );

    cameraUpdate(&gameCamera);

    if (inputIsPressed(KEY_X)) {
        stateChange(GAME_STATE_MENU);
    }

    if (inputIsPressed(KEY_Y)) {
        stateChange(GAME_STATE_BATTLE);
    }
}

static void worldRender(void) {
    tileRendererRender(&worldMap, &gameCamera);
    entityRendererRender(playerEntity(&player), &gameCamera);
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
