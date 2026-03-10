#include <stdio.h>

enum icon
{
    EMPTY = ' ',
    MISS = '.',
    HIT = '&',

    SHIP = '#'
};

/* The board X/Y size */
#define BOARD_X 15
#define BOARD_Y 10

enum icon board[BOARD_X][BOARD_Y];

void initBoard()
{
    /* Print Header */
    printf("\n   ");
    for(int x = 0; x < BOARD_X; x++)
    {
        printf("%c ", 'A' + x);
    }
    printf("\n");

    /* Print board */
    for(int y = 0; y < BOARD_Y; y++)
    {
        if(y >= 10) { printf("%d ", y); }
        else
            printf(" %d ", y);

        for(int x = 0; x < BOARD_X; x++)
        {
            /* ADD SWITCH FOR DRAW TYPES */
            board[x][y] = EMPTY;
        }
        printf("\n");
    }
}
