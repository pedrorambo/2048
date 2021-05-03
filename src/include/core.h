#include <config.h>

#ifndef CORE_H
#define CORE_H

typedef struct
{
    int score;
    char name[USERNAME_MAX_LENGTH + 1];
} t_user;

typedef struct
{
    int table[TABLE_SIZE][TABLE_SIZE];
    int score;
    int movements;
    t_user ranking[RANKING_SIZE];
    int rankingSize;
    char username[USERNAME_MAX_LENGTH + 1];
} t_tableData;

void playUp(t_tableData *);
void playDown(t_tableData *);
void playLeft(t_tableData *);
void playRight(t_tableData *);
void flushData(t_tableData *tableData);
void addInitialPieces(t_tableData *tableData);

#endif
