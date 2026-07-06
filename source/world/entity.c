#include "world/entity.h"

#include <stddef.h>

void entityInit(Entity *entity, int id, EntityType type) {
    if (entity == NULL) {
        return;
    }

    entity->id = id;
    entity->type = type;

    entity->x = 0;
    entity->y = 0;

    entity->velocityX = 0;
    entity->velocityY = 0;

    entity->width = 16;
    entity->height = 16;

    entity->active = true;
    entity->visible = true;
    entity->solid = true;

    spriteInit(&entity->sprite);
    spriteSetSize(&entity->sprite, entity->width, entity->height);
    spriteSetPosition(&entity->sprite, entity->x, entity->y);
    spriteSetVisible(&entity->sprite, entity->visible);
}

void entitySetPosition(Entity *entity, int x, int y) {
    if (entity == NULL) {
        return;
    }

    entity->x = x;
    entity->y = y;

    spriteSetPosition(&entity->sprite, entity->x, entity->y);
}

void entityMove(Entity *entity, int dx, int dy) {
    if (entity == NULL) {
        return;
    }

    entitySetPosition(entity, entity->x + dx, entity->y + dy);
}

void entitySetVelocity(Entity *entity, int velocityX, int velocityY) {
    if (entity == NULL) {
        return;
    }

    entity->velocityX = velocityX;
    entity->velocityY = velocityY;
}

void entityUpdate(Entity *entity) {
    if (entity == NULL || !entity->active) {
        return;
    }

    entityMove(entity, entity->velocityX, entity->velocityY);
}

void entitySetSize(Entity *entity, int width, int height) {
    if (entity == NULL) {
        return;
    }

    if (width <= 0 || height <= 0) {
        return;
    }

    entity->width = width;
    entity->height = height;

    spriteSetSize(&entity->sprite, entity->width, entity->height);
}

void entitySetActive(Entity *entity, bool active) {
    if (entity == NULL) {
        return;
    }

    entity->active = active;
}

void entitySetVisible(Entity *entity, bool visible) {
    if (entity == NULL) {
        return;
    }

    entity->visible = visible;

    spriteSetVisible(&entity->sprite, visible);
}

void entitySetSolid(Entity *entity, bool solid) {
    if (entity == NULL) {
        return;
    }

    entity->solid = solid;
}

bool entityIsActive(const Entity *entity) {
    return entity != NULL && entity->active;
}

bool entityIsVisible(const Entity *entity) {
    return entity != NULL && entity->visible;
}

bool entityIsSolid(const Entity *entity) {
    return entity != NULL && entity->solid;
}

int entityX(const Entity *entity) {
    return entity == NULL ? 0 : entity->x;
}

int entityY(const Entity *entity) {
    return entity == NULL ? 0 : entity->y;
}

int entityWidth(const Entity *entity) {
    return entity == NULL ? 0 : entity->width;
}

int entityHeight(const Entity *entity) {
    return entity == NULL ? 0 : entity->height;
}

Sprite *entitySprite(Entity *entity) {
    if (entity == NULL) {
        return NULL;
    }

    return &entity->sprite;
}

const Sprite *entitySpriteConst(const Entity *entity) {
    if (entity == NULL) {
        return NULL;
    }

    return &entity->sprite;
}
