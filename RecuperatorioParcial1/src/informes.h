#ifndef INFORMES_H_
#define INFORMES_H_

int totalServiciosPrestados(eTrabajo *aTrabajos,int cantidadTrabajos, eServicio *aServicios,int cantidadServicios);

int listarTrabajosConDescripcionServicio(eTrabajo *trabajos,int cantidadTrabajos,eServicio *aServicios,int cantidadServicios);

int buscaEImprimeServicioMasUsado(eTrabajo *trabajos,int cantidadTrabajos,eServicio *aServicios,int cantidadServicios);

#endif
