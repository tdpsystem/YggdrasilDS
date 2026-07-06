#ifndef YGG_WORLD_COLLISION_H
#define YGG_WORLD_COLLISION_H

#include <stdbool.h>

#include "../graphics/tilemap.h"
#include "graphics/tilemap.h"
#include "world\entity.h"

#define TILE_SIZE 16

bool collisionTileIsSolid(Tile tile);

bool collisionPointIsSolid(const TileMap *map, int worldX, int worldY);

bool collisionRectIsSolid(const TileMap *map, int x, int y, int width, int height);

bool collisionCanMoveEntity(const TileMap *map, const Entity *entity, int dx, int dy);

void collisionMoveEntity(const TileMap *map, Entity *entity, int dx, int dy);

#endif
