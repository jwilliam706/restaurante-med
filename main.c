# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

int mainMenu()
{
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
  return option;
}

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

int main(){
    mainMenu();
}