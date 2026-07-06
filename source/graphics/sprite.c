#include "graphics/sprite.h"

#include <stddef.h>
#include <stdbool.h>

void spriteInit(Sprite *sprite) {
    if (sprite == NULL) {
        return;
    }

    sprite->x = 0;
    sprite->y = 0;

    sprite->width = 16;
    sprite->height = 16;

    sprite->frame = 0;
    sprite->frameCount = 1;

    sprite->visible = true;
    sprite->flip = SPRITE_FLIP_NONE;
}

void spriteSetPosition(Sprite *sprite, int x, int y) {
    if (sprite == NULL) {
        return;
    }

    sprite->x = x;
    sprite->y = y;
}

void spriteMove(Sprite *sprite, int dx, int dy) {
    if (sprite == NULL) {
        return;
    }

    sprite->x += dx;
    sprite->y += dy;
}

void spriteSetSize(Sprite *sprite, int width, int height) {
    if (sprite == NULL) {
        return;
    }

    if (width <= 0 || height <= 0) {
        return;
    }

    sprite->width = width;
    sprite->height = height;
}

void spriteSetFrame(Sprite *sprite, int frame) {
    if (sprite == NULL) {
        return;
    }

    if (frame < 0) {
        frame = 0;
    }

    if (frame >= sprite->frameCount) {
        frame = sprite->frameCount - 1;
    }

    sprite->frame = frame;
}

void spriteSetFrameCount(Sprite *sprite, int frameCount) {
    if (sprite == NULL) {
        return;
    }

    if (frameCount <= 0) {
        frameCount = 1;
    }

    sprite->frameCount = frameCount;

    if (sprite->frame >= sprite->frameCount) {
        sprite->frame = sprite->frameCount - 1;
    }
}

void spriteSetVisible(Sprite *sprite, bool visible) {
    if (sprite == NULL) {
        return;
    }

    sprite->visible = visible;
}

void spriteSetFlip(Sprite *sprite, SpriteFlip flip) {
    if (sprite == NULL) {
        return;
    }

    sprite->flip = flip;
}

int spriteX(const Sprite *sprite) {
    return sprite == NULL ? 0 : sprite->x;
}

int spriteY(const Sprite *sprite) {
    return sprite == NULL ? 0 : sprite->y;
}

int spriteWidth(const Sprite *sprite) {
    return sprite == NULL ? 0 : sprite->width;
}

int spriteHeight(const Sprite *sprite) {
    return sprite == NULL ? 0 : sprite->height;
}

int spriteFrame(const Sprite *sprite) {
    return sprite == NULL ? 0 : sprite->frame;
}

bool spriteIsVisible(const Sprite *sprite) {
    return sprite != NULL && sprite->visible;
}
