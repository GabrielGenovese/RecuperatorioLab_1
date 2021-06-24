#include "Servicio.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones_UTN.h"

int inicializacionServicio(eServicio *aServicios, int cantidadElementos)
{
	int retorno = -1;

	if(aServicios != NULL && cantidadElementos > 0)
	{
		for(int i = 0; i < cantidadElementos; i++)
		{
			retorno = 0;
			aServicios[i].isEmpty = 1;
		}
	}
	return retorno;
}


int buscarLibreServicio(eServicio *aServicios, int cantidadElementos, int* indice)
{
	int retorno = -1;

	if(aServicios != NULL && cantidadElementos > 0 && indice != NULL)
	{
		for(int i = 0; i < cantidadElementos; i++)
		{
			if(aServicios[i].isEmpty)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int ingresoDatosServicio(eServicio *aServicios,int posicion, int* idServicio)
{
	int retorno = -1;

	if (aServicios != NULL && posicion > -1 && idServicio != NULL)
	{
		aServicios[posicion].idServicio = *idServicio;

		validacionStringAlpha(aServicios[posicion].descripcion,"Ingrese la descripcion del servicio: ",25,"Error, Ingrese una descripcion correcta\n");
		validacionNumeroFloatConMinMax(&aServicios[posicion].precio,0,1000000,"Ingrese el precio del servicio: ","Ingrese un numero Correcto: ");

		aServicios[posicion].isEmpty = 0;
		*idServicio = *idServicio + 1 ;

		tituloServicio();
		imprimeUnServicio(aServicios,posicion);

		retorno = 0;
	}

	return retorno;
}


void tituloServicio()
{
	printf("\n%10s","ID|");
	printf("%20s","Descripcion|");
	printf("%20s","Precio|");
}


int imprimeUnServicio(eServicio *aServicios, int posicion)
{
	int retorno = -1;

	if(aServicios != NULL && posicion > -1)
	{
		printf("\n%10d|",(*(aServicios+posicion)).idServicio);
		printf("%20s|",(*(aServicios+posicion)).descripcion);
		printf("%20.2f|\n",(*(aServicios+posicion)).precio);

		retorno = 0;
	}

	return retorno;
}


int imprimeTodosLosServicios(eServicio *aServicios,int cantidadElementos)
{
	int retorno = -1;

	if(aServicios != NULL && cantidadElementos > 0)
	{
		tituloServicio();
		for(int i = 0; i < cantidadElementos; i++)
		{
			if(!(*(aServicios+i)).isEmpty)
			{
				imprimeUnServicio(aServicios,i);
				retorno=0;
			}

		}
	}

	return retorno;
}


int buscarIdServicio(eServicio servicios[],int cantidadElementos, int* posicionID,char mensaje[])
{
	int retorno = -1;
	int idTrabajo;

	if(servicios != NULL && posicionID != NULL && cantidadElementos > 0 && mensaje != NULL)
	{
		validacionNumeroEntero(&idTrabajo,mensaje);

		for(int i = 0; i < cantidadElementos; i++)
		{
			if(!(*(servicios+i)).isEmpty && (*(servicios+i)).idServicio == idTrabajo)
			{
				*posicionID = i;
				imprimeUnServicio(servicios,i);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int buscarIdServicioPorDescripcion(eServicio *aServicios,int cantidadElementos, int* id,char mensaje[])
{
	int retorno = -1;
	char descripcionServicio[25];
	char descripcionAux[25];

	if(aServicios != NULL && id != NULL && cantidadElementos > 0 && mensaje != NULL)
	{
		validacionStringAlpha(descripcionServicio,mensaje,25,"Error, ");
		strlwr(descripcionServicio);
		for(int i = 0; i < cantidadElementos; i++)
		{
			strcpy(descripcionAux,aServicios[i].descripcion);
			strlwr(descripcionAux);
			if(!aServicios[i].isEmpty && !strcmp(descripcionAux,descripcionServicio))
			{
				*id = aServicios[i].idServicio;
				imprimeUnServicio(aServicios,i);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int bajaLogicaServicio(eServicio *aServicios, int posicion)
{
	int retorno = -1;

	if(aServicios != NULL)
	{
		aServicios[posicion].isEmpty = 1;
		retorno = 0;
	}

	return retorno;
}


int imprimeServicioPorID(eServicio *aServicios, int cantidadElementos, int idContribuyente)
{
	int retorno = -1;
	if(aServicios != NULL && cantidadElementos > 0 && idContribuyente > 99)
	{
		tituloServicio();
		for(int i = 0; i < cantidadElementos ; i++)
		{
			if(aServicios[i].idServicio == idContribuyente && !aServicios[i].isEmpty)
			{
				imprimeUnServicio(aServicios,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}



