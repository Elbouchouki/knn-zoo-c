#ifndef ANIMAL_H
#define ANIMAL_H

#define NAME_MAX 30

typedef struct
{
    char animal_name[NAME_MAX];
    int hair, feathers, eggs, milk, airborne, aquatic, predator, toothed, backbone, breathes, venomous, fins, legs, tail, domestic, catsize, type_id;
    double distance;
} animal_t;

void afficher(animal_t);
#endif