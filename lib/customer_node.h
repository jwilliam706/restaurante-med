#ifndef CUSTOMER_NODE_H
#define CUSTOMER_NODE_H
#include "stdio.h"
#include "../models/customer.h"

typedef struct
{
  customer *value;
  struct customer_node *next;
} customer_node;

#endif