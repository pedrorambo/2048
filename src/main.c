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
#include <promptView.h>
#include <keys.h>
#include <windows.h>
#include <utils.h>

void handleWindow(WINDOW *window, t_tableData *tableData, const unsigned int currentWindow)
{
    switch (currentWindow)
    {
    case WINDOW_PROMPT_SAVE:
        renderPrompt(window);
        break;
    case WINDOW_GAME:
        renderTable(window, tableData);
        break;
    case WINDOW_PROMPT_RANKING:
        renderPromptRanking(window, tableData);
    default:
        break;
    }
}

void handleInput(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
    switch (*currentWindow)
    {
    case WINDOW_HOME:
        break;
    case WINDOW_GAME:
        switch (key)
        {
        case KEY_DOWN:
            *currentWindow = WINDOW_PROMPT_RANKING;
            playDown(tableData);
            break;
        case KEY_UP:
            playUp(tableData);
            break;
        case KEY_RIGHT:
            playRight(tableData);
            break;
        case KEY_LEFT:
            playLeft(tableData);
            break;
        case GAME_KEY_N:
            *currentWindow = WINDOW_PROMPT_SAVE;
            break;
        default:
            break;
        }
        break;
    case WINDOW_PROMPT_SAVE:
        break;
    case WINDOW_PROMPT_RANKING:
        if (key == KEY_BACKSPACE)
        {
            tableData->username[strlen(tableData->username) - 1] = '\0';
        }
        else if (keyIsAlphanumerical(key) && strlen(tableData->username) < USERNAME_MAX_LENGTH - 1)
        {
            tableData->username[strlen(tableData->username)] = key;
        }
        else if (key == GAME_KEY_ENTER)
        {
            // TODO Update Ranking
        }
        break;
    default:
        break;
    }
}

int main()
{
    int key;
    t_tableData tableData = {0};
    unsigned int currentWindow = WINDOW_GAME;
    WINDOW *window = initView();

    srand(time(NULL));
    initGame(&tableData);

    // Load ranking
    loadRanking(&tableData);

    renderTable(window, &tableData);

    do
    {
        handleWindow(window, &tableData, currentWindow);

        key = getNextKey(window);
        handleInput(&tableData, key, &currentWindow);
    } while (key != GAME_KEY_ENTER);

    destroyView();
    return 0;
}