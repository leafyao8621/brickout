#ifndef _CORE_H_
#define _CORE_H_

extern char x, y, vx, vy, px, bricks[120], attached;

void core_reset_paddle(void);
void core_reset(void);
void core_move_paddle(char dir);
void core_proceed(void);

#endif
