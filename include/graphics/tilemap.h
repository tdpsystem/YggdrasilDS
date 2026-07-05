#ifndef YGG_GRAPHICS_TILEMAP_H
#define YGG_GRAPHICS_TILEMAP_H

#include <stdbool.h>
#include <stdint.h>

#define TILEMAP_WIDTH 64
#define TILEMAP_HEIGHT 64

typedef uint8_t Tile;

typedef struct TileMap {
    int width;
    int height;

    Tile tiles[TILEMAP_HEIGHT][TILEMAP_WIDTH];
} TileMap;

void tileMapInit(TileMap *map);

Tile tileMapGet(const TileMap *map, int x, int y);
void tileMapSet(TileMap *map, int x, int y, Tile tile);

bool tileMapIsInside(const TileMap *map, int x, int y);

#endif