#ifndef YGG_GRAPHICS_CAMERA_H
#define YGG_GRAPHICS_CAMERA_H

#include <nds.h>

typedef struct Camera {
    int x;
    int y;

    int targetX;
    int targetY;

    int minX;
    int minY;
    int maxX;
    int maxY;
} Camera;

void cameraInit(Camera *camera);
void cameraSetPosition(Camera *camera, int x, int y);
void cameraSetTarget(Camera *camera, int x, int y);
void cameraSetBounds(Camera *camera, int minX, int minY, int maxX, int maxY);

void cameraUpdate(Camera *camera);

int cameraX(const Camera *camera);
int cameraY(const Camera *camera);

#endif