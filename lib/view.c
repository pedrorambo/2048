#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../config.h"
#include "tableLogic.h"
#include "tablePlays.h"

WINDOW *win = NULL;

void drawBlockPiece(WINDOW *win, int y, int x, int value)
{
    wattron(win, COLOR_PAIR(2));

    if (value == 0)
        return;

    for (int l = x; l < (x + 5); l++)
    {
        for (int c = y; c < (y + 10); c++)
        {
            wmove(win, l, c);
            waddch(win, ' ');
        }
    }

    wmove(win, (x + 2), (y + 3));
    wprintw(win, "%4d", value);
}

void drawTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    wclear(win);

    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            drawBlockPiece(win, (c * 10), (l * 5), table[l][c]);
        }
    }
    wrefresh(win);
}

void initView()
{
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();

    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, COLOR_RED);

    win = newwin(100, 100, 0, 0);
    wrefresh(win);
}

int getNextKey()
{
    int ch = wgetch(win);

    wmove(win, 0, 42);
    wprintw(win, "Tecla: %d ", ch);
    wrefresh(win);

    return ch;
}

void destroyView()
{
    endwin();
}