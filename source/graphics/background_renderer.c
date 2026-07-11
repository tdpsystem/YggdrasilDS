#include "graphics/background_renderer.h"

#include <nds.h>
#include <stddef.h>

#include "generated/terrain_tiles.h"

#define TILESET_META_COLUMNS  8
#define TILESET_HW_COLUMNS   16

#define MAP_LOGICAL_WIDTH    32
#define MAP_LOGICAL_HEIGHT   32

#define MAP_HW_WIDTH         64
#define MAP_HW_HEIGHT        64

#define YGG_BG_TILE_BASE 0
#define YGG_BG_MAP_BASE  8

static int bgId = -1;
static bool mapUploaded = false;

static void uploadLogicalMap(const TileMap *tileMap)
{
    if (tileMap == NULL || bgId < 0)
    {
        return;
    }

    u16 *bgMap = bgGetMapPtr(bgId);

    if (bgMap == NULL)
    {
        return;
    }

    /*
     * Clear all four 32x32 screen blocks used by a 512x512
     * text background.
     */
    dmaFillHalfWords(
        0,
        bgMap,
        MAP_HW_WIDTH * MAP_HW_HEIGHT * sizeof(u16)
    );

    for (int logicalY = 0;
         logicalY < MAP_LOGICAL_HEIGHT;
         logicalY++)
    {
        for (int logicalX = 0;
             logicalX < MAP_LOGICAL_WIDTH;
             logicalX++)
        {
            int gid = tileMapGet(
                tileMap,
                logicalX,
                logicalY
            );

            /*
             * Tiled GIDs:
             *   0 = empty
             *   1 = first logical 16x16 tile
             *
             * Mannheim currently has grass beneath every overlay,
             * so an unexpected zero can safely fall back to tile 1.
             */
            if (gid <= 0)
            {
                gid = 1;
            }

            int metaTile = gid - 1;

            int metaX =
                metaTile % TILESET_META_COLUMNS;

            int metaY =
                metaTile / TILESET_META_COLUMNS;

            /*
             * The source sheet is 128 pixels wide:
             *
             *   128 / 8 = 16 hardware tiles per row.
             *
             * Each logical 16x16 tile is composed of four
             * 8x8 Nintendo DS background tiles.
             */
            int topLeftTile =
                (metaY * 2 * TILESET_HW_COLUMNS) +
                (metaX * 2);

            int hwX = logicalX * 2;
            int hwY = logicalY * 2;

            /*
             * A 512x512 text BG is divided into four 32x32
             * screen blocks. We cannot address it as one flat
             * 64x64 array, so convert each coordinate to its
             * screen-block location.
             */
            int screenBlockX = hwX / 32;
            int screenBlockY = hwY / 32;

            int localX = hwX % 32;
            int localY = hwY % 32;

            int screenBlock =
                screenBlockY * 2 +
                screenBlockX;

            int mapIndex =
                screenBlock * 32 * 32 +
                localY * 32 +
                localX;

            /*
             * Every logical tile starts at an even hardware
             * coordinate, so its 2x2 entries never cross a
             * screen-block boundary.
             */
            bgMap[mapIndex] =
                topLeftTile;

            bgMap[mapIndex + 1] =
                topLeftTile + 1;

            bgMap[mapIndex + 32] =
                topLeftTile + TILESET_HW_COLUMNS;

            bgMap[mapIndex + 33] =
                topLeftTile +
                TILESET_HW_COLUMNS +
                1;
        }
    }
}

void backgroundRendererInit(void)
{
    videoSetMode(
        MODE_0_2D |
        DISPLAY_BG0_ACTIVE |
        DISPLAY_SPR_ACTIVE
    );

    vramSetBankA(VRAM_A_MAIN_BG);

    bgId = bgInit(
    0,
    BgType_Text8bpp,
    BgSize_T_512x512,
    YGG_BG_MAP_BASE,
    YGG_BG_TILE_BASE
);

    if (bgId < 0)
    {
        return;
    }

    dmaCopy(
        terrain_tilesTiles,
        bgGetGfxPtr(bgId),
        terrain_tilesTilesLen
    );

    dmaCopy(
        terrain_tilesPal,
        BG_PALETTE,
        terrain_tilesPalLen
    );

    mapUploaded = false;
}

void backgroundRendererShutdown(void)
{
    bgId = -1;
    mapUploaded = false;
}

void backgroundRendererBeginFrame(void)
{
}

void backgroundRendererRenderTileMap(
    const TileMap *tileMap,
    const Camera *camera
)
{
    if (
        tileMap == NULL ||
        camera == NULL ||
        bgId < 0
    )
    {
        return;
    }

    /*
     * Mannheim is static for this test, so upload it once.
     * Set mapUploaded back to false whenever maps change.
     */
    if (!mapUploaded)
    {
        uploadLogicalMap(tileMap);
        mapUploaded = true;
    }

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