#ifndef YGG_WORLD_WORLD_H
#define YGG_WORLD_WORLD_H

#include "graphics\camera.h"
#include "graphics\tilemap.h"
#include "world\player.h"

typedef struct World {
    Camera camera;
    TileMap tileMap;
    Player player;
} World;

void worldInit(World *world);
void worldUpdate(World *world);
void worldRender(World *world);

void worldLoadTestMap(World *world);

Camera *worldCamera(World *world);
TileMap *worldTileMap(World *world);
Player *worldPlayer(World *world);

const Camera *worldCameraConst(const World *world);
const TileMap *worldTileMapConst(const World *world);
const Player *worldPlayerConst(const World *world);

#endif