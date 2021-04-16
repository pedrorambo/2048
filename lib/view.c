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

    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(10, 925, 941, 945);//white
    init_color(11, 776, 780, 670);//cream-white
    init_color(12, 952, 698, 478);//8-orange
    init_color(13, 964, 588, 392);//16-orange
    init_color(14, 968, 486, 372);//32-red
    init_color(15, 968, 372, 231);//64-red
    init_color(16, 929, 815, 450);//128-yellow
    init_color(17, 929, 800, 380);//256-yellow
    init_color(18, 929, 823, 474);//512-yellow
    init_color(19, 929, 772, 247);//1024-yellow
    init_color(20, 556, 266, 678);//2048-purple

    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, 20);//testbench
    init_pair(10, COLOR_BLACK, 10);
    init_pair(11, COLOR_BLACK, 11);
    init_pair(12, COLOR_BLACK, 12);
    init_pair(13, COLOR_BLACK, 13);
    init_pair(14, COLOR_BLACK, 14);
    init_pair(15, COLOR_BLACK, 15);
    init_pair(16, COLOR_BLACK, 16);
    init_pair(17, COLOR_BLACK, 17);
    init_pair(18, COLOR_BLACK, 18);
    init_pair(19, COLOR_BLACK, 19);
    init_pair(20, COLOR_BLACK, 20);


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