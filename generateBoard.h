#include <stdio.h>

/* TODO
 * Implement char input
 * X/Y char placement
 * Two boars for player and enemy
 */

enum icon
{
    EMPTY = ' ',
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
            printf("%c ", boardP[x][y]);
        }

        /* Seperator */
        for(int x = 0; x < BOARD_X; x++)
            printf(" ");

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
