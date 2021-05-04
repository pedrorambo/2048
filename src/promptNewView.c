#include <ncurses.h>
#include <config.h>
#include <view.h>
#include <core.h>

/*Função para criar prompt para sair do jogo ao usuário*/
void drawPromptNew(WINDOW *window)
{
    drawString(window, "Desenha iniciar um novo jogo?", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Pressione s/S para continuar,", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "e qualquer outra tecla para cancelar.", 2, 3, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "", 2, 4, 40, 1, VIEW_COLOR_GREY);
}

/*Função para mostrar prompt para sair do jogo ao usuário*/
void renderPromptNew(WINDOW *window)
{
    wclear(window);
    drawPromptNew(window);
    wrefresh(window);
}