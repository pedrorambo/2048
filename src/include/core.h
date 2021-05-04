#include <config.h>

#ifndef CORE_H
#define CORE_H

/*Estrutura para guardar informações do usuário*/
typedef struct
{
    int score;
    char name[USERNAME_MAX_LENGTH + 1];
} t_user;

/*Estrutura base para o jogo*/
typedef struct
{
    int table[TABLE_SIZE][TABLE_SIZE];
    int score;
    int movements;
    t_user ranking[RANKING_SIZE];
    int rankingSize;
    char username[USERNAME_MAX_LENGTH + 1];
    char filename[MAX_FILENAME + 1];
    int exit;
    int gameFinished;
} t_tableData;

/*Função para mover as peças para cima*/
void playUp(t_tableData *, int);

/*Função para mover as peças para baixo*/
void playDown(t_tableData *, int);

/*Função para mover as peças para esquerda*/
void playLeft(t_tableData *, int);

/*Função para mover as peças para direita*/
void playRight(t_tableData *, int);

/*Função para reinicializar os dados do jogo*/
void flushData(t_tableData *tableData);

/*Função para adicionar duas peças ao tabuleiro no ínicio do jogo*/
void addInitialPieces(t_tableData *tableData);

/*Função para limpar o nome do arquivo*/
void clearFileName(t_tableData *tableData);

#endif
