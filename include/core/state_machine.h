#ifndef YGG_CORE_STATE_H
#define YGG_CORE_STATE_H

typedef enum GameStateId
{
    GAME_STATE_BOOT = 0,
    GAME_STATE_TITLE,
    GAME_STATE_WORLD,
    GAME_STATE_BATTLE,
    GAME_STATE_MENU,
    GAME_STATE_GAME_OVER,
    GAME_STATE_COUNT
} GameStateId;

typedef struct GameState
{
    void (*enter)(void);
    void (*update)(void);
    void (*render)(void);
    void (*exit)(void);
} GameState;

void stateInit(void);
void stateRegister(GameStateId id, GameState state);
void stateChange(GameStateId id);
void stateUpdate(void);
void stateRender(void);

GameStateId stateCurrent(void);

#endif