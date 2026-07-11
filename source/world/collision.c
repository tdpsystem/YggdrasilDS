#include "world/collision.h"

#include <stddef.h>

bool collisionTileIsSolid(Tile tile)
{
    switch (tile)
    {
        /* Hedge */
        case 3:

            /* Cliffs */
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:

            /* Water and shoreline */
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
            return true;

            /* Grass and paths */
        default:
            return false;
    }
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

bool collisionCanMoveEntity(
    const TileMap *map,
    const Entity *entity,
    int dx,
    int dy
)
{
    if (map == NULL || entity == NULL)
    {
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

void collisionMoveEntity(const TileMap *map, Entity *entity, int dx, int dy)
{
    if (map == NULL || entity == NULL)
    {
        return;
    }

    if (!entityIsSolid(entity))
    {
        entityMove(entity, dx, dy);
        return;
    }

    if (collisionCanMoveEntity(map, entity, dx, 0))
    {
        entityMove(entity, dx, 0);
    }

    if (collisionCanMoveEntity(map, entity, 0, dy))
    {
        entityMove(entity, 0, dy);
    }
}
