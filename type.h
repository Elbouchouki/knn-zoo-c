#ifndef TYPE_H
#define TYPE_H

#define MAXTYPE 10

typedef struct
{
    int num;
    char name[20];
    int frequence;
} type_T;

typedef struct
{
    type_T types[MAXTYPE];
    int taille;
} type_t;

void afficher_types(type_t *);

void reset(type_t *);
int trie_type(type_t *);
type_t read_type_from_csv(char *);

#endif