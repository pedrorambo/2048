#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "lib/prints.h"
#include "lib/utils.h"
#include "lib/tableLogic.h"
#include "lib/tablePlays.h"

int main()
{
    srand(time(NULL));
    int table[TABLE_SIZE][TABLE_SIZE] = {0};
    int changed = 0;

    // Init game
    addInitialPiecesToTable(table);
    printTable(table);

    changed = playDown(table);
    printTable(table);
    printf("Changed: %d\n", changed);

    changed = playLeft(table);
    printTable(table);
    printf("Changed: %d\n", changed);

    changed = playUp(table);
    printTable(table);
    printf("Changed: %d\n", changed);

    changed = playRight(table);
    printTable(table);
    printf("Changed: %d\n", changed);

    changed = playRight(table);
    printTable(table);
    printf("Changed: %d\n", changed);
}