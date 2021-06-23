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
	int idServicioDeTrabajo;
	int idTrabajo = 1;
	int indiceTrabajo;
	int posicionID;
	int trabajoIngresado = 0;

	eServicio servicios[SERVICIOS] = {
			{2000,"Limpieza",250,0},
			{2001,"Parche",300,0},
			{2002,"Centrado",400,0},
			{2003,"Cadena",350,0}
	};

	eTrabajo trabajos[TRABAJOS] = {
			{1,"toyota",26,2000,{28,12,2000},0},
			{2,"motor",25,2001,{28,12,2000},0},
			{3,"movis",26,2003,{28,12,2015},0},
			{4,"roche",26,2002,{28,12,2007},0}
	};

	inicializacionTrabajo(trabajos,TRABAJOS);
	inicializacionServicio(servicios,SERVICIOS);
	(*(servicios+0)).isEmpty = 0;
	(*(servicios+1)).isEmpty = 0;
	(*(servicios+2)).isEmpty = 0;
	(*(servicios+3)).isEmpty = 0;
	(*(trabajos+0)).isEmpty = 0;
	(*(trabajos+1)).isEmpty = 0;
	(*(trabajos+2)).isEmpty = 0;
	(*(trabajos+3)).isEmpty = 0;

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
				printf("Servicio Inexistente");
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
							validacionStringAlpha((*(trabajos+posicionID)).marcaBicicleta,"Ingrese la nueva marca de la bicicleta: ",21);
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
							printf("Opcion Invalida");
							break;
						}
					}while(opcionSecundaria != 3);
				}
				else
				{
					printf("ID INVALIDO");
				}
			}
			else
			{
				printf("NO HAY TRABAJOS INGRESADOS");
			}

			break;
		case 3:
			if(trabajoIngresado)
			{
				if(!buscarIdTrabajo(trabajos,TRABAJOS,&indiceTrabajo,"Ingrese el id del trabajo a dar de baja: "))
				{
					bajaLogicaTrabajo(trabajos,indiceTrabajo);
				}
				else
				{
					printf("ID INVALIDO");
				}
			}
			else
			{
				printf("NO HAY TRABAJOS INGRESADOS");
			}
			break;
		case 4:
			if(trabajoIngresado)
			{
				do
				{
					menuAscDesc(&opcionSecundaria,"Opcion: ");
				}while(opcionSecundaria < 1 || opcionSecundaria > 3 );
				switch(opcionSecundaria)
				{
				case 1:
					listarTrabajos(trabajos,TRABAJOS,1);
					break;
				case 2:
					listarTrabajos(trabajos,TRABAJOS,0);
					break;
				case 3:
					break;
				}
			}
			else
			{
				printf("NO HAY TRABAJOS INGRESADOS");
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
				printf("NO HAY TRABAJADORES INGRESADOS");
			}

			break;
		case 7:
			break;
		default:
			printf("Opcion Invalida");
			break;
		}

	}while(opcion != 7);

	return EXIT_SUCCESS;
}
