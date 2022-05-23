#include <stdio.h>
#include <stdlib.h>

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

void stats()
{
  int statsOption = statsMenu();
      switch (statsOption)
      {
      case 1:
        // Ventas totales del dia
        break;
      case 2:
        // Promedio de consumo por cliente
        break;
      case 3:
        // Platillo favorito
        break;
      case 4:
        // Platillo mas consumido
        break;
      case 5:
        // Platillo mas rentable
        break;
      case 6:
        // Platillo menos rentable
        break;
      default:
        printf("Opcion no valida\n");
        break;
      }
}
