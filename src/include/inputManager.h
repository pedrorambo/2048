#include <ncurses.h>
#include <core.h>

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

/* Gerencia a visualização da janela selecionada */
void handleWindow(WINDOW *window, t_tableData *tableData, const unsigned int currentWindow);

/* Gerenciar as teclas de acordo com a janela aberta */
void handleInput(t_tableData *tableData, const int key, unsigned int *currentWindow);

#endif