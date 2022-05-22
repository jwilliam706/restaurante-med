#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "../lib/constants.h"

void createTables(){
    sqlite3 *db;
   char *error = 0;
   int res;
   char *sql;

   res = sqlite3_open(DB_FILE, &db);
   if (res)
     {
       fprintf(stderr, "No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
       exit(0);
     }
   else
     {
       fprintf(stderr, "Base de datos OK\n");
     }

   sql = "CREATE TABLE dishes ("
     "`id` INT PRIMARY KEY, "
     "`name` TEXT, "
     "`price` FLOAT)";

      res = sqlite3_exec(db, sql, NULL, 0, &error);
   if (res != SQLITE_OK)
     {
       fprintf(stderr, "Error creando tabla dishes: %s\n", error);
       sqlite3_free(error);
     }
   else
     {
       fprintf(stdout, "Tabla dishes creada!\n");
     }

   sql = "CREATE TABLE customers ("
      "`id` INT PRIMARY KEY, "
      "`name` TEXT, "
      "`phone` INT, "
      "`email` TEXT, "
      "`addresss` TEXT)";

       res = sqlite3_exec(db, sql, NULL, 0, &error);
   if (res != SQLITE_OK)
     {
       fprintf(stderr, "Error creando tabla customers: %s\n", error);
       sqlite3_free(error);
     }
   else
     {
       fprintf(stdout, "Tabla customers creada!\n");
     }

   sql = "CREATE TABLE bills ("
      "`id` INT PRIMARY KEY, "
      "`number` INT, "
      "`date` DATETIME, "
      "`subtotal` FLOAT, "
      "`iva` FLOAT, "
      "`total` FLOAT, "
      "`customer_id` INT,"
      "FOREIGN KEY(customer_id) REFERENCES customers(id))";

       res = sqlite3_exec(db, sql, NULL, 0, &error);
   if (res != SQLITE_OK)
     {
       fprintf(stderr, "Error creando tabla bills: %s\n", error);
       sqlite3_free(error);
     }
   else
     {
       fprintf(stdout, "Tabla bills creada!\n");
     }

   sql = "CREATE TABLE bill_details ("
      "`id` INT PRIMARY KEY, "
      "`bill_id` INT, "
      "`dish_id` INT, "
      "`quantity` INT, "
      "`price` FLOAT,"
      "FOREIGN KEY(bill_id) REFERENCES bills(id),"
      "FOREIGN KEY(dish_id) REFERENCES dishes(id))";

       res = sqlite3_exec(db, sql, NULL, 0, &error);
   if (res != SQLITE_OK)
     {
       fprintf(stderr, "Error creando tabla bill_details: %s\n", error);
       sqlite3_free(error);
     }
   else
     {
       fprintf(stdout, "Tabla bill_details creada!\n");
     }

   sqlite3_close(db);
}