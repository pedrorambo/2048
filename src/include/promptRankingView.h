#include <ncurses.h>
#include <core.h>

#ifndef PROMPT_RANKING_VIEW_H
#define PROMPT_RANKING_VIEW_H

void renderPromptRanking(WINDOW *window, t_tableData *tableData);
void drawHud(WINDOW *window);

#endif