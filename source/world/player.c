#include "world/player.h"

#include <stddef.h>

#include <nds.h>

#include "world/collision.h"

#include "input/input.h"

#include "util/debug.h"

void playerInit(Player *player) {
    if (player == NULL) {
        return;
    }

    entityInit(&player->entity, 0, ENTITY_TYPE_PLAYER);

    player->speed = 1;
    player->facingX = 0;
    player->facingY = 1;

    entitySetSize(&player->entity, 16, 16);
    entitySetPosition(&player->entity, 120, 88);
}

void playerUpdate(Player *player, const TileMap *tileMap)
{
    if (player == NULL || tileMap == NULL)
    {
        return;
    }

    int dx = 0;
    int dy = 0;

    if (inputIsHeld(KEY_LEFT))
    {
        dx -= player->speed;
        player->facingX = -1;
        player->facingY = 0;
    }

    if (inputIsHeld(KEY_RIGHT))
    {
        dx += player->speed;
        player->facingX = 1;
        player->facingY = 0;
    }

    if (inputIsHeld(KEY_UP))
    {
        dy -= player->speed;
        player->facingX = 0;
        player->facingY = -1;
    }

    if (inputIsHeld(KEY_DOWN))
    {
        dy += player->speed;
        player->facingX = 0;
        player->facingY = 1;
    }

    if (dx != 0 || dy != 0)
    {
        collisionMoveEntity(
            tileMap,
            &player->entity,
            dx,
            dy
        );
    }

    entityUpdate(&player->entity);
}

void playerSetPosition(Player *player, int x, int y) {
    if (player == NULL) {
        return;
    }

    entitySetPosition(&player->entity, x, y);
}

void playerMove(Player *player, int dx, int dy) {
    if (player == NULL) {
        return;
    }

    entityMove(&player->entity, dx, dy);
}

int playerX(const Player *player) {
    if (player == NULL) {
        return 0;
    }

    return entityX(&player->entity);
}

int playerY(const Player *player) {
    if (player == NULL) {
        return 0;
    }

    return entityY(&player->entity);
}

Entity *playerEntity(Player *player) {
    if (player == NULL) {
        return NULL;
    }
    return &player->entity;
}

const Entity *playerEntityConst(const Player *player) {
    if (player == NULL) {
        return NULL;
    }

    return &player->entity;
}
