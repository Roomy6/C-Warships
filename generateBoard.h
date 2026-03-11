#include <stdio.h>
#include <ncurses.h>

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
#define BOARD_Y 6

enum icon boardP[BOARD_X][BOARD_Y];
enum icon boardE[BOARD_X][BOARD_Y];
enum icon player[BOARD_X][BOARD_Y];
enum icon enemy[BOARD_X][BOARD_Y];

void initBoard()
{
    printf("Draw Board\n");
    /* Print Header */
    printf("\n   ");
    for(int x = 0; x < BOARD_X; x++)
        printf("%c ", 'A' + x);

    printf("|   ");
    for(int x = 0; x < BOARD_X; x++)
        printf("%c ", 'A' + x);

    printf("\n");

    /* Print board */
    for(int y = 0; y < BOARD_Y; y++)
    {
        if(y >= 10) { printf("%d ", y); }
        else printf(" %d ", y);

        for(int x = 0; x < BOARD_X; x++)
        {
            /* Draw the player board */
            printf("%c ", boardP[x][y] = EMPTY);
        }

        /* Seperator only works if
         * the board is empty, and since
         * it's initalised with water we don't
         * need it */

        /* Seperator */
//      for(int x = 0; x < BOARD_X; x++)
//          printf(" ");

        printf("|");

        if(y >= 10) { printf("%d ", y); }
        else printf(" %d ", y);

        for(int x = 0; x < BOARD_X; x++)
        {
            /* Draw the enemy board */
            printf("%c ", boardE[x][y]);
        }

        printf("\n");
    }
}

void updateBoard()
{
    for(int y = 0; y < BOARD_Y; y++)
    {
        for(int x = 0; x < BOARD_X; x++)
        {
            /* Draw the icons */
            boardP[x][y];
            boardE[x][y];
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
