#ifndef BILL_H
#define BILL_H

typedef struct
{
    int id;
    int dish_id;
    char name[20];
    int quantity;
    float price;
} bill_detail;


typedef struct
{
    int id;
    int number;
    int date;
    int customer_id;
    bill_detail items[10];
    float subtotal;
    float iva;
    float total;
} bill;

void printDetail(bill_detail detail) {
    float total = detail.price * detail.quantity;
    printf("%s - %d x %.2f = %.2f \n", detail.name, detail.quantity, detail.price, total);
}

#endif