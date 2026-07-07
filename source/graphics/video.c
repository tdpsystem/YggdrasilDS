#include "graphics/video.h"
#include "util/debug.h"

void videoInit(void) {
    videoSetMode(MODE_0_2D | DISPLAY_SPR_ACTIVE | DISPLAY_BG0_ACTIVE);
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankG(VRAM_G_MAIN_SPRITE);
}

void videoBeginFrame(void) {
}

void videoEndFrame(void) {
    swiWaitForVBlank();
}

void videoClearConsole(void) {
    debugClear();
}
