#include <stdio.h>
#include <core.h>
#include <ranking.h>
#include <string.h>
#include <logFile.h>
#include <stdlib.h>

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

    fprintf(file, "%d\n", tableData->rankingSize);

    for (int i = 0; i < tableData->rankingSize; i++)
    {
        fprintf(file, "%d %s\n", tableData->ranking[i].score, tableData->ranking[i].name);
    }

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
        fscanf(file, "%d ", &rankingSize);
        t_user ranking[rankingSize];

        for (int i = 0; i < rankingSize; i++)
        {
            int score;
            char name[USERNAME_MAX_LENGTH + 1];

            char *tok;
            char readString[READ_STRING_SIZE + 1] = {0};

            fgets(readString, READ_STRING_SIZE, file);

            tok = strtok(readString, " ");
            score = atoi(tok);

            tok = strtok(NULL, " ");
            ranking[i].score = score;
            tok[strlen(tok) - 1] = '\0';
            strcpy(ranking[i].name, tok);
        }

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
            if (playerRanked(tableData))
            {
                int index = tableData->rankingSize - 1;
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