#include "graphics\entity_renderer.h"

#include <nds.h>
#include <stddef.h>

#define SCREEN_WIDTH_PIXELS 256
#define SCREEN_HEIGHT_PIXELS 192

static u16 *entityRenderTarget = NULL;

void entityRendererInit(void) {
    entityRenderTarget = (u16 *)BG_GFX;
}

static void drawPixel(int x, int y, u16 color) {
    if (entityRenderTarget == NULL) {
        return;
    }

    if (x < 0 || y < 0 || x >= SCREEN_WIDTH_PIXELS || y >= SCREEN_HEIGHT_PIXELS) {
        return;
    }

    entityRenderTarget[y * SCREEN_WIDTH_PIXELS + x] = color;
}

static void drawRect(int x, int y, int width, int height, u16 color) {
    for (int py = 0; py < height; py++) {
        for (int px = 0; px < width; px++) {
            drawPixel(x + px, y + py, color);
        }
    }
}

void entityRendererRender(const Entity *entity, const Camera *camera) {
    if (entity == NULL || camera == NULL) {
        return;
    }

    if (!entityIsActive(entity) || !entityIsVisible(entity)) {
        return;
    }

    int screenX = entityX(entity) - cameraX(camera);
    int screenY = entityY(entity) - cameraY(camera);

    drawRect (
        screenX,
        screenY,
        entityWidth(entity),
        entityHeight(entity),
        RGB15(31, 31, 31)
    );
}