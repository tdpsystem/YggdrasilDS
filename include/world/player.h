#ifndef YGG_WORLD_PLAYER_H
#define YGG_WORLD_PLAYER_H

#include "world\entity.h"

typedef struct Player {
    Entity entity;

    int speed;
    int facingX;
    int facingY;
} Player;

void playerInit(Player *player);

void playerUpdate(Player *player);

void playerSetPosition(Player *player, int x, int y);

void playerMove(Player *player, int dx, int dy);

int playerX(const Player *player);

int playerY(const Player *player);

Entity *playerEntity(Player *player);

const Entity *playerEntityConst(const Player *player);

#endif
