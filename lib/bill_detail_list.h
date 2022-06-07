#ifndef BILL_DETAIL_LIST_H
#define BILL_DETAIL_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../models/bill_detail.h"

typedef struct DetailNode
{
  bill_detail *value;
  struct DetailNode *next;
} bill_detail_node;

typedef struct
{
  bill_detail_node *head;
  bill_detail_node *tail;
  int size;
} bill_detail_list;

bill_detail_list *create_bill_detail_list()
{
  bill_detail_list *newList = malloc(sizeof(bill_detail_list));
  newList->size = 0;
  newList->head = NULL;
  newList->tail = NULL;
  return newList;
}

void addBillDetail(bill_detail_list *list, bill_detail *value)
{
  bill_detail_node *newNode = malloc(sizeof(bill_detail_node));
  newNode->value = value;
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

void printBillDetail(bill_detail *detail)
{
    float total = detail->price * detail->quantity;
    printf("%s - %d x %.2f = %.2f \n", detail->name, detail->quantity, detail->price, total);
}

void printBillDetails(bill_detail_list *list)
{
  bill_detail_node *current = list->head;
  printf("\n----------Detalles de factura----------\n");
  while (current != NULL)
  {
    printBillDetail(current->value);
    current = current->next;
  }
}

#endif