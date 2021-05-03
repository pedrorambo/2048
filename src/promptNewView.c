#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>
#include <promptNewView.h>

void drawPromptNew(WINDOW *window)
{
    drawString(window, "Desenha iniciar um novo jogo?", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Pressione s/S para continuar,", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "e qualquer outra tecla para cancelar.", 2, 3, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "", 2, 4, 40, 1, VIEW_COLOR_GREY);
}

void renderPromptNew(WINDOW *window)
{
    wclear(window);
    drawPromptNew(window);
    wrefresh(window);
}