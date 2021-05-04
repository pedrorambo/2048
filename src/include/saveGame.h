#include <config.h>
#include <core.h>

#ifndef SAVE_GAME_H
#define SAVE_GAME_H

/*Estrutura para armazenar dados do jogo em arquivos externos*/
typedef struct
{
    int table[TABLE_SIZE][TABLE_SIZE];
    int score;
    int movements;
} t_saveData;

/*Função para carregar arquivo com um jogo em progresso*/
int loadGame(t_tableData *tableData, char *filename);

/*Função para salvar progresso em um arquivo externo*/
void saveGame(t_tableData *tableData, char *filename);

#endif