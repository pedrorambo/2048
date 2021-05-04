#include <stdio.h>
#include <config.h>

/*Função para imprimir a tabela no terminal*/
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

/*Função para imprimir uma linha no terminal*/
void printLine(int line[TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        printf("%3d ", line[l]);
    }
    printf("\n");
}