#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>
#include <tableView.h>
#include <rankingPersistence.h>
#include <promptView.h>
#include <keys.h>

int main(void)
{
    int key;
    t_tableData tableData;
    WINDOW *window = initView();

    srand(time(NULL));
    initGame(&tableData);

    // Load ranking
    loadRanking(&tableData);

    // Ranking Mock
    // strcpy(tableData.ranking[0].name, "Pedro 1");
    // tableData.ranking[0].score = 40;
    // strcpy(tableData.ranking[1].name, "Pedro 2");
    // tableData.ranking[1].score = 10;
    // strcpy(tableData.ranking[2].name, "Pedro 3");
    // tableData.ranking[2].score = 90;
    // tableData.rankingSize = 3;

    renderTable(window, &tableData);

    do
    {
        key = getNextKey(window);

        switch (key)
        {
        case KEY_DOWN:
            playDown(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_UP:
            playUp(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_RIGHT:
            playRight(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_LEFT:
            playLeft(&tableData);
            renderTable(window, &tableData);
            break;
        case KEY_NEWGAME:
            renderPrompt(window);
            initGame(&tableData);

        default:
            break;
        }

    } while (key != KEY_ESC);

    destroyView();
    return 0;
}