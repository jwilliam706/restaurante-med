#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef struct
{
    int id;
    char name[20];
    float price;
} dish;

dish dishes[7];

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