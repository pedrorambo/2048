#include <ncurses.h>
#include <core.h>
#include <config.h>

#ifndef PROMPT_LOAD_VIEW_H
#define PROMPT_LOAD_VIEW_H

/*Função para mostrar prompt para salvar o progresso do jogo ao usuário*/
void renderPromptLoad(WINDOW *window, t_tableData *tableData);

#endif