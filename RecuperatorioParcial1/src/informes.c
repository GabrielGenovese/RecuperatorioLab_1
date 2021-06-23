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
