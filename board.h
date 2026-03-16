#ifndef CONSTANT
#define CONSTANT

enum icon
{
    EMPTY = ' ',
    WATER = '~',
    MISS = '.',
    HIT = '&',

    SHIP = '#'
};

/* This define code is all over the place
 * and would be nice to redefine all of them
 * but its still Alpha so :shrug:
 */

/* Window padding */
#define WIN_PADDING 1

/* Board size */
#define BOARD_SIZE 10

/* The board X/Y size */
#define BOARD_X 23
#define BOARD_Y 13

/* Game info board dimentions */
#define INFO_X 20
#define INFO_Y 11

#endif
