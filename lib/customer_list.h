#ifndef CUSTOMER_LIST_H
#define CUSTOMER_LIST_H

#include "stdio.h"
#include "customer_node.h"

typedef struct
{
  customer_node *head;
  customer_node *tail;
  int size;
} customer_list;

#endif