#ifndef CUSTOMER_D_H
#define CUSTOMER_D_H

#include "stdio.h"
#include "../models/customer.h"
#include "../lib/customer_list.h"
#include "../lib/utils.h"

customer_list *customers;

void addTestData(customer_list *list)
{
  customer *newCustomer = malloc(sizeof(customer));
  customer *newCustomer2 = malloc(sizeof(customer));

  newCustomer->id = 1;
  strcpy(newCustomer->name, "Carlos");
  strcpy(newCustomer->email, "carlos@gmail.com");
  strcpy(newCustomer->phone, "7099-2311");
  strcpy(newCustomer->address, "col. fatima");
 
  newCustomer2->id = 2;
  strcpy(newCustomer2->name, "Carlos");
  strcpy(newCustomer2->email, "carlos2@gmail.com");
  strcpy(newCustomer2->phone, "7222-2311");
  strcpy(newCustomer2->address, "2 col. fatima");

  addCustomer(list, newCustomer);
  addCustomer(list, newCustomer2);
}

 void createTestCustomers(){
    initCustomerList(&customers);
    addTestData(&customers);
 }

#endif