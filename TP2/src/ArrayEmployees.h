/*
 * ArrayEmployees.h
 *
 *  Created on: 12 oct. 2021
 *      Author: MI COMPU
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include "Biblioteca.h"


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int IsEmpty;

} Employee;

//=========================================PROTOTIPOS PEDIDOS====================================================
int initEmployees(Employee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
  */

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length);

/** \brief muestra UN solo empleado , usado solo por el printEmployeeS ( plural )
 *
 * \param uno Employee el empleado pasado
 * \return void
 *
 */
void printEmployee(Employee uno);

/** \brief muestra los encabezados, las lineas para el empleado especificamente pasado
 *
 * \param uno Employee
 * \return void
 *
 */
void printONEEmployee(Employee uno);



/** \brief Muestra un menú relativo a lo que se necesita y entrega un entero seleccionado por el usuario
 *
 * \param menu[] char el cartel indicativo con los items a seleccionar
 * \param desde int rango acorde al cartel , numero inferior a validar de la entrada del usuario
 * \param hasta int rango acorde al cartel , numero superior a validar
 * \return int la eleccion del usuario validada
 *
 */
int ObtenerEleccionDeMenu(char menu[],int desde,int hasta);


/** \brief Permite el ingreso de un nuevo empleado validando que haya espacio , se grabe en un lugar
 * disponible del array y le pasa los valores a la funcion addEmployee, muestra el resultado de tal proceso
 *
 * \param lista[] Employee el listado de empleados en array
 * \param tam int la capacidad maxima del array
 * \return void
 *
 */
void CargarNuevoEmpleado(Employee lista[],int tam);

/** \brief Carga preliminar para probar otras funciones, ya recibe el array preparado y puede incluso cargarse mas valores
 *
 * \param lista[] Employee la lista preparada para cargar , si el array tiene carga, la pisa
 * \return void
 *
 */
void HarcodeoDeEmpleados(Employee lista[]);

/** \brief Permite eligiendo un ID de empleado, que se valida, elegir un campo menos el ID a modificar, una vez elegido
 * se pide el nuevo valor del campo elegido y se confirma la modificacion o cancela
 *
 * \param lista[] Employee array de empleados
 * \param tam int tope del array
 * \return void
 *
 */
void ModificarEmpleado(Employee lista[],int tam);

/** \brief  Permite eligiendo un ID de empleado, que se valida, borrar un empleado usando el metodo removeEmployee
 * pudiendo confirmar o cancelar el borrado
 *
 * \param lista[]  Employee array de empleados
 * \param tam int tope del array
 * \return void
 *
 */
void BorrarEmpleado(Employee lista[],int tam);


/** \brief Permite seleccionar el sentido de ordenamiento, primero por el apellido y dentro del mismo, por el sector
 * emplea la funcion sortEmployees y devuelve la lista ordenada
 *
 * \param lista[]  Employee array de empleados
 * \param tam int tope del array
 * \return void
 *
 */
void OrdenarPorSectorYporApellido(Employee lista[],int tam);


/** \brief Permite analizar los valores cargados hasta el momento en el array y mostrar resultados
 *
 * \param lista[]  Employee array de empleados
 * \param tam int tope del array
 * \return void
 *
 */
void TotalPromedioSalariosYcantidadSuperanPromedio(Employee lista[],int tam);


/** \brief Obtiene la cantidad de registros cargados al momento, se emplea para validar al principio sin harcodeo
 *
 * \param lista[] Employee array de empleados
 * \param tam int tope del array
 * \return int
 *
 */
int ContarEmpleados(Employee lista[],int tam);

/** \brief Donde transcurre toda la operatoria interactiva
 *
 * \param lista[] Employee array de empleados
 * \param tam int tope del array
 * \return void
 *
 */
void Menu(Employee lista[],int tam);

/** \brief devuelve el primer registro del array disponible para cargar un empleado nuevo
 *
 * \param lista[] Employee array de empleados
 * \param tam int tope del array
 * \return int el indice fisico NO EL ID , el indice del array
 *
 */
int buscarLibre(Employee lista[],int tam);


/** \brief Recorre el array contabilizando el mayor ID y le suma 1 de modo que siempre se obtiene un ID distinto
 * para mostrar y operar con los registros cargados en el array
 *
 * \param lista[] Employee array de empleados
 * \param tam int tope del array
 * \return int el siguiente del mayor ID
 *
 */
int proxIdEmpleado(Employee lista[],int tam);




#endif /* ARRAYEMPLOYEES_H_ */
