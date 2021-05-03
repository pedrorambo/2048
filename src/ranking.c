#include <stdio.h>
#include <core.h>
#include <ranking.h>
#include <string.h>

int indexOfPlayer(t_tableData *tableData)
{
    for (int i = 0; i < tableData->rankingSize; i++)
    {
        if (strcmp(tableData->ranking[i].name, tableData->username) == 0)
            return i;
    }
    return -1;
}

int playerRanked(t_tableData *tableData)
{
    for (int i = 0; i < tableData->rankingSize; i++)
    {
        if (tableData->score >= tableData->ranking[i].score)
            return 1;
    }
    return 0;
}

void addPlayerToRanking(t_tableData *tableData)
{
    int playerIndex = -1;
    t_user user = {0};
    user.score = tableData->score;
    strcpy(user.name, tableData->username);

    sortRanking(tableData);

    playerIndex = indexOfPlayer(tableData);
    if (playerIndex >= 0)
    {
        if (tableData->score > tableData->ranking[playerIndex].score)
            tableData->ranking[playerIndex].score = tableData->score;
    }
    else
    {
        int rankingIsFull = tableData->rankingSize >= RANKING_SIZE;
        if (rankingIsFull)
        {
            if (playerRanked)
            {
                int index = tableData->rankingSize;
                tableData->ranking[index] = user;
                tableData->rankingSize = index;
            }
        }
        else
        {
            int index = tableData->rankingSize;
            tableData->ranking[index] = user;
            tableData->rankingSize = index + 1;
        }
    }

    sortRanking(tableData);
    saveRanking(tableData);
}

void sortRanking(t_tableData *tableData)
{
    t_user tempUser = {0};

    for (int i = 0; i < tableData->rankingSize; i++)
    {
        for (int next = 0; next < tableData->rankingSize; next++)
        {
            if (tableData->ranking[next].score < tableData->ranking[i].score)
            {
                tempUser = tableData->ranking[i];
                tableData->ranking[i] = tableData->ranking[next];
                tableData->ranking[next] = tempUser;
            }
        }
    }
}

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