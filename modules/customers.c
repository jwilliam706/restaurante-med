#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../models/customer.h"
#include "../data/customer.c"

customer *createNewCustomer()
{
	system("cls");
	customer *newCustomer = malloc(sizeof(customer));
	printf("Ingreso de nuevo cliente\n");
	printf("ID: ");
	scanf("%d", &newCustomer->code);
	printf("Nombre: ");
	scanf(" %[^\n]", &newCustomer->name);
	printf("Telefono: ");
	scanf("%s", &newCustomer->phone);
	printf("Email: ");
	scanf(" %[^\n]", &newCustomer->email);
	printf("Direccion: ");
	scanf(" %[^\n]", &newCustomer->address);
	printf("\n>>DATOS ALMACENADOS CORRECTAMENTE<<");
	return newCustomer;
}

customer *searchCustomer()
{
	int option;
	customer *customer;
	system("cls");
	if (customers->head == NULL)
	{
		printf("La lista esta vacia");
		return NULL;
	}
	printf("mmm");
	while (option != 3)
	{
		printf("Buscar cliente\n");
		printf("=====================================\n");
		printf("1. Buscar por id\n");
		printf("2. Buscar por nombre\n\n");
		printf("3. Cancelar\n");
		printf("=====================================\n");
		printf("Opcion: ");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
		case 1:
			customer = searchCustomerById();
			if (customer != NULL)
			{
				return customer;
			}
			break;
		case 2:
			customer = searchCustomerByName();
			if (customer != NULL)
			{
				return customer;
			}
			break;
		case 3:
			return NULL;
		default:
			break;
		}
	}
	return NULL;
}

customer *getCustomer()
{
	int option = 0;
	customer *customer;

	while (option != 3)
	{
		printf("Ingrese un cliente\n");
		printf("=====================================\n");
		printf("1. Nuevo cliente\n");
		printf("2. Existente\n\n");
		printf("3. Cancelar\n");
		printf("=====================================\n");
		printf("Opcion: ");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
		case 1:
			customer = createNewCustomer();
			if (customer != NULL)
			{
				return customer;
			}
		case 2:
			customer = searchCustomer();
			if (customer != NULL)
			{
				return customer;
			}
		case 3:
			return NULL;
		default:
			break;
		}
	}
	return NULL;
}
