#ifndef CUSTOMER_LIST_H
#define CUSTOMER_LIST_H

#include <stdio.h>
#include "../models/customer.h"

typedef struct CustomerNode
{
  customer *value;
  struct CustomerNode *next;
} customer_node;

typedef struct
{
  customer_node *head;
  customer_node *tail;
  int size;
} customer_list;

void initCustomerList(customer_list **list)
{
  *list = malloc(sizeof(customer_list));

  (*list)->size = 0;
  (*list)->head = NULL;
  (*list)->tail = NULL;
}

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

#endif