#include "core/asset_manager.h"

#include <stddef.h>

void assetManagerInit(void)
{
}

void assetManagerShutdown(void)
{
}

bool assetLoad(Asset *asset)
{
    if (asset == NULL)
    {
        return false;
    }

    asset->loaded = true;

    return true;
}

void assetUnload(Asset *asset)
{
    if (asset == NULL)
    {
        return;
    }

    asset->loaded = false;
}

bool assetIsLoaded(const Asset *asset)
{
    if (asset == NULL)
    {
        return false;
    }

    return asset->loaded;
}