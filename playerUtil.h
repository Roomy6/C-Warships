#include <ncurses.h>
#include "board.h"

#ifndef SELECT
#define SELECT

typedef struct Select {
    int y, x;
    int maxY, maxX;
    int offsetY, offsetX;
} Select;

Select selec;

void initSelect()
{
    selec.maxY = BOARD_Y - 2 + selec.offsetY;
    selec.maxX = BOARD_X - 2 + selec.offsetX;

    selec.offsetY = 2;
    selec.offsetX = 3;

    selec.y = selec.offsetY;
    selec.x = selec.offsetX;
}

int isGameOver(bool *running)
{
}

int moveSelection(WINDOW *board_win, bool *running)
{
    int ch = wgetch(board_win);

    /* Get boards Y/X */
    int b_y, b_x;
    getmaxyx(board_win, b_y, b_x);

    /* Switch case for movement */
    switch (ch) {
        case KEY_UP:
            if(selec.y > selec.offsetY)
                selec.y--;
            mvprintw(1, 0, "Up");
            clrtoeol();
            break;
        case KEY_DOWN:
            if(selec.y < selec.maxY)
                selec.y++;
            mvprintw(1, 0, "Down");
            clrtoeol();
            break;
        case KEY_LEFT:
            if(selec.x > selec.offsetX)
                selec.x -= 2;
            mvprintw(1, 0, "Left");
            clrtoeol();
            break;
        case KEY_RIGHT:
            if(selec.x < selec.maxX)
                selec.x += 2;
            mvprintw(1, 0, "Right");
            clrtoeol();
            break;
        case 'Q':
        case 'q':
            *running = false;
            break;
    }

    return 1;
}

int prevY = -1;
int prevX = -1;

void drawSelection(WINDOW *board_win)
{
    /* Restore previous position */
    if(prevY != -1 && prevX != -1)
    {
        chtype old = mvwinch(board_win, prevY, prevX);
        mvwaddch(board_win, prevY, prevX, old & A_CHARTEXT);
    }

    /* Read the character under the cursor */
    chtype ch = mvwinch(board_win, selec.y, selec.x);

    /* Turn highlighting ON */
    wattron(board_win, A_REVERSE);
    mvwaddch(board_win, selec.y, selec.x, ch & A_CHARTEXT); 
    
    /* Move cursor back to selection POS */
    wmove(board_win, selec.y, selec.x);

    /* Turn highlighting off */
    wattroff(board_win, A_REVERSE);

    /* Save position */
    prevY = selec.y;
    prevX = selec.x;
}

#endif
