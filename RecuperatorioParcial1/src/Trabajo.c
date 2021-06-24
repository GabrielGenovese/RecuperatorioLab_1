#include "Trabajo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones_UTN.h"



int inicializacionTrabajo(eTrabajo trabajos[], int cantidadElementos)
{
	int retorno = -1;

	if(trabajos != NULL && cantidadElementos > 0)
	{
		for(int i = 0; i < cantidadElementos; i++)
		{
			retorno = 0;
			trabajos[i].isEmpty = 1;
		}
	}


	return retorno;
}


int buscarLibreTrabajo(eTrabajo trabajos[], int cantidadElementos, int* indice)
{
	int retorno = -1;

	if(trabajos != NULL && cantidadElementos > 0 && indice != NULL)
	{
		for(int i = 0; i < cantidadElementos; i++)
		{
			if(trabajos[i].isEmpty)
			{
				*indice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}




int ingresoDatosTrabajo(eTrabajo *trabajos,int posicion, int* idTrabajo, int idServicio)
{
	int retorno = -1;

	if (trabajos != NULL && posicion > -1 && idTrabajo != NULL)
	{
		trabajos[posicion].idTrabajo = *idTrabajo;

		validacionStringAlpha((*(trabajos+posicion)).marcaBicicleta,"Ingrese la marca de la bicicleta: ",21,"Error,");
		trabajos[posicion].idServicio = idServicio;
		validacionNumeroEnteroConMinMax(&(*(trabajos+posicion)).fecha.dia,1,30,"Ingrese el dia: ","Porfavor Ingrese un dia Correcto: ");
		validacionNumeroEnteroConMinMax(&(*(trabajos+posicion)).fecha.Mes,1,12,"Ingrese el mes: ","Porfavor Ingrese un mes Correcto: ");
		validacionNumeroEnteroConMinMax(&(*(trabajos+posicion)).fecha.Anio,2000,2021,"Ingrese el Año: ","Porfavor Ingrese un Año Correcto: ");

		trabajos[posicion].isEmpty = 0;
		*idTrabajo = *idTrabajo + 1 ;

		tituloTrabajo();
		imprimeUnTrabajo(trabajos,posicion);

		retorno = 0;
	}

	return retorno;
}


void tituloTrabajo()
{
	printf("\n%10s|","ID");
	printf("%20s|","Marca");
	printf("%10s|","Fecha");
	printf("%20s|","ID Servicio");
}

int imprimeFecha(eFecha *Fecha)
{
	int retorno = -1;

	if(Fecha != NULL)
	{
		printf("%2d/%2d/%4d|",(*Fecha).dia,(*Fecha).Mes,(*Fecha).Anio);
	}

	return retorno;
}

int imprimeUnTrabajo(eTrabajo *trabajos, int posicion)
{
	int retorno = -1;

	if(trabajos != NULL && posicion > -1)
	{
		printf("\n%10d|",trabajos[posicion].idTrabajo);
		printf("%20s|",trabajos[posicion].marcaBicicleta);
		imprimeFecha(&trabajos[posicion].fecha);
		printf("%20d|",trabajos[posicion].idServicio);

		retorno = 0;
	}

	return retorno;
}

int buscarIdTrabajo(eTrabajo trabajos[],int cantidadElementos, int* posicionID,char mensaje[])
{
	int retorno = -1;
	int idTrabajo;

	if(trabajos != NULL && posicionID != NULL && cantidadElementos > 0 && mensaje != NULL)
	{
		validacionNumeroEntero(&idTrabajo,mensaje);

		for(int i = 0; i < cantidadElementos; i++)
		{
			if(!trabajos[i].isEmpty && trabajos[i].idTrabajo == idTrabajo)
			{
				*posicionID = i;
				imprimeUnTrabajo(trabajos,i);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int bajaLogicaTrabajo(eTrabajo trabajos[], int posicion)
{
	int retorno = -1;

	if(trabajos != NULL)
	{
		trabajos[posicion].isEmpty = 1;
		retorno = 0;
	}

	return retorno;
}


int imprimeTrabajoPorID(eTrabajo trabajos[], int cantidadElementos, int idTrabajo)
{
	int retorno = -1;
	if(trabajos != NULL && cantidadElementos > 0 && idTrabajo > 99)
	{
		tituloTrabajo();
		for(int i = 0; i < cantidadElementos ; i++)
		{
			if(trabajos[i].idTrabajo == idTrabajo && !trabajos[i].isEmpty)
			{
				imprimeUnTrabajo(trabajos,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int altaTrabajo(eTrabajo *trabajos, int cantidadElementos, int* idTrabajo,int idServicio)
{
	int retorno = -1;
	int indiceLibre;

	if(trabajos != NULL && cantidadElementos > 0 && idTrabajo != NULL && idServicio > 1999)
	{
		if(!buscarLibreTrabajo(trabajos,cantidadElementos,&indiceLibre))
		{
			ingresoDatosTrabajo(trabajos,indiceLibre,idTrabajo,idServicio);
			retorno = 0;
		}
		else
		{
			printf("No hay espacio para mas trabajos.");
		}
	}

	return retorno;
}



int ordenaPorAnioYMarca (eTrabajo *trabajos,int cantidadElementos, int orden)
{
	int retorno = -1;
	eTrabajo Aux;

	if(trabajos != NULL && cantidadElementos > 0 && (orden == 0 || orden == 1))
	{
		for(int i = 0; i < cantidadElementos -1; i++)
		{
			for(int j = i+1; j < cantidadElementos; j++)
			{
				if(!(*(trabajos+i)).isEmpty &&!(*(trabajos+j)).isEmpty )
				{
					if((orden && (*(trabajos+i)).fecha.Anio > (*(trabajos+j)).fecha.Anio) || (!orden && (*(trabajos+i)).fecha.Anio < (*(trabajos+j)).fecha.Anio))
					{
						Aux = *(trabajos+i);
						*(trabajos+i) = *(trabajos+j);
						*(trabajos+j) = Aux;
						retorno = 0;
					}
					else
					{
						if((*(trabajos+i)).fecha.Anio == (*(trabajos+j)).fecha.Anio)
						{
							if((orden && strcmp((*(trabajos+i)).marcaBicicleta,(*(trabajos+j)).marcaBicicleta) == 1) || (!orden && strcmp((*(trabajos+i)).marcaBicicleta,(*(trabajos+j)).marcaBicicleta) == -1))
							{
								Aux = *(trabajos+i);
								*(trabajos+i) = *(trabajos+j);
								*(trabajos+j) = Aux;
								retorno = 0;
							}
						}

					}
				}

			}
		}
	}

	return retorno;
}

int ordenaPorMarca(eTrabajo *trabajos,int cantidadElementos, int orden)
{
	int retorno = -1;
	eTrabajo Aux;

	if(trabajos != NULL && cantidadElementos > 0 && (orden == 0 || orden == 1))
	{
		for(int i = 0; i < cantidadElementos -1; i++)
				{
					for(int j = i+1; j < cantidadElementos; j++)
					{
						if((orden && strcmp((*(trabajos+i)).marcaBicicleta,(*(trabajos+j)).marcaBicicleta) == 1) || (!orden && strcmp((*(trabajos+i)).marcaBicicleta,(*(trabajos+j)).marcaBicicleta) == -1))
						{
							Aux = *(trabajos+i);
							*(trabajos+i) = *(trabajos+j);
							*(trabajos+j) = Aux;
							retorno = 0;
						}

					}
				}
	}
	return retorno;
}

int listarTrabajos(eTrabajo *trabajos,int cantidadElementos)
{
	int retorno = -1;
	if(trabajos != NULL && cantidadElementos >0)
	{
		tituloTrabajo();
		for(int i = 0; i < cantidadElementos;i++)
		{
			if(!(*(trabajos+i)).isEmpty)
			{
				imprimeUnTrabajo(trabajos,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/*********************************************MANIULACIONES DE LA SEGUNDA ESTRUCTURA***********************************/


/*
int imprimeRecaudacionesPorIDContribuyente(eRecaudacion recaudaciones[], int cantidadElementos, int idContribuyente)
{
	int retorno = -1;
	if(recaudaciones != NULL && cantidadElementos > 0 && idContribuyente >999)
	{
		tituloRecaudaciones();
		for(int i = 0; i < cantidadElementos ; i++)
		{
			if(recaudaciones[i].idContribuyente == idContribuyente && !recaudaciones[i].isEmpty)
			{
				imprimeUnaRecaudacion(recaudaciones,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}


int bajaLogicaRecaudacionesPorIDContribuyente(eRecaudacion recaudaciones[], int cantidadElementos, int idContribuyente)
{
	int retorno = -1;

	if(recaudaciones != NULL && cantidadElementos > 0 && idContribuyente >999)
	{
		for(int i = 0; i < cantidadElementos; i++)
		{
			if(recaudaciones[i].idContribuyente == idContribuyente && !recaudaciones[i].isEmpty)
			{
				recaudaciones[i].isEmpty = 1;
			}
		}
		retorno = 0;
	}

	return retorno;
}
*/
