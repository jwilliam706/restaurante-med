# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

int mainMenu()
{
  int result;
  printf("--------------------------------------------------\n          SISTEMA DE RESTAURANTE\n-------------------------------------------------- \n\n");

  printf("Seleccione una opcion: \n\n");
  printf("[1] Leer precios de los platillos\n");
  printf("[2] Generar nueva factura\n");
  printf("[3]  Estadisticas\n");
  printf("[4]  Salir\n");
  printf("Opcion: ");
  scanf("%d", &result);
  getchar();
  return result;
}
int main(){
    mainMenu();
}