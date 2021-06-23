#include <stdio.h>
#include "validaciones_UTN.h"

int menuPrincipal(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Alta Trabajo\n");
		printf("2. Modificar Trabajo\n");
		printf("3. Baja Trabajo\n");
		printf("4. Listar Trabajos\n");
		printf("5. Listar Servicios\n");
		printf("6. Total\n");
		printf("7. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}

int menuModificar(int* opcElegida, char mensaje[])
{
	int retorno = -1;
	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n\t Menu Modificar\n");
		printf("\n1. Modificar Marca de La Bicicleta\n");
		printf("2. Modificar Servicio\n");
		printf("3. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);
		retorno = 0;
	}
	return retorno;
}


int menuAscDesc(int* opcElegida, char mensaje[])
{
	int retorno = -1;
	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Ordenar de forma ascendente\n");
		printf("2. Ordenar de forma descendente\n");
		printf("3. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);
		retorno = 0;
	}
	return retorno;
}

