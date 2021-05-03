#include <stdio.h>
#include <core.h>
#include <rankingPersistence.h>
#include <string.h>

void saveRanking(t_tableData *tableData)
{
    FILE *file;
    file = fopen(FILE_NAME, "w");
    fwrite(&(tableData->rankingSize), sizeof(int), 1, file);
    fwrite(tableData->ranking, sizeof(t_user), tableData->rankingSize, file);
    fflush(file);
    fclose(file);
}

void loadRanking(t_tableData *tableData)
{
    FILE *file;
    int rankingSize = 0;
    file = fopen(FILE_NAME, "r");

    if (file != NULL)
    {
        fread(&rankingSize, sizeof(int), 1, file);
        t_user ranking[rankingSize];
        fread(ranking, sizeof(t_user), rankingSize, file);
        fclose(file);

        tableData->rankingSize = rankingSize;

        for (int i = 0; i < rankingSize; i++)
        {
            tableData->ranking[i].score = ranking[i].score;
            strcpy(tableData->ranking[i].name, ranking[i].name);
        }
    }

    tableData->rankingSize = rankingSize;
}