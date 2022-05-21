#include <stdio.h>
#include <stdlib.h>
#include "dishes.c"
#include "customers.c"
#include "models/bill.h"
#include "lib/utils.h"
#include "lib/bill_node.h"

bill_detail_list *readBillDetails()
{
  bill_detail_list *details = create_bill_detail_list();
  int option = 1;
  while (option != 2)
  {
    bill_detail *detail = malloc(sizeof(bill_detail));
    int selectedDish;
    printf("\n\n--------------------Nueva Factura--------------------\n");

    printDishes();
    printf("\n\nSeleccione el platillo: ");
    scanf("%d", &selectedDish);
    detail->price = dishes[selectedDish - 1].price;
    strcpy(&detail->name, dishes[selectedDish - 1].name);
    printf("Ingrese la cantidad: ");
    scanf("%d", &detail->quantity);
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
  newBill.number = 1;
  newCustomer = getCustomer();
  bill_detail_list *list = readBillDetails();
  printf("--------------------Factura--------------------\n");
  printCustomer(newCustomer);
  print_bill_details(list);
  printf("Orden registrada con exito!\n");
  waitUser();
}
