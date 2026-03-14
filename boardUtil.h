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

enum icon boardP[BOARD_X][BOARD_Y];
enum icon boardE[BOARD_X][BOARD_Y];
enum icon player[BOARD_X][BOARD_Y];
enum icon enemy[BOARD_X][BOARD_Y];

void initBoard()
{
    /* Print Header */
    clear();
    for(int x = 0; x < BOARD_X; x++)
        mvprintw(0, x*2+3, "%c ", 'A' + x);

    /* Print board */
    for(int y = 0; y < BOARD_Y; y++)
    {
        if(y >= 10) { mvprintw(y+1, 0, "%2d", y); }
        else mvprintw(y+1, 0, "%2d ", y);

        for(int x = 0; x < BOARD_X; x++)
        {
            /* Draw the player board */
            mvprintw(y+1, x*2+3, "%c ", boardP[x][y] = WATER);
        }
    }
   
    move(BOARD_Y + 2, 0);
   
    /* Init the fleet with its id's
     * and ship information */
    int id = 0;
    int index = 0;

    for(int t = 0; t < SHIP_TYPE; t++)
    {
        for(int i = 0; i < ships[t].count; i++)
        {
            fleet[index] = ships[t];
            fleet[index].id = id++;
            fleet[index].hits = 0;

            index++;
        }
    }

    fleet[3].x = 5;

    /* Pos set test */
    for(int i = 0; i < MAX_SHIPS; i++)
    {
        printw("%s | ID:%d\nX:%d, Y:%d\n", fleet[i].name, fleet[i].id, fleet[i].x, fleet[i].y);
    }
    
    refresh();
}

void updateBoard()
{
    for(int y = 0; y < BOARD_Y; y++)
    {
        for(int x = 0; x < BOARD_X; x++)
        {
            /* Draw the icons */
            boardP[x][y];
        }
    }
}

void drawIcon(enum icon board[BOARD_X][BOARD_Y], enum icon ico, int x, int y)
{
   if(x < 0 || x >= BOARD_X) return;
   if(y < 0 || x >= BOARD_Y) return;

   board[x][y] = ico;
   updateBoard();
}
