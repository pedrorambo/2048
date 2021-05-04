#include <config.h>
#include <tableLogic.h>
#include <core.h>

/*Função para limpar o nome do arquivo*/
void clearFileName(t_tableData *tableData)
{
    for (int i = 0; i < MAX_FILENAME - 1; i++)
    {
        tableData->filename[i] = '\0';
    }
}

/*Função para reinicializar os dados do jogo*/
void flushData(t_tableData *tableData)
{
    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            tableData->table[l][c] = 0;
        }
    }

    clearFileName(tableData);
    tableData->score = 0;
    tableData->movements = 0;
    tableData->gameFinished = 0;
}

/*Função para adicionar duas peças ao tabuleiro no ínicio do jogo*/
void addInitialPieces(t_tableData *tableData)
{
    addInitialPiecesToTable(tableData->table);
}

/* Verifica se já existe a peça 2048, ou se não existem mais jogadas possíveis */
int checkGameEnded(t_tableData *tableData)
{
    t_tableData copyTableData = {0};
    copyTable(tableData->table, copyTableData.table);
    copyTableData.movements = tableData->movements;
    int initialMovements = tableData->movements;

    for (int l = 0; l < TABLE_SIZE; l++)
    {
        for (int c = 0; c < TABLE_SIZE; c++)
        {
            if (tableData->table[l][c] == 2048)
            {
                return 1;
            }
        }
    }

    playDown(&copyTableData, 1);
    playUp(&copyTableData, 1);
    playRight(&copyTableData, 1);
    playLeft(&copyTableData, 1);

    if (copyTableData.movements == initialMovements)
    {
        return 1;
    }

    return 0;
}

/* Aplica a jogada, verificando se houveram alterações */
void play(t_tableData *tableData, int fake)
{
    int changed = applyDownMovement(tableData->table, &(tableData->score));
    if (changed != 0)
    {
        tableData->movements += 1;
        addPiecesToTable(tableData->table);
    }
    if (!fake && checkGameEnded(tableData))
        tableData->gameFinished = 1;
}

/*Função para mover as peças para cima*/
void playUp(t_tableData *tableData, int fake)
{
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    play(tableData, fake);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
}

/*Função para mover as peças para baixo*/
void playDown(t_tableData *tableData, int fake)
{
    play(tableData, fake);
}

/*Função para mover as peças para esquerda*/
void playLeft(t_tableData *tableData, int fake)
{
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    play(tableData, fake);
    rotateClockwise(tableData->table);
}

/*Função para mover as peças para direita*/
void playRight(t_tableData *tableData, int fake)
{
    rotateClockwise(tableData->table);
    play(tableData, fake);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
    rotateClockwise(tableData->table);
}
