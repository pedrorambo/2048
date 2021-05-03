#include <ncurses.h>
#include <core.h>

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

void handleWindow(WINDOW *window, t_tableData *tableData, const unsigned int currentWindow);
void handleInput(t_tableData *tableData, const int key, unsigned int *currentWindow);

#endif