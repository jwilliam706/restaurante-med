#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>

typedef struct{
	int Codigo;
	char Nombre[100];
	int Telefono;
	char Email[100];
	char Direccion [100];
	struct Cliente *sgte;
}Cliente;

Cliente *primero = NULL;
Cliente * ultimo = NULL;

void registroCliente(int i){
	system("cls");
	Cliente *cliente = malloc(sizeof(Cliente));
	//Ingresar cliente desde el menu
	if (i = 1){
		printf("Ingreso de clientes\n");
		printf("ID: "); scanf("%d",&cliente->Codigo);
		printf("Nombre: "); scanf(" %[^\n]",&cliente->Nombre);
		printf("Telefono: "); scanf("%d",&cliente->Telefono);
		printf("Email: "); scanf(" %[^\n]",&cliente->Email);
		printf("Direccion: "); scanf(" %[^\n]",&cliente->Direccion);
		printf("\n>>DATOS ALMACENADOS CORRECTAMENTE<<");
		
	}
	//Ingresar cliente desde el pedido de platillos
	else if (i = 2){
		
	}
}
void mostrarClientes(){
	system("cls");
	//Crear puntero auxiliar para recorrido de lista
	Cliente *i = primero;
	int aux = 0;
	
	//Preguntar si la lista no esta vacia
	if(i != NULL){
		printf("LISTADO DE CLIENTES");
		while (i != NULL){
		printf("\n ============================ \n")
		printf("Código: %d",i->Codigo);
		printf("Nombre: %s",i->Nombre);	
		printf("Telefono: %s",i->Telefono);	
		i = i->sgte;
		}
	}
	else{
		printf("<<NO HAY CLIENTES EN LA LISTA>>");
		printf("[1] Para agregar un cliente");
		printf("[2] Para salir");
		scanf("%d",&aux);
		if (aux = 1){
			registroCliente(aux);
		}
	}
}
