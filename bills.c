#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "models/bill.h"
#include "dishes.c"
#include "customers.c"

void readBillDetails()
{
  int option = 1;
  int currentItem = 0;
  // 1 -> read detail
  // 2 -> salir
  // int size = 2;
  bill_detail items[1];
  while (option != 2)
  {
    int selectedDish;
    printDishes();
    printf("Seleccione el platillo: ");
    scanf("%d", &selectedDish);
    items[currentItem].price = dishes[selectedDish - 1].price;
    strcpy(items[currentItem].name, dishes[selectedDish - 1].name);
    printf("Ingrese la cantidad: ");
    scanf("%d", &items[currentItem].quantity);
    printDetail(items[currentItem]);

    printf("Desea agregar otro platillo?\n");
    printf("[1] Si\n");
    printf("[2] No\n");
    scanf("%d", &option);
    getchar();
  }
}

void createNewBill()
{
  bill newBill;
  customer *newCustomer;
  newBill.number = 1;
  newCustomer = getCustomer();
  if (newCustomer != NULL)
  {
    printCustomer(newCustomer);
    readBillDetails();
    printf("Orden registrada con exito!\n");
    waitUser();
  }
}
