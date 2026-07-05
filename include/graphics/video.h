#ifndef YGG_VIDEO_H
#define YGG_VIDEO_H

#include <nds.h>

void videoInit(void);

void videoBeginFrame(void);
void videoEndFrame(void);

void videoClearConsole(void);

#endif