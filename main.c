#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zoo.h"
#include "type.h"
#include "animal.h"

int test_1(zoo_t *zoo, type_t *types)
{
    // frog
    // 0,0,1,0,0,1,1,1,1,1,0,0,4,0,0,0
    animal_t animal;
    char *excpected = "Amphibian";
    animal.hair = 0;
    animal.feathers = 0;
    animal.eggs = 1;
    animal.milk = 0;
    animal.airborne = 0;
    animal.aquatic = 1;
    animal.predator = 1;
    animal.toothed = 1;
    animal.backbone = 1;
    animal.breathes = 1;
    animal.venomous = 0;
    animal.fins = 0;
    animal.legs = 4;
    animal.tail = 0;
    animal.domestic = 0;
    animal.catsize = 0;
    char *result = classify(zoo, types, animal);
    printf("----------------- Test 1 -----------------\n");
    printf("%15s : %2s%s\n", "Animal name", "", "Frog");
    printf("%15s : %2s%s\n", "Output", "", result);
    printf("%15s : %2s%s\n", "Excepted", "", excpected);
    printf("------------------------------------------\n");
    return strcmp(result, excpected) == 0;
}

int test_2(zoo_t *zoo, type_t *types)
{
    // starfish
    // 0 0 1 0 0 1 1 0 0 0 0 0 5 0 0 0
    animal_t animal;
    char *excpected = "Invertebrate";
    animal.hair = 0;
    animal.feathers = 0;
    animal.eggs = 1;
    animal.milk = 0;
    animal.airborne = 0;
    animal.aquatic = 1;
    animal.predator = 1;
    animal.toothed = 0;
    animal.backbone = 0;
    animal.breathes = 0;
    animal.venomous = 0;
    animal.fins = 0;
    animal.legs = 5;
    animal.tail = 0;
    animal.domestic = 0;
    animal.catsize = 0;
    char *result = classify(zoo, types, animal);
    printf("----------------- Test 2 -----------------\n");
    printf("%15s : %2s%s\n", "Animal name", "", "Starfish");
    printf("%15s : %2s%s\n", "Output", "", result);
    printf("%15s : %2s%s\n", "Excepted", "", excpected);
    printf("------------------------------------------\n");
    return strcmp(result, excpected) == 0;
}

int test_3(zoo_t *zoo, type_t *types)
{
    // seasnake
    // 0	0	0	0	0	1	1	1	1	0	1	0	0	1	0	0
    animal_t animal;
    char *excpected = "Reptile";
    animal.hair = 0;
    animal.feathers = 0;
    animal.eggs = 0;
    animal.milk = 0;
    animal.airborne = 0;
    animal.aquatic = 1;
    animal.predator = 1;
    animal.toothed = 1;
    animal.backbone = 1;
    animal.breathes = 0;
    animal.venomous = 1;
    animal.fins = 0;
    animal.legs = 0;
    animal.tail = 1;
    animal.domestic = 0;
    animal.catsize = 0;
    char *result = classify(zoo, types, animal);
    printf("----------------- Test 3 -----------------\n");
    printf("%15s : %2s%s\n", "Animal name", "", "Seasnake");
    printf("%15s : %2s%s\n", "Output", "", result);
    printf("%15s : %2s%s\n", "Excepted", "", excpected);
    printf("------------------------------------------\n");
    return strcmp(result, excpected) == 0;
}

int test_4(zoo_t *zoo, type_t *types)
{
    // wolf
    // 1,0,0,1,0,0,1,1,1,1,0,0,4,1,0,1
    animal_t animal;
    char *excpected = "Mammal";
    animal.hair = 1;
    animal.feathers = 0;
    animal.eggs = 0;
    animal.milk = 1;
    animal.airborne = 0;
    animal.aquatic = 0;
    animal.predator = 1;
    animal.toothed = 1;
    animal.backbone = 1;
    animal.breathes = 1;
    animal.venomous = 0;
    animal.fins = 0;
    animal.legs = 4;
    animal.tail = 1;
    animal.domestic = 0;
    animal.catsize = 1;
    char *result = classify(zoo, types, animal);
    printf("----------------- Test 4 -----------------\n");
    printf("%15s : %2s%s\n", "Animal name", "", "Wolf");
    printf("%15s : %2s%s\n", "Output", "", result);
    printf("%15s : %2s%s\n", "Excepted", "", excpected);
    printf("------------------------------------------\n");
    return strcmp(result, excpected) == 0;
}

int test_5(zoo_t *zoo, type_t *types)
{
    // octopus
    // 0,0,1,0,0,1,1,0,0,0,0,0,8,0,0,1
    animal_t animal;
    char *excpected = "Invertebrate";
    animal.hair = 0;
    animal.feathers = 0;
    animal.eggs = 1;
    animal.milk = 0;
    animal.airborne = 0;
    animal.aquatic = 1;
    animal.predator = 1;
    animal.toothed = 0;
    animal.backbone = 0;
    animal.breathes = 0;
    animal.venomous = 0;
    animal.fins = 0;
    animal.legs = 8;
    animal.tail = 0;
    animal.domestic = 0;
    animal.catsize = 1;
    char *result = classify(zoo, types, animal);
    printf("----------------- Test 5 -----------------\n");
    printf("%15s : %2s%s\n", "Animal name", "", "Octopus");
    printf("%15s : %2s%s\n", "Output", "", result);
    printf("%15s : %2s%s\n", "Excepted", "", excpected);
    printf("------------------------------------------\n");
    return strcmp(result, excpected) == 0;
}
int main()
{
    int test_cases = 5, successful_test = 0;
    zoo_t zoo = read_zoo_from_csv("./dataset/zoo.csv");
    type_t types = read_type_from_csv("./dataset/type.csv");
    successful_test += test_1(&zoo, &types);
    successful_test += test_2(&zoo, &types);
    successful_test += test_3(&zoo, &types);
    successful_test += test_4(&zoo, &types);
    successful_test += test_5(&zoo, &types);
    double accurency = (double)successful_test / test_cases * 100;
    printf("------------------------------------------\n");
    printf("%20s : %d\n", "Number of tests", test_cases);
    printf("%20s : %d\n", "Successful tests", successful_test);
    printf("%20s : %.0lf%% \n", "Accurency rate", accurency);
    printf("------------------------------------------\n");

    return 0;
}