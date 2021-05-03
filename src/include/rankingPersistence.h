#include <core.h>

#ifndef RANKING_PERSISTENCE_H
#define RANKING_PERSISTENCE_H

#define FILE_NAME "ranking.bin"

void saveRanking(t_tableData *);
void loadRanking(t_tableData *);

#endif