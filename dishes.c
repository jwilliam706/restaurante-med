#ifndef DISHES_H
#define DISHES_H
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "models/dish.h"
#include "data/dish.c"

dish readDish(int id)
{
    dish newDish;
    printf("Ingrese el nombre del platillo %d: ", id + 1);
    readString(newDish.name, 20);
    printf("Ingrese el precio del platillo %d: ", id + 1);
    scanf("%f", &newDish.price);
    getchar();
    newDish.id = id;
    return newDish;
}

void readDishes()
{
    for(int i = 0; i < 7; i++)
    {
        dishes[i] = readDish(i);
    }
}

void printDishes()
{
    for(int i = 0; i < 7; i++)
    {
        printf("%d - %s - $%.2f\n", dishes[i].id + 1, dishes[i].name, dishes[i].price);
    }
}
#endif
