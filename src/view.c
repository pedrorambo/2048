#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <config.h>
#include <tableLogic.h>
#include <core.h>
#include <view.h>

/* Inicializa as cores e os pares de cores */
void initColors()
{
    init_color(VIEW_COLOR_BLACK, 0, 0, 0);
    init_color(VIEW_COLOR_WHITE, 933, 894, 854);
    init_color(VIEW_COLOR_DARK_WHITE, 933, 882, 788);
    init_color(VIEW_COLOR_ORANGE, 952, 698, 478);
    init_color(VIEW_COLOR_DARK_ORANGE, 964, 588, 392);
    init_color(VIEW_COLOR_RED, 968, 486, 372);
    init_color(VIEW_COLOR_DARK_RED, 968, 372, 231);
    init_color(VIEW_COLOR_LIGHT_YELLOW, 929, 815, 450);
    init_color(VIEW_COLOR_YELLOW, 929, 800, 380);
    init_color(VIEW_COLOR_DARK_YELLOW, 929, 823, 474);
    init_color(VIEW_COLOR_DARKER_YELLOW, 929, 772, 247);
    init_color(VIEW_COLOR_PURPLE, 556, 266, 678);
    init_color(VIEW_COLOR_GREY, 188, 188, 188);
    init_color(VIEW_COLOR_LIGHT_GREY, 800, 800, 800);

    init_pair(VIEW_COLOR_WHITE, COLOR_BLACK, VIEW_COLOR_WHITE);
    init_pair(VIEW_COLOR_DARK_WHITE, COLOR_BLACK, VIEW_COLOR_DARK_WHITE);
    init_pair(VIEW_COLOR_ORANGE, COLOR_BLACK, VIEW_COLOR_ORANGE);
    init_pair(VIEW_COLOR_DARK_ORANGE, COLOR_BLACK, VIEW_COLOR_DARK_ORANGE);
    init_pair(VIEW_COLOR_RED, COLOR_BLACK, VIEW_COLOR_RED);
    init_pair(VIEW_COLOR_DARK_RED, COLOR_BLACK, VIEW_COLOR_DARK_RED);
    init_pair(VIEW_COLOR_LIGHT_YELLOW, COLOR_BLACK, VIEW_COLOR_LIGHT_YELLOW);
    init_pair(VIEW_COLOR_YELLOW, COLOR_BLACK, VIEW_COLOR_YELLOW);
    init_pair(VIEW_COLOR_DARK_YELLOW, COLOR_BLACK, VIEW_COLOR_DARK_YELLOW);
    init_pair(VIEW_COLOR_DARKER_YELLOW, COLOR_BLACK, VIEW_COLOR_DARKER_YELLOW);
    init_pair(VIEW_COLOR_PURPLE, COLOR_BLACK, VIEW_COLOR_PURPLE);
    init_pair(VIEW_COLOR_GREY, COLOR_BLACK, VIEW_COLOR_GREY);
    init_pair(VIEW_COLOR_LIGHT_GREY, COLOR_BLACK, VIEW_COLOR_LIGHT_GREY);
    init_pair(VIEW_COLOR_GREY, COLOR_WHITE, VIEW_COLOR_GREY);
}

/*Função para inicializar a interface gráfica*/
WINDOW *initView()
{
    WINDOW *window;
    initscr();
    start_color();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(SHOW_CURSOR);
    initColors();

    window = newwin(TABLE_WINDOW_WIDTH, TABLE_WINDOW_HEIGHT, TABLE_WINDOW_X, TABLE_WINDOW_Y);

    wrefresh(window);

    return window;
}

/*Função para obter o input via teclado do usuário*/
int getNextKey(WINDOW *window)
{
    keypad(window, TRUE);
    cbreak();
    noecho();
    int ch = wgetch(window);
    return ch;
}

/*Função para desenhar um inteiro com um determinado tamanho e um padding*/
void drawInt(WINDOW *window, int value, int x, int y, int width, int padding, int colorPairIndex)
{
    int valueMaxLength = width - (padding * 2);
    wattron(window, COLOR_PAIR(colorPairIndex));
    wmove(window, y, x);
    wprintw(window, "%*c%*d%*c", padding, ' ', valueMaxLength, value, padding, ' ');
}

/*Função para desenhar uma string com um determinado tamanho e um padding*/
void drawString(WINDOW *window, char value[], int x, int y, int width, int padding, int colorPairIndex)
{
    int valueMaxLength = width - (padding * 2);
    wattron(window, COLOR_PAIR(colorPairIndex));
    wmove(window, y, x);
    wprintw(window, "%*c%*s%*c", padding, ' ', valueMaxLength, value, padding, ' ');
}

/*Função para desenhar um bloco com cabeçalho com um determinado tamanho e um padding*/
void drawCardInt(WINDOW *window, char title[], int value, int x, int y, int width)
{
    drawString(window, title, x, y, width, CARD_TITLE_PADDING, VIEW_COLOR_LIGHT_GREY);
    drawInt(window, value, x, y + 1, width, CARD_VALUE_PADDING, VIEW_COLOR_GREY);
}

/*Função para desenhar o cabeçalho do ranking*/
void drawCardRanking(WINDOW *window, char title[], t_tableData *tableData, int x, int y, int width)
{
    drawString(window, title, x, y, width, CARD_TITLE_PADDING, VIEW_COLOR_LIGHT_GREY);

    for (int i = 0; i < tableData->rankingSize; i++)
    {
        drawInt(window, tableData->ranking[i].score, x, y + i + 1, RANKING_CARD_SCORE_WIDTH, CARD_VALUE_PADDING, VIEW_COLOR_GREY);
        drawString(window, tableData->ranking[i].name, x + RANKING_CARD_SCORE_WIDTH, y + i + 1, width - RANKING_CARD_SCORE_WIDTH, CARD_VALUE_PADDING, VIEW_COLOR_GREY);
    }
}

/*Função para desativar a interface gráfica*/
void destroyView()
{
    endwin();
}
