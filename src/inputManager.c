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
#include <promptRankingView.h>
#include <saveGame.h>
#include <promptSaveView.h>
#include <promptExitView.h>
#include <promptNewView.h>
#include <mainMenu.h>
#include <promptLoadView.h>

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
        break;
    case WINDOW_PROMPT_LOAD:
        renderPromptLoad(window, tableData);
        break;
    default:
        break;
    }
}

void handleWindowHomeInput(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
    switch (key)
    {
    case GAME_KEY_N:
        *currentWindow = WINDOW_GAME;
        break;
    case GAME_KEY_C:
        clearFileName(tableData);
        *currentWindow = WINDOW_PROMPT_LOAD;
        break;
    case GAME_KEY_ESC:
        tableData->exit = TRUE;
    default:
        break;
    }
}

void handleWindowGameInput(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
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
        clearFileName(tableData);
        *currentWindow = WINDOW_PROMPT_SAVE;
        break;
    case GAME_KEY_ESC:
        *currentWindow = WINDOW_PROMPT_EXIT;
    default:
        break;
    }
}

void handleWindowPromptRanking(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
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
}

void handleWindowEndgameRanking(t_tableData *tableData)
{
    tableData->exit = 1;
}

void handleWindowPromptSave(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
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
}

void handleWindowPromptExit(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
    if (key == GAME_KEY_S || key == GAME_KEY_S_UPPERCASE)
    {
        tableData->exit = TRUE;
    }
    else
    {
        *currentWindow = WINDOW_GAME;
    }
}

void handleWindowPromptNew(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
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
}

void handleWindowPromptLoad(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
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
        int success = loadGame(tableData, tableData->filename);
        if (success)
            *currentWindow = WINDOW_GAME;
    }
}

void handleInput(t_tableData *tableData, const int key, unsigned int *currentWindow)
{
    switch (*currentWindow)
    {
    case WINDOW_HOME:
        handleWindowHomeInput(tableData, key, currentWindow);
        break;
    case WINDOW_GAME:
        handleWindowGameInput(tableData, key, currentWindow);
        break;
    case WINDOW_PROMPT_RANKING:
        handleWindowPromptRanking(tableData, key, currentWindow);
        break;
    case WINDOW_ENDGAME_RANKING:
        handleWindowEndgameRanking(tableData);
        break;
    case WINDOW_PROMPT_SAVE:
        handleWindowPromptSave(tableData, key, currentWindow);
        break;
    case WINDOW_PROMPT_EXIT:
        handleWindowPromptExit(tableData, key, currentWindow);
        break;
    case WINDOW_PROMPT_NEW:
        handleWindowPromptNew(tableData, key, currentWindow);
        break;
    case WINDOW_PROMPT_LOAD:
        handleWindowPromptLoad(tableData, key, currentWindow);
        break;
    default:
        break;
    }
}