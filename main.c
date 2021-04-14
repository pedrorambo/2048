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

	for (int l = 0; l < 5; l++)
	{
		for (int c = 0; c < 10; c++)
		{
			wmove(win, l, c);
			waddch(win, ' ');
		}
	}

	wattron(win, COLOR_PAIR(1));
	wmove(win, 2, 3);
	wprintw(win, "%4d", 2048);
}

int main(void)
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);

	init_pair(1, COLOR_BLACK, COLOR_YELLOW);
	init_pair(2, COLOR_BLACK, COLOR_RED);

	WINDOW *win = newwin(20, 40, 0, 0);
	drawBlockPiece(win, 0, 0, 10);

	wrefresh(win);

	while (TRUE)
	{
	}

	endwin();
}