#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>
#include <tableView.h>

#ifndef KEY_ESC
#define KEY_ESC 27
#endif

int main(void)
{
    int key;
    t_tableData tableData;
    WINDOW *window = initView();

    srand(time(NULL));
    initGame(&tableData);

    // Ranking Mock
    strcpy(tableData.ranking[0].name, "Pedro 1");
    tableData.ranking[0].score = 40;
    strcpy(tableData.ranking[1].name, "Pedro 2");
    tableData.ranking[1].score = 10;
    tableData.rankingSize = 2;

    renderTable(window, &tableData);

    do
    {
        key = getNextKey(window);

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

        renderTable(window, &tableData);
    } while (key != KEY_ESC);

    destroyView();
    return 0;
}