#include <math.h>
#include <config.h>
#include <utils.h>

int getRandomPosition()
{
    int minValue = 0;
    int maxValue = (TABLE_SIZE * TABLE_SIZE) - 1;

    return getRandomNumber(minValue, maxValue);
}

void addValueToRandomPositionOnTable(int table[TABLE_SIZE][TABLE_SIZE], int value)
{
    int isOccupied = 0;
    do
    {
        int randomPosition = getRandomPosition();
        int l = floor(randomPosition / TABLE_SIZE);
        int c = randomPosition % TABLE_SIZE;
        isOccupied = table[l][c];
        if (!isOccupied)
        {
            table[l][c] = value;
        }
    } while (isOccupied);
}

void getTableLine(int line[TABLE_SIZE], int table[TABLE_SIZE][TABLE_SIZE], int lineIndex)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        line[i] = table[lineIndex][i];
    }
}

void applyDownGravity(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 1; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            if (table[(l - 1)][c] != 0 && table[l][c] == 0)
            {
                table[l][c] = table[(l - 1)][c];
                table[(l - 1)][c] = 0;
            }
        }
    }
}

void copyTable(int incoming[TABLE_SIZE][TABLE_SIZE], int outcoming[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            outcoming[l][c] = incoming[l][c];
        }
    }
}

int compareTables(int table1[TABLE_SIZE][TABLE_SIZE], int table2[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            if (table1[l][c] != table2[l][c])
            {
                return 1;
            }
        }
    }
    return 0;
}

int applyDownMovement(int table[TABLE_SIZE][TABLE_SIZE])
{
    int previousTable[TABLE_SIZE][TABLE_SIZE] = {0};
    copyTable(table, previousTable);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        applyDownGravity(table);
    }

    for (int l = (TABLE_SIZE - 1); l > 0; l--)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            int upValue = table[(l - 1)][c];
            if (upValue != 0 && upValue == table[l][c])
            {
                table[(l - 1)][c] = 0;
                table[l][c] *= 2;
            }
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        applyDownGravity(table);
    }

    return compareTables(previousTable, table);
}

void addInitialPiecesToTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int i = 0; i < 2; i++)
    {
        addValueToRandomPositionOnTable(table, 2);
    }
}

void addPiecesToTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    int pieceValue = 2;
    if (getRandomBooleanByChance(10))
        pieceValue = 4;
    addValueToRandomPositionOnTable(table, pieceValue);
}

void rotateClockwise(int a[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE / 2; l++)
    {
        for (int c = l; c < TABLE_SIZE - l - 1; c++)
        {
            int temp = a[l][c];
            a[l][c] = a[TABLE_SIZE - 1 - c][l];
            a[TABLE_SIZE - 1 - c][l] = a[TABLE_SIZE - 1 - l][TABLE_SIZE - 1 - c];
            a[TABLE_SIZE - 1 - l][TABLE_SIZE - 1 - c] = a[c][TABLE_SIZE - 1 - l];
            a[c][TABLE_SIZE - 1 - l] = temp;
        }
    }
}