#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "lib/prints.h"
#include "lib/utils.h"
#include "lib/tableLogic.h"

int main()
{
    srand(time(NULL));
    int table[TABLE_SIZE][TABLE_SIZE] = {0};

    table[1][0] = 2;
    table[1][1] = 2;
    table[3][0] = 8;

    printTable(table);

    // Apply right movement

    printf("Rotaciona:\n");
    rotateClockwise(table);
    printTable(table);

    printf("Gravidade:\n");
    applyDownMovement(table);
    printTable(table);

    printf("Rotaciona:\n");
    rotateClockwise(table);
    rotateClockwise(table);//eae 
    rotateClockwise(table);
    printTable(table);
}