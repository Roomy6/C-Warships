
#define MAX_SHIP_SIZE 5
#define MAX_SHIPS 8

struct ship
{
    const char *name;       /* Ship name */
    int count;              /* Total # of type ship */
    int size;               /* Type ship size */

    int id;
    int x[MAX_SHIP_SIZE];   /* X Pos */
    int y[MAX_SHIP_SIZE];   /* Y Pos */

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
    return fleet;
}

/* Implementation example
 int id = 0;
 int index = 0;

 for(int t = 0; t < SHIP_TYPE; t++)
 {
 for(int i = 0; i < ship_types[t].count; i++)
 {
 fleet[index].id = id++;
 fleet[index].type = &ship_types[t];
 fleet[index].hits = 0;

 index++;
 }
 }
*/
