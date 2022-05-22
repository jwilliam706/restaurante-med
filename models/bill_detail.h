#ifndef BILL_DETAIL_H
#define BILL_DETAIL_H

#include "../lib/bill_list.h"

typedef struct
{
  char name[20];
  int quantity;
  float price;
  float subTotal;
} bill_detail;

#endif