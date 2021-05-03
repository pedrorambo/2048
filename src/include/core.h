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
    char filename[MAX_FILENAME + 1];
    int exit;
    int gameFinished;
} t_tableData;

void playUp(t_tableData *, int);
void playDown(t_tableData *, int);
void playLeft(t_tableData *, int);
void playRight(t_tableData *, int);
void flushData(t_tableData *tableData);
void addInitialPieces(t_tableData *tableData);

#endif
