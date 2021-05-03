#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

void drawPromptRanking(WINDOW *window, char name[USERNAME_MAX_LENGTH + 1])
{
    drawString(window, "Voce chegou ao fim do jogo!", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Informe seu nome para o ranking", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, name, 2, 3, 40, 1, VIEW_COLOR_GREY);
}

void renderPromptRanking(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawPromptRanking(window, tableData->username);
    wrefresh(window);
}

void drawHud(WINDOW *window)
{
    drawString(window, "Comandos", 42, 16, 24, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "N - Novo Jogo", 42, 17, 24, 1, VIEW_COLOR_GREY);
    drawString(window, "S - Salvar Jogo", 42, 18, 24, 1, VIEW_COLOR_GREY);
    drawString(window, "ESC - Sair do Jogo", 42, 19, 24, 1, VIEW_COLOR_GREY);
}
