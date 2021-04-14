#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include "config.h"
#include "lib/prints.h"
#include "lib/utils.h"
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
}