#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "models/customer.h"


customer *first = NULL;
customer *last = NULL;

customer *createNewCustomer(){
	system("cls");
	customer *newCustomer = malloc(sizeof(customer));
	//Ingresar customer desde el menu
	printf("Ingreso de nuevo cliente\n");
	printf("ID: "); scanf("%d",&newCustomer->code);
	printf("Nombre: "); scanf(" %[^\n]",&newCustomer->name);
	printf("Telefono: "); scanf("%d",&newCustomer->phone);
	printf("Email: "); scanf(" %[^\n]",&newCustomer->email);
	printf("Direccion: "); scanf(" %[^\n]",&newCustomer->address);
	printf("\n>>DATOS ALMACENADOS CORRECTAMENTE<<");
	return newCustomer;		
}

void printCustomers(){
	// system("cls");
	//Crear puntero auxiliar para recorrido de lista
	customer *i = first;
	int aux = 0;
	
	//Preguntar si la lista no esta vacia
	if(i != NULL){
		printf("LISTADO DE customerS");
		while (i != NULL){
		printCustomer(i);
		i = i->next;
		}
	}
	else{
		printf("<<NO HAY customerS EN LA LISTA>>");
	}
}

void printCustomer(customer *cust){
	printf("\n ============================");
	printf("\nC�digo: %d",cust->code);
	printf("\nNombre: %s",cust->name);	
	printf("\nTelefono: %d",cust->phone);	
	printf("\nEmail: %s",cust->email);
	printf("\nDireccion: %s",cust->address);
}

customer *getCustomer(){
	int option = 0;
	printf("CREAR FACTURA: Ingrese un cliente\n");
	printf("=====================================\n");
	printf("1. Nuevo cliente\n");
	printf("2. Existente\n");
	scanf("%d",&option);
	getchar();
	switch (option)
	{
	case 1:
		createNewCustomer();
		break;
	case 2:
		// Mostrar buscar o ingresar id
		return NULL;
		break;
	default:
	return NULL;
		break;
	}
}

customer *searchCustomer(int aux){
	customer *i = first;
	int code= 0;
	char name[100];
	int customerFind=0;
	system("cls");
	if(first != NULL){
		//Search trough code
		if(aux == 1){
			printf("Digite codigo de cliente a buscar: ");
		scanf("%d",&code);
		while(i!=NULL){
			if(i->code==code){
				printf("\nCodigo %d",i->code);
				printf("\nNombre %s",i->name);
				printf("\nDireccion %s",i->address);
				printf("\nEmail %s",i->email);
				printf("\nTelefono %s",i->phone);
				customerFind=1;
				break;
			}
		i=i->next;
		}
		if(customerFind==0)
		printf("\n Codigo no encontrado");
		}
		else if(aux == 2){
			//Search trough name
			printf("Digite nombre a cliente a buscar: ");
			scanf("%s",&name);
		while(i!=NULL){
			if(i->name==name){
				printf("\nCodigo %d",i->code);
				printf("\nNombre %s",i->name);
				printf("\nDireccion %s",i->address);
				printf("\nEmail %s",i->email);
				printf("\nTelefono %s",i->phone);
				customerFind=1;
				break;
			}
		i=i->next;
		}
		if(customerFind==0)
		printf("\n Nombre no encontrado");
		}
		
	}else{
		printf("La lista esta vacia");
	}
	system("pause");
}

