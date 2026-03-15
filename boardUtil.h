#include <stdio.h>
#include <ncurses.h>
#include "shipUtil.h"

/* TODO
 * Board X/Y selection
 * Implement char input
 * X/Y char placement
 * Title
 */

enum icon
{
    EMPTY = ' ',
    WATER = '~',
    MISS = '.',
    HIT = '&',

    SHIP = '#'
};

/* The board X/Y size */
#define BOARD_X 20
#define BOARD_Y 10
#define BOARD_ORIGIN_X 3
#define BOARD_ORIGIN_Y 1

enum icon boardP[BOARD_X][BOARD_Y];
enum icon boardE[BOARD_X][BOARD_Y];
enum icon player[BOARD_X][BOARD_Y];
enum icon enemy[BOARD_X][BOARD_Y];

/*
 * https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/windows.html#WINDOWBASICS
 */

WINDOW *boardWin()
{
    int height, width;
    getmaxyx(stdscr, height, width);

    WINDOW *board_win = newwin(BOARD_Y, BOARD_X,
            (height - BOARD_Y) / 2, (width - BOARD_X) / 2);

    return board_win;
}

void initFleet()
{
}

void initBoard(WINDOW *board_win)
{
    initFleet();
    box(board_win, 0, 0);
}

void updateBoard(WINDOW *board_win)
{    
}

void drawIcon(enum icon board[BOARD_X][BOARD_Y], enum icon ico, int x, int y)
{
   if(x < 0 || x >= BOARD_X) return;
   if(y < 0 || y >= BOARD_Y) return;

   board[x][y] = ico;
}
