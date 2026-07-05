#include "graphics/tilemap.h"

#include <stddef.h>

void tileMapInit(TileMap *map)
{
    if (map == NULL)
        return;

    map->width = TILEMAP_WIDTH;
    map->height = TILEMAP_HEIGHT;

    for (int y = 0; y < TILEMAP_HEIGHT; y++)
    {
        for (int x = 0; x < TILEMAP_WIDTH; x++)
        {
            map->tiles[y][x] = 0;
        }
    }
}

bool tileMapIsInside(const TileMap *map, int x, int y)
{
    if (map == NULL)
        return false;

    return x >= 0 &&
           y >= 0 &&
           x < map->width &&
           y < map->height;
}

Tile tileMapGet(const TileMap *map, int x, int y)
{
    if (!tileMapIsInside(map, x, y))
        return 0;

    return map->tiles[y][x];
}

void tileMapSet(TileMap *map, int x, int y, Tile tile)
{
    if (!tileMapIsInside(map, x, y))
        return;

    map->tiles[y][x] = tile;
}