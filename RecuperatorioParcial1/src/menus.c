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
		printf("7. El o los servicios con más trabajos realizados.\n");
		printf("8. salir\n");
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

int menuInformes(int* opcElegida, char mensaje[])
{
	int retorno = -1;
	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Listado de todos los trabajos ordenados por año y marca\n");
		printf("2. Listado de todos los trabajos ordenados por marca de la bicicleta.\n");
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
		printf("\n0. Ordenar de forma descendente\n");
		printf("1. Ordenar de forma ascendente\n");
		validacionNumeroEntero(opcElegida,mensaje);
		retorno = 0;
	}
	return retorno;
}

