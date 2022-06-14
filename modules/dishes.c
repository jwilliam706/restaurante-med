#ifndef DISHES_H
#define DISHES_H
#include <stdio.h>
#include <stdlib.h>
#include "../data/dishes.c"
#include "../models/dish.h"
#include "../lib/utils.h"
#include "../lib/constants.h"
#include "../database/sqlite3.h"

void saveDish(dish *newDish)
{
  sqlite3 *db;
  char *error = 0;
  int res;
  char sql[200];

  res = sqlite3_open(DB_FILE, &db);
  if (res)
  {
    printf("No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  snprintf(sql, 200, "INSERT INTO dishes (id, name, price) VALUES (%d, '%s', %lf);", newDish->id, newDish->name, newDish->price);

  res = sqlite3_exec(db, sql, NULL, 0, &error);
  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", error);
    sqlite3_free(error);
  }
  else
  {
    printf("Registro insertado!\n");
  }
}

dish readDish(int id)
{
  dish newDish;
  printf("Ingrese el nombre del platillo %d: ", id);
  readString(newDish.name, 20);
  printf("Ingrese el precio del platillo %d: ", id);
  scanf("%f", &newDish.price);
  getchar();
  newDish.id = id;
  return newDish;
}

void readDishes()
{
  int savedDishes = 0;
  int lastId = 0;
  printf("Platillos guardados actualmente: \n");
  for (int i = 0; i < 7; i++)
  {
    dish *d = &dishes[i];
    int id = d->id;
    if (id != 0)
    {
      lastId = d->id;
      savedDishes += 1;
      printf("%s\n", d->name);
    }
  }
  waitUser();
  printf("Nuevos platillos a guardar (actuales=%d): \n", savedDishes);
  for (int i = 0; i < 7; i++)
  {
    dish *d = &dishes[i];
    int id = d->id;
    if (id == 0)
    {
      lastId += 1;
      savedDishes += 1;
      printf("%s\n", d->name);
      dishes[i] = readDish(lastId);
      printf("Saved dish %s\n", dishes[i].name);
      saveDish(&dishes[i]);
    }
  }
}

void printDishes()
{
  for (int i = 0; i < 7; i++)
  {
    printf("\n%d - %s - $%.2f", dishes[i].id, dishes[i].name, dishes[i].price);
  }
}

void loadDishes()
{
  sqlite3 *db;
  char *error = 0;
  int res;
  char *sql;
  sqlite3_stmt *stmt;
  res = sqlite3_open(DB_FILE, &db);
  if (res)
  {
    printf("No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  sql = "SELECT * FROM dishes;";

  res = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", sqlite3_errmsg(db));
    exit(0);
  }
  int i = 0;
  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    if (i > 6)
    {
      break;
    }
    dish d;
    d.id = sqlite3_column_int(stmt, 0);
    strcpy(d.name, sqlite3_column_text(stmt, 1));
    d.price = sqlite3_column_double(stmt, 2);
    dishes[i] = d;
    i++;
  }
  sqlite3_finalize(stmt);
}

dish *getDish()
{
  int selectedDish;
  printDishes();
  printf("\nSeleccione el platillo: ");
  scanf("%d", &selectedDish);
  return &dishes[selectedDish - 1];
}

#endif
