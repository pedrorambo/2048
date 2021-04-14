#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "config.h"
#include "lib/prints.h"
#include "lib/utils.h"
#include "lib/tableLogic.h"
#include "lib/tablePlays.h"

void drawBlockPiece(WINDOW *win, int y, int x, int value)
{
	wattron(win, COLOR_PAIR(2));

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

void drawTable(WINDOW *win, int table[4][4])
{
	for (int l = 0; l < 4; l++)
	{
		for (int c = 0; c < 4; c++)
		{
			drawBlockPiece(win, (c * 10), (l * 5), table[l][c]);
		}
	}
}

int main(void)
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);

	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	init_pair(2, COLOR_BLACK, COLOR_RED);

	int table[4][4] = {
		{2, 2, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 4, 0},
		{0, 0, 0, 16},
	};

	WINDOW *win = newwin(100, 100, 0, 0);

	drawTable(win, table);

	wrefresh(win);

	while (TRUE)
	{
	}

	endwin();
}