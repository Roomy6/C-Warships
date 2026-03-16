#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#include "shipUtil.h"
#include "board.h"
#include "playerUtil.h"

/* TODO
 * Board X/Y selection
 * Implement char input
 * X/Y char placement
 * Title
 */

enum icon boardP[BOARD_X][BOARD_Y];
enum icon boardE[BOARD_X][BOARD_Y];
enum icon player[BOARD_X][BOARD_Y];
enum icon enemy[BOARD_X][BOARD_Y];

/*
 * https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/windows.html#WINDOWBASICS
 */

int boardWinY, boardWinX;

WINDOW *boardWin()
{
    int height, width;
    getmaxyx(stdscr, height, width);
    
    boardWinY = (height - BOARD_Y) / 2;
    boardWinX = (width - BOARD_X) / 2;

    WINDOW *board_win = newwin(BOARD_Y, BOARD_X,
            boardWinY, boardWinX);

    wrefresh(board_win);
    box(board_win, 0, 0);
    return board_win;
}

WINDOW *boardTitle(WINDOW *board_win)
{
    int height, width;
    getmaxyx(stdscr, height, width);

    return board_win;
}

WINDOW *boardGameInfo(WINDOW *board_win)
{
    int height, width;
    getmaxyx(stdscr, height, width);

    WINDOW *boardGameInfo_win = newwin(INFO_Y, INFO_X,
            boardWinY, boardWinX + BOARD_X + WIN_PADDING);
    
    mvprintw(0, 0, "X:%d Y:%d", boardWinX, boardWinY);

    wrefresh(boardGameInfo_win);
    box(boardGameInfo_win, 0, 0);
    return boardGameInfo_win;
}

void initFleet()
{
}

void initBoard(WINDOW *board_win)
{
    initFleet();

    int height, width;
    getmaxyx(board_win, height, width);

    /* Draw coords */
    for(int col = 0; col < BOARD_SIZE; col++)
        mvwprintw(board_win, 1, col * 2 + 3, "%c", 'A' + col);

    for(int row = 0; row < BOARD_SIZE; row++)
        mvwprintw(board_win, row + 2, 1, "%d", row);

    for(int y = 2; y < height - 1; y++)
    {
        for(int x = 3; x < width - 1; x += 2)
        {
            mvwaddch(board_win, y, x, WATER);
        }
    }

    wrefresh(board_win);
}

void updateBoard(WINDOW *board_win)
{    
    mvwprintw(board_win, 0, 1, "Board Game");
    wrefresh(board_win);
}

void updateBoardInfo(WINDOW *boardGameInfo_win)
{
    mvwprintw(boardGameInfo_win, 0, 1, "Board Info");
    mvwprintw(boardGameInfo_win, 1, 1, "Size: %d", BOARD_SIZE);
    mvwprintw(boardGameInfo_win, 2, 1, "Selec: X:%d, Y:%d", selec.x, selec.y);

    for(int i = 1; i < INFO_X - 1; i++)
        mvwprintw(boardGameInfo_win, 3, i, "-");

    mvwprintw(boardGameInfo_win, 4, 1, "Ships: %d", BOARD_SIZE);
    mvwprintw(boardGameInfo_win, 5, 1, "Hits: %d", BOARD_SIZE);
    wrefresh(boardGameInfo_win);
}

void drawIcon(enum icon board[BOARD_X][BOARD_Y], enum icon ico, int x, int y)
{
   if(x < 0 || x >= BOARD_X) return;
   if(y < 0 || y >= BOARD_Y) return;

   board[x][y] = ico;
}
