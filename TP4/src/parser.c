/*
 * parser.c
 *
 *  Created on: 17 nov. 2021
 *      Author: MI COMPU
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo abierto listo para ser leído en modo texto
 * \param pArrayListEmployee LinkedList* lista de empleados a cargar
 * \return int resultado de la operación
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 1;
    int itemsLeidos;
    int intId, intHorasTrabajadas,intSueldo;
    char charNombre[128];
    int total = 0;
    itemsLeidos = fscanf(pFile,"%s,%s,%s,%s\n",charNombre,charNombre, charNombre, charNombre);
        do
        {
            itemsLeidos = fscanf(pFile,"%d,%[^,],%d,%d\n",&intId,charNombre, &intHorasTrabajadas, &intSueldo);
            if(itemsLeidos == 4)
            {
                ll_add(pArrayListEmployee, employee_newParametrosInt(intId,charNombre,intHorasTrabajadas,intSueldo));
                total ++;
            }
            else
            {
                ok = 0;

                break;
            }
        }
        while(!feof(pFile));

    return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo abierto listo para ser leído en modo binario
 * \param pArrayListEmployee LinkedList* lista de empleados a cargar
 * \return int resultado de la operación
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 1;
    Employee auxEmp;
    int idInt, horasTrabajadasInt,sueldoInt;
    char nombreChar[128];

    do
    {

        fread(&auxEmp,sizeof(Employee),1,pFile);
        idInt = ((int) auxEmp.id);
        horasTrabajadasInt = ((int) auxEmp.horasTrabajadas);
        sueldoInt = ((int) auxEmp.sueldo);
        strcpy(nombreChar,auxEmp.nombre);
        ll_add(pArrayListEmployee, employee_newParametrosInt(idInt,nombreChar,horasTrabajadasInt,sueldoInt));

    }
    while(!feof(pFile));

    return ok;
}
