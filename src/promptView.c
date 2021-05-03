#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

void drawPrompt(WINDOW *window)
{
    drawString(window, "Desenha salvar o jogo?", 2, 1, 30, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "", 2, 2, 30, 1, VIEW_COLOR_GREY);
}

void renderPrompt(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawPrompt(window);
    wrefresh(window);
}