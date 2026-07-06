#ifndef YGG_WORLD_MAP_LOADER_H
#define YGG_WORLD_MAP_LOADER_H

#include <stdbool.h>

#include "graphics\tileMap.h"

typedef enum MapId {
    MAP_ID_TEST = 0,
    MAP_ID_MANNHEIM_VILLAGE,
    MAP_ID_IRONWOOD_FOREST,
    MAP_ID_DRAUGR_BARROW,
    MAP_ID_COUNT
} MapId;

bool mapLoaderLoad(MapId mapId, TileMap *tilemap);

#endif