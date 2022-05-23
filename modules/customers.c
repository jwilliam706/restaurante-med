#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../models/customer.h"

customer *first = NULL;
customer *last = NULL;

customer *createNewCustomer()
{
	system("cls");
	customer *newCustomer = malloc(sizeof(customer));
	// Ingresar customer desde el menu
	printf("Ingreso de nuevo cliente\n");
	printf("ID: ");
	scanf("%d", &newCustomer->code);
	printf("Nombre: ");
	scanf(" %[^\n]", &newCustomer->name);
	printf("Telefono: ");
	scanf("%d", &newCustomer->phone);
	printf("Email: ");
	scanf(" %[^\n]", &newCustomer->email);
	printf("Direccion: ");
	scanf(" %[^\n]", &newCustomer->address);
	printf("\n>>DATOS ALMACENADOS CORRECTAMENTE<<");
	return newCustomer;
}

void printCustomers()
{
	// system("cls");
	// Crear puntero auxiliar para recorrido de lista
	customer *i = first;
	int aux = 0;

	// Preguntar si la lista no esta vacia
	if (i != NULL)
	{
		printf("LISTADO DE customers");
		while (i != NULL)
		{
			printCustomer(i);
			i = i->next;
		}
	}
	else
	{
		printf("<<NO HAY customerS EN LA LISTA>>");
	}
}

void printCustomer(customer *cust)
{
	printf("\n ============================");
	printf("\nC�digo: %d", cust->code);
	printf("\nNombre: %s", cust->name);
	printf("\nTelefono: %d", cust->phone);
	printf("\nEmail: %s", cust->email);
	printf("\nDireccion: %s", cust->address);
}

customer *getCustomer()
{
	int option = 0;
	printf("CREAR FACTURA: Ingrese un cliente\n");
	printf("=====================================\n");
	printf("1. Nuevo cliente\n");
	printf("2. Existente\n");
	scanf("%d", &option);
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
