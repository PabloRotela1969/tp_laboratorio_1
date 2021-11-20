#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
// se agregaron funciones a este menú con el fin de ejercitar las funciones del LinkedList
// que sirve de soporte a la operatoria de este programa

int main()
{
    int option = 0;
    int resultado;
    int modo = 0;
    setbuf(stdout, NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();


    do
    {
        resultado = 1;
        printf("\n                        MENU  \n");
        if(ll_isEmpty(listaEmpleados))
        {
            printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
            printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
            printf(" 3. Alta de empleado\n");
            printf(" 4. Salir\n");
            option = inputIntDesdeHasta("Su opcion : ",1,4);
            switch(option)
            {
            case 1:
                resultado = controller_loadFromText("data.csv",listaEmpleados);

                break;
            case 2:
                resultado = controller_loadFromBinary("data.bin", listaEmpleados);
                break;
            case 3:
                resultado = controller_addEmployee(listaEmpleados);
                break;
            case 4:
                option = 15;
                break;
            }

            switch(resultado)
            {
            case 0:
                printf("\nOPERACION TERMINADA CON PROBLEMAS\n");
                break;
            case 1:
                printf("\nOPERACION TERMINADA CON EXITO\n");
                break;
            case 2:
                printf("\nOPERACION CANCELADA POR EL USUARIO\n");
                break;
            }

        }
        else
        {
            printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
            printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
            printf(" 3. Alta de empleado\n");
            printf(" 4. Modificar datos de empleado\n");
            printf(" 5. Baja de empleado\n");
            printf(" 6. Listar empleados\n");
            printf(" 7. Ordenar empleados\n");
            printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
            printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
            printf("10. Filtrar los empleados con sueldo mayor a 50000\n");
            printf("11. Filtrar los empleados cuyo nombre empiece con R \n");
            printf("12. Filtrar los empleados con nombres mayor a 12 caracteres de largo  \n");
            printf("13. Filtrar los empleados con nombres que contengan una letra  \n");
            printf("14. Filtrar los empleados por un ID  \n");
            printf("15. Filtrar los empleados por una HORA TRABAJADA  \n");
            printf("16. Filtrar los empleados por un SUELDO  \n");
            printf("17. Salir\n");
            option = inputIntDesdeHasta("Su opcion : ",1,17);
            switch(option)
            {
            case 1:
                resultado = controller_loadFromText("data.csv",listaEmpleados);

                break;
            case 2:
                resultado = controller_loadFromBinary("data.bin", listaEmpleados);
                break;
            case 3:
                resultado = controller_addEmployee(listaEmpleados);
                break;
            case 4:
                resultado = controller_editEmployee(listaEmpleados);
                break;
            case 5:
                modo = inputIntDesdeHasta("Borrar usando : \n 1 = ll_remove \n 2 = ll_pop y ll_push \n : ", 1,2);
                if(modo == 1)
                {
                    resultado = controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    resultado = controller_removeEmployeePop(listaEmpleados);
                }
                break;
            case 6:
                resultado = controller_ListEmployees(listaEmpleados);
                break;
            case 7:
                resultado = controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                resultado = controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                resultado = controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            case 10:
                resultado = controller_ListEmployees(ll_filter(listaEmpleados,employee_SueldoMayorDe50000));
                break;
            case 11:
                resultado = controller_ListEmployees(ll_filter(listaEmpleados,employee_nombreComienzaConR));
                break;
            case 12:
                resultado = controller_ListEmployees(ll_filter(listaEmpleados,employee_nombreMasLargoQue12Caracteres));
                break;
            case 13:
                resultado = controller_ListEmployees(ll_filter2(listaEmpleados,employee_nombreContieneLetra));
                break;
            case 14:
                resultado = controller_ListEmployees(ll_filter3(listaEmpleados,employee_nombreConId));
                break;
            case 15:
                resultado = controller_ListEmployees(ll_filter3(listaEmpleados,employee_nombreConHorasTrabajadas));
                break;
            case 16:
                resultado = controller_ListEmployees(ll_filter3(listaEmpleados,employee_nombreConSueldo));
                break;
            }
            switch(resultado)
            {
            case 0:
                printf("\nOPERACION TERMINADA CON PROBLEMAS\n");
                break;
            case 1:
                printf("\nOPERACION TERMINADA CON EXITO\n");
                break;
            case 2:
                printf("\nOPERACION CANCELADA POR EL USUARIO\n");
                break;
            }

        }

    }while(option != 17);

    ll_clear(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
