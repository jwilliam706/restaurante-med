#ifndef BILL_H
#define BILL_H

#include "../lib/bill_list.h"

typedef struct
{
    int id;
    int number;
    int customer_id;
    bill_detail_list *details;
    time_t date;
    float subtotal;
    float iva;
    float total;
} bill;

#endif