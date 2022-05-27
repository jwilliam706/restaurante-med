#ifndef CUSTOMER_D_H
#define CUSTOMER_D_H

#include "stdio.h"
#include "../models/dish.h"
#include "../models/customer.h"
#include "../lib/customer_node.h"
#include "../lib/customer_list.h"
#include "../lib/utils.h"

customer_list *customers;

void addCustomer(customer_list *list, customer *data)
{
  customer_node *newNode = malloc(sizeof(customer_node));
  newNode->value = data;
  newNode->next = NULL;
  if (list->head == NULL)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail->next = newNode;
    list->tail = newNode;
  }
  list->size = list->size + 1;
}

void addTestData(customer_list *list)
{
  customer *newCustomer = malloc(sizeof(customer));
  customer *newCustomer2 = malloc(sizeof(customer));

  newCustomer->code = 1;
  strcpy(newCustomer->name, "Carlos");
  strcpy(newCustomer->email, "carlos@gmail.com");
  strcpy(newCustomer->phone, "7099-2311");
  strcpy(newCustomer->address, "col. fatima");

  newCustomer2->code = 2;
  strcpy(newCustomer2->name, "Carlos");
  strcpy(newCustomer2->email, "carlos2@gmail.com");
  strcpy(newCustomer2->phone, "7222-2311");
  strcpy(newCustomer2->address, "2 col. fatima");

  addCustomer(list, newCustomer);
  addCustomer(list, newCustomer2);
}

void initCustomerList(customer_list *list)
{
  list = malloc(sizeof(customer_list));

  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

void printCustomer(customer *customer)
{
  printf("\n\----DATOS DE CLIENTE----\n");
  printf("\Mem add: %d", &customer);
  printf("\nCodigo %d", customer->code);
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
      printf("cliente: %d\n", current->value->code);
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

customer *searchCustomerById()
{
  int *code;
  int found = 0;
  customer_node *current = customers->head;
  printf("Digite el codigo de cliente a buscar: ");
  scanf("%d", &code);
  getchar();
  while (current != NULL)
  {
    if (current->value->code == code)
    {
      return current->value;
    }
    current = current->next;
  }
  printf("\nCliente con codigo '%d' no encontrado...\n\n", code);
  return NULL;
}

customer *createCustomer(customer *from)
{
  customer *newCustomer = malloc(sizeof(customer));
  newCustomer->code = from->code;
  strcpy(newCustomer->name, from->name);
  strcpy(newCustomer->email, from->email);
  strcpy(newCustomer->phone, from->phone);
  strcpy(newCustomer->address, from->address);
  return newCustomer;
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

#endif