#include <config.h>

#ifndef STRUCT_TABLE_DATA_H
#define STUCT_TABLE_DATA_H
typedef struct
{
    int table[TABLE_SIZE][TABLE_SIZE];
    int score;
    int movements;
} t_tableData;
#endif

void playUp(t_tableData *);
void playDown(t_tableData *);
void playLeft(t_tableData *);
void playRight(t_tableData *);
void initGame(t_tableData *);