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

int keyIsAlphanumerical(char key)
{
    return (key >= 65 && key <= 90) || (key >= 97 && key <= 122);
}