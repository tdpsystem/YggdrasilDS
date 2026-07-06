#include "world\map_loader.h"

#include <stddef.h>

static void loadTestMap(TileMap *tileMap) {
    tileMapInit(tileMap);

    for (int y = 0; y < tileMap->height; y++) {
        for (int x = 0; x < tileMap->width; x++) {
            if (x == 0 || y == 0 || x == tileMap->width - 1 || y == tileMap->height - 1) {
                tileMapSet(tileMap, x, y, 1);
            }
            else if ((x + y) % 2 == 0) {
                tileMapSet(tileMap, x, y, 2);
            }
            else {
                tileMapSet(tileMap, x, y, 0);
            }
        }
    }
}

static void loadMannheimVillage(TileMap *tileMap) {
    loadTestMap(tileMap);
}

static void loadIronwoodForest(TileMap *tileMap) {
    loadTestMap(tileMap);
}

static void loadDraugrBarrow(TileMap *tileMap) {
    loadTestMap(tileMap);
}

bool mapLoaderLoad(MapId mapId, TileMap *tileMap) {
    if (tileMap == NULL) {
        return false;
    }

    switch (mapId) {
        case MAP_ID_TEST:
            loadTestMap(tileMap);
            return true;
        case MAP_ID_MANNHEIM_VILLAGE:
            loadMannheimVillage(tileMap);
            return true;
        case MAP_ID_IRONWOOD_FOREST:
            loadIronwoodForest(tileMap);
            return true;
        case MAP_ID_DRAUGR_BARROW:
            loadDraugrBarrow(tileMap);
            return true;
        default:
            return false;
    }
}