#include <nds.h>

#include "core/engine.h"

int main(void) {
    engineInit();

    while (engineIsRunning()) {
        engineUpdate();
        engineRender();
    }

    return 0;
}
