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
    // Inicializações de tipos
    int key;
    int gameLoaded = 0;
    int once = 0;
    t_tableData tableData = {0};
    unsigned int currentWindow = WINDOW_HOME;
    WINDOW *window = initView();

    // Inicializações
    srand(time(NULL));
    flushData(&tableData);

    // Carrega o jogo salvo
    gameLoaded = loadGame(&tableData, "output");
    if (!gameLoaded)
        addInitialPieces(&tableData);

    // Carrega o ranking salvo
    loadRanking(&tableData);

    // Looping principal do jogo
    do
    {
        // Verifica se o jogo acabou
        if (tableData.gameFinished && !once)
        {
            currentWindow = WINDOW_PROMPT_RANKING;
            once = 1;
        }

        // Gerencia a janela aberta
        handleWindow(window, &tableData, currentWindow);

        // Gerencia o input do usuário
        key = getNextKey(window);
        handleInput(&tableData, key, &currentWindow);
    } while (!tableData.exit);

    destroyView();
    return 0;
}