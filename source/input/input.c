#include "input/input.h"

static touchPosition touch;
static u32 held = 0;
static u32 down = 0;
static u32 up = 0;

void inputInit(void) {
    held = 0;
    down = 0;
    up = 0;

    touchRead(&touch);
}

void inputUpdate(void) {
    scanKeys();

    held = keysHeld();
    down = keysDown();
    up = keysUp();

    touchRead(&touch);
}

u32 inputHeld(void) {
    return held;
}

u32 inputDown(void) {
    return down;
}

u32 inputUp(void) {
    return up;
}

bool inputIsHeld(u32 key) {
    return (held & key) != 0;
}

bool inputIsPressed(u32 key) {
    return (down & key) != 0;
}

bool inputIsReleased(u32 key) {
    return (up & key) != 0;
}

touchPosition inputTouch(void) {
    return touch;
}
