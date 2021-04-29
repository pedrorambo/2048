#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <tablePlays.h>
#include <view.h>

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