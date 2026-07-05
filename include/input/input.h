#ifndef YGG_INPUT_H
#define YGG_INPUT_H

#include <nds.h>
#include <stdbool.h>

void inputInit(void);
void inputUpdate(void);

u32 inputHeld(void);
u32 inputDown(void);
u32 inputUp(void);

bool inputIsHeld(u32 key);
bool inputIsPressed(u32 key);
bool inputIsReleased(u32 key);

touchPosition inputTouch(void);

#endif