#include <ncurses.h>
#include <config.h>
#include <view.h>
#include <core.h>

/* Desenha o ranking */
void drawRankingView(WINDOW *window, t_tableData *tableData)
{
    drawString(window, "Voce chegou ao fim do jogo!", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Presisone qualquer tecla para sair", 2, 2, 40, 1, VIEW_COLOR_GREY);
    drawCardRanking(window, "Ranking", tableData, 44, 1, 40);
}

/*Função para mostrar o ranking ao usuário*/
void renderRankingView(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawRankingView(window, tableData);
    wrefresh(window);
}