#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dishes.c"
#include "customers.c"

#include "models/bill.h"
#include "lib/utils.h"
#include "lib/bill_list.h"

dish getDish()
{
  int selectedDish;
  printDishes();
  printf("\nSeleccione el platillo: ");
  scanf("%d", &selectedDish);
  return dishes[selectedDish - 1];
}

bill_detail_list *readBillDetails()
{
  bill_detail_list *details = create_bill_detail_list();
  int option = 1;
  printf("\n\n--------------------Nueva Factura--------------------\n");
  getCurrentTime();
  while (option != 2)
  {
    bill_detail *detail = malloc(sizeof(bill_detail));
    dish dish = getDish();

    printf("Selected dish: %s - $%.2f\n", dish.name, dish.price);
    detail->price = dish.price;
    strcpy(&detail->name, dish.name);

    printf("Ingrese la cantidad: ");
    scanf("%d", &detail->quantity);

    detail->subTotal = detail->price * detail->quantity;
    printDetail(*detail);
    add_bill_detail(details, *detail);

    printf("Desea agregar otro platillo?\n");
    printf("[1] Si\n");
    printf("[2] No\n");
    scanf("%d", &option);
    getchar();
  }

  return details;
}

void createNewBill()
{
  bill newBill;
  customer *newCustomer;
  newCustomer = getCustomer();
  newBill.customer_id = newCustomer->code;
  newBill.number = 1;
  newBill.date = getCurrentTime();
  newBill.details = readBillDetails();
  printCustomer(newCustomer);
  printBill(&newBill);
  printf("Orden registrada con exito!\n");
  waitUser();
}

void printBill(bill *bill)
{

  double accumulator = 0.0; //- total of invoice acum
  printf("--------------------Factura--------------------\n");
  printf("\nFecha de factura: %s\n", getLocaleCurrentTime(bill->date));
  printf("\nPlatillo\tCantidad\tPrecio Unitario\t\tSub total");
  printf("\n-------------------------------------------------------------------------------------\n");
  bill_detail_node *itemData = bill->details->head;
  while (itemData != NULL)
  {
    printf("%d", itemData->value.name);
    printf("\t\t%d", itemData->value.quantity);
    printf("\t\t$%f", itemData->value.price);
    printf("\t\t$%f", itemData->value.subTotal);
    printf("\n");

    //- Acum of total value
    accumulator += itemData->value.subTotal;

    //- Next Item
    itemData = itemData->next;
  }

  //- Table Footer
  printf("-------------------------------------------------------------------------------------\n");
  printf("\nTotal a pagar: ------------------------------------------------------------$%f\n\n", accumulator);
}