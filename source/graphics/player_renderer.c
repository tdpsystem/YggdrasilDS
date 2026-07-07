#include "graphics\player_renderer.h"

#include <stddef.h>

#include "graphics\entity_renderer.h"

void playerRendererInit(void) {
    entityRendererInit();
}

void playerRendererRender(const Player *player, const Camera *camera) {
    if (player == NULL || camera == NULL) {
        return;
    }

    entityRendererRender(playerEntityConst(player), camera);
}
