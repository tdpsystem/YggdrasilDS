#ifndef YGG_WORLD_ENTITY_H
#define YGG_WORLD_ENTITY_H

#include <stdbool.h>

#include "graphics/sprite.h"

typedef enum EntityType {
    ENTITY_TYPE_NONE = 0,
    ENTITY_TYPE_PLAYER,
    ENTITY_TYPE_NPC,
    ENTITY_TYPE_OBJECT,
    ENTITY_TYPE_TRIGGER
} EntityType;

typedef struct Entity {
    int id;

    EntityType type;

    int x;
    int y;

    int velocityX;
    int velocityY;

    int width;
    int height;

    bool active;
    bool visible;
    bool solid;

    Sprite sprite;
} Entity;

void entityInit(Entity *entity, int id, EntityType type);

void entitySetPosition(Entity *entity, int x, int y);
void entityMove(Entity *entity, int dx, int dy);

void entitySetVelocity(Entity *entity, int velocityX, int velocityY);
void entityUpdate(Entity *entity);

void entitySetSize(Entity *entity, int width, int height);

void entitySetActive(Entity *entity, bool active);
void entitySetVisible(Entity *entity, bool visible);
void entitySetSolid(Entity *entity, bool solid);

bool entityIsActive(const Entity *entity);
bool entityIsVisible(const Entity *entity);
bool entityIsSolid(const Entity *entity);

int entityX(const Entity *entity);
int entityY(const Entity *entity);
int entityWidth(const Entity *entity);
int entityHeight(const Entity *entity);

Sprite *entitySprite(Entity *entity);
const Sprite *entitySpriteConst(const Entity *entity);

#endif