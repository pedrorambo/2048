#include "../config.h"
#include "tableLogic.h"

int playUp(int table[TABLE_SIZE][TABLE_SIZE])
{
    rotateClockwise(table);
    rotateClockwise(table);
    int changed = applyDownMovement(table);
    rotateClockwise(table);
    rotateClockwise(table);
    return changed;
}

int playDown(int table[TABLE_SIZE][TABLE_SIZE])
{
    int changed = applyDownMovement(table);
    return changed;
}

int playLeft(int table[TABLE_SIZE][TABLE_SIZE])
{
    rotateClockwise(table);
    rotateClockwise(table);
    rotateClockwise(table);
    int changed = applyDownMovement(table);
    rotateClockwise(table);
    return changed;
}

int playRight(int table[TABLE_SIZE][TABLE_SIZE])
{
    rotateClockwise(table);
    int changed = applyDownMovement(table);
    rotateClockwise(table);
    rotateClockwise(table);
    rotateClockwise(table);
    return changed;
}