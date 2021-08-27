#include <string.h>
#include "core.h"

char x, y, vx, vy, px, bricks[120], attached;

void core_reset_paddle(void) {
    x = 12;
    y = 18;
    px = 12;
    vx = 0;
    vy = -1;
    attached = 1;
}

void core_reset(void) {
    core_reset_paddle();
    memset(bricks, 1, 120);
}

void core_move_paddle(char dir) {
    char nx = px + dir;
    if (nx < 2 || nx > 22) {
        return;
    }
    px += dir;
    if (attached) {
        x += dir;
    }
}

void core_proceed(void) {

}
