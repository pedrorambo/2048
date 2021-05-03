#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

void drawPromptSave(WINDOW *window, char filename[MAX_FILENAME + 1])
{
    drawString(window, "Salvar jogo", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Informe o nome do arquivo", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, filename, 2, 3, 40, 1, VIEW_COLOR_GREY);
}

void renderPromptSave(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawPromptSave(window, tableData->filename);
    wrefresh(window);
}