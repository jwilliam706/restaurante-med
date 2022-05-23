#ifndef BILL_H
#define BILL_H

#include "../lib/bill_list.h"

typedef struct
{
    int id;
    int number;
    int date;
    int customer_id;
    bill_detail_list *details;
    time_t date;
    float subtotal;
    float iva;
    float total;
} bill;

void printDetail(bill_detail *detail)
{
    float total = detail->price * detail->quantity;
    printf("%s - %d x %.2f = %.2f \n", detail->name, detail->quantity, detail->price, total);
}

#endif