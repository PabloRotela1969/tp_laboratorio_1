#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


/** \brief función estática que permite obtener un número correlativo a partir de uno inicial, cada vez que se la llame
 *         se usa sólo acá, por eso no tiene prototipo
 * \return int el número nuevo a usar en el alta
 *
 */
static int siguienteId()
{
    //static int id = 5000;
	int id;

    FILE* pArchivo;
    if((pArchivo = fopen("ultimo.txt","rt")) == NULL)
    {
        printf("\nARCHIVO NO ENCONTRADO\n");
    }
    else
    {
        fscanf(pArchivo,"%d",&id);
        ++id;
        fclose(pArchivo);
       if((pArchivo = fopen("ultimo.txt","wt")) != NULL)
	   {
    	   fprintf(pArchivo,"%d",id);
       }

    }

    fclose(pArchivo);
    return id;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* el path completo al archivo origen de los datos, ruta , nombre y extensión si la tuviera
 * \param pArrayListEmployee LinkedList* la lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ok;
    FILE* pArchivo;
    if((pArchivo = fopen(path,"r")) == NULL)
    {
        printf("\nARCHIVO NO ENCONTRADO\n");
    }
    else
    {
        printf("\nCARGANDO DATOS A MEMORIA..\n");
        ok = parser_EmployeeFromText(pArchivo, pArrayListEmployee);
    }
    printf("\nTODO CARGADO.\n");
    fclose(pArchivo);

    return ok;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* el path completo al archivo origen de los datos, ruta , nombre y extensión si la tuviera
 * \param pArrayListEmployee LinkedList* la lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok;
    FILE* pArchivo;
    if((pArchivo = fopen(path,"rb")) == NULL)
    {
        printf("\nARCHIVO NO ENCONTRADO\n");
    }
    else
    {
        printf("\nCARGANDO DATOS A MEMORIA..\n");
        ok = parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
    }
    printf("\nTODO CARGADO.\n");
    fclose(pArchivo);

    return ok;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 1;


       printf(" AGREGAR EMPLEADO \n");


       int idNuevo  = 0;
       char nombreNuevo[128];
       int horasNuevo = 0;
       int sueldoNuevo = 0;
       Employee* nuevoEmpleado = NULL;


       idNuevo  = siguienteId();
       inputString("Ingrese el nombre : ", nombreNuevo, 128);
       horasNuevo = inputInt("Ingrese las horas trabajadas : ");
       sueldoNuevo = inputInt("Ingrese el sueldo : ");


       if( inputInt(" Pulse 1 para confirmar, cualquier otra para cancelar el ingreso : ") == 1)
       {
           nuevoEmpleado = employee_newParametrosInt(idNuevo, nombreNuevo,horasNuevo, sueldoNuevo);
           ll_add(pArrayListEmployee, (Employee*) nuevoEmpleado);
       }
       else
       {
           ok = 2;

       }

    return ok;
}




/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 1;
    int idDeEmpleadoABorrar = 0;
    int indiceDelArray = -1;
    int confirmacion = 0;
    int campoAModificar = 0;
    Employee* auxEmpleado = NULL;

    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int idEmpleado;

    if(!ll_isEmpty(pArrayListEmployee))
    {
        printf("\n SELECCIONE EL EMPLEADO A MODIFICAR POR SU ID \n");
        controller_ListEmployees(pArrayListEmployee);
        idDeEmpleadoABorrar = inputInt("\n Ingrese el ID : ");
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado, &idEmpleado);
            if( idEmpleado == idDeEmpleadoABorrar)
            {
                indiceDelArray = i;
                break;
            }

        }


        if( indiceDelArray ==  -1)
        {
            printf("\nNO SE ENCONTRÓ EL ITEM SELECCIONADO CON EL ID %d \n",idDeEmpleadoABorrar);

            ok = 2;
        }
        else
        {
            printf(" %3s %30s %3s %3s \n", "ID", "NOMBRE","HORAS", "SUELDO");
            controller_ListEmployee(auxEmpleado);
            printf("\nSELECCIONE EL CAMPO POR NUMERO\n");
            printf(" 1 - nombre \n");
            printf(" 2 - horas trabajadas \n");
            printf(" 3 - sueldo \n");
            campoAModificar = inputIntDesdeHasta(" Ingrese valor del 1 al 3 : ",1,3);
            switch(campoAModificar)
            {
            case 1:
                inputString(" Ingrese el nuevo nombre : ", auxNombre,128);
                confirmacion = inputIntDesdeHasta(" Ingrese 1 para confirmar el cambio, 2 para cancelar : ",1,2);
                if(confirmacion == 1)
                {

                    employee_setNombre(auxEmpleado, auxNombre);
                    ok = 1;
                }
                else
                {
                    ok = 2;
                }

                break;
            case 2:
                auxHorasTrabajadas = inputInt(" Ingrese la nueva cantidad de horas trabajadas : ");
                confirmacion = inputIntDesdeHasta(" Ingrese 1 para confirmar el cambio, 2 para cancelar : ",1,2);
                if(confirmacion == 1)
                {

                    employee_setHorasTrabajadas(auxEmpleado, auxHorasTrabajadas);
                    ok = 1;
                }
                else
                {
                    ok = 2;
                }
                break;

            case 3:
                auxSueldo = inputInt(" Ingrese la nueva cantidad del sueldo : ");
                confirmacion = inputIntDesdeHasta(" Ingrese 1 para confirmar el cambio, 2 para cancelar : ",1,2);
                if(confirmacion == 1)
                {

                    employee_setSueldo(auxEmpleado, auxSueldo);
                    ok = 1;
                }
                else
                {
                    ok = 2;
                }
                break;
            }
            auxEmpleado = NULL;

        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA PROCESAR\n");
        ok = 0;
    }

    return ok;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 1;
    int idDeEmpleadoABorrar = 0;
    int indiceDelArray = -1;
    int confirmacion = 0;
    Employee* auxEmpleado = NULL;
    int idEmpleado;
    if(!ll_isEmpty(pArrayListEmployee))
    {
        printf("\n SELECCIONE EL EMPLEADO A BORRAR POR SU ID \n");
        controller_ListEmployees(pArrayListEmployee);
        idDeEmpleadoABorrar = inputInt("\n Ingrese el ID : ");
        for(int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado, &idEmpleado);
            if(idEmpleado == idDeEmpleadoABorrar)
            {
                indiceDelArray = i;
                break;
            }

        }


        if( indiceDelArray ==  -1)
        {
            printf("\nNO SE ENCONTRÓ EL ITEM SELECCIONADO CON EL ID %d \n",idDeEmpleadoABorrar);

            ok = 2;
        }
        else
        {
            printf(" %3s %30s %3s %3s \n", "ID", "NOMBRE","HORAS", "SUELDO");
            controller_ListEmployee(auxEmpleado);
            confirmacion = inputIntDesdeHasta(" Ingrese 1 para confirmar el borrado, 2 para cancelar : ",1,2);
            if(confirmacion == 1)
            {

                ll_remove(pArrayListEmployee, indiceDelArray);
                ok = 1;
            }
            else
            {
                ok = 2;
            }
            auxEmpleado = NULL;

        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA PROCESAR\n");
        ok = 0;
    }

    return ok;
}

/** \brief Listar UN SOLO empleado
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_ListEmployee(Employee* unEmployee)
{
    printf(" %3d %30s %10d %10d \n", unEmployee->id,unEmployee->nombre,unEmployee->horasTrabajadas,unEmployee->sueldo);
    return 1;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
    int tamPagina = 15;
    int renglon = tamPagina;
    int paginado = 0;
    int opcionCorte = 0;
    int ok = 1;
    if(!ll_isEmpty(pArrayListEmployee))
    {
        paginado = inputIntDesdeHasta("( Pulse 1 para paginar, 2  muestra todo de corrido ) :",1,2);
        printf(" %3s %30s   %8s   %8s \n", "ID", "NOMBRE","HORAS", "SUELDO");
        Employee* unEmployee = NULL;
        int tam = ll_len(pArrayListEmployee);
        for(int i = 0; i< tam; i++)
        {
            renglon --;
            if( renglon == 0 && paginado == 1  )
            {
                opcionCorte = inputIntDesdeHasta("Pulse :\n 1 - para continuar listando \n 2 - para cortar el listado justo ahora \n 3 - para listar todo lo que sigue : ",1,3);
                if(opcionCorte == 2)
                {
                    break;
                }
                if(opcionCorte == 3)
                {
                    paginado = 0;
                }
                printf(" %3s %30s   %8s   %8s \n", "ID", "NOMBRE","HORAS", "SUELDO");
                renglon = tamPagina;
            }


            unEmployee = (Employee*) ll_get(pArrayListEmployee,i);
            controller_ListEmployee(unEmployee);

        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA PROCESAR\n");
        ok = 0;
    }
    return ok;
}



/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 1;
    int campoAmodificar = 0;
    int sentido = 0;
    if(!ll_isEmpty(pArrayListEmployee))
    {
        printf("\nSELECCIONE EL CAMPO POR NUMERO\n");
        printf(" 1 - id \n");
        printf(" 2 - nombre \n");
        printf(" 3 - horas trabajadas \n");
        printf(" 4 - sueldo \n");
        campoAmodificar = inputIntDesdeHasta(" Ingrese valor del 1 al 4 : ",1,4);

        printf("\nSELECCIONE EL SENTIDO\n");
        printf(" 1 - ascendente \n");
        printf(" 2 - descendente \n");

        sentido = inputIntDesdeHasta(" Ingrese valor del 1 al 2 : ",1,2);


        for(int i = 0; i < ll_len(pArrayListEmployee) - 1; i++)
        {
            for(int j = i + 1; j < ll_len(pArrayListEmployee); j++)
            {
                switch(campoAmodificar)
                {
                case 1:
                    if(sentido == 1 )
                    {
                        if( ((Employee*)ll_get(pArrayListEmployee,i))->id > ((Employee*)ll_get(pArrayListEmployee,j))->id )
                        {
                            swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }

                    }
                    else
                    {
                        if( ((Employee*)ll_get(pArrayListEmployee,i))->id < ((Employee*)ll_get(pArrayListEmployee,j))->id )
                        {
                            swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }
                    }

                    break;
                case 2:
                    if(sentido == 1)
                    {
                         if( strcmp( ((Employee*)ll_get(pArrayListEmployee,i))->nombre, ((Employee*)ll_get(pArrayListEmployee,j))->nombre) > 0)
                        {
                             swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }
                    }
                    else
                    {
                        if( strcmp( ((Employee*)ll_get(pArrayListEmployee,i))->nombre, ((Employee*)ll_get(pArrayListEmployee,j))->nombre) < 0)
                        {
                            swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }
                    }


                    break;
                case 3:
                    if(sentido == 1)
                    {
                         if( ((Employee*)ll_get(pArrayListEmployee,i))->horasTrabajadas > ((Employee*)ll_get(pArrayListEmployee,j))->horasTrabajadas )
                        {
                             swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }

                    }
                    else
                    {
                         if( ((Employee*)ll_get(pArrayListEmployee,i))->horasTrabajadas < ((Employee*)ll_get(pArrayListEmployee,j))->horasTrabajadas)
                        {
                             swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }

                    }

                    break;
                case 4:
                    if(sentido == 1)
                    {
                         if( ((Employee*)ll_get(pArrayListEmployee,i))->sueldo >((Employee*)ll_get(pArrayListEmployee,j))->sueldo)
                        {

                            swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }
                    }
                    else
                    {
                         if( ((Employee*)ll_get(pArrayListEmployee,i))->sueldo < ((Employee*)ll_get(pArrayListEmployee,j))->sueldo)
                        {
                        	 swap(((Employee*)ll_get(pArrayListEmployee,i)), ((Employee*)ll_get(pArrayListEmployee,j)));
                        }
                    }
                    break;
                }

            }
        }
    }
    else
    {
        printf("\nNO HAY DATOS PARA PROCESAR\n");
        ok = 0;
    }
    return ok;
}


/**
 * @brief Funci�n que recibe dos empleados y los invierte, usada para el ordenamiento
 *
 * @param uno
 * @param dos
 */
void swap(Employee* uno, Employee* dos)
{
	Employee aux;
	aux = *uno;
	*uno = *dos;
	*dos = aux;
}




/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* el path completo al archivo origen de los datos, ruta , nombre y extensión si la tuviera
 * \param pArrayListEmployee LinkedList* la lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 1;
    FILE* pArchivo;
    Employee* auxEmpleado = NULL;

		if((pArchivo = fopen(path,"wt")) == NULL)
		{
			printf("\nARCHIVO NO ENCONTRADO\n");
			ok = 0;
		}
		else
		{


				printf("\nSALVANDO DATOS A ARCHIVO DE TEXTO..\n");
				fprintf(pArchivo, "%s,%s,%s,%s\n", "id","nombre","horasTrabajadas","sueldo");
				for(int i = 0;i < ll_len(pArrayListEmployee); i++)
				{
					auxEmpleado = ll_get(pArrayListEmployee,i);
					fprintf(pArchivo, "%d,%s,%d,%d\n", auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
				}
				printf("\nFIN DE PROCESO.\n");


				fclose(pArchivo);
		}


    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* el path completo al archivo origen de los datos, ruta , nombre y extensión si la tuviera
 * \param pArrayListEmployee LinkedList* la lista completa de empleados
 * \return int resultado de la operación
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 1;
    FILE* pArchivo;
    Employee* auxEmpleado = NULL;

		if((pArchivo = fopen(path,"wb")) == NULL)
		{
			printf("\nARCHIVO NO ENCONTRADO\n");
			ok = 0;
		}
		else
		{
				remove(path);
				printf("\nSALVANDO DATOS A ARCHIVO BINARIO..\n");
				for(int i = 0;i < ll_len(pArrayListEmployee); i++)
				{
					auxEmpleado = ll_get(pArrayListEmployee,i);
					fwrite(auxEmpleado,sizeof(Employee),1,pArchivo);
				}
				printf("\nFIN DE PROCESO.\n");

				fclose(pArchivo);
		}

    return ok;
}





