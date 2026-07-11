#include "world/world.h"

#include <stddef.h>

#include "graphics/background_renderer.h"
#include "graphics/sprite_renderer.h"
#include "graphics/oam_renderer.h"

#include "world/collision.h"
#include "world/map_loader.h"
#include "world/entity.h"

#include "generated/mannheim_map.h"

#define WORLD_SCREEN_WIDTH   256
#define WORLD_SCREEN_HEIGHT  192

#define WORLD_SCREEN_CENTER_X (WORLD_SCREEN_WIDTH / 2)
#define WORLD_SCREEN_CENTER_Y (WORLD_SCREEN_HEIGHT / 2)

void worldInit(World *world) {
#define MANNHEIM_PIXEL_WIDTH  \
(MANNHEIM_MAP_WIDTH * TILE_SIZE)

#define MANNHEIM_PIXEL_HEIGHT \
(MANNHEIM_MAP_HEIGHT * TILE_SIZE)

    if (world == NULL) {
        return;
    }

    cameraInit(&world->camera);
    tileMapInit(&world->tileMap);
    playerInit(&world->player);

    if (!mapLoaderLoad(
        MAP_ID_MANNHEIM_VILLAGE,
        &world->tileMap
    )) {
        mapLoaderLoad(
            MAP_ID_TEST,
            &world->tileMap
        );
    }

    cameraSetBounds(
        &world->camera,
        0,
        0,
        MANNHEIM_PIXEL_WIDTH - WORLD_SCREEN_WIDTH,
        MANNHEIM_PIXEL_HEIGHT - WORLD_SCREEN_HEIGHT
    );

    cameraSetPosition(
        &world->camera,
        playerX(&world->player) - WORLD_SCREEN_CENTER_X,
        playerY(&world->player) - WORLD_SCREEN_CENTER_Y
    );
}

void worldUpdate(World *world) {
    if (world == NULL) {
        return;
    }

    playerUpdate(
        &world->player,
        &world->tileMap
    );

    cameraSetTarget(
        &world->camera,
        playerX(&world->player) - WORLD_SCREEN_CENTER_X,
        playerY(&world->player) - WORLD_SCREEN_CENTER_Y
    );

    cameraUpdate(&world->camera);
}

void worldRender(World *world) {
    if (world == NULL) {
        return;
    }

    backgroundRendererRenderTileMap(&world->tileMap, &world->camera);
    spriteRendererRenderPlayer(&world->player, &world->camera);
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
