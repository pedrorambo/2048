#include <ncurses.h>
#include <core.h>
#include <config.h>

#ifndef PROMPT_SAVE_VIEW
#define PROMPT_SAVE_VIEW

/*Função para mostrar prompt para salvar o progresso do jogo ao usuário*/
void renderPromptSave(WINDOW *window, t_tableData *tableData);

#endif