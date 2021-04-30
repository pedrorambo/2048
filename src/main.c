#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>
#include <keys.h>

int main(void)
{
    t_tableData tableData;
    srand(time(NULL));
    initView();
    int key;

    initGame(&tableData);
    drawTable(tableData.table);

    do
    {
        key = getNextKey();

        if (key == KEY_DOWN)
        {
            playDown(&tableData);
        }
        else if (key == KEY_UP)
        {
            playUp(&tableData);
        }
        else if (key == KEY_LEFT)
        {
            playLeft(&tableData);
        }
        else if (key == KEY_RIGHT)
        {
            playRight(&tableData);
        }

        drawTable(tableData.table);
    } while (key != KEY_ESC);

    destroyView();
    return 0;
}