#include <ncurses.h>
#include <stdio.h>

/* Code by Roomy
 * This is an example project
 * to implement basic char movement
 * and a game loop
 */

/* Player structure */
typedef struct Player {
    int x, y;
    char player;
} Player;

/* Player character and init */
#define PLAYER '#'
Player player;

int running;

/* Player movement fnction */
int movePlayer(WINDOW *board_win)
{
    /* Get char input from board_win */
    int ch = wgetch(board_win);
    
    /* get the max X/Y from board_win */
    int max_y, max_x;
    getmaxyx(board_win, max_y, max_x);
 
    /* Player movement and basic collision */
    switch (ch)
    {
        case KEY_LEFT:
            if (player.x > 1)
                player.x--;
            break;

        case KEY_RIGHT:
            if (player.x < max_x - 2)
                player.x++;
            break;

        case KEY_UP:
            if (player.y > 1)
                player.y--;
            break;

        case KEY_DOWN:
            if (player.y < max_y - 2)
                player.y++;
            break;

        case 'q':
            running = 0;
            return 0;
    }
    return 1;
}

/* Init the player */
void initPlayer()
{
    running = 1;

    player.player = PLAYER;
    player.x = 1;
    player.y = 1;
}

/* Player draw function */
void drawPlayer(WINDOW *board_win)
{
    /* Erase the board */
    werase(board_win);
    /* Draw the board_win border */
    box(board_win, 0, 0);

    /* Draw the player */
    mvwaddch(board_win, player.y, player.x,
            player.player);

    /* Move the cursor to player POS */
    wmove(board_win, player.y, player.x);
}

/* Board function */
WINDOW *boardWin()
{
    int width, height;
    getmaxyx(stdscr, height, width);

    WINDOW *board_win = newwin((height / 2),
            (width / 2), 1, 1);

    return board_win;
}

int main()
{
    initscr();      /* Init ncurses */
    initPlayer();   /* Init player */
    clear();        /* Clear console */
    noecho();       /* No logout */
    cbreak();       /* Disable line buffering */
 
    WINDOW *board_win;
    board_win = boardWin();
    
    /* Enable keyboard input for board_win */
    keypad(board_win, TRUE);
    
    /* Refresh the screen */
    refresh();
    
    /* This is here to pre-draw the board
     * to not wait for the loop to do it */
    box(board_win, 0, 0);
    drawPlayer(board_win);
    
    /* "Game" loop */
    while (running)
    {
        movePlayer(board_win);
        wrefresh(board_win);
        drawPlayer(board_win);

        mvprintw(0, 0, "X:%d Y:%d",
                player.x, player.y);
        refresh();
    }
    
    /* Delete the win and end it */
    delwin(board_win);
    endwin();

    return 0;
}

