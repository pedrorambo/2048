#include <core.h>

#ifndef RANKING_PERSISTENCE_H
#define RANKING_PERSISTENCE_H

#define FILE_NAME "ranking.txt"
#define READ_STRING_SIZE 30

/*Função para carregar ranking salvo em arquivo para o jogo*/
void loadRanking(t_tableData *);
/*Função para adicionar o jogador ao ranking, caso ele tenha pontuação suficiente*/
void addPlayerToRanking(t_tableData *tableData);

#endif