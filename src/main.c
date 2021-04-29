#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <tablePlays.h>
#include <view.h>
#include <keys.h>

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
        case INPUT_KEY_DOWN:
            if (playDown(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
            break;
        case INPUT_KEY_UP:
            if (playUp(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
            break;
        case INPUT_KEY_LEFT:
            if (playLeft(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
            break;
        case INPUT_KEY_RIGHT:
            if (playRight(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
            break;
        default:
            break;
        }
    }
}