/*
 * Employee.c
 *
 *  Created on: 17 nov. 2021
 *      Author: MI COMPU
 */




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
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
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
        printf("recibi un empleado vacío");
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

        if(!employee_setId(nuevoEmpleado, id))
        {
            printf("\nFALLA EN EL ID\n");
            ok = 0;
        }

        if(!employee_setNombre(nuevoEmpleado,nombreStr))
        {
            printf("\nFALLA EN EL NOMBRE\n");
            ok = 0;
        }

        if(!employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas))
        {
            printf("\nFALLA EN LAS HORAS TRABAJADAS\n");
            ok = 0;
        }

        if(!employee_setSueldo(nuevoEmpleado, sueldo))
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
    if(emp != NULL && strlen(nombre) > 0 )
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






/** \brief funcion para ser usada por puntero desde ll_sort
 *
 * \param idd1 void* primer id
 * \param idd2 void* segundo id
 * \return int 0 si son iguales, 1 si el primero es mayor que el segundo, sino -1
 *
 */
int employee_sortId(void* idd1 , void* idd2)
{
    Employee* d1 = idd1;
    Employee* d2 = idd2;
    int id1 = d1->id;
    int id2 = d2->id;

    int retorno = 0;
    if(id1 > id2)
    {
        retorno = 1;
    }
    else
    {
        if(id1 < id2)
        {
            retorno =-1;
        }
    }
    return retorno;
}

/** \brief funcion para ser usada por puntero desde ll_sort
 *
 * \param nombre1 void* primer nombre
 * \param nombre2 void* segundo nombre
 * \return int 0 si son iguales, 1 si el primero es mayor que el segundo, sino -1
 *
 */
int employee_sortNombre(void* nombre1, void* nombre2)
{
    Employee* e1 = nombre1;
    Employee* e2 = nombre2;

    return strcmp(e1->nombre,e2->nombre);
}

/** \brief  funcion para ser usada por puntero desde ll_sort
 *
 * \param hora1 void* primer cantidad de horas trabajadas
 * \param hora2 void* segunda cantidad de horas trabajadas
 * \return int  0 si son iguales, 1 si el primero es mayor que el segundo, sino -1
 *
 */
int employee_sortHorasTrabajadas(void* hora1 , void* hora2)
{
    Employee* d1 = hora1;
    Employee* d2 = hora2;
    int h1 = d1->horasTrabajadas;
    int h2 = d2->horasTrabajadas;
    int retorno = 0;
    if(h1 > h2)
    {
        retorno = 1;
    }
    else
    {
        if(h1 < h2)
        {
            retorno = -1;
        }
    }
    return retorno;
}

/** \brief  funcion para ser usada por puntero desde ll_sort
 *
 * \param sueldo1 void* primer sueldo
 * \param sueldo2 void* segundo sueldo
 * \return int  0 si son iguales, 1 si el primero es mayor que el segundo, sino -1
 *
 */
int employee_sortSueldo(void* sueldo1 , void* sueldo2)
{
    Employee* s1 = sueldo1;
    Employee* s2 = sueldo2;
    int su1 = s1->sueldo;
    int su2 = s2->sueldo;
    int retorno = 0;
    if(su1 > su2)
    {
        retorno = 1;
    }
    else
    {
        if(su1 < su2)
        {
            retorno = -1;
        }
    }
    return retorno;
}





/** \brief  Revisa en el puntero a void que castea a empleado, si el sueldo supera al numero 50000
 *
 * \param empleado void*
 * \return int 1 si cumple con el criterio, 0 si no lo hace
 *
 */
int employee_SueldoMayorDe50000(void* empleado)
{
    int respuesta = 0;
    if(empleado != NULL)
    {
        Employee* e = (Employee*) empleado;
        if(e->sueldo >= 50000)
        {
            respuesta = 1;
        }
    }

    return respuesta;

}

/** \brief Revisa en el puntero a void que castea a empleado, si el nombre del mismo comienza con la letra R
 *
 * \param empleado void*
 * \return int devuelve un 0 si no cumple y un 1 si cumple
 *
 */
int employee_nombreComienzaConR(void* empleado)
{
    int respuesta = 0;
    int largoNombre = 0;

    if(empleado != NULL)
    {
        Employee* e = (Employee*) empleado;
        largoNombre = strlen(e->nombre);
        for(int i = 0;i<largoNombre;i++)
        {
            char letra =  e->nombre[i];
            if((letra == 'R') )
            {
                respuesta = 1;
                break;
            }
        }

    }

    return respuesta;
}





/** \brief Recibe un puntero a void, lo castea a empleado y revisa en la longitud del nombre si supera a 12 caracteres
 *
 * \param empleado void*
 * \return int 1 si cumple con el criterio, 0 si no lo hace
 *
 */
int employee_nombreMasLargoQue12Caracteres(void* empleado)
{
    int respuesta = 0;
    int largoNombre = 0;

    if(empleado != NULL)
    {
        Employee* e = (Employee*) empleado;
        largoNombre = strlen(e->nombre);
        if(largoNombre > 12)
        {
            respuesta = 1;
        }

    }

    return respuesta;
}





/** \brief Función de criterio para ll_filter2, toma un puntero a void que es un Empleado y busca en su nombre si tiene algún caracter
 *  que fuera pasado como segundo parametro
 * \param empleado void*
 * \param caracter char
 * \return int 0 si no está contenido el caracter en el nombre del empleado pasado, por el contrario 1
 *
 */
int employee_nombreContieneLetra(void* empleado, char caracter)
{
    int respuesta = 0;
    int largoNombre = 0;

    if(empleado != NULL )
    {
        Employee* e = (Employee*) empleado;
        largoNombre = strlen(e->nombre);
        for(int i = 0;i<largoNombre;i++)
        {
            char letra =  e->nombre[i];
            if((letra == caracter) )
            {
                respuesta = 1;
                break;
            }
        }

    }

    return respuesta;
}




int employee_nombreConId(void* empleado, int numero)
{
    int respuesta = 0;

    if(empleado != NULL && numero > 0)
    {
        Employee* e = (Employee*) empleado;

        if(e->id == numero)
        {
            respuesta = 1;
        }

    }

    return respuesta;
}


int employee_nombreConHorasTrabajadas(void* empleado, int numero)
{
    int respuesta = 0;

    if(empleado != NULL && numero > 0)
    {
        Employee* e = (Employee*) empleado;

        if(e->horasTrabajadas == numero)
        {
            respuesta = 1;
        }

    }

    return respuesta;
}




int employee_nombreConSueldo(void* empleado, int numero)
{
    int respuesta = 0;

    if(empleado != NULL && numero > 0)
    {
        Employee* e = (Employee*) empleado;

        if(e->sueldo == numero)
        {
            respuesta = 1;
        }

    }

    return respuesta;
}

