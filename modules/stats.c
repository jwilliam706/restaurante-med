#include <stdio.h>
#include <stdlib.h>
#include "./totalSales.h"
#include "../models/customer.h"

int statsMenu()
{
  int option;
  printf("--------------------------------------------------\n          SISTEMA DE RESTAURANTE\n-------------------------------------------------- \n\n");

  printf("Seleccione una opcion: \n\n");
  printf("[1] Ventas totales del dia\n");
  printf("[2] Promedio de consumo por cliente\n");
  printf("[3] Platillo favorito\n");
  printf("[4] Platillo mas consumido\n");
  printf("[5] Platillo mas rentable\n");
  printf("[6] Platillo menos rentable\n");
  printf("Opcion: ");
  scanf("%d", &option);
  getchar();
  return option;
}


//- FUNCTIONS SECTION
//-
//- Favorite Dish Function
void getFavoriteDish(bill_list *list, dish *dishes){
  //- Local Variables
  int favorite_dish_position            = 0;
  int dishesConsumedCountPerCustomer[]  = {0,0,0,0,0,0,0,0};
  int bigger                            = 0;

  //- Bill list head
  bill_node *currentBill = list->head;
  
  //- Bill empty validation
  if (currentBill != NULL)
  {
    //- Bills While
    while (currentBill != NULL)
    {
      //- Bill data Head
      bill *billData = currentBill->value;

      //- Detail Head
      bill_detail_node *currentDetail = billData->details->head;
      
      //- Detail While
      while (currentDetail != NULL)
      {
        //- if the dish is on the detail, variable increase 1, the item quantity doesnt matter 
        if(currentDetail->value->dish_id == dishes[0].id){ dishesConsumedCountPerCustomer[0] += 1; }
        else if(currentDetail->value->dish_id == dishes[1].id){ dishesConsumedCountPerCustomer[1] += 1; }
        else if(currentDetail->value->dish_id == dishes[2].id){ dishesConsumedCountPerCustomer[2] += 1; }
        else if(currentDetail->value->dish_id == dishes[3].id){ dishesConsumedCountPerCustomer[3] += 1; }
        else if(currentDetail->value->dish_id == dishes[4].id){ dishesConsumedCountPerCustomer[4] += 1; }
        else if(currentDetail->value->dish_id == dishes[5].id){ dishesConsumedCountPerCustomer[5] += 1; }
        else if(currentDetail->value->dish_id == dishes[6].id){ dishesConsumedCountPerCustomer[6] += 1; }
        else if(currentDetail->value->dish_id == dishes[7].id){ dishesConsumedCountPerCustomer[7] += 1; }

        currentDetail = currentDetail->next;
      }
      currentBill = currentBill->next;
    }

    for(int i = 0; i<=7; i++){
      if(i == 0){
        favorite_dish_position = i;
        bigger = dishesConsumedCountPerCustomer[i];
      }else{
        if(bigger < dishesConsumedCountPerCustomer[i]){
          favorite_dish_position = i;
          bigger = dishesConsumedCountPerCustomer[i];
        }
      }
    }
    
    printf("El plato favorito es: %s\n",dishes[favorite_dish_position].name);
  }
  else
  {
    printf("No hay datos para procesar...\n");
  }
  system("pause");
}

//- Most Consumed Dish Function
void getMostConsumedDish(bill_list *list, dish *dishes){
  //- Local Variables
  int favorite_dish_position  = 0;
  int dishesConsumedCount[]   = {0,0,0,0,0,0,0,0};
  int bigger                  = 0;

  //- Bill list head
  bill_node *currentBill = list->head;
  
  //- Bill empty validation
  if (currentBill != NULL)
  {
    //- Bills While
    while (currentBill != NULL)
    {
      //- Bill data Head
      bill *billData = currentBill->value;

      //- Detail Head
      bill_detail_node *currentDetail = billData->details->head;
      
      //- Detail While
      while (currentDetail != NULL)
      {
        //- if the dish is on the detail, variable increase 1, the item quantity doesnt matter 
        if(currentDetail->value->dish_id == dishes[0].id){ dishesConsumedCount[0] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[1].id){ dishesConsumedCount[1] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[2].id){ dishesConsumedCount[2] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[3].id){ dishesConsumedCount[3] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[4].id){ dishesConsumedCount[4] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[5].id){ dishesConsumedCount[5] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[6].id){ dishesConsumedCount[6] += currentDetail->value->quantity; }
        else if(currentDetail->value->dish_id == dishes[7].id){ dishesConsumedCount[7] += currentDetail->value->quantity; }
        
        currentDetail = currentDetail->next;
      }
      currentBill = currentBill->next;
    }

    for(int i = 0; i<=7; i++){
      if(i == 0){
        favorite_dish_position = i;
        bigger = dishesConsumedCount[i];
      }else{
        if(bigger < dishesConsumedCount[i]){
          favorite_dish_position = i;
          bigger = dishesConsumedCount[i];
        }
      }
    }
    printf("El plato mas consumido es: %s\n",dishes[favorite_dish_position].name);
  }
  else
  {
    printf("No hay datos para procesar...\n");
  }

  system("pause");
}

void getDishMoreMoneyMakes(bill_list *list, dish *dishes){
  //- Local Variables
  int favorite_dish_position    = 0;
  float moneyGeneratedByDish[]  = {0.0,0.0,0.0,0.0,0.0,0.0,0.0};
  float bigger                  = 0;

  //- Bill list head
  bill_node *currentBill = list->head;
  
  //- Bill empty validation
  if (currentBill != NULL)
  {
    //- Bills While
    while (currentBill != NULL)
    {
      //- Bill data Head
      bill *billData = currentBill->value;

      //- Detail Head
      bill_detail_node *currentDetail = billData->details->head;
      
      //- Detail While
      while (currentDetail != NULL)
      {
        //- Evaluation Works
        //- if the dish is on the detail, variable increase
        if(currentDetail->value->dish_id == dishes[0].id){ moneyGeneratedByDish[0] += (currentDetail->value->quantity * currentDetail->value->price); }
        else if(currentDetail->value->dish_id == dishes[1].id){ moneyGeneratedByDish[1] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[2].id){ moneyGeneratedByDish[2] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[3].id){ moneyGeneratedByDish[3] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[4].id){ moneyGeneratedByDish[4] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[5].id){ moneyGeneratedByDish[5] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[6].id){ moneyGeneratedByDish[6] += currentDetail->value->quantity * currentDetail->value->price; }
        
        currentDetail = currentDetail->next;
      }
      currentBill = currentBill->next;
    }

    for(int i = 0; i<=7; i++){
      if(i == 0){
        favorite_dish_position = i;
        bigger = moneyGeneratedByDish[i];
      }else{
        if(bigger < moneyGeneratedByDish[i]){
          favorite_dish_position = i;
          bigger = moneyGeneratedByDish[i];
        }
      }
    }

    printf("El plato que mas dinero genera es: %s\n",dishes[favorite_dish_position].name);
  }
  else
  {
    printf("No hay datos para procesar...\n");
  }

  system("pause");
}

// Function to retreive average total by ID 
void getAveragePerCustomer(bill_list *list){
      bill_node *billCustomer = list->head;
      customer *idcustomer = searchCustomer();
      int id = 0;
      float totalSum = 0;
      int counter = 0;
      int validation = 0;
      float average = 0;
      if (idcustomer != NULL)
      {
        id = idcustomer->id;
          while(billCustomer != NULL){
          bill *billData = billCustomer->value;
            if(billData->customer_id == id){
              totalSum = totalSum + billData->total;
              counter = counter +1;
              }
        billCustomer = billCustomer->next;
      }
      average = totalSum/counter;
      printf("\nEl promedio de consumo del cliente %s con ID: %d es: $%'.2f\n",idcustomer->name, id, average);
      }
      else{
        printf("ID no encontrado.");
      }
      
      
      system("pause");
}

void getDishLessMoneyMakes(bill_list *list, dish *dishes){
  //- Local Variables
  int favorite_dish_position  = 0;
  int moneyGeneratedByDish[]  = {0.0,0.0,0.0,0.0,0.0,0.0,0.0};
  double minor                = 0;

  //- Bill list head
  bill_node *currentBill = list->head;
  
  //- Bill empty validation
  if (currentBill != NULL)
  {
    //- Bills While
    while (currentBill != NULL)
    {
      //- Bill data Head
      bill *billData = currentBill->value;

      //- Detail Head
      bill_detail_node *currentDetail = billData->details->head;
      
      //- Detail While
      while (currentDetail != NULL)
      {
        //- Evaluation Works
        //- if the dish is on the detail, variable increase
        if(currentDetail->value->dish_id == dishes[0].id){ moneyGeneratedByDish[0] += (currentDetail->value->quantity * currentDetail->value->price); }
        else if(currentDetail->value->dish_id == dishes[1].id){ moneyGeneratedByDish[1] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[2].id){ moneyGeneratedByDish[2] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[3].id){ moneyGeneratedByDish[3] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[4].id){ moneyGeneratedByDish[4] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[5].id){ moneyGeneratedByDish[5] += currentDetail->value->quantity * currentDetail->value->price; }
        else if(currentDetail->value->dish_id == dishes[6].id){ moneyGeneratedByDish[6] += currentDetail->value->quantity * currentDetail->value->price; }
        
        currentDetail = currentDetail->next;
      }
      currentBill = currentBill->next;
    }

    for(int i = 0; i<=7; i++){
      if(i == 0){
        favorite_dish_position = i;
        minor = moneyGeneratedByDish[i];
      }else{
        if(minor > moneyGeneratedByDish[i]){
          favorite_dish_position = i;
          minor = moneyGeneratedByDish[i];
        }
      }
    }
    printf("El plato que menos dinero genera es: %s\n",dishes[favorite_dish_position].name);
  }
  else
  {
    printf("No hay datos para procesar...\n");
  }

  system("pause");
}
//- END OF FUNCTIONS SECTION

void stats()
{
  int statsOption = statsMenu();
  system("cls");
      switch (statsOption)
      {
      case 1:
        calculateTotalSalesForToday();
        waitUser();
        break;
      case 2:
        getAveragePerCustomer(bills);
        break;
      case 3:
        // Platillo favorito
        getFavoriteDish(bills, dishes);
        break;
      case 4:
        // Platillo mas consumido
        getMostConsumedDish(bills, dishes);
        break;
      case 5:
        // Platillo mas rentable
        getDishMoreMoneyMakes(bills, dishes);
        break;
      case 6:
        // Platillo menos rentable
        getDishLessMoneyMakes(bills, dishes);
        break;
      default:
        printf("Opcion no valida\n");
        break;
      }
}
