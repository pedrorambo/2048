#ifndef UTILS_H
#define UTILS_H

/*Função para obter um número aleatório*/
float getRandomNumber(int, int);

/*Função para determinar chance do valor aleatório a ser adicionado na tabela ser 2 ou 4(10%)*/
int getRandomBooleanByChance(int);

/*Função para determinar se um tecla é uma letra ou um número*/
int keyIsAlphanumerical(char key);

#endif