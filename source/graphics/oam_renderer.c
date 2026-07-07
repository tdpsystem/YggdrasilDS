#include "graphics\oam_renderer.h"

#include <nds.h>
#include <string.h>

#include "generated\hero_placeholder.h"

#define HERO_SPRITE_ID 0
#define HERO_SPRITE_SIZE SpriteSize_16x16
#define HERO_SPRITE_COLOR_FORMAT SpriteColorFormat_16Color

static u16 *heroGfx = NULL;
static bool oamReady = false;

static void loadHeroPalette(void)
{
    SPRITE_PALETTE[0] = RGB15(31, 0, 31);
    SPRITE_PALETTE[1] = RGB15(31, 31, 31);
    SPRITE_PALETTE[2] = RGB15(31, 31, 31);
    SPRITE_PALETTE[3] = RGB15(31, 31, 31);
    SPRITE_PALETTE[4] = RGB15(31, 31, 31);
    SPRITE_PALETTE[5] = RGB15(31, 31, 31);
    SPRITE_PALETTE[6] = RGB15(31, 31, 31);
    SPRITE_PALETTE[7] = RGB15(31, 31, 31);
} //temporary palette

void oamRendererInit(void)
{
    vramSetBankG(VRAM_G_MAIN_SPRITE);

    oamInit(&oamMain, SpriteMapping_1D_32, false);

    loadHeroPalette();

    heroGfx = oamAllocateGfx(
        &oamMain,
        HERO_SPRITE_SIZE,
        HERO_SPRITE_COLOR_FORMAT
    );

    if (heroGfx != NULL)
    {
        dmaCopy(
            hero_placeholderTiles,
            heroGfx,
            hero_placeholderTilesLen
        );
    }

    oamReady = true;
}

void oamRendererBeginFrame(void) {

}

void oamRendererEndFrame(void) {
    oamUpdate(&oamMain);
}

void oamRendererRenderHero(int x, int y) {
    if (!oamReady || heroGfx == NULL) {
        return;
    }

    oamSet(
        &oamMain,
        HERO_SPRITE_ID,
        x,
        y,
        0,
        0,
        HERO_SPRITE_SIZE,
        HERO_SPRITE_COLOR_FORMAT,
        heroGfx,
        -1,
        false,
        false,
        false,
        false,
        false
    );
}

void oamRendererRenderSprite(const Sprite *sprite) {
    if (sprite == NULL) {
        return;
    }

    if (!spriteIsVisible(sprite)) {
        oamClear(&oamMain, HERO_SPRITE_ID,0);
        return;
    }

    oamRendererRenderHero(spriteX(sprite), spriteY(sprite));
}