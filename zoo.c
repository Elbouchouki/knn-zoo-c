#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "zoo.h"

#define ZOOLENGTH 18
#define MAXCHAR 1024

void insertAnimal(char *line, zoo_t *zoo)
{
    const char *tok;
    char *token = strtok(line, ",");
    animal_t animal;
    char *values[ZOOLENGTH];
    int i = 0;
    while (token != NULL)
    {
        values[i++] = token;
        token = (char *)strtok(NULL, ",");
    }
    strncpy(animal.animal_name, values[0], 20);
    strtok(animal.animal_name, "\n");
    animal.hair = atoi(values[1]);
    animal.feathers = atoi(values[2]);
    animal.eggs = atoi(values[3]);
    animal.milk = atoi(values[4]);
    animal.airborne = atoi(values[5]);
    animal.aquatic = atoi(values[6]);
    animal.predator = atoi(values[7]);
    animal.toothed = atoi(values[8]);
    animal.backbone = atoi(values[9]);
    animal.breathes = atoi(values[10]);
    animal.venomous = atoi(values[11]);
    animal.fins = atoi(values[12]);
    animal.legs = atoi(values[13]);
    animal.tail = atoi(values[14]);
    animal.domestic = atoi(values[15]);
    animal.catsize = atoi(values[16]);
    animal.type_id = atoi(values[17]);
    zoo->animals[zoo->taille] = animal;
    zoo->taille = zoo->taille + 1;
}

zoo_t read_zoo_from_csv(char *filename)
{
    zoo_t zoo;
    zoo.taille = 0;
    FILE *stream = fopen(filename, "r");
    char line[MAXCHAR];
    fgets(line, MAXCHAR, stream);
    while (fgets(line, MAXCHAR, stream))
    {
        char *tmp = strdup(line);
        insertAnimal(tmp, &zoo);
        free(tmp);
    }
    return zoo;
}

void trie(zoo_t *zoo)
{
    int i, j;
    for (i = 0; i < zoo->taille; i++)
        for (j = 0; j < zoo->taille - i; j++)
            if (zoo->animals[j].distance > zoo->animals[j + 1].distance)
            {
                animal_t temp = zoo->animals[j];
                zoo->animals[j] = zoo->animals[j + 1];
                zoo->animals[j + 1] = temp;
            }
}

char *classify(zoo_t *zoo, type_t *types, animal_t animal_x)
{
    reset(types);
    int k = sqrt(zoo->taille) / 2;
    for (int i = 0; i < zoo->taille; i++)
    {
        zoo->animals[i].distance = sqrt(
            (zoo->animals[i].hair - animal_x.hair) * (zoo->animals[i].hair - animal_x.hair) +
            (zoo->animals[i].feathers - animal_x.feathers) *
                (zoo->animals[i].feathers - animal_x.feathers) +
            (zoo->animals[i].eggs - animal_x.eggs) *
                (zoo->animals[i].eggs - animal_x.eggs) +
            (zoo->animals[i].milk - animal_x.milk) *
                (zoo->animals[i].milk - animal_x.milk) +
            (zoo->animals[i].airborne - animal_x.airborne) *
                (zoo->animals[i].airborne - animal_x.airborne) +
            (zoo->animals[i].aquatic - animal_x.aquatic) *
                (zoo->animals[i].aquatic - animal_x.aquatic) +
            (zoo->animals[i].predator - animal_x.predator) *
                (zoo->animals[i].predator - animal_x.predator) +
            (zoo->animals[i].toothed - animal_x.toothed) *
                (zoo->animals[i].toothed - animal_x.toothed) +
            (zoo->animals[i].backbone - animal_x.backbone) *
                (zoo->animals[i].backbone - animal_x.backbone) +
            (zoo->animals[i].breathes - animal_x.breathes) *
                (zoo->animals[i].breathes - animal_x.breathes) +
            (zoo->animals[i].venomous - animal_x.venomous) *
                (zoo->animals[i].venomous - animal_x.venomous) +
            (zoo->animals[i].fins - animal_x.fins) *
                (zoo->animals[i].fins - animal_x.fins) +
            (zoo->animals[i].legs - animal_x.legs) *
                (zoo->animals[i].legs - animal_x.legs) +
            (zoo->animals[i].tail - animal_x.tail) *
                (zoo->animals[i].tail - animal_x.tail) +
            (zoo->animals[i].domestic - animal_x.domestic) *
                (zoo->animals[i].domestic - animal_x.domestic) +
            (zoo->animals[i].catsize - animal_x.catsize) *
                (zoo->animals[i].catsize - animal_x.catsize));
    }
    trie(zoo);
    for (int i = 0; i < k; i++)
    {
        types->types[zoo->animals[i].type_id - 1].frequence++;
    }
    // afficher_types(types);
    int max = trie_type(types);
    // printf("max : %d\n", max);
    // afficher_types(types);
    return types->types[max].name;
}
