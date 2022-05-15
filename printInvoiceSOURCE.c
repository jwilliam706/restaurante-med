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
	
	InvoiceItems *itemData = first;
	
	while(itemData != NULL){
		printf("\nItem name = %s",itemData->detail.itemName);
		printf("\nItem Amount = %d",itemData->detail.itemAmount);
		printf("\nSubtotal = %f\n",itemData->detail.subTotal);
		
		itemData = itemData->next;
	}
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
	printf("Welcome\n");
	
	//- Test of add detail function
	//- 1 item
	InvoiceDetail detail;
	detail.itemAmount = 1;
	strcpy(detail.itemName,"hola");
	detail.subTotal = 120.00;
	addItem(detail);
	//- 2 item
	detail.itemAmount = 2;
	strcpy(detail.itemName,"hola2");
	detail.subTotal = 122.00;
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
