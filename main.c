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

void addValue2ToRandomPositionOnTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    int isOccupied = 0;
    do
    {
        int randomPosition = getRandomPosition();
        int l = floor(randomPosition / TABLE_SIZE);
        int c = randomPosition % TABLE_SIZE;
        isOccupied = table[l][c];
        if(!isOccupied){
            table[l][c] = 2;
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

int main()
{
    srand(time(NULL));
    int table[TABLE_SIZE][TABLE_SIZE] = {0};

    addValue2ToRandomPositionOnTable(table);
    printTable(table);
    printf("\n\n");
    
    printf("Hello, world!");
}