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
    int key;

    do
    {
        key = getNextKey();

        if (key == KEY_DOWN)
        {

            if (playDown(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }
        else if (key == KEY_UP)
        {
            if (playUp(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }
        else if (key == KEY_LEFT)
        {
            if (playLeft(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }
        else if (key == KEY_RIGHT)
        {
            if (playRight(table) != 0)
                addPiecesToTable(table);
            drawTable(table);
        }

    } while (key != KEY_ESC);

    destroyView();
    return 0;
}