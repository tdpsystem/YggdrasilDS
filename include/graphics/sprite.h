#ifndef YGG_GRAPHICS_SPRITE_H
#define YGG_GRAPHICS_SPRITE_H

#include <nds.h>
#include <stdbool.h>

typedef enum SpriteFlip {
    SPRITE_FLIP_NONE = 0,
    SPRITE_FLIP_HORIZONTAL,
    SPRITE_FLIP_VERTICAL,
    SPRITE_FLIP_BOTH
} SpriteFlip;

typedef struct Sprite {
    int x;
    int y;

    int width;
    int height;

    int frame;
    int frameCount;

    bool visible;
    SpriteFlip flip;
} Sprite;

void spriteInit(Sprite *sprite);
void spriteSetPosition(Sprite *sprite, int x, int y);
void spriteMove(Sprite *sprite, int dx, int dy);
void spriteSetSize(Sprite *sprite, int width, int height);

void spriteSetFrame(Sprite *sprite, int frame);
void spriteSetFrameCount(Sprite *sprite, int frameCount);

void spriteSetVisible(Sprite *sprite, bool visible);
void spriteSetFlip(Sprite *sprite, SpriteFlip flip);

int spriteX(const Sprite *sprite);
int spriteY(const Sprite *sprite);
int spriteWidth(const Sprite *sprite);
int spriteHeight(const Sprite *sprite);
int spriteFrame(const Sprite *sprite);

bool spriteIsVisible(const Sprite *sprite);

#endif
