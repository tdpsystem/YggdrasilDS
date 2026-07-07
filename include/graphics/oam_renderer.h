#ifndef YGG_GRAPHICS_OAM_RENDERER_H
#define YGG_GRAPHICS_OAM_RENDERER_H

#include "graphics\sprite.h"

void oamRendererInit(void);
void oamRendererShutdown(void);

void oamRendererBeginFrame(void);
void oamRendererEndFrame(void);

void oamRendererRenderHero(int x, int y);
void oamRendererRenderSprite(const Sprite *sprite);

#endif