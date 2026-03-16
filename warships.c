#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

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
    curs_set(0);        /* Set cursor invisible */
   
    WINDOW *board_win, *boardGameInfo_win, *boardTitle_win;
    board_win = boardWin();
    boardGameInfo_win = boardGameInfo(board_win);
    boardTitle_win = boardTitle(board_win);

    keypad(board_win, TRUE);

    refresh();

    /* Init and update before loop */
    initBoard(board_win);
    updateBoard(board_win);
    updateBoardInfo(boardGameInfo_win);
    initSelect();

    running = true;
    while(running)
    {
        /* REMINDER
         * input -> update -> draw
         */
        
        /* Input */
        moveSelection(board_win, &running);

        /* Update */
        updateBoard(board_win);
        updateBoardInfo(boardGameInfo_win);

        /* Draw */
        drawSelection(board_win);

        wrefresh(board_win);
        wrefresh(boardGameInfo_win);
    }

    delwin(board_win);
    endwin();
    return 0;
}
