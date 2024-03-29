#include <stdio.h>
#include <stdlib.h>
#include "Servicio.h"
#include "Trabajo.h"
#include "menus.h"
#include "validaciones_UTN.h"
#include "informes.h"

#define TRABAJOS 100
#define SERVICIOS 4

int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int opcionSecundaria = 0;
	int orden;
	int idServicioDeTrabajo;
	int idTrabajo = 1;
	//int idServicios = 2004;
	int indiceTrabajo;
	int posicionID;
	int trabajoIngresado = 0;

	eServicio servicios[SERVICIOS] = {
			{2000,"Limpieza",250,0},
			{2001,"Parche",300,0},
			{2002,"Centrado",400,0},
			{2003,"Cadena",350,0}
	};

	eTrabajo trabajos[TRABAJOS];/* = {
			{1,"yoyo",26,2000,{28,12,2000},0},
			{2,"maraca",26,2002,{28,12,2001},0},
			{3,"porra",26,2001,{28,12,2002},0},
			{4,"alert",26,2002,{28,12,2021},0},
			{5,"cachi",26,2000,{28,12,2008},0}
	};*/

	inicializacionTrabajo(trabajos,TRABAJOS);
	inicializacionServicio(servicios,SERVICIOS);
	(*(servicios+0)).isEmpty = 0;
	(*(servicios+1)).isEmpty = 0;
	(*(servicios+2)).isEmpty = 0;
	(*(servicios+3)).isEmpty = 0;
	/*(*(trabajos+0)).isEmpty = 0;
	(*(trabajos+1)).isEmpty = 0;
	(*(trabajos+2)).isEmpty = 0;
	(*(trabajos+3)).isEmpty = 0;
	(*(trabajos+4)).isEmpty = 0;
	*/
	do{
		menuPrincipal(&opcion,"Opcion: ");
		switch(opcion)
		{
		case 1:
			if(!buscarIdServicioPorDescripcion(servicios,SERVICIOS,&idServicioDeTrabajo,"Ingrese el servicio dado a la bicicleta (Limpieza/Parche/etc...): "))
			{
				altaTrabajo(trabajos,TRABAJOS,&idTrabajo,idServicioDeTrabajo);
				trabajoIngresado = 1;
			}
			else
			{
				printf("Servicio Inexistente\n");
			}
			break;
		case 2:
			if(trabajoIngresado)
			{
				if(!buscarIdTrabajo(trabajos,TRABAJOS,&posicionID,"Ingrese el id del trabajo a modificar: "))
				{
					do
					{
						menuModificar(&opcionSecundaria,"Opcion:");
						switch(opcionSecundaria)
						{
						case 1:
							validacionStringAlpha((*(trabajos+posicionID)).marcaBicicleta,"Ingrese la nueva marca de la bicicleta: ",21,"Error, ");
							imprimeUnTrabajo(trabajos,posicionID);
							break;
						case 2:
							if(!buscarIdServicioPorDescripcion(servicios,SERVICIOS,&idServicioDeTrabajo,"Ingrese el servicio dado a la bicicleta (Limpieza/Parche/etc...): "))
							{
								(*(trabajos+posicionID)).idServicio = idServicioDeTrabajo;
								imprimeUnTrabajo(trabajos,posicionID);
							}
							break;
						case 3:
							break;
						default:
							printf("Opcion Invalida\n");
							break;
						}
					}while(opcionSecundaria != 3);
				}
				else
				{
					printf("ID INVALIDO\n");
				}
			}
			else
			{
				printf("NO HAY TRABAJOS INGRESADOS\n");
			}

			break;
		case 3:
			if(trabajoIngresado)
			{
				if(!buscarIdTrabajo(trabajos,TRABAJOS,&indiceTrabajo,"Ingrese el id del trabajo a dar de baja: "))
				{
					imprimeUnTrabajo(trabajos,indiceTrabajo);
					if(!bajaLogicaTrabajo(trabajos,indiceTrabajo))
					{
						printf("Trabajo borrado correctamente\n");
					}
				}
				else
				{
					printf("ID INVALIDO\n");
				}
			}
			else
			{
				printf("NO HAY TRABAJOS INGRESADOS\n");
			}
			break;
		case 4:
			if(trabajoIngresado)
			{
				do
				{
					menuInformes(&opcionSecundaria,"Opcion: ");
				}while(opcionSecundaria < 1 || opcionSecundaria > 3);
				do
				{
					menuAscDesc(&orden,"Opcion: ");
				}while(orden < 0 || orden > 1 );
				switch(opcionSecundaria)
				{
				case 1:
					ordenaPorAnioYMarca(trabajos,TRABAJOS,orden);
					break;
				case 2:
					ordenaPorMarca(trabajos,TRABAJOS,orden);
					break;
				case 3:
					break;
				}
				listarTrabajosConDescripcionServicio(trabajos,TRABAJOS,servicios,SERVICIOS);
			}
			else
			{
				printf("NO HAY TRABAJOS INGRESADOS\n");
			}

			break;
		case 5:
			imprimeTodosLosServicios(servicios,SERVICIOS);
			break;
		case 6:
			if(trabajoIngresado)
			{
				totalServiciosPrestados(trabajos,TRABAJOS,servicios,SERVICIOS);
			}
			else
			{
				printf("NO HAY TRABAJADORES INGRESADOS\n");
			}
			break;
		case 7:
			if(trabajoIngresado)
			{
				buscaEImprimeServicioMasUsado(trabajos,TRABAJOS,servicios,SERVICIOS);
			}
			else
			{
				printf("NO HAY TRABAJADORES INGRESADOS\n");
			}
			break;
		case 8:
			break;
		default:
			printf("Opcion Invalida\n");
			break;
		}
	}while(opcion != 8);

	return EXIT_SUCCESS;
}
