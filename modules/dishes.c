#ifndef DISHES_H
#define DISHES_H
#include <stdio.h>
#include <stdlib.h>
#include "../data/dish.c"
#include "../models/dish.h"
#include "../lib/utils.h"
#include "../lib/constants.h"
#include "../database/sqlite3.h"

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
    for (int i = 0; i < 7; i++)
    {
        dishes[i] = readDish(i+1);
    }
    saveDishes();
}

void printDishes()
{
    for (int i = 0; i < 7; i++)
    {
        printf("\n%d - %s - $%.2f", dishes[i].id, dishes[i].name, dishes[i].price);
    }
}

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

void saveDishes()
{
  for (int i = 0; i < 7; i++)
  {
    saveDish(&dishes[i]);
  }
}

void loadDishes(){
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
   else
     {
       printf("Base de datos OK\n");
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
    if (i > 6){
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

#endif
