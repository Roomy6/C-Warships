#include <stdio.h>
#include <stdlib.h>

#define MAX_SHIP_SIZE 5
#define MAX_SHIPS 10

struct ship
{
    const char *name;       /* Ship name */
    int size;               /* Type ship size */
    int count;              /* Total # of type ship */

    int id;
    int x;                  /* X Pos */
    int y;                  /* Y Pos */

    int hits;               /* # of hits on ship */
};

enum ship_type
{
    CARRIER,
    BATTLESHIP,
    CRUISER,
    SUBMARINE,
    DESTROYER,

    SHIP_TYPE
};

struct ship ships[SHIP_TYPE] =
{
    /* TYPE | SIZE COUNT */
    [CARRIER]       = { "Carrier", 5, 1 },
    [BATTLESHIP]    = { "Battleship", 4, 2 },
    [CRUISER]       = { "Cruiser", 3, 2 },
    [SUBMARINE]     = { "Submarine", 3, 1 },
    [DESTROYER]     = { "Destroyer", 2, 4 }
};

/* Trying to implement a id function
 * to the ships to reference them
 * seperately, this is a unique
 * challenge hah */
struct ship fleet[MAX_SHIPS];

struct ship* get_ship_by_id(int id)
{
    for(int i = 0; i < MAX_SHIPS; i++)
    {
        if(fleet[i].id == id)
            return &fleet[i];
    }
    return NULL;
}

void place_ship(struct ship *s)
{
    int placed = 0;

    while(!placed)
    {
        /* TODO
         * Replace the board size to the defined variable
         * this causes a loop feedback thing causing many
         * errors so idk how to fix that.
         * 
         * AND
         *
         * Implement random seed. */

        int dir = rand() % 2;   /* 0 = horizontal, 1 = vertical */
        int startX = rand() % 10;
        int startY = rand() % 10;

        int valid = 1;

        for(int i = 0; i < s->size; i++)
        {
            int x = startX + (dir == 0 ? i : 0);
            int y = startY + (dir == 1 ? i : 0);

            /* Check board limits */
            if(x >= 10 || y >= 10)
            {
                valid = 0;
                break;
            }

            /* Check collision */
            /*
            if(is_occupied(x, y))
            {
                valid = 0;
                break;
            }
            */
        }

        if(!valid)
            continue;

        /* Write coordinates */
        for(int i = 0; i < s->size; i++)
        {
            s->x = startX + (dir == 0 ? i : 0);
            s->y = startY + (dir == 1 ? i : 0);
        }

        placed = 1;
    }
}
