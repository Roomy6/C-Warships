#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "boardUtil.h"

/* Input command */
char command;

bool running = false;
bool gameOver = false;

int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);

    initBoard();
    
    while(1)
        initBoard();

    getch();
    endwin();
    return 0;
}
