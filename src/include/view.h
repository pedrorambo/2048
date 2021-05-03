#include <config.h>
#include <ncurses.h>
#include <core.h>

#ifndef VIEW_H
#define VIEW_H

#define SHOW_CURSOR 0

#define VIEW_COLOR_BLACK 30
#define VIEW_COLOR_WHITE 10         // piece 2
#define VIEW_COLOR_DARK_WHITE 11    // piece 4
#define VIEW_COLOR_ORANGE 12        // piece 8
#define VIEW_COLOR_DARK_ORANGE 13   // piece 16
#define VIEW_COLOR_RED 14           // piece 32
#define VIEW_COLOR_DARK_RED 15      // piece 64
#define VIEW_COLOR_LIGHT_YELLOW 16  // piece 128
#define VIEW_COLOR_YELLOW 17        // piece 256
#define VIEW_COLOR_DARK_YELLOW 18   // piece 512
#define VIEW_COLOR_DARKER_YELLOW 19 // piece 1024
#define VIEW_COLOR_PURPLE 20        // piece 2048
#define VIEW_COLOR_LIGHT_GREY 21
#define VIEW_COLOR_GREY 22

#define TABLE_WINDOW_WIDTH 100
#define TABLE_WINDOW_HEIGHT 100
#define TABLE_WINDOW_X 0
#define TABLE_WINDOW_Y 0

#define CARD_TITLE_PADDING 2
#define CARD_VALUE_PADDING 1

#define RANKING_CARD_WIDTH 24
#define RANKING_CARD_SCORE_WIDTH 7

/*Função para inicializar a interface gráfica*/
WINDOW *initView();
/*Função para obter o input via teclado do usuário*/
int getNextKey(WINDOW *window);
/*Função para desenhar um inteiro com um determinado tamanho e um padding*/
void drawInt(WINDOW *window, int value, int x, int y, int width, int padding, int colorPairIndex);
/*Função para desenhar uma string com um determinado tamanho e um padding*/
void drawString(WINDOW *window, char value[], int x, int y, int width, int padding, int colorPairIndex);
/*Função para desenhar um bloco com cabeçalho com um determinado tamanho e um padding*/
void drawCardInt(WINDOW *window, char title[], int value, int x, int y, int width);
/*Função para desativar a interface gráfica*/
void destroyView();
/*Função para desenhar o cabeçalho do ranking*/
void drawCardRanking(WINDOW *window, char title[], t_tableData *tableData, int x, int y, int width);

#endif