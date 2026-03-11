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
    noecho();
    curs_set(0);

    running = true;
    initBoard();
    drawIcon(boardE, MISS, 3, 1);

    /* Leaving a space at the begining removes
     * any whitespace from returning, but string
     * input does not require it (maybe)
     * 9%s prevents the 10 byte buffer limit */
    //scanf("%9s", guess);

    /* Remove buffer to prevent overflow to other
     * scanf functions */
//    int c;
//    while ((c = getchar()) != '\n' && c != EOF);

//  if (!strcmp(guess, "quit") ||
//          !strcmp(guess, "q")) return 1;

    //      printf("guess: %s\n", guess);

    /* Concatinate rX & rY into buffer */
    char buffer[10];

    /* Convert the rX coord to a
     * alphabet representitive */
    //char letter = 'A' + rX;
    //sprintf(buffer, "%c%d", letter, rY);
    //      printf("buffer: %s\n", buffer);

    /* This code can be reused as a check if the
     * player has hit a terget or not */
//  if(!strcmp(guess, buffer))
//  {
//      printf("Correct!\n");
//  } else printf("Wrong!\n");

    /* Reset the buffer to all 0's */
    memset(buffer, 0, sizeof(buffer));

    getch();
    endwin();
    return 0;
}
