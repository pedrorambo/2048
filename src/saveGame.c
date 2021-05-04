#include <stdio.h>
#include <core.h>
#include <ranking.h>
#include <string.h>
#include <saveGame.h>
#include <tableLogic.h>

/*Função para salvar progresso em um arquivo externo*/
void saveGame(t_tableData *tableData, char *filename)
{
    t_saveData saveData = {0};
    saveData.movements = tableData->movements;
    saveData.score = tableData->score;
    copyTable(tableData->table, saveData.table);

    FILE *file;
    file = fopen(filename, "w");
    fwrite(&saveData, sizeof(t_saveData), 1, file);
    fflush(file);
    fclose(file);
}

/*Função para carregar arquivo com um jogo em progresso*/
int loadGame(t_tableData *tableData, char *filename)
{
    t_saveData saveData = {0};

    FILE *file;
    file = fopen(filename, "r");

    if (file != NULL)
    {
        fread(&saveData, sizeof(t_saveData), 1, file);
        fclose(file);

        tableData->score = saveData.score;
        tableData->movements = saveData.movements;
        copyTable(saveData.table, tableData->table);
        return 1;
    }
    return 0;
}
