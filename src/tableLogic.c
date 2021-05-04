#include <math.h>
#include <config.h>
#include <utils.h>
#include <tableLogic.h>

/*Função para obter posições aleatórias do tabuleiro*/
int getRandomPosition()
{
    int minValue = 0;
    int maxValue = (TABLE_SIZE * TABLE_SIZE) - 1;

    return getRandomNumber(minValue, maxValue);
}

/*Função para atribuir um valor para uma posição aleatória*/
void addValueToRandomPositionOnTable(int table[TABLE_SIZE][TABLE_SIZE], int value)
{
    int isOccupied = 0;
    do
    {
        int randomPosition = getRandomPosition();
        int l = floor(randomPosition / TABLE_SIZE);
        int c = randomPosition % TABLE_SIZE;
        isOccupied = table[l][c];
        if (!isOccupied)
        {
            table[l][c] = value;
        }
    } while (isOccupied);
}

/*Função para extrair uma linha do tabuleiro*/
void getTableLine(int line[TABLE_SIZE], int table[TABLE_SIZE][TABLE_SIZE], int lineIndex)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        line[i] = table[lineIndex][i];
    }
}

/*Função para aplicar um movimento pra baixo(gravidade) nas peças do tabuleiro, considerando colisões*/
void applyDownGravity(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 1; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            if (table[(l - 1)][c] != 0 && table[l][c] == 0)
            {
                table[l][c] = table[(l - 1)][c];
                table[(l - 1)][c] = 0;
            }
        }
    }
}

/*Função para copiar um tabuleiro*/
void copyTable(int incoming[TABLE_SIZE][TABLE_SIZE], int outcoming[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            outcoming[l][c] = incoming[l][c];
        }
    }
}

/*Função para comparar se houve mudanças entre duas tabelas*/
int compareTables(int table1[TABLE_SIZE][TABLE_SIZE], int table2[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            if (table1[l][c] != table2[l][c])
            {
                return 1;
            }
        }
    }
    return 0;
}

/*Função para comparar se é possivel somar os valores das peças, e se possível, aplica a soma e o movimento pra baixo, ignorando colisões*/
int applyDownMovement(int table[TABLE_SIZE][TABLE_SIZE], int *score)
{
    int previousTable[TABLE_SIZE][TABLE_SIZE] = {0};
    copyTable(table, previousTable);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        applyDownGravity(table);
    }

    for (int l = (TABLE_SIZE - 1); l > 0; l--)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            int upValue = table[(l - 1)][c];
            if (upValue != 0 && upValue == table[l][c])
            {
                table[(l - 1)][c] = 0;
                table[l][c] *= 2;
                *score += upValue * 2;
            }
        }
    }

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        applyDownGravity(table);
    }

    return compareTables(previousTable, table);
}

/*Função para adicionar duas peças em posições aleatórias no ínicio do jogo*/
void addInitialPiecesToTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int i = 0; i < INITIAL_PIECES_QUANTITY; i++)
    {
        addValueToRandomPositionOnTable(table, INITIAL_PIECES_VALUE);
    }
}

/*Função para adicionar peças ao tabuleiro*/
void addPiecesToTable(int table[TABLE_SIZE][TABLE_SIZE])
{
    int pieceValue = INITIAL_PIECES_VALUE;
    if (getRandomBooleanByChance(SECONDARY_PIECE_CHANCE))
        pieceValue = SECONDARY_PIECE_VALUE;
    addValueToRandomPositionOnTable(table, pieceValue);
}

/*Função para rotacionar o tabuleiro(matriz), no sentido horário em 90 graus*/
void rotateClockwise(int table[TABLE_SIZE][TABLE_SIZE])
{
    for (int l = 0; l < TABLE_SIZE / 2; l++)
    {
        for (int c = l; c < TABLE_SIZE - l - 1; c++)
        {
            int pieceValue = table[l][c];
            table[l][c] = table[TABLE_SIZE - 1 - c][l];
            table[TABLE_SIZE - 1 - c][l] = table[TABLE_SIZE - 1 - l][TABLE_SIZE - 1 - c];
            table[TABLE_SIZE - 1 - l][TABLE_SIZE - 1 - c] = table[c][TABLE_SIZE - 1 - l];
            table[c][TABLE_SIZE - 1 - l] = pieceValue;
        }
    }
}