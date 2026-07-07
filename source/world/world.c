#include "world\world.h"

#include <stddef.h>

#include "graphics\player_renderer.h"
#include "graphics\tile_renderer.h"
#include "world\collision.h"

#define SCREEN_WIDTH   256
#define SCREEN_HEIGHT  192

#define SCREEN_CENTER_X (SCREEN_WIDTH / 2)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)

void worldInit(World *world) {
    if (world == NULL) {
        return;
    }

    cameraInit(&world->camera);
    tileMapInit(&world->tileMap);
    playerInit(&world->player);

    worldLoadTestMap(world);

    cameraSetBounds(
        &world->camera,
        0,
        0,
        TILEMAP_WIDTH * TILE_SIZE - SCREEN_WIDTH,
        TILEMAP_HEIGHT * TILE_SIZE - SCREEN_HEIGHT
    );

    cameraSetPosition(
        &world->camera,
        playerX(&world->player) - SCREEN_CENTER_X,
        playerY(&world->player) - SCREEN_CENTER_Y
    );
}

void worldUpdate(World *world) {
    if (world == NULL) {
        return;
    }

    playerUpdate(&world->player);

    cameraSetTarget(
        &world->camera,
        playerX(&world->player) - SCREEN_CENTER_X,
        playerY(&world->player) - SCREEN_CENTER_Y
    );

    cameraUpdate(&world->camera);

    cameraSetPosition(
        &world->camera,
        cameraX(&world->camera),
        cameraY(&world->camera)
    );
}

void worldRender(World *world) {
    if (world == NULL) {
        return;
    }

    tileRendererRender(&world->tileMap, &world->camera);
    playerRendererRender(&world->player, &world->camera);
}

void worldLoadTestMap(World *world) {
    if (world == NULL) {
        return;
    }

    tileMapInit(&world->tileMap);

    for (int y = 0; y < TILEMAP_HEIGHT; y++) {
        for (int x = 0; x < TILEMAP_WIDTH; x++) {
            if (x == 0 || y == 0 || x == TILEMAP_WIDTH - 1 || y == TILEMAP_HEIGHT - 1) {
                tileMapSet(&world->tileMap, x, y, 1);
            } else if ((x + y) % 2 == 0) {
                tileMapSet(&world->tileMap, x, y, 2);
            } else {
                tileMapSet(&world->tileMap, x, y, 0);
            }
        }
    }
}

Camera *worldCamera(World *world) {
    return world == NULL ? NULL : &world->camera;
}

TileMap *worldTileMap(World *world) {
    return world == NULL ? NULL : &world->tileMap;
}

Player *worldPlayer(World *world) {
    return world == NULL ? NULL : &world->player;
}

const Camera *worldCameraConst(const World *world) {
    return world == NULL ? NULL : &world->camera;
}

const TileMap *worldTileMapConst(const World *world) {
    return world == NULL ? NULL : &world->tileMap;
}

const Player *worldPlayerConst(const World *world) {
    return world == NULL ? NULL : &world->player;
}
