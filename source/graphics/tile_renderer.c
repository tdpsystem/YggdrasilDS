#include "graphics\tile_Renderer.h"

#include <nds.h>
#include <stddef.h>

#define SCREEN_WIDTH_PIXELS 256
#define SCREEN_HEIGHT_PIXELS 192
#define TILE_RENDER_SIZE 8

static int bgId = -1;
static u16 *bgMap = NULL;

static u16 tileColor(Tile tile) {
    switch (tile) {
        case 1:
            return RGB15(10, 10, 10);
        case 2:
            return RGB15(0, 18, 0);
        case 3:
            return RGB15(0, 0, 18);
        default:
            return RGB15(4, 20, 4);
    }
}

void tileRendererInit(void) {
    videoSetMode(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_BG);

    bgId = bgInit(
        3,
        BgType_Bmp16,
        BgSize_B16_256x256,
        0,
        0
    );

    bgMap = bgGetGfxPtr(bgId);
}

void tileRendererRender(const TileMap *map, const Camera *camera) {
    if (map == NULL || camera == NULL || bgMap == NULL) {
        return;
    }

    int camX = cameraX(camera);
    int camY = cameraY(camera);

    for (int y = 0; y < SCREEN_HEIGHT_PIXELS; y++) {
        for (int x = 0; x < SCREEN_WIDTH_PIXELS; x++) {
            int worldX = camX + x;
            int worldY = camY + y;

            int tileX = worldX / TILE_RENDER_SIZE;
            int tileY = worldY / TILE_RENDER_SIZE;

            Tile tile = tileMapGet(map, tileX, tileY);

            bgMap[y * SCREEN_WIDTH_PIXELS + x] = tileColor(tile);
        }
    }
}
