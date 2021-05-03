#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <string.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>
#include <tableView.h>
#include <ranking.h>
#include <keys.h>
#include <windows.h>
#include <utils.h>
#include <rankingView.h>
#include <logFile.h>
#include <promptRankingView.h>
#include <saveGame.h>
#include <promptSaveView.h>
#include <promptExitView.h>
#include <promptNewView.h>
#include <mainMenu.h>

void handleWindow(WINDOW *window, t_tableData *tableData, const unsigned int currentWindow)
{
    switch (currentWindow)
    {
    case WINDOW_HOME:
    renderMainMenu(window);
        break;
    case WINDOW_GAME:
        renderTable(window, tableData);
        break;
    case WINDOW_PROMPT_RANKING:
        renderPromptRanking(window, tableData);
        break;
    case WINDOW_ENDGAME_RANKING:
        renderRankingView(window, tableData);
        break;
    case WINDOW_PROMPT_SAVE:
        renderPromptSave(window, tableData);
        break;
    case WINDOW_PROMPT_EXIT:
        renderPromptExit(window);
        break;
    case WINDOW_PROMPT_NEW:
        renderPromptNew(window);
    default:

        break;
    }
}

void handleInput(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
    switch (*currentWindow)
    {
    case WINDOW_HOME:
                switch (key)
        {
        case GAME_KEY_N:
            *currentWindow = WINDOW_GAME;
            break;
        case GAME_KEY_S:
            *currentWindow = WINDOW_PROMPT_SAVE;
            break;
        case GAME_KEY_ESC:
            tableData->exit = TRUE;
        default:
            break;
        }
        break;
    case WINDOW_GAME:
        switch (key)
        {
        case KEY_DOWN:
            playDown(tableData, 0);
            break;
        case KEY_UP:
            playUp(tableData, 0);
            break;
        case KEY_RIGHT:
            playRight(tableData, 0);
            break;
        case KEY_LEFT:
            playLeft(tableData, 0);
            break;
        case GAME_KEY_N:
            *currentWindow = WINDOW_PROMPT_NEW;
            break;
        case GAME_KEY_S:
            *currentWindow = WINDOW_PROMPT_SAVE;
            break;
        case GAME_KEY_ESC:
            *currentWindow = WINDOW_PROMPT_EXIT;
        default:
            break;
        }
        break;
    case WINDOW_PROMPT_RANKING:
        if (key == KEY_ENTER || key == GAME_KEY_ENTER)
        {
            addPlayerToRanking(tableData);
            *currentWindow = WINDOW_ENDGAME_RANKING;
        }
        else if (key == KEY_BACKSPACE)
        {
            tableData->username[strlen(tableData->username) - 1] = '\0';
        }
        else if (keyIsAlphanumerical(key) && strlen(tableData->username) < USERNAME_MAX_LENGTH - 1)
        {
            tableData->username[strlen(tableData->username)] = key;
        }
        break;
    case WINDOW_ENDGAME_RANKING:
        tableData->exit = 1;
        break;
    case WINDOW_PROMPT_SAVE:
        if (key == KEY_BACKSPACE)
        {
            tableData->filename[strlen(tableData->filename) - 1] = '\0';
        }
        else if (keyIsAlphanumerical(key) && strlen(tableData->filename) < MAX_FILENAME - 1)
        {
            tableData->filename[strlen(tableData->filename)] = key;
        }
        else if (key == KEY_ENTER || key == GAME_KEY_ENTER)
        {
            saveGame(tableData, tableData->filename);
            *currentWindow = WINDOW_GAME;
        }
        break;
    case WINDOW_PROMPT_EXIT:
        if (key == GAME_KEY_S || key == GAME_KEY_S_UPPERCASE)
        {
            tableData->exit = TRUE;
        }
        else
        {
            *currentWindow = WINDOW_GAME;
        }
        break;
    case WINDOW_PROMPT_NEW:
        if (key == GAME_KEY_S || key == GAME_KEY_S_UPPERCASE)
        {
            flushData(tableData);
            addInitialPieces(tableData);
            *currentWindow = WINDOW_GAME;
        }
        else
        {
            *currentWindow = WINDOW_GAME;
        }
        break;
    default:
        break;
    }
}

int main()
{
    int key;
    int gameLoaded = 0;
    t_tableData tableData = {0};

    srand(time(NULL));
    unsigned int currentWindow = WINDOW_HOME;
    WINDOW *window = initView();
    flushData(&tableData);

    gameLoaded = loadGame(&tableData, "output");
    logInt("Loaded: ", gameLoaded);

    if (!gameLoaded)
        addInitialPieces(&tableData);

    loadRanking(&tableData);

    // tableData.table[0][0] = 1024;
    // tableData.table[0][1] = 1024;

    renderTable(window, &tableData);

    do
    {
        if (tableData.gameFinished)
            currentWindow = WINDOW_PROMPT_RANKING;

        handleWindow(window, &tableData, currentWindow);

        key = getNextKey(window);
        handleInput(&tableData, key, &currentWindow);
    } while (!tableData.exit);

    destroyView();
    return 0;
}