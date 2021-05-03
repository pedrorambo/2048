#include <ncurses.h>
#include <core.h>
#include <config.h>

#ifndef PROMPT_SAVE_VIEW
#define PROMPT_SAVE_VIEW

void renderPromptSave(WINDOW *window, t_tableData *tableData);

#endif