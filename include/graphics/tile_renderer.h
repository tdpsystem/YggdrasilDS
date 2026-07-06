#ifndef YGG_GRAPHICS_TILE_RENDERER_H
#define YGG_GRAPHICS_TILE_RENDERER_H

#include "camera.h"
#include "tilemap.h"
#include "graphics\camera.h"
#include "graphics\tilemp.h"

void tileRendererInit(void);

void tileRendererRender(const TileMap *map, const Camera *camera);

#endif
