#ifndef TRABAJO_H_
#define TRABAJO_H_

#define TEXTO 21

typedef struct{
	int dia;
	int Mes;
	int Anio;
}eFecha;

typedef struct
{
	int idTrabajo;

	char marcaBicicleta[TEXTO];
	int rodadoBicicleta;
	int idServicio;
	eFecha fecha;

	int isEmpty;
}eTrabajo;


/*brief Inicializa todos los elementos del array contribuyentes en vacio (isEmpty = 1)
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int inicializacionTrabajo(eTrabajo trabajos[], int cantidadElementos);


/*brief Busca un elemento vacio en el array contribuyentes y devuelve la posicion de este en el array por referencia.
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array de tipo int.
 * param3 Variable donde se guardara el indice pasado por referencia, Tipo int*.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int buscarLibreTrabajo(eTrabajo trabajos[], int cantidadElementos, int* indice);


/*brief Hace las validaciones de datos e ingresa los datos en un elemento del array contribuyentes, suma +1 al contador
idContribuyente despues del ingreso y validaciones, y asigna ese elemento en uso (isEmpty = 0).
 * param1 Array de tipo eContribuyente.
 * param2 Posicion del elemento en el array contribuyentes, Tipo Int.
 * param3 Id del contribuyente al que se le esta agregando los datos,Tipo int*.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int ingresoDatosTrabajo(eTrabajo trabajos[],int posicion, int* idTrabajo, int idServicio);


/*brief Imprime el titulo de los datos de un contribuyente.
 * */
void tituloTrabajo();


/*brief Imprime la fecha de la estructura pasada por parametros
 * param1 Fecha eFecha, estructura que guarda el dia mes y año a imprimier
 * return retorna 0 si no hubo problemas, sino imprime -1
 * */
int imprimeFecha(eFecha *Fecha);

/*brief Imprime los datos de un contribuyente del array contribuyentes
 * param1 Array de tipo eContribuyente.
 * param2 Posicion del elemento a imprimir, en el array contribuyentes, Tipo Int.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int imprimeUnTrabajo(eTrabajo *trabajos, int posicion);


/*brief Pide un id y lo busca entre los ids de todos los elementos del array contribuyentes, si lo encuentra devuelve la posicion del
elemento en el array por referencia.
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array, Tipo int.
 * param3 Variable donde se guardara la posicion del elemento que su id coincide con el id ingresado, Tipo int*.
 * param4 Mensaje que se mostrara cuando pida el id, Tipo Char [].
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int buscarIdTrabajo(eTrabajo trabajos[],int cantidadElementos, int* posicionID, char mensaje[]);


/*brief Hace la baja logica, pone un elemento en vacio (isEmpty = 1), de un elemento del array contribuyentes.
 * param1  Array de tipo eContribuyente.
 * param2 Posicion del elemento a hacer la baja logica, en el array contribuyentes, Tipo Int.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int bajaLogicaTrabajo(eTrabajo trabajos[], int posicion);


/*brief Busca un elemento del array contribuyentes que su id coincida con el id pasado por parametros y si lo encuentra imprime sus
 datos.
* param1 Array de tipo eContribuyente.
* param2 Cantidad de elementos del array de tipo int.
* param3 Id de un contribuyente pasada por valor, Tipo int.
* return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int imprimeTrabajoPorID(eTrabajo trabajos[], int cantidadElementos, int idContribuyente);


/*brief Hace el alta de un elemento eTrabajo y lo guarda en el array trabajos
 * param1 eTrabajo *trabajos, array donde seran guardados los elementos dados de alta.
 * param2 int cantidadElementos, cantidad de elementos del array.
 * param3 int* idTrabajo, id del trabajo que sera dado de alta, al dar de alta un trabajo al id se le suma 1
 * param4 int idServicio, idServicio del trabajo que sera dado de alta.
 * */
int altaTrabajo(eTrabajo *trabajos, int cantidadElementos, int* idTrabajo,int idServicio);


/*brief Ordena por Año y si son iguales ordena por marca, segun el orden (ascendente/descendente)
 * param1 eTrabajo *trabajos, array con los elementos a ordenar.
 * param2 int cantidadElementos, cantidad de elementos del array.
 * param3 int orden,[1] para que sea ascendente [0] para que sea descendente.
 * return retorna 0 si funciona correctamente o -1 si hubo algun error.
 * */
int ordenaPorAnioYMarca (eTrabajo *trabajos,int cantidadElementos, int orden);


/*brief ordena e imprime todos los trabajos de un array de tipo eTrabajo
 * param1 eTrabajo* trabajos, array a ordenar e imprimir.
 * param2 int cantidadElementos, cantidad de elementos del array.

 * */
int listarTrabajos(eTrabajo *trabajos,int cantidadElementos);


int ordenaPorMarca(eTrabajo *trabajos,int cantidadElementos, int orden);

/*********************************************MANIULACIONES DE LA SEGUNDA ESTRUCTURA***********************************/


/*brief Busca un elemento del array recaudaciones en el que su idContribuyente coincida con el id pasado por parametros y
si lo encuentra imprime sus datos.
* param1 Array de tipo eRecaudacion.
* param2 Cantidad de elementos del array de tipo int.
* param3 Id de un contribuyente pasada por valor, Tipo int.
* return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
//int imprimeRecaudacionesPorIDContribuyente(eRecaudacion recaudaciones[], int cantidadElementos, int idContribuyente);


/*brief Hace la baja logica, pone un elemento en vacio (isEmpty = 1), de un elemento del array recaudaciones.
 * param1  Array de tipo eRecaudacion.
 * param2 Posicion del elemento a hacer la baja logica, en el array recaudaciones, Tipo Int.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
//int bajaLogicaRecaudacionesPorIDContribuyente(eRecaudacion recaudaciones[], int cantidadElementos, int idContribuyente);

#endif /* TRABAJO_H_ */
