#ifndef YGG_GRAPHICS_SPRITE_RENDERER_H
#define YGG_GRAPHICS_SPRITE_RENDERER_H

#include "graphics\camera.h"
#include "graphics\sprite.h"

#include "world\player.h"

void spriteRendererInit(void);
void spriteRendererShutdown(void);

void spriteRendererBeginFrame(void);

void spriteRendererRenderSprite(const Sprite* sprite, const Camera* camera);
void spriteRendererRenderPlayer(const Player* player, const Camera* camera);

void spriteRendererEndFrame(void);

#endif
