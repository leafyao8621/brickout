#include <unistd.h>
#include <ncurses.h>
#include "controller.h"
#include "../core/core.h"

static void initialize(void) {
    for (int i = 1; i < 23; ++i) {
        for (int j = 0; j < 27; ++j) {
            if (!j || j == 26 || i == 1 || i == 22) {
                mvaddch(i, j, '*');
            } else if (j > 1 && j < 25 && i > 2 && i < 8) {
                mvaddch(i, j, '*');
            }
        }
    }
}

static void clear_paddle(void) {
    mvaddstr(21, px - 1, "     ");
}

static void draw_paddle(void) {
    mvaddstr(21, px - 1, "*****");
}

static void clear_ball(void) {
    mvaddch(y + 2, x + 1, ' ');
}

static void draw_ball(void) {
    mvaddch(y + 2, x + 1, '*');
}

void controller_initialize(void) {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    cbreak();
    nodelay(stdscr, 1);
    core_reset();
    initialize();
    draw_paddle();
    draw_ball();
    mvaddstr(0, 0, "Brickout");
}

void controller_main_loop(void) {
    for (int in = getch(), cond = 1, cont = 0; cond; in = getch()) {
        switch (in) {
        case 'Q':
        case 'q':
            cond = 0;
            break;
        case KEY_LEFT:
        case 'A':
        case 'a':
            clear_paddle();
            if (attached) {
                clear_ball();
            }
            core_move_paddle(-1);
            draw_paddle();
            if (attached) {
                draw_ball();
            }
            break;
        case KEY_RIGHT:
        case 'D':
        case 'd':
            clear_paddle();
            if (attached) {
                clear_ball();
            }
            core_move_paddle(1);
            draw_paddle();
            if (attached) {
                draw_ball();
            }
            break;
        case 'Z':
        case 'z':
        case 'J':
        case 'j':
            attached = 1;
            break;
        }
        if (cont == 30 && !attached) {
            clear_ball();
            core_proceed();
            draw_ball();
        }
        usleep(16667);
    }
}

void controller_finalize(void) {
    nodelay(stdscr, 0);
    clear();
    mvaddstr(0, 0, "Brickout");
    mvaddstr(1, 0, "Game Over");
    getch();
    endwin();
}
