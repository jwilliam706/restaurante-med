#ifndef BILL_SQL_H
#define BILL_SQL_H

#include <stdio.h>
#include <stdlib.h>
#include "../models/bill.h"
#include "../lib/bill_list.h"
#include "../lib/constants.h"
#include "../database/sqlite3.h"
#include "../data/bills.c"

bill_detail_list *loadBillDetails(int id)
{
  sqlite3 *db;
  char *error = 0;
  int res;
  char sql[100];
  sqlite3_stmt *stmt;

  res = sqlite3_open(DB_FILE, &db);
  if (res)
  {
    printf("No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  snprintf(sql, 100, "SELECT * FROM bill_details where bill_id = %d;", id);
  res = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  bill_detail_list *billDetails = create_bill_detail_list();
  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    bill_detail *detail = malloc(sizeof(bill_detail));
    detail->id = sqlite3_column_int(stmt, 0);
    detail->bill_id = sqlite3_column_int(stmt, 1);
    detail->dish_id = sqlite3_column_int(stmt, 2);
    detail->quantity = sqlite3_column_int(stmt, 3);
    detail->price = sqlite3_column_double(stmt, 4);
    addBillDetail(billDetails, detail);
  }

  sqlite3_finalize(stmt);
  return billDetails;
}

void loadBills()
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

  sql = "SELECT * FROM bills;";
  res = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    bill *b = malloc(sizeof(bill));
    b->id = sqlite3_column_int(stmt, 0);
    b->number = sqlite3_column_int(stmt, 1);
    b->date = sqlite3_column_int(stmt, 2);
    b->subtotal = sqlite3_column_double(stmt, 3);
    b->iva = sqlite3_column_double(stmt, 4);
    b->total = sqlite3_column_double(stmt, 5);
    b->customer_id = sqlite3_column_int(stmt, 6);
    b->details = loadBillDetails(b->id);
    addBill(bills, b);
  }

  sqlite3_finalize(stmt);
}

#endif