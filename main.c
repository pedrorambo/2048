#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "config.h"
#include "lib/tableLogic.h"
#include "lib/tablePlays.h"
#include "lib/view.h"

int main(void)
{
	srand(time(NULL));
	int table[TABLE_SIZE][TABLE_SIZE] = {0};
	initView();
	addInitialPiecesToTable(table);
	drawTable(table);

	while (TRUE)
	{
		int key = getNextKey();

		switch (key)
		{
		case 66: // Down
			if (playDown(table) != 0)
				addPiecesToTable(table);
			drawTable(table);
			break;
		case 65: // Up
			if (playUp(table) != 0)
				addPiecesToTable(table);
			drawTable(table);
			break;
		case 68: // Left
			if (playLeft(table) != 0)
				addPiecesToTable(table);
			drawTable(table);
			break;
		case 67: // Right
			if (playRight(table) != 0)
				addPiecesToTable(table);
			drawTable(table);
			break;
		default:
			break;
		}
	}
}