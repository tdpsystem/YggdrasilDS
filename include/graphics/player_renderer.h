#ifndef YGG_GRAPHICS_PLAYER_RENDERER_H
#define YGG_GRAPHICS_PLAYER_RENDERER_H

#include "graphics\camera.h"
#include "world\player.h"

void playerRendererInit(void);
void playerRendererRender(const Player *player, const Camera *camera);

#endif