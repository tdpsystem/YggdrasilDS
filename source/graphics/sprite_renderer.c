#include "graphics\sprite_renderer.h"

#include <stddef.h>

#include "graphics\oam_renderer.h"

#include "world\entity.h"

void spriteRendererInit(void) {

}

void spriteRendererShutDown(void) {

}

void spriteRendererBeginFrame(void) {

}

void spriteRendererRenderSprite(const Sprite* sprite, const Camera* camera) {
    if (sprite == NULL || camera == NULL) {
        return;
    }

    int screenX = spriteX(sprite) - cameraX(camera);
    int screenY = spriteY(sprite) - cameraY(camera);

    oamRendererRenderHero(screenX, screenY);
}

void spriteRendererRenderPlayer(const Player* player, const Camera* camera) {
    if (player == NULL || camera == NULL) {
        return;
    }

    const Entity *entity = playerEntityConst(player);

    if (entity == NULL) {
        return;
    }

    spriteRendererRenderSprite(entitySpriteConst(entity), camera);
}

void spriteRendererEndFrame(void) {

}