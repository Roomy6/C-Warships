
struct ship
{
    const char *name;
    int count;
    int size;
};

enum shipType
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
