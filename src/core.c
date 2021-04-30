#include <config.h>
#include <tableLogic.h>
#include <core.h>

void initGame(t_tableData *tableData)
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            tableData->table[l][c] = 0;
        }
    }

    tableData->score = 0;
    tableData->movements = 0;

    addInitialPiecesToTable(tableData->table);
}

void play(t_tableData *tableData)
{
    int changed = applyDownMovement(tableData->table, &(tableData->score));
    if (changed != 0)
    {
        tableData->movements += 1;
        addPiecesToTable(tableData->table);
    }
    return;
}

void playUp(t_tableData *tableData)
{
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    play(tableData);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
}

void playDown(t_tableData *tableData)
{
    play(tableData);
}

void playLeft(t_tableData *tableData)
{
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    play(tableData);
    rotateClockwise(tableData->table);
}

void playRight(t_tableData *tableData)
{
    rotateClockwise(tableData->table);
    play(tableData);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
}
