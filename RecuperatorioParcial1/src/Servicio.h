#ifndef SERVICIO_H_
#define SERVICIO_H_

#define DESCRIPCION 25

typedef struct
{
	int idServicio;
	char descripcion[DESCRIPCION];
	float precio;

	int isEmpty;
}eServicio;


/*brief Inicializa todos los elementos del array contribuyentes en vacio (isEmpty = 1)
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int inicializacionServicio(eServicio *aServicios, int cantidadElementos);


/*brief Busca un elemento vacio en el array contribuyentes y devuelve la posicion de este en el array por referencia.
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array de tipo int.
 * param3 Variable donde se guardara el indice pasado por referencia, Tipo int*.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int buscarLibreServicio(eServicio aServicios[], int cantidadElementos, int* indice);


/*brief Hace las validaciones de datos e ingresa los datos en un elemento del array contribuyentes, suma +1 al contador
idContribuyente despues del ingreso y validaciones, y asigna ese elemento en uso (isEmpty = 0).
 * param1 Array de tipo eContribuyente.
 * param2 Posicion del elemento en el array contribuyentes, Tipo Int.
 * param3 Id del contribuyente al que se le esta agregando los datos,Tipo int*.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int ingresoDatosServicio(eServicio aServicios[],int posicion, int* idContribuyente);


/*brief Imprime el titulo de los datos de un contribuyente.
 * */
void tituloServicio();


/*brief Imprime los datos de un contribuyente del array contribuyentes
 * param1 Array de tipo eContribuyente.
 * param2 Posicion del elemento a imprimir, en el array contribuyentes, Tipo Int.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int imprimeUnServicio(eServicio aServicios[], int posicion);


/*brief Pide un id y lo busca entre los ids de todos los elementos del array contribuyentes, si lo encuentra devuelve la posicion del
elemento en el array por referencia.
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array, Tipo int.
 * param3 Variable donde se guardara la posicion del elemento que su id coincide con el id ingresado, Tipo int*.
 * param4 Mensaje que se mostrara cuando pida el id, Tipo Char [].
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int buscarIdServicio(eServicio servicios[],int cantidadElementos, int* posicionID,char mensaje[]);

/*brief Pide una descripcion de un servicio y lo busca entre los ids de todos los elementos del array contribuyentes,
 * si lo encuentra devuelve el id del elemento en el array por referencia.
 * param1 Array de tipo eContribuyente.
 * param2 Cantidad de elementos del array, Tipo int.
 * param3 Variable donde se guardara la posicion del elemento que su id coincide con el id ingresado, Tipo int*.
 * param4 Mensaje que se mostrara cuando pida el id, Tipo Char [].
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int buscarIdServicioPorDescripcion(eServicio aServicios[],int cantidadElementos, int* id, char mensaje[]);


/*brief Hace la baja logica, pone un elemento en vacio (isEmpty = 1), de un elemento del array contribuyentes.
 * param1  Array de tipo eContribuyente.
 * param2 Posicion del elemento a hacer la baja logica, en el array contribuyentes, Tipo Int.
 * return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int bajaLogicaServicio(eServicio aServicios[], int posicion);


/*brief Busca un elemento del array contribuyentes que su id coincida con el id pasado por parametros y si lo encuentra imprime sus
 datos.
* param1 Array de tipo eContribuyente.
* param2 Cantidad de elementos del array de tipo int.
* param3 Id de un contribuyente pasada por valor, Tipo int.
* return retorna 0 si no hubo problemas, y -1 si hubo algun error.
 * */
int imprimeServicioPorID(eServicio aServicios[], int cantidadElementos, int idContribuyente);

/*brief Imprime todos los elementos del array aServicios que no esten vacios
 * param1 eServicio aServicios, array del que vamos a imprimir los elementos
 * param2 int CantidadElementos, cantidad de elementos que tiene el array
 * return retorna 0 si funciono correctamente o -1 si hubo algun error.
 * */
int imprimeTodosLosServicios(eServicio *aServicios,int cantidadElementos);

#endif /* SERVICIO_H_ */
