#include <stdio.h>
#include <logFile.h>

void logChar(char *message, char caractere)
{
    FILE *file;
    file = fopen(LOG_FILE, "a+");
    fprintf(file, "%s 0x%x %d\n", message, (unsigned int)caractere, (unsigned int)caractere);
    fflush(file);
    fclose(file);
}

void logString(char *message, char *string)
{
    FILE *file;
    file = fopen(LOG_FILE, "a+");
    fprintf(file, "%s %s\n", message, string);
    fflush(file);
    fclose(file);
}

void logInt(char *message, int value)
{
    FILE *file;
    file = fopen(LOG_FILE, "a+");
    fprintf(file, "%s %d\n", message, value);
    fflush(file);
    fclose(file);
}