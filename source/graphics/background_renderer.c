#include "graphics/background_renderer.h"

#include <nds.h>
#include <stddef.h>

static int bgId = -1;

void backgroundRendererInit(void)
{
    videoSetMode(MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_SPR_ACTIVE);

    vramSetBankA(VRAM_A_MAIN_BG);

    bgId = bgInit(
        0,
        BgType_Text8bpp,
        BgSize_T_256x256,
        0,
        1
    );
}

void backgroundRendererShutdown(void)
{
}

void backgroundRendererBeginFrame(void)
{
}

void backgroundRendererRenderTileMap(
    const TileMap *tileMap,
    const Camera *camera)
{
    if (tileMap == NULL || camera == NULL)
    {
        return;
    }

    /*
        TODO

        1. Convert world position to tile coordinates.

        2. Determine visible tiles.

        3. Copy visible map section into BG map memory.

        4. Scroll background using:

            bgSetScroll(bgId,
                        cameraX(camera),
                        cameraY(camera));
    */

    bgSetScroll(
        bgId,
        cameraX(camera),
        cameraY(camera)
    );
}

void backgroundRendererEndFrame(void)
{
    bgUpdate();
}