#include "Servicio.h"
#include "Trabajo.h"
#include <stdio.h>
#include <stdlib.h>

int totalServiciosPrestados(eTrabajo *aTrabajos,int cantidadTrabajos, eServicio *aServicios,int cantidadServicios)
{
	int retorno = -1;
	float acumuladorDineroTotal = 0;

	if(aTrabajos != NULL && cantidadTrabajos > 0 && aServicios != NULL && cantidadServicios > 0)
	{
		for(int i = 0; i <cantidadTrabajos; i++)
		{
			if(!(*(aTrabajos+i)).isEmpty)
			{
				for(int j = 0; j < cantidadServicios; j++)
				{
					if((*(aTrabajos+i)).idServicio == (*(aServicios+j)).idServicio && !(*(aServicios+j)).isEmpty)
					{
						acumuladorDineroTotal += (*(aServicios+j)).precio;
						retorno = 0;
					}
				}
			}
		}
		printf("El total de dinero por los servicios prestados es: %.2f",acumuladorDineroTotal);
	}

	return retorno;
}
void tituloTrabajoConServicio()
{
	tituloTrabajo();
	printf("%25s|","Descripcion Servicio\n");
}


int listarTrabajosConDescripcionServicio(eTrabajo *trabajos,int cantidadTrabajos,eServicio *aServicios,int cantidadServicios)
{
	int retorno = -1;
	if(trabajos != NULL && cantidadTrabajos >0 && aServicios != NULL && cantidadServicios > 0)
	{
		tituloTrabajoConServicio();
		for(int i = 0; i < cantidadTrabajos;i++)
		{
			if(!(*(trabajos+i)).isEmpty)
			{
				imprimeUnTrabajo(trabajos,i);
				for(int j = 0; j <cantidadServicios;j++)
				{
					if((*(aServicios+j)).idServicio == (*(trabajos+i)).idServicio)
					{
						printf("%25s|",(*(aServicios+j)).descripcion);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int buscaEImprimeServicioMasUsado(eTrabajo *trabajos,int cantidadTrabajos,eServicio *aServicios,int cantidadServicios)
{
	int retorno = -1;
	int contadorDelServicioMasUsado;
	int contador = 0;
	int flagPrimerComparacion = 0;

	if(trabajos != NULL && cantidadTrabajos > 0 && aServicios != NULL && cantidadServicios > 0)
	{
		for(int i = 0; i < cantidadServicios; i++ )
		{
			contador = 0;
			for(int j = 0; j < cantidadTrabajos; j++)
			{
				if((*(aServicios+i)).idServicio == (*(trabajos+j)).idServicio)
				{
					contador++;
				}
			}
			if(!flagPrimerComparacion || (contadorDelServicioMasUsado < contador))
			{
				contadorDelServicioMasUsado = contador;
				retorno = 0;

				flagPrimerComparacion = 1;
			}
		}
		printf("El Servicio Mas usado es: \n\n");
		tituloServicio();
		for(int i = 0; i < cantidadServicios; i++ )
		{
			contador = 0;
			for(int j = 0; j < cantidadTrabajos; j++)
			{

				if((*(aServicios+i)).idServicio == (*(trabajos+j)).idServicio)
				{
					contador++;
				}
			}
			if(contador == contadorDelServicioMasUsado)
			{
				imprimeUnServicio(aServicios,i);
			}
		}
		retorno = 0;
	}
	return retorno;
}
