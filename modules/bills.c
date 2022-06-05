#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dishes.c"
#include "customers.c"

#include "../models/bill.h"
#include "../lib/utils.h"
#include "../lib/bill_list.h"

dish *getDish()
{
  int selectedDish;
  printDishes();
  printf("\nSeleccione el platillo: ");
  scanf("%d", &selectedDish);
  return &dishes[selectedDish - 1];
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

    memcpy(&detail->price, &dish->price, sizeof(float));
    strcpy(detail->name, dish->name);

    printf("Ingrese la cantidad: ");
    scanf("%d", &detail->quantity);

    detail->subTotal = detail->price * detail->quantity;
    addBillDetail(details, detail);
    printDetail(detail);
    printf("Desea agregar otro platillo?\n");
    printf("[1] Si\n");
    printf("[2] No\n");
    scanf("%d", &option);
    getchar();
  }

  return details;
}

int getNextBillNumber(){
  // TODO: Implementar metodo para retornar el siguiente numero de factura
  // Tomar en cuenta que las facturas se numeran de 1 a N para cada dia
  return 1;
}

void createNewBill()
{
  bill newBill;
  customer *customer;
  customer = getCustomer();
  if (customer != NULL)
  {
    newBill.customer_id = customer->id;
    newBill.number = getNextBillNumber();
    newBill.date = getCurrentTime();
    newBill.details = readBillDetails();
    printBill(&newBill);
    printf("Orden registrada con exito!\n");
    waitUser();
  }
}

void printBill(bill *bill)
{

  double accumulator = 0.0; //- total of invoice acum
  printf("---------------------------------------Factura----------------------------------------\n");
  printf("\nFecha de factura: %s\n", getLocaleCurrentTime(bill->date));
  printf("\nPlatillo\tCantidad\tPrecio Unitario\t\tSub total");
  printf("\n-------------------------------------------------------------------------------------\n");
  bill_detail_node *current = bill->details->head;
  while (current != NULL)
  {
    // print detai?
    printf("%s", current->value->name);
    printf("\t\t%d", current->value->quantity);
    printf("\t\t$%'.2f", current->value->price);
    printf("\t\t\t$%'.2f", current->value->subTotal);
    printf("\n");

    //- Acum of total value
    accumulator += current->value->subTotal;

    //- Next Item
    current = current->next;
  }

  //- Table Footer
  printf("-------------------------------------------------------------------------------------\n");
  printf("\nTotal a pagar: ------------------------------------------------------------$%'.2f\n\n", accumulator);
}

void printDetail(bill_detail *detail)
{
    float total = detail->price * detail->quantity;
    printf("%s - %d x %.2f = %.2f \n", detail->name, detail->quantity, detail->price, total);
}

void searchBill(){
	//- Search trough IDbill or idClient?
	bill newBill;
	int opcion = 0;
	int codigo = 0;
	int codigoCliente = 0;
	int fEncontrado = 0;
	int cEncontrado = 0;
	printf("Buscar Factura");
	prtinf("Favor ingresar una de las siguientes opciones");
	printf("[1] Buscar por ID Factura");
	printf("[2] Buscar por ID Cliente");
	scanf("%d",&opcion);
	switch(opcion){
			case 1:
				// - ID Factura search
				printf("Digite codigo a buscar: ");
				scanf("%d",&codigo);
				while(newBill!=NULL){
					if(newBill->id==codigo){
						printf("\nCodigo %d",newBill->id);
						printf("\nCodigo de cliente  %d",newBill->customer_id);
						printf("\nSubTotal %f",newBill->subtotal);
						printf("\nTotal %f",newBill->total);
					fEncontrado=1;
					break;
					}
					newBill = newBill->details->head;
					}
				if(fEncontrado==0)
				printf("\n Codigo no encontrado");
				break;
			case 2:
				// - ID Client search
				printf("Digite codigo de cliente a buscar: ");
				scanf("%d",&codigoCliente);
				while(newBill!=NULL){
					if(newBill->customer_id==codigoCliente);
						printf("\nCodigo %d",newBill->id);
						printf("\nCodigo de cliente  %d",newBill->customer_id);
						printf("\nSubTotal %f",newBill->subtotal);
						printf("\nTotal %f",newBill->total);
					cEncontrado=1;
				}
				newBill = newBill->details->head;
				
				if(cEncontrado==0)
				printf("\n Codigo no encontrado");
				break;
			default:
				system("cls");
				printf("\n Opcion incorrecta\n");
				system("pause");
				printf("Ingresar una de las siguientes opciones:");
				searchBill();
			}
}
