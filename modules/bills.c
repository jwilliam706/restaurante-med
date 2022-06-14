#include <stdio.h>
#include <stdlib.h>
#include "dishes.c"
#include "customers.c"
#include "../models/bill.h"
#include "../lib/utils.h"
#include "../lib/bill_sql.h"
#include "../lib/bill_list.h"
#include "../lib/constants.h"
#include "../database/sqlite3.h"
#include "totalSales.h"

void saveBillDetails(int bill_id, bill_detail_list *details)
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

  bill_detail_node *current = details->head;
  int successCount = 0;
  while (current != NULL)
  {
    bill_detail *detail = current->value;
    snprintf(sql, 200, "INSERT INTO bill_details (bill_id, dish_id, quantity, price) VALUES (%d, %d, %d, %lf);",
             bill_id, detail->dish_id, detail->quantity, detail->price);
    res = sqlite3_exec(db, sql, NULL, 0, &error);
    if (res != SQLITE_OK)
    {
      printf("Error: %s\n", error);
      sqlite3_free(error);
    }
    int id = sqlite3_last_insert_rowid(db);
    detail->id = id;
    successCount++;
    current = current->next;
  }
}

int saveBill(bill *newBill)
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

  snprintf(sql, 200, "INSERT INTO bills (number, date, subtotal, iva, total, customer_id) VALUES (%d, %ld, %lf, %lf, %lf, %d);",
           newBill->number, newBill->date, newBill->subtotal, newBill->iva, newBill->total, newBill->customer_id);

  res = sqlite3_exec(db, sql, NULL, 0, &error);
  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", error);
    sqlite3_free(error);
  }
  int id = sqlite3_last_insert_rowid(db);
  newBill->id = id;
  saveBillDetails(id, newBill->details);

  return id;
}

bill_detail_list *readBillDetails()
{
  bill_detail_list *details = create_bill_detail_list();
  int option = 1;
  printf("\n\n---------------------------------------Nueva Factura---------------------------------------\n");
  getCurrentTime();
  while (option != 2)
  {
    bill_detail *detail = malloc(sizeof(bill_detail));
    dish *dish = getDish();

    detail->price = dish->price;
    detail->dish_id = dish->id;
    strcpy(detail->name, dish->name);

    printf("Ingrese la cantidad: ");
    scanf("%d", &detail->quantity);

    addBillDetail(details, detail);
    printBillDetail(detail);
    printf("Desea agregar otro platillo?\n");
    printf("[1] Si\n");
    printf("[2] No\n");
    scanf("%d", &option);
    getchar();
  }

  return details;
}

int getNextBillNumber()
{
  bill_node *current = bills->head;
  time_t currentTime = getCurrentTime();
  int max = 0;
  while (current != NULL)
  {
    if (current->value->date > getStartOfTodayTime())
    {
      if (current->value->number > max)
      {
        max = current->value->number;
      }
    }

    current = current->next;
  }
  return max + 1;
}

float calculateBillSubTotal(bill_detail_list *details)
{
  //- Head of Bill detail list
  bill_detail_node *current = details->head; //- Bill details head set
  float bill_total_accumulator = 0.0;        //- Bill Total accumulator init

  //- If bill details list is empty
  if (current != NULL)
  {
    while (current != NULL)
    {
      bill_total_accumulator += (current->value->quantity * current->value->price);
      current = current->next;
    }
    return bill_total_accumulator;
  }
  else
  {
    return 0.0; // Bill doesnt have details
  }
}

float calculateBillIVA(bill *bill)
{
  return bill->subtotal * 0.13;
}

float calculateBillTotal(bill *bill)
{
  return bill->subtotal + bill->iva;
}
//- End of calculateBillTotal

void printBill(bill *bill)
{
  printf("---------------------------------------Factura %d-------------------------------------\n", bill->number);
  printf("\nFecha de factura: %s\n", getLocaleCurrentTimeFor(&(bill->date)));
  printf("\nPlatillo\tCantidad\tPrecio Unitario\t\tPrecio total");
  printf("\n-------------------------------------------------------------------------------------\n");
  bill_detail_node *current = bill->details->head;
  while (current != NULL)
  {
    printf("%d", current->value->dish_id);
    printf("\t\t%d", current->value->quantity);
    printf("\t\t$%'.2f", current->value->price);
    printf("\t\t\t$%'.2f", current->value->quantity * current->value->price);
    printf("\n");
    current = current->next;
  }

  printf("-------------------------------------------------------------------------------------\n\n");
  printf("\nSubtotal: ----------------------------------------------------------------  $%8.2f\n", bill->subtotal);
  printf("\nIVA: ---------------------------------------------------------------------  $%8.2f\n", bill->iva);
  printf("\nTotal a pagar: -----------------------------------------------------------  $%8.2f\n\n\n", bill->total);
}

void printBills(bill_list *list)
{
  bill_node *current = list->head;
  if (current != NULL)
  {
    printf("---Lista de facturas---\n");
    while (current != NULL)
    {
      printBill(current->value);
      current = current->next;
    }
  }
  else
  {
    printf("Lista de facturas vacia...\n");
  }
  system("pause");
}

void createNewBill()
{
  bill *newBill = malloc(sizeof(bill));
  customer *customer = getCustomer();
  if (customer != NULL)
  {
    newBill->customer_id = customer->id;
    newBill->number = getNextBillNumber();
    newBill->date = getCurrentTime();
    newBill->details = readBillDetails();
    newBill->subtotal = calculateBillSubTotal(newBill->details);
    newBill->iva = calculateBillIVA(newBill);
    newBill->total = calculateBillTotal(newBill);
    newBill->id = saveBill(newBill);
    printBill(newBill);
    addBill(bills, newBill);
    waitUser();
  }
}
