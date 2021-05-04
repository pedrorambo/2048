#include <ncurses.h>
#include <config.h>
#include <view.h>
#include <core.h>

/* Desenha o ranking */
void drawPromptRanking(WINDOW *window, char name[USERNAME_MAX_LENGTH + 1])
{
    drawString(window, "Voce chegou ao fim do jogo!", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Informe seu nome para o ranking", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, name, 2, 3, 40, 1, VIEW_COLOR_GREY);
}

/*Função para mostrar prompt que pede o nome do jogador ao usuário*/
void renderPromptRanking(WINDOW *window, t_tableData *tableData)
{
    wclear(window);
    drawPromptRanking(window, tableData->username);
    wrefresh(window);
}