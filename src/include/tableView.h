#include <config.h>
#include <ncurses.h>
#include <view.h>
#include <core.h>

#ifndef TABLE_VIEW_H
#define TABLE_VIEW_H

#define PIECE_WIDTH 10
#define PIECE_HEIGHT 5

#define PIECE_TEXT_OFFSET_X 2
#define PIECE_TEXT_OFFSET_Y 3

#define SCORE_CARD_WIDTH 9
#define MOVEMENTS_CARD_WIDTH 14

/*Função para mostrar tabuleiro na tela para o usuário*/
void renderTable(WINDOW *window, t_tableData *tableData);

#endif