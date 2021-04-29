#include <math.h>
#include <config.h>
#include <utils.h>

#define INITIAL_PIECES_QUANTITY 2
#define INITIAL_PIECES_VALUE 2

#define SECONDARY_PIECE_CHANCE 10
#define SECONDARY_PIECE_VALUE 4

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
    for (int i = 0; i < INITIAL_PIECES_QUANTITY; i++)
    {
        addValueToRandomPositionOnTable(table, INITIAL_PIECES_VALUE);
    }
}

void addPiecesToTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    int pieceValue = INITIAL_PIECES_VALUE;
    if (getRandomBooleanByChance(SECONDARY_PIECE_CHANCE))
        pieceValue = SECONDARY_PIECE_VALUE;
    addValueToRandomPositionOnTable(table, pieceValue);
}

void rotateClockwise(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE / 2; l++)
    {
        for (int c = l; c < TABLE_SIZE - l - 1; c++)
        {
            int pieceValue = table[l][c];
            table[l][c] = table[TABLE_SIZE - 1 - c][l];
            table[TABLE_SIZE - 1 - c][l] = table[TABLE_SIZE - 1 - l][TABLE_SIZE - 1 - c];
            table[TABLE_SIZE - 1 - l][TABLE_SIZE - 1 - c] = table[c][TABLE_SIZE - 1 - l];
            table[c][TABLE_SIZE - 1 - l] = pieceValue;
        }
    }
}