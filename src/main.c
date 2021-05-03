#include <windows.h>
#include <stdlib.h>
#include <core.h>
#include <ncurses.h>
#include <time.h>
#include <view.h>
#include <saveGame.h>
#include <ranking.h>
#include <inputManager.h>

int main()
{
    int key;
    int gameLoaded = 0;
    int once = 0;
    t_tableData tableData = {0};

    srand(time(NULL));
    unsigned int currentWindow = WINDOW_HOME;
    WINDOW *window = initView();
    flushData(&tableData);

    gameLoaded = loadGame(&tableData, "output");

    if (!gameLoaded)
        addInitialPieces(&tableData);

    loadRanking(&tableData);

    // tableData.table[0][0] = 1024;
    // tableData.table[0][1] = 1024;

    do
    {
        if (tableData.gameFinished && !once)
        {
            currentWindow = WINDOW_PROMPT_RANKING;
            once = 1;
        }

        handleWindow(window, &tableData, currentWindow);

        key = getNextKey(window);
        handleInput(&tableData, key, &currentWindow);
    } while (!tableData.exit);

    destroyView();
    return 0;
}