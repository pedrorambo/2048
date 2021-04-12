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



int main()
{
    srand(time(NULL));
    int table[TABLE_SIZE][TABLE_SIZE] = {0};

    addValueToRandomPositionOnTable(table, 2);
    addValueToRandomPositionOnTable(table, 2);

    //TODO Executar gravirt TAMANHO/2 vezes

    printTable(table);

    applyDownGravity(table);
    printTable(table);

    applyDownGravity(table);
    printTable(table);

    applyDownGravity(table);
    printTable(table);
    

    printf("Hello, world!");
}