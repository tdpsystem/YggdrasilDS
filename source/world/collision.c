#include "world/collision.h"

#include <stddef.h>

bool collisionTileIsSolid(Tile tile) {
    return tile == 1;
}

bool collisionPointIsSolid(const TileMap *map, int worldX, int worldY) {
    if (map == NULL) {
        return true;
    }

    int tileX = worldX / TILE_SIZE;
    int tileY = worldY / TILE_SIZE;

    Tile tile = tileMapGet(map, tileX, tileY);

    return collisionTileIsSolid(tile);
}

bool collisionRectIsSolid(const TileMap *map, int x, int y, int width, int height) {
    if (map == NULL) {
        return true;
    }

    if (width <= 0 || height <= 0) {
        return true;
    }

    int left = x;
    int right = x + width - 1;
    int top = y;
    int bottom = y + height - 1;

    if (collisionPointIsSolid(map, left, top)) {
        return true;
    }

    if (collisionPointIsSolid(map, right, top)) {
        return true;
    }

    if (collisionPointIsSolid(map, left, bottom)) {
        return true;
    }

    if (collisionPointIsSolid(map, right, bottom)) {
        return true;
    }

    return false;
}

bool collisionCanMoveEntity(const TileMap *map, const Entity *entity, int dx, int dy) {
    if (map == NULL) {
        return false;
    }

    int nextX = entityX(entity) + dx;
    int nextY = entityY(entity) + dy;

    return !collisionRectIsSolid(
        map,
        nextX,
        nextY,
        entityWidth(entity),
        entityHeight(entity)
    );
}

void collisionMoveEntity(const TileMap *map, Entity *entity, int dx, int dy) {
    if (map == NULL) {
        return;
    }

    if (!entityIsSolid(entity)) {
        entityMove(entity, dx, dy);
        return;
    }

    if (collisionCanMoveEntity(map, entity,dx, 0)) {
        entityMove(entity, 0, dy);
    }
}