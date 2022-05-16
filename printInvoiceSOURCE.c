//- Standard Libraries
#include <stdio.h>
#include <stdlib.h>

//- Language Package
#include <locale.h>
#include <windows.h>

//- Utility Libraries
#include <math.h>
#include <string.h>

//- LIST STRUCT SECTION
//- Detail Struct Define
typedef struct InvoiceInformation{
	char invoiceDate[100];
	char customersName[100];
	double total;
} InvoiceInformation;

//- Detail Struct Define
typedef struct InvoiceDetail{
	char itemName[100];
	short itemAmount;
	int dishID;
	double unitPrice;
	double subTotal;
} InvoiceDetail;

//- Invoice List Struct Define
typedef struct InvoiceItems{
	InvoiceDetail detail;
	struct InvoiceItems *next;
} InvoiceItems;

//Aux pointers 
InvoiceItems *first = NULL;
InvoiceItems *last  = NULL;

//- LIST FUNCTIONS (ADD)
//- Add Item
void addItem(InvoiceDetail detail){
	InvoiceItems *newDetail = (InvoiceItems*)malloc(sizeof(InvoiceItems));
	newDetail->detail = detail;
	newDetail->next 	= NULL;
	
	if(first == NULL){
		first = newDetail;
		last = newDetail;
	}else{
		last->next = newDetail;
		last = newDetail;
	}
}

//- Show lista data
void showListData(){
	//- Local Variables
	double accumulator = 0.0;//- total of invoice acum
	
	//- Table Head
	printf("\nFecha de factura: 2022-05-16(DEMO DATE)\n");
	printf("\nPlatillo\tCantidad\tPrecio Unitario\t\tSub total");
	printf("\n-------------------------------------------------------------------------------------\n");
	
	InvoiceItems *itemData = first;
	
	//- Table Body (Invoice Details)
	while(itemData != NULL){
		printf("%d",itemData->detail.dishID);
		printf("\t\t%d",itemData->detail.itemAmount);
		printf("\t\t$%f",itemData->detail.unitPrice);
		printf("\t\t$%f",itemData->detail.subTotal);
		printf("\n");
		
		//- Acum of total value
		accumulator += itemData->detail.subTotal;
		
		//- Next Item
		itemData = itemData->next;
	}
	
	//- Table Footer
	printf("-------------------------------------------------------------------------------------\n");
	printf("\nTotal a pagar: ------------------------------------------------------------$%f\n\n",accumulator);
	
}

//- UTILITY FUNCTIONS SECTION
//- Console & Forecolor Change Function
//- @colorSetting is the vhar string to setting the console and forecolor
void basicConfigurations(char colorSetting[]){
	//- Spanish Laguage Settings
    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252); // change STDIN - for Windows
    SetConsoleOutputCP(1252); // change STDOUT - for Windows
    
    //- Console Colore Settings
	system(colorSetting);
}

//- WORKER FUNCTION SECTION
void workerFunction(){
	//- Test of add detail function
	//- 1 item
	InvoiceDetail detail;
	detail.itemAmount 	= 1;
	detail.dishID 		= 1;
	detail.unitPrice	= 7.80;
	detail.subTotal 	= (detail.itemAmount*detail.unitPrice);
	addItem(detail);
	//- 2 item
	detail.itemAmount 	= 2;
	detail.dishID 		= 6;
	detail.unitPrice	= 5.65;
	detail.subTotal 	= (detail.itemAmount*detail.unitPrice);
	addItem(detail);
	
	//- Print InvoiceDetails
	showListData();
}

//- MAIN METHOD SECTION
int main(){
	//- Console Settings
    basicConfigurations("color 3f");
	
	//- Worker Function
    workerFunction();
	
	//- Last readKey
	system("pause"); 
	return 0;
}
