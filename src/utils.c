#include <stdlib.h>

/*Função para obter um número aleatório*/
float getRandomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

/*Função para determinar chance do valor aleatório a ser adicionado na tabela ser 2 ou 4(10%)*/
int getRandomBooleanByChance(int chance)
{
    int randomNumber = getRandomNumber(1, 100);
    return randomNumber <= chance;
}

/*Função para determinar se um tecla é uma letra ou um número*/
int keyIsAlphanumerical(char key)
{
    return (key >= 65 && key <= 90) || (key >= 97 && key <= 122);
}