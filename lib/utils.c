#include <stdlib.h>

float getRandomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int getRandomBooleanByChance(int chance)
{
    int randomNumber = getRandomNumber(1, 100);
    return randomNumber <= chance;
}