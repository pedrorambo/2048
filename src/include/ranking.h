#include <core.h>

#ifndef RANKING_PERSISTENCE_H
#define RANKING_PERSISTENCE_H

#define FILE_NAME "ranking.txt"
#define READ_STRING_SIZE 30

void loadRanking(t_tableData *);
void addPlayerToRanking(t_tableData *tableData);

#endif