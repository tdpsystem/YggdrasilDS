#ifndef YGG_GRAPHICS_BACKGROUND_RENDERER_H
#define YGG_GRAPHICS_BACKGROUND_RENDERER_H

#include "graphics\camera.h"
#include "graphics\tilemap.h"

void backgroundRendererInit(void);
void backgroundRendererShutdown(void);

void backgroundRendererBeginFrame(void);
void backgroundRendererRenderTileMap(const TileMap *tileMap, const Camera *camera);
void backgroundRendererEndFrame(void);

#endif