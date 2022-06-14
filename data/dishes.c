#ifndef DISH_D_H
#define DISH_D_H
#include "../models/dish.h"

dish dishes[7];

void initDishes()
{
for (int i = 0; i < 7; i++)
{
  dishes[i].id = -1;
}
}

#endif