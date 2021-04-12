#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TABLE_SIZE 4

float getRandomNumber(int min, int max)
{
    int randomNumber = rand();
    return min + (rand() % (max - min + 1));
}

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
        if(!isOccupied){
            table[l][c] = value;
        }
    } while (isOccupied);
}

void printTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            printf("%3d ", table[l][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void printLine(int line[TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        printf("%3d ", line[l]);
    }
    printf("\n");
}

void getTableLine(int line[TABLE_SIZE], int table[TABLE_SIZE][TABLE_SIZE], int lineIndex){
    for(int i = 0; i < TABLE_SIZE; i++){
        line[i] = table[lineIndex][i];
    }
}

void applyDownGravity(int table[TABLE_SIZE][TABLE_SIZE]){
    for (int l = 1; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            if(table[(l - 1)][c] != 0 && table[l][c] == 0){
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
            if(table1[l][c] != table2[l][c]){
                return 1;
            }
        }
    }
    return 0;
}

int applyDownMovement(int table[TABLE_SIZE][TABLE_SIZE]){
    int previousTable[TABLE_SIZE][TABLE_SIZE] = {0};
    copyTable(table, previousTable);

    for(int i = 0; i < TABLE_SIZE; i++){
        applyDownGravity(table);
    }

    for (int l = (TABLE_SIZE - 1); l > 0; l--)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            int upValue = table[(l - 1)][c];
            if(upValue != 0 && upValue == table[l][c]){
                table[(l - 1)][c] = 0;
                table[l][c] *= 2;
            }
        }
    }

    for(int i = 0; i < TABLE_SIZE; i++){
        applyDownGravity(table);
    }

    return compareTables(previousTable, table);
}

int main()
{
    srand(time(NULL));
    int table[TABLE_SIZE][TABLE_SIZE] = {0};

    //addValueToRandomPositionOnTable(table, 2);
    //addValueToRandomPositionOnTable(table, 2);

    table[0][3] = 0;
    table[1][3] = 0;
    table[2][3] = 2;
    table[3][3] = 8;

    printTable(table);

    int changed = applyDownMovement(table);

    printTable(table);
    printf("Changed: %d\n", changed);

    printf("Hello, world!");
}