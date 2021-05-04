#include <ncurses.h>
#include <config.h>
#include <view.h>
#include <core.h>

/* Desenha o prompt de confirmação */
void drawPromptExit(WINDOW *window)
{
    drawString(window, "Desenha sair do jogo?", 2, 1, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "Pressione s/S para sair,", 2, 2, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "e qualquer outra tecla para cancelar.", 2, 3, 40, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "", 2, 4, 40, 1, VIEW_COLOR_GREY);
}

/*Função para imprimir um prompt de novo jogo ao usuário*/
void renderPromptExit(WINDOW *window)
{
    wclear(window);
    drawPromptExit(window);
    wrefresh(window);
}