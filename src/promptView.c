#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>



void drawPrompt(WINDOW *window, int prompt[PROMPT_HEIGHT][PROMPT_WIDTH])
{
    for (int l = 0; l < PROMPT_HEIGHT; l++)
    {
        for (int c = 0; c < PROMPT_WIDTH; c++)
        {
            drawBlockPiece(window, (c * PIECE_WIDTH), (l * PIECE_HEIGHT), prompt[l][c]);
        }
    }
}

void renderPrompt(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawPrompt(window, tableData->table);
    wrefresh(window);
}

void destroyPrompt(WINDOW *window)
{
    wclear(window);
    wrefresh(window);
}