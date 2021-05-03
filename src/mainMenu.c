#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <view.h>
#include <tableView.h>
#include <core.h>

void drawMainMenu(WINDOW *window)
{
    drawString(window, "Novo Jogo", 2, 4, 10, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "[N]", 2, 5, 11, 1, VIEW_COLOR_GREY);
    drawString(window, "Carregar Jogo", 32, 4, 10, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "[S]", 32, 5, 15, 1, VIEW_COLOR_GREY);
    drawString(window, "Sair do Jogo", 65, 4, 15, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "[ESC]", 65, 5, 15, 1, VIEW_COLOR_GREY);
}

void draw2048(WINDOW *window)
{
    drawString(window, " /\\\\\\\\\\\\\\\\\\          /\\\\\\\\\\\\\\                /\\\\\\         /\\\\\\\\\\\\\\\\\\        ", 2, 7, 60, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "/\\\\\\///////\\\\\\      /\\\\\\/////\\\\\\            /\\\\\\\\\\       /\\\\\\///////\\\\\\     ", 2, 8, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "\\///      \\//\\\\\\    /\\\\\\    \\//\\\\\\         /\\\\\\/\\\\\\      \\/\\\\\\     \\/\\\\\\    ", 2, 9, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "           /\\\\\\/    \\/\\\\\\     \\/\\\\\\       /\\\\\\/\\/\\\\\\      \\///\\\\\\\\\\\\\\\\\\/    ", 2, 10, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "          /\\\\\\//     \\/\\\\\\     \\/\\\\\\     /\\\\\\/  \\/\\\\\\       /\\\\\\///////\\\\\\  ", 2, 11, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "        /\\\\\\//        \\/\\\\\\     \\/\\\\\\   /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\   /\\\\\\     \\//\\\\\\ ", 2, 12, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "       /\\\\\\/           \\//\\\\\\    /\\\\\\   \\///////////\\\\\\//   \\//\\\\\\     /\\\\\\ ", 2, 13, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "        /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\///\\\\\\\\\\\\\\/              \\/\\\\\\      \\///\\\\\\\\\\\\\\\\\\/", 2, 14, 55, 1, VIEW_COLOR_LIGHT_GREY);
    drawString(window, "        \\///////////////    \\///////                \\///         \\///////// ", 2, 15, 55, 1, VIEW_COLOR_LIGHT_GREY);
}

void renderMainMenu(WINDOW *window)
{
    wclear(window);
    draw2048(window);
    drawMainMenu(window);
    wrefresh(window);
}