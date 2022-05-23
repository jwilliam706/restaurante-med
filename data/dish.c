#ifndef DISH_D_H
#define DISH_D_H
#include "../models/dish.h"

dish dishes[7];

void initDishValues()
{
  dish newDish;

  newDish.id = 0;
  strcpy(newDish.name, "Pizza");
  newDish.price = 12.0;
  dishes[0] = newDish;
}
#endif