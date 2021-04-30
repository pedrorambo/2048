#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>

#ifndef KEY_ESC
#define KEY_ESC 27
#endif

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

        switch (key)
        {
        case KEY_DOWN:
            playDown(&tableData);
            break;
        case KEY_UP:
            playUp(&tableData);
            break;
        case KEY_RIGHT:
            playRight(&tableData);
            break;
        case KEY_LEFT:
            playLeft(&tableData);
            break;
        default:
            break;
        }

        drawTable(tableData.table);
    } while (key != KEY_ESC);

    destroyView();
    return 0;
}