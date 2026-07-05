#include "core/game.h"
#include "core/state_machine.h"

#include "core/states/battle_state.h"
#include "core/states/boot_state.h"
#include "core/states/menu_state.h"
#include "core/states/title_state.h"
#include "core/states/world_state.h"

void gameInit(void)
{
    stateInit();

    stateRegister(GAME_STATE_BOOT, bootStateCreate());
    stateRegister(GAME_STATE_TITLE, titleStateCreate());
    stateRegister(GAME_STATE_WORLD, worldStateCreate());
    stateRegister(GAME_STATE_BATTLE, battleStateCreate());
    stateRegister(GAME_STATE_MENU, menuStateCreate());

    stateChange(GAME_STATE_TITLE);
}

void gameUpdate(void)
{
    stateUpdate();
}

void gameRender(void)
{
    stateRender();
}
