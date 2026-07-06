#ifndef YGG_GRAPHICS_ENTITY_RENDERER_H
#define YGG_GRAPHICS_ENTITY_RENDERER_H

#include "graphics\camera.h"
#include "world\entity.h"

void entityRendererInit(void);
void entityRendererRender(const Entity *entity, const Camera *camera);

#endif