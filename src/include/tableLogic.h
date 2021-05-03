#include <config.h>

/*Função para obter posições aleatórias do tabuleiro*/
int getRandomPosition();
/*Função para atribuir um valor para uma posição aleatória*/
void addValueToRandomPositionOnTable(int[TABLE_SIZE][TABLE_SIZE], int);
/*Função para extrair uma linha do tabuleiro*/
void getTableLine(int[TABLE_SIZE], int[TABLE_SIZE][TABLE_SIZE], int);
/*Função para aplicar um movimento pra baixo(gravidade) nas peças do tabuleiro, considerando colisões*/
void applyDownGravity(int[TABLE_SIZE][TABLE_SIZE]);
/*Função para copiar um tabuleiro*/
void copyTable(int[TABLE_SIZE][TABLE_SIZE], int[TABLE_SIZE][TABLE_SIZE]);
/*Função para comparar se houve mudanças entre duas tabelas*/
int compareTables(int[TABLE_SIZE][TABLE_SIZE], int[TABLE_SIZE][TABLE_SIZE]);
/*Função para comparar se é possivel somar os valores das peças, e se possível, aplica a soma e o movimento pra baixo, ignorando colisões*/
int applyDownMovement(int[TABLE_SIZE][TABLE_SIZE], int *score);
/*Função para adicionar duas peças em posições aleatórias no ínicio do jogo*/
void addInitialPiecesToTable(int[TABLE_SIZE][TABLE_SIZE]);
/*Função para adicionar peças ao tabuleiro*/
void addPiecesToTable(int[TABLE_SIZE][TABLE_SIZE]);
/*Função para rotacionar o tabuleiro(matriz), no sentido horário em 90 graus*/
void rotateClockwise(int[TABLE_SIZE][TABLE_SIZE]);