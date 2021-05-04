#include <ncurses.h>
#include <core.h>

#ifndef RANKING_VIEW_H
#define RANKING_VIEW_H

/*Função para mostrar o ranking ao usuário*/
void renderRankingView(WINDOW *window, t_tableData *tableData);

#endif