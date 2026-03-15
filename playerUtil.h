#include <ncurses.h>

int isGameOver(bool running)
{
    return true;
}

int moveSelection(WINDOW *board_win, bool running)
{
    int ch = wgetch(board_win);

    /* Get boards Y/X */
    int b_y, b_x;
    getmaxyx(board_win, b_y, b_x);

    /* Switch case for movement */
    switch (ch) {
        case KEY_LEFT:
            mvprintw(0, 0, "Test.");
            break;
        case 'Q':
        case 'q':
            running = false;
            break;
    }

    return 1;
}
