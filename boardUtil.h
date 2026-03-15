#include <stdio.h>
#include <ncurses.h>
#include "shipUtil.h"

/* TODO
 * Implement char input
 * X/Y char placement
 * Two boars for player and enemy
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
#define BOARD_X 10
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

    WINDOW *board_win = newwin(height, width,
            1, 1);

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

/* Char placement helper */
void board_addch(int x, int y, char c)
{
    int sx = BOARD_ORIGIN_X + x * 2;
    int sy = BOARD_ORIGIN_Y + y;
    
    /* Should prob invert X/Y becuase ncurses xD */
    mvaddch(sy, sx, c);
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
