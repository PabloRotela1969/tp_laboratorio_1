/*
 * Controller.h
 *
 *  Created on: 17 nov. 2021
 *      Author: MI COMPU
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Employee.h"
#include "parser.h"
#include "Funciones.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(Employee* unEmployee);
int controller_ListEmployees(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_removeEmployeePop(LinkedList* pArrayListEmployee);


#endif /* CONTROLLER_H_ */
