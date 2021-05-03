#include <config.h>
#include <core.h>

#ifndef SAVE_GAME_H
#define SAVE_GAME_H

typedef struct
{
    int table[TABLE_SIZE][TABLE_SIZE];
    int score;
    int movements;
} t_saveData;

int loadGame(t_tableData *tableData, char *filename);
void saveGame(t_tableData *tableData, char *filename);

#endif