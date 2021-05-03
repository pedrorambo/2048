#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

void drawRankingView(WINDOW *window, t_tableData *tableData)
{
    drawString(window, "Voce chegou ao fim do jogo!", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Presisone qualquer tecla apra sair", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);

    drawCardRanking(window, "Ranking", tableData, 20, 3, 40);
}

void renderRankingView(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawRankingView(window, tableData);
    wrefresh(window);
}