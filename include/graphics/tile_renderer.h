#ifndef YGG_GRAPHICS_TILE_RENDERER_H
#define YGG_GRAPHICS_TILE_RENDERER_H


#include "graphics\camera.h"
#include "graphics\tilemap.h"

void tileRendererInit(void);

void tileRendererRender(const TileMap *map, const Camera *camera);

#endif
