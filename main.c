#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include "dishes.c"
#include "stats.c"

int mainMenu()
{
  system("cls");
  int option;
  printf("--------------------------------------------------\n          SISTEMA DE RESTAURANTE\n-------------------------------------------------- \n\n");

  printf("Seleccione una opcion: \n\n");
  printf("[1] Leer precios de los platillos\n");
  printf("[2] Generar nueva factura\n");
  printf("[3]  Estadisticas\n");
  printf("[4]  Salir\n");
  printf("Opcion: ");
  scanf("%d", &option);
  getchar();
  system("cls");
  return option;
}

int main(){
    int menuOption = mainMenu();
    switch (menuOption)
    {
    case 1:
      // Leer precios de los platillos
      readDishes();
      break;
    case 2:
      // Generar nueva factura
      break;
    case 3:
      // Estadisticas
      stats();
    case 4:
      // Salir
      break;
    
    default:
      printf("Opcion no valida\n");
      break;
    }
}