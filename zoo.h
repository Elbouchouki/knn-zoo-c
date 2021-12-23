#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "type.h"

#define MAXANIMALS 150

typedef struct
{
    int taille;
    animal_t animals[MAXANIMALS];
} zoo_t;

zoo_t read_zoo_from_csv(char *);

void trie(zoo_t *);

char *classify(zoo_t *, type_t *, animal_t);

#endif
