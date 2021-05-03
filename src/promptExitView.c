#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

void drawPromptExit(WINDOW *window)
{
    drawString(window, "Desenha sair do jogo?", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Pressione s/S para sair,", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "e qualquer outra tecla para cancelar.", 2, 3, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "", 2, 4, 40, 1, VIEW_COLOR_GREY);
}

void renderPromptExit(WINDOW *window)
{
    wclear(window);
    drawPromptExit(window);
    wrefresh(window);
}