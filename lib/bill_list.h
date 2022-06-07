#ifndef BILL_LIST_H
#define BILL_LIST_H

#include <stdio.h>
#include "../models/bill.h"

typedef struct BillNode
{
  bill *value;
  struct BillNode *next;
} bill_node;

typedef struct
{
  bill_node *head;
  bill_node *tail;
  int size;
} bill_list;

void initBillList(bill_list **list)
{
  *list = malloc(sizeof(bill_list));

  (*list)->size = 0;
  (*list)->head = NULL;
  (*list)->tail = NULL;
}

void addBill(bill_list *list, bill *data)
{
  bill_node *newNode = malloc(sizeof(bill_node));
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