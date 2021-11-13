

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief Crea espacio en la memoria dinámica para alojar un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        employee_setId(nuevoEmpleado,0);
        employee_setNombre(nuevoEmpleado, "");
        employee_setHorasTrabajadas(nuevoEmpleado, 0);
        employee_setSueldo(nuevoEmpleado, 0);
    }
    return nuevoEmpleado;
}



/** \brief Construye un empleado valiéndose del constructor por defecto, o sea, crea espacio en la memoria dinámica
 * y carga una estructura llena en esa posición ( no se empleó por preferir los parámetros int )
 * ver employee_newParametrosInt
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* nuevoEmpleado = employee_new();
    if( nuevoEmpleado != NULL )
    {
        printf("recibi un empleado vacio");
        if(!(employee_setId(nuevoEmpleado, atoi(idStr))
                && employee_setNombre(nuevoEmpleado,nombreStr)
                && employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr)) ))
        {

        }
        else
        {
            printf("\nNO SE SUMINISTRARON TODOS LOS PARAMETROS AL CONSTRUCTOR POR PARAMETROS\n");

        }
    }
    else
    {
        printf("\nNO SE PUDO CREAR UN NUEVO EMPLEADO\n");
        employee_delete(nuevoEmpleado);
        nuevoEmpleado = NULL;
    }

    return nuevoEmpleado;
}





/** \brief Construye un empleado valiéndose del constructor por defecto, o sea, crea espacio en la memoria dinámica
 *
 * \param id int el id para usar como referencia del registro en operaciones como baja y modificación
 * \param nombreStr char* el nombre del empleado
 * \param horasTrabajadas int la cantidad de horas trabajadas
 * \param sueldo int el sueldo
 * \return Employee* un puntero a un empleado cargado exitosamente en memoria
 *
 */
Employee* employee_newParametrosInt(int id,char* nombreStr,int horasTrabajadas, int sueldo)
{
    Employee* nuevoEmpleado = employee_new();
    int ok = 1;
    if( nuevoEmpleado != NULL )
    {

        if(employee_setId(nuevoEmpleado, id) == 0)
        {
            printf("\nFALLA EN EL ID\n");
            ok = 0;
        }

        if(employee_setNombre(nuevoEmpleado,nombreStr) == 0)
        {
            printf("\nFALLA EN EL NOMBRE\n");
            ok = 0;
        }

        if(employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas) == 0)
        {
            printf("\nFALLA EN LAS HORAS TRABAJADAS\n");
            ok = 0;
        }

        if(employee_setSueldo(nuevoEmpleado, sueldo) == 0)
        {
            printf("\nFALLA EN SUELDO\n");
            ok = 0;
        }

        if(!ok)
        {
            printf("\nNO SE PUDO CARGAR UN NUEVO EMPLEADO\n");
             employee_delete(nuevoEmpleado);
        }
    }

    return nuevoEmpleado;
}



/** \brief elimina la estructura empleado en memoria
 *
 * \param emp Employee* el empleado a eliminar
 * \return void
 *
 */
void employee_delete(Employee* emp)
{
    if(emp != NULL)
    {
       free(emp);
    }

}

/** \brief adjudica un id a la estructura empleado
 *
 * \param emp Employee* empleado en memoria
 * \param id int el id a adjudicar
 * \return int resultado de la operación
 *
 */
int employee_setId(Employee* emp,int id)
{
    int ok = 0;
    if(emp != NULL && id > -1 )
    {
        emp->id = id;
        ok = 1;
    }
    return ok;
}

/** \brief extrae el id de un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param id int* el id del empleado a tratar
 * \return int resultado de la operación
 *
 */
int employee_getId(Employee* emp,int* id)
{
    int ok = 0;
    if(emp != NULL && id >= 0 )
    {
        *id =  emp->id;

        ok = 1;
    }
    return ok;
}

/** \brief adjudica un nombre a un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param nombre char* nombre a adjudicar
 * \return int resultado de la operación
 *
 */
int employee_setNombre(Employee* emp,char* nombre)
{
    int ok = 0;
    if(emp != NULL  )
    {
        strcpy(emp->nombre,nombre);
        ok = 1;
    }
    return ok;
}

/** \brief extrae el nombre de un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param nombre char* nombre obtenido
 * \return int resultado de la operación
 *
 */
int employee_getNombre(Employee* emp,char* nombre)
{
    int ok = 0;
    if(emp != NULL && strlen(nombre) > 0  )
    {
        strcpy(nombre,emp->nombre);
        ok = 1;
    }
    return ok;
}

/** \brief adjudica la cantidad de horas trabajadas a un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param horasTrabajadas int cantidad de horas a adjudicarle
 * \return int resultado de la operación
 *
 */
int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas)
{
    int ok = 0;
    if(emp != NULL && horasTrabajadas >= 0 )
    {
        emp->horasTrabajadas = horasTrabajadas;
        ok = 1;
    }
    return ok;
}


/** \brief obtiene la cantidad de horas de un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param horasTrabajadas int* cantidad de horas obtenidas del empleado
 * \return int  resultado de la operación
 *
 */
int employee_getHorasTrabajadas(Employee* emp,int* horasTrabajadas)
{
    int ok = 0;
    if(emp != NULL && horasTrabajadas >= 0 )
    {

        *horasTrabajadas = emp->horasTrabajadas;
        ok = 1;
    }
    return ok;
}

/** \brief adjudica la cantidad del sueldo a un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param sueldo int cantidad de sueldo a adjudicar
 * \return int  resultado de la operación
 *
 */
int employee_setSueldo(Employee* emp,int sueldo)
{
    int ok = 0;
    if(emp != NULL && sueldo > 0 )
    {
        emp->sueldo = sueldo;
        ok = 1;
    }
    return ok;
}


/** \brief obtiene la cantidad del sueldo de un empleado
 *
 * \param emp Employee* empleado a tratar
 * \param sueldo int* cantidad extraida de un empleado
 * \return int  resultado de la operación
 *
 */
int employee_getSueldo(Employee* emp,int* sueldo)
{
   int ok = 0;
    if(emp != NULL && sueldo > 0 )
    {
        *sueldo = emp->sueldo;

        ok = 1;
    }
    return ok;
}






