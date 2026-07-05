#include "graphics\camera.h"

static int clampInt(int value, int minValue, int maxValue) {
    if (value < minValue) {
        return minValue;
    }
    if (value > maxValue) {
        return maxValue;
    }
    return value;
}

void cameraInit(Camera *camera) {
    if (camera == NULL) {
        return;
    }

    camera->x = 0;
    camera->y = 0;

    camera->targetX = 0;
    camera->targetY = 0;

    camera->minX = 0;
    camera->minY = 0;
    camera->maxX = 0;
    camera->maxY = 0;
}

void cameraSetPosition(Camera *camera, int x, int y) {
    if (camera == NULL) {
        return;
    }

    camera->x = clampInt(x, camera->minX, camera->maxX);
    camera->y = clampInt(y, camera->minY, camera->maxY);

    camera->targetX = camera->x;
    camera->targetY = camera->y;
}

void cameraSetTarget(Camera *camera, int x, int y) {
    if (camera == NULL) {
        return;
    }

    camera->targetX = clampInt(x, camera->minX, camera->maxX);
    camera->targetY = clampInt(y, camera->minY, camera->maxY);
}

void cameraSetBounds(Camera *camera, int minX, int minY, int maxX, int maxY) {
    if (camera == NULL) {
        return;
    }

    camera->minX = minX;
    camera->minY = minY;
    camera->maxX = maxX;
    camera->maxY = maxY;

    camera->x = clampInt(camera->x, minX, camera->maxX);
    camera->y = clampInt(camera->y, minY, camera->maxY);

    camera->targetX = clampInt(camera->targetX, camera->minX, camera->maxX);
    camera->targetY = clampInt(camera->targetY, camera->minY, camera->maxY);
}

void cameraUpdate(Camera *camera) {
    if (camera == NULL) {
        return;
    }

    if (camera->x < camera->targetX) {
        camera->x++;
    }
    else if (camera->x > camera->targetX) {
        camera->x--;
    }
    if (camera->y < camera->targetY) {
        camera->y++;
    }
    else if (camera->y > camera->targetY) {
        camera->y--;
    }
}

int cameraX(const Camera *camera) {
    if (camera == NULL) {
        return 0;
    }
    return camera->x;
}

int cameraY(const Camera *camera) {
    if (camera == NULL) {
        return 0;
    }
    return camera->y;
}