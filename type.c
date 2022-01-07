#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "type.h"

#define MAXCHAR 1024

int get_max(type_t *types)
{
    int i, max_index = 0;
    for (i = 0; i < types->taille; i++)
        if (types->types[max_index].frequence <= types->types[i].frequence)
            max_index = i;
    return max_index;
}

void insert_type(char *line, type_t *types)
{
    const char *tok;
    char *token = strtok(line, ",");
    char *values[2];
    type_T type;
    char c[20];
    int i = 0;
    while (token != NULL)
    {
        values[i++] = token;
        token = (char *)strtok(NULL, ",");
    }
    strncpy(type.name, values[1], 20);
    strtok(type.name, "\n");
    type.num = atoi(values[0]);
    type.frequence = 0;
    types->types[types->taille] = type;
    types->taille = types->taille + 1;
}

type_t read_type_from_csv(char *filename)
{
    type_t types;
    types.taille = 0;
    FILE *stream = fopen(filename, "r");
    char line[MAXCHAR];
    fgets(line, MAXCHAR, stream);
    while (fgets(line, MAXCHAR, stream))
    {
        char *tmp = strdup(line);
        insert_type(tmp, &types);
        free(tmp);
    }
    return types;
}

void reset(type_t *types)
{
    for (int i = 0; i < types->taille; i++)
    {
        types->types[i].frequence = 0;
    }
}

void afficher_types(type_t *types)
{
    printf("types stats:\n");
    for (int i = 0; i < types->taille; i++)
    {
        printf("%5d %15s : %d \n", types->types[i].num, types->types[i].name, types->types[i].frequence);
    }
}
