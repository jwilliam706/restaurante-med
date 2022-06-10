#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../models/customer.h"
#include "../data/customers.c"
#include "../lib/constants.h"
#include "../database/sqlite3.h"

void saveCustomer(customer *newCustomer)
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

  snprintf(sql, 200, "INSERT INTO customers (name, phone, email, address) VALUES ('%s', '%s', '%s', '%s');",
           newCustomer->name, newCustomer->phone, newCustomer->email, newCustomer->address);

  res = sqlite3_exec(db, sql, NULL, 0, &error);
  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", error);
    sqlite3_free(error);
  }
  else
  {
    printf("\n>>DATOS ALMACENADOS CORRECTAMENTE<<");
  }
}

customer *createNewCustomer()
{
  system("cls");
  customer *newCustomer = malloc(sizeof(customer));
  printf("Ingreso de nuevo cliente\n");
  newCustomer->id = 0;
  printf("Nombre: ");
  scanf(" %[^\n]", &newCustomer->name);
  printf("Telefono: ");
  scanf("%s", &newCustomer->phone);
  printf("Email: ");
  scanf(" %[^\n]", &newCustomer->email);
  printf("Direccion: ");
  scanf(" %[^\n]", &newCustomer->address);
  saveCustomer(newCustomer);
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
  int id;
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

//--
void print_custormers_by_name_search(customer_list *list){
  //- Customer list head
  customer_node *current = list->head;
  
  //- Customer empty validation
  if (current != NULL)
  {
    //- Customer List While
    while (current != NULL)
    {
      printf("\n-----------------------------------------------------------------------");
      printf("\nID: %d",current->value->id);
      printf("\nNombre: %s",current->value->name);
      printf("\nEmail: %s",current->value->email);
      printf("\nDireccion: %s",current->value->address);
      printf("\nTelefono: %s",current->value->phone);
      current = current->next;
    }
    printf("\n-----------------------------------------------------------------------\n");
  }
}

//- 
customer *get_customer_by_id(customer_list *list, int id){
  customer_node *current = list->head;
  while (current != NULL)
  {
    if (current->value->id == id)
    {
      return current->value;
    }
    current = current->next;
  }
  printf("Hubo un error");
  return NULL;
}

//--
customer *search_customers_by_name(){
  system("cls");
  char name[50];
  int id;
  customer_node *current = customers->head;
  customer_list *foundResults = malloc(sizeof(customer_list));
  printf("Digite el nombre del cliente a buscar: ");
  readString(name, 50);

  //- Customers List search
  while (current != NULL)
  {
    if (strcmp(current->value->name, name) == 0)
    {
      //- New Costumer
      customer *newCustomer = createCustomer(current->value);

      //- Add Section
      customer_node *newNode = malloc(sizeof(customer_node));
      newNode->value = newCustomer;
      newNode->next = NULL;
      if (foundResults->head == NULL)
      {
        foundResults->head = newNode;
        foundResults->tail = newNode;
      }
      else
      {
        foundResults->tail->next = newNode;
        foundResults->tail = newNode;
      }
      foundResults->size = foundResults->size + 1;
      //-
    }
    current = current->next;
  }

  //-
  printf("Se encontraron %d resultados.\n",foundResults->size);

  //-
  print_custormers_by_name_search(foundResults);
  //-
  printf("\nDigite el id de cliente a utilizar:");
  scanf("%d", &id);
  getchar();
  //-
  return  get_customer_by_id(foundResults,id);
}


//--

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
    
    //printf("a %d", &foundResults->size);
    current = current->next;
    //printf("b");
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
      customer = search_customers_by_name();
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
      printCustomer(current->value);
      current = current->next;
    }
  }
  else
  {
    printf("Lista de clientes vacia...\n");
  }
  system("pause");
}

void loadCustomers()
{
  sqlite3 *db;
  char *error = 0;
  int res;
  char *sql;
  sqlite3_stmt *stmt;

  res = sqlite3_open(DB_FILE, &db);
  if (res)
  {
    printf("No se pudo abrir la base de datos: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  sql = "SELECT * FROM customers;";

  res = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);

  if (res != SQLITE_OK)
  {
    printf("Error: %s\n", sqlite3_errmsg(db));
    exit(0);
  }

  while (sqlite3_step(stmt) == SQLITE_ROW)
  {
    customer *c = malloc(sizeof(customer));
    c->id = sqlite3_column_int(stmt, 0);
    strcpy(c->name, sqlite3_column_text(stmt, 1));
    strcpy(c->phone, sqlite3_column_text(stmt, 2));
    strcpy(c->email, sqlite3_column_text(stmt, 3));
    strcpy(c->address, sqlite3_column_text(stmt, 4));
    addCustomer(customers, c);
  }

  sqlite3_finalize(stmt);
}
