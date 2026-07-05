#include "core/state_machine.h"

#include <stddef.h>

static GameState states[GAME_STATE_COUNT];
static GameStateId currentState = GAME_STATE_BOOT;
static GameStateId nextState = GAME_STATE_BOOT;
static int hasCurrentState = 0;
static int changeRequested = 0;

void stateInit(void)
{
    for (int i = 0; i < GAME_STATE_COUNT; i++)
    {
        states[i].enter = NULL;
        states[i].update = NULL;
        states[i].render = NULL;
        states[i].exit = NULL;
    }

    currentState = GAME_STATE_BOOT;
    nextState = GAME_STATE_BOOT;
    hasCurrentState = 0;
    changeRequested = 0;
}

void stateRegister(GameStateId id, GameState state)
{
    if (id < 0 || id >= GAME_STATE_COUNT)
    {
        return;
    }

    states[id] = state;
}

void stateChange(GameStateId id)
{
    if (id < 0 || id >= GAME_STATE_COUNT)
    {
        return;
    }

    nextState = id;
    changeRequested = 1;
}

static void applyStateChange(void)
{
    if (!changeRequested)
    {
        return;
    }

    GameStateId targetState = nextState;

    changeRequested = 0;

    if (hasCurrentState)
    {
        if (states[currentState].exit != NULL)
        {
            states[currentState].exit();
        }
    }

    currentState = targetState;
    hasCurrentState = 1;

    if (states[currentState].enter != NULL)
    {
        states[currentState].enter();
    }
}

void stateUpdate(void)
{
    while (changeRequested)
    {
        applyStateChange();
    }

    if (!hasCurrentState)
    {
        return;
    }

    if (states[currentState].update != NULL)
    {
        states[currentState].update();
    }

    while (changeRequested)
    {
        applyStateChange();
    }
}

void stateRender(void)
{
    if (!hasCurrentState)
    {
        return;
    }

    if (states[currentState].render != NULL)
    {
        states[currentState].render();
    }
}

GameStateId stateCurrent(void)
{
    return currentState;
}