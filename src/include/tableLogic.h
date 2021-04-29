#include <config.h>

int getRandomPosition();

void addValueToRandomPositionOnTable(int[TABLE_SIZE][TABLE_SIZE], int);

void getTableLine(int[TABLE_SIZE], int[TABLE_SIZE][TABLE_SIZE], int);

void applyDownGravity(int[TABLE_SIZE][TABLE_SIZE]);

void copyTable(int[TABLE_SIZE][TABLE_SIZE], int[TABLE_SIZE][TABLE_SIZE]);

int compareTables(int[TABLE_SIZE][TABLE_SIZE], int[TABLE_SIZE][TABLE_SIZE]);

int applyDownMovement(int[TABLE_SIZE][TABLE_SIZE]);

void addInitialPiecesToTable(int[TABLE_SIZE][TABLE_SIZE]);

void addPiecesToTable(int[TABLE_SIZE][TABLE_SIZE]);

void rotateClockwise(int[TABLE_SIZE][TABLE_SIZE]);