#include <stdio.h>
#include <stdlib.h>
#include "animal.h"

const char *boolHelper(int bool_val)
{
    if (bool_val)
        return "oui";
    else
        return "non";
}

void afficher(animal_t animal)
{
    printf("\t\n");
    printf("%15s%2s%s\n", "- name", ":", animal.animal_name);
    printf("%15s%2s%s\n", "- hair", ":", boolHelper(animal.hair));
    printf("%15s%2s%s\n", "- eggs", ":", boolHelper(animal.eggs));
    printf("%15s%2s%s\n", "- feathers", ":", boolHelper(animal.feathers));
    printf("%15s%2s%s\n", "- milk", ":", boolHelper(animal.milk));
    printf("%15s%2s%s\n", "- airborne", ":", boolHelper(animal.airborne));
    printf("%15s%2s%s\n", "- aquatic", ":", boolHelper(animal.aquatic));
    printf("%15s%2s%s\n", "- predator", ":", boolHelper(animal.predator));
    printf("%15s%2s%s\n", "- toothed", ":", boolHelper(animal.toothed));
    printf("%15s%2s%s\n", "- backbone", ":", boolHelper(animal.backbone));
    printf("%15s%2s%s\n", "- breathes", ":", boolHelper(animal.breathes));
    printf("%15s%2s%s\n", "- venomous", ":", boolHelper(animal.venomous));
    printf("%15s%2s%s\n", "- fins", ":", boolHelper(animal.fins));
    printf("%15s%2s%d\n", "- legs", ":", animal.legs);
    printf("%15s%2s%s\n", "- tail", ":", boolHelper(animal.tail));
    printf("%15s%2s%s\n", "- domestic", ":", boolHelper(animal.domestic));
    printf("%15s%2s%s\n", "- catsize", ":", boolHelper(animal.catsize));
    printf("%15s%2s%d\n", "- type", ":", animal.type_id);
}
