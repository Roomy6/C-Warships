#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "boardUtil.h"
#include "playerUtil.h"

/* Input command */
char command;

bool running = false;
bool gameOver = false;

int main()
{
    initscr();          /* Init ncurses */
    noecho();           /* No terminal LOG */
    cbreak();           /* Disable line buffering */
//  curs_set(0);        /* Set cursor invisible */
   
    WINDOW *board_win;
    board_win = boardWin();

    keypad(board_win, TRUE);

    refresh();

    initBoard(board_win);
   
    running = true;
    while(running)
    {
        /* REMINDER
         * input -> update -> draw
         */
        moveSelection(board_win, running);
        wrefresh(board_win);
        updateBoard(board_win);

        refresh();
    }

    delwin(board_win);
    endwin();
    return 0;
}
