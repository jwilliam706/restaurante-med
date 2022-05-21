#ifndef CUSTOMER_M_H
#define CUSTOMER_M_H
typedef struct
{
	int code;
	char name[100];
	int phone;
	char email[100];
	char address[100];
	struct customer *next;
} customer;
#endif