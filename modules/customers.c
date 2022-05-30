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
  newCustomer->id = NULL;
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

// Copy customer?
customer *createCustomer(customer *from)
{
  customer *newCustomer = malloc(sizeof(customer));
  newCustomer->id = from->id;
  strcpy(newCustomer->name, from->name);
  strcpy(newCustomer->email, from->email);
  strcpy(newCustomer->phone, from->phone);
  strcpy(newCustomer->address, from->address);
  return newCustomer;
}

customer *searchCustomerById()
{
  int *id;
  int found = 0;
  customer_node *current = customers->head;
  printf("Digite el codigo de cliente a buscar: ");
  scanf("%d", &id);
  getchar();
  while (current != NULL)
  {
    if (current->value->id == id)
    {
      return current->value;
    }
    current = current->next;
  }
  printf("\nCliente con codigo '%d' no encontrado...\n\n", id);
  return NULL;
}

customer *searchCustomerByName()
{
  char name[50];
  customer_node *current = customers->head;
  customer_list *foundResults = malloc(sizeof(customer_list));
  printf("Digite el nombre del cliente a buscar: ");
  readString(name, 50);
  while (current != NULL)
  {
    if (strcmp(current->value->name, name) == 0)
    {
      customer *newCustomer = createCustomer(current->value);
      addCustomer(foundResults, newCustomer);
    }
    printf("a %d", &foundResults->size);
    current = current->next;
    printf("b");
  }
  printf("\nClientes con nombre '%s' encontrados: %d\n", name, foundResults->size);
  if (foundResults->size == 1)
  {
    return foundResults->head->value;
  }
  else if (foundResults->size > 1)
  {
    printf("----------\n");
    printf(customers->head->value->name);
    printf("\n");
    printf(foundResults->head->value->name);
    printf("----------\n");
    printf("\nSe encontraron mas de un cliente con el nombre '%s'\n", name);
    printf("N de clientes encontrados: %d\n", foundResults->size);
    // printCustomers(foundResults);
  }
  else
  {
    printf("\n Cliente con nombre '%s' no encontrado\n\n", name);
  }
  return NULL;
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

void printCustomer(customer *customer)
{
  printf("\n---DATOS DE CLIENTE----\n");
  printf("\nCodigo %d", customer->id);
  printf("\nNombre %s", customer->name);
  printf("\nDireccion %s", customer->address);
  printf("\nEmail %s", customer->email);
  printf("\nTelefono %s\n\n", customer->phone);
}

void printCustomers(customer_list *list)
{
  customer_node *current = list->head;
  if (current != NULL)
  {
    printf("---Lista de clientes---\n");
    while (current != NULL)
    {
      printf("cliente: %d\n", current->value->id);
      printCustomer(current->value);
      current = current->next;
    }
  }
  else
  {
    printf("Lista de clientes vacia...");
  }
  system("pause");
}
