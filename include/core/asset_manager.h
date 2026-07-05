#ifndef YGG_CORE_ASSET_MANAGER_H
#define YGG_CORE_ASSET_MANAGER_H

#include <stdbool.h>
#include <stddef.h>

typedef enum AssetType {
    ASSET_GRAPHIC = 0,
    ASSET_TILESET,
    ASSET_TILEMAP,
    ASSET_PALETTE,
    ASSET_SPRITE,
    ASSET_FONT,
    ASSET_SOUND,
    ASSET_MUSIC,
    ASSET_COUNT
} AssetType;

typedef struct Asset {
    const char *name;
    void *data;
    unsigned int size;
    AssetType type;
    bool loaded;
} Asset;

void assetManagerInit(void);
void assetManagerShutdown(void);

bool assetLoad(Asset *asset);
void assetUnload(Asset *asset);

bool assetIsLoaded(const Asset *asset);

#endif