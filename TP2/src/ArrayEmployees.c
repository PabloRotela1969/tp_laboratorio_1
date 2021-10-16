/*
 * ArrayEmployees.c
 *
 *  Created on: 12 oct. 2021
 *      Author: MI COMPU
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"



//======================================================================================================================
//==========================================FUNCIONES PEDIDAS===========================================================


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int i;
    Employee vacio;
    int resultado = -1;
    vacio.id = 0;
    vacio.IsEmpty = 1;
    strcpy(vacio.name, "");
    strcpy(vacio.lastName, "");
    vacio.salary = 0.0;
    vacio.sector = 0;
    for(i=0;i<len;i++)
    {
        list[i] = vacio;
        resultado = 0;
    }
    return resultado;
}


int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int opcion;
    int indiceLibre = buscarLibre(list,len);
    Employee nuevo;
    int resultado = -1;

    nuevo.id = id;
    strcpy(nuevo.name, name);
    strcpy(nuevo.lastName, lastName);
    nuevo.salary = salary;
    nuevo.sector = sector;
    nuevo.IsEmpty = 0;
    opcion = inputIntDesdeHasta("Ingrese 1 si completa la operacion , 2 para cancelar : " , 1,2);
    if(opcion ==1)
    {
        list[indiceLibre] = nuevo;
        resultado = 0;
    }
    else
    {
        resultado = 2;
    }


    return resultado;
}


int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    int encontrado = -1;
    for(i = 0; i<len;i++)
    {
        if( list[i].id == id && list[i].IsEmpty == 0)
        {
            encontrado = i;
            break;
        }

    }
    return encontrado;
}



int removeEmployee(Employee list[], int len, int id)
{
    int i;
    int encontrado = -1;
    for(i=0;i<len;i++)
    {
        if( list[i].id == id)
        {
            list[i].IsEmpty = 1;
            encontrado = 0;
        }
    }

    return encontrado;
}



int sortEmployees(Employee list[], int len, int order)
{
    int i;
    int j;
    Employee aux;
    int resultado = -1;
    for(i=0;i<len-1;i++)
    {
        for(j=(i+1);j<len;j++)
        {
            resultado = 0;
            if(order == 1)
            {
                if(list[i].IsEmpty != 1 && list[j].IsEmpty != 1)
                {

                    if( strcmp( list[i].lastName , list[j].lastName ) > 0 )
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else
                    {
                        if( strcmp( list[i].lastName , list[j].lastName ) == 0 )
                        {
                            if(list[i].sector > list[j].sector )
                            {
                                aux = list[i];
                                list[i] = list[j];
                                list[j] = aux;
                            }
                        }

                    }


                }


            }
            else
            {
                if(list[i].IsEmpty != 1 && list[j].IsEmpty != 1)
                {

                    if(strcmp( list[i].lastName , list[j].lastName ) < 0 )
                    {
                        aux = list[j];
                        list[j] = list[i];
                        list[i] = aux;
                    }
                    else
                    {
                        if(strcmp( list[i].lastName , list[j].lastName ) == 0 )
                        {
                            if(list[i].sector < list[j].sector )
                            {
                                aux = list[j];
                                list[j] = list[i];
                                list[i] = aux;
                            }
                        }

                    }
                }
            }

        }
    }
    return resultado;
}





int printEmployees(Employee list[], int length)
{
    int i;
    int resultado = -1;
    printf("|%5s|%30s|%30s|%15s|%6s|\n","ID","NAME","LASTNAME","SALARY","SECTOR");
    printf("--------------------------------------------------------------------------------------------\n");
    for(i=0;i<length;i++)
    {
        if(list[i].IsEmpty == 0)
        {
            resultado = 0;
            printEmployee(list[i]);
        }

    }
    printf("--------------------------------------------------------------------------------------------\n");

    return resultado;
}

void printEmployee(Employee uno)
{
    printf("|%5d|%30s|%30s| % 11.2f   |%6d|\n",uno.id,uno.name,uno.lastName,uno.salary,uno.sector);
}

void printONEEmployee(Employee uno)
{
    printf("|%5s|%30s|%30s|%15s|%6s|\n","ID","NAME","LASTNAME","SALARY","SECTOR");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("|%5d|%30s|%30s| % 11.2f   |%6d|\n",uno.id,uno.name,uno.lastName,uno.salary,uno.sector);
    printf("--------------------------------------------------------------------------------------------\n");
}


//======================================================================================================================
//==========================================FUNCIONES PROPIAS===========================================================
//======================================================================================================================

int ContarEmpleados(Employee empleados[],int tam)
{
    int i;
    int cantidad = 0;
    for(i = 0;i<tam;i++)
    {
        if(empleados[i].IsEmpty == 0)
        {
            cantidad++;
        }
    }
    return cantidad;
}

void HarcodeoDeEmpleados(Employee empleados[])
{

    int ids[4] = {100,105,106,107};
    char nombres[4][51] = {"Ana","Fabiana","Nancy","Pedro"};
    char apellido[4][51] = {"Pazos","Maciel","Andrada","Picapiedras"};
    float salarios[4] = {40000.3,43000.4,51000.8,52000.1};
    int sectores[4] = {1,1,2,3};
    int vacios[4] = {0,0,0,0};

    for(int i = 0;i<4;i++)
    {
        empleados[i].id = ids[i];
        strcpy(empleados[i].name, nombres[i]);
        strcpy(empleados[i].lastName, apellido[i]);
        empleados[i].salary = salarios[i];
        empleados[i].sector = sectores[i];
        empleados[i].IsEmpty = vacios[i];
    }



}

int buscarLibre(Employee empleados[],int tam)
{
    int i;
    int indiceLibre = -1;

    for(i = 0;i<tam;i++)
    {
        if(empleados[i].IsEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}


int proxIdEmpleado(Employee empleados[],int tam)
{
    int i;
    int max = -2;
    int primerVez = 1;
    for(i=0;i<tam;i++)
    {
        if(!empleados[i].IsEmpty)
        {
            if(empleados[i].id > max || primerVez )
            {
                primerVez = 0;
                max = empleados[i].id;
            }
        }
    }
    return max + 1;
}

void CargarNuevoEmpleado(Employee empleados[],int tam)
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int indiceLibre;
    int resultado= -1;

    indiceLibre = buscarLibre(empleados,tam);
    if(indiceLibre > -1)
    {
        id = proxIdEmpleado(empleados,tam);
        inputString("Ingrese el nombre : ",nombre,51);
        inputString("Ingrese el apellido : ",apellido,51);
        salario = inputFloat("Ingrese el salario :");
        sector = inputInt("Ingrese el sector :" );
        resultado = addEmployee(empleados,tam,id,nombre,apellido,salario,sector);
    }
    switch(resultado)
    {
    case -1:
        printf("\n No se encontro espacio disponible \n");
        break;
    case 0:
        printf("\n Operacion exitosa \n");
        break;
    case 2:
        printf("\n Operacion cancelada \n");
        break;
    }
}

void ModificarEmpleado(Employee empleados[],int tam)
{
    int id;
    int resultado;
    Employee unEmpleado;
    int campo;
    char nuevoApellido[50];
    char nuevoNombre[50];
    float nuevoSalario;
    int nuevoSector;
    int opcion;

    printEmployees(empleados,tam);
    id = inputInt("Ingrese el ID del empleado a modificar : ");
    resultado = findEmployeeById(empleados,tam,id);
    if(resultado > -1)
    {
        system("cls");
        unEmpleado = empleados[resultado];
        printONEEmployee(unEmpleado);

        campo = ObtenerEleccionDeMenu("\n --ELIJA EL CAMPO A MODIFICAR --\n 1 - nombre\n 3 - apellido \n 4 - salario \n 5 - sector \n ",1,6);
        switch(campo)
        {
        case 1:

                inputString("Ingrese nuevo nombre :",nuevoNombre,50);
                 opcion = inputIntDesdeHasta("Ingrese 1 si completa la operacion , 2 para cancelar : ", 1,2);
                if(opcion ==1)
                {
                    strcpy(empleados[resultado].name, nuevoNombre);
                    resultado = 0;
                }
                else
                {
                    resultado = 2;
                }

            break;
        case 3:
                inputString("Ingrese nuevo apellido :",nuevoApellido,50);
                opcion = inputIntDesdeHasta("Ingrese 1 si completa la operacion , 2 para cancelar : ", 1,2);
                if(opcion ==1)
                {
                    strcpy(empleados[resultado].lastName, nuevoApellido);
                    resultado = 0;
                }
                else
                {
                    resultado = 2;
                }

            break;
        case 4:
                nuevoSalario = inputFloat("Ingrese nuevo salario : ");
                opcion = inputIntDesdeHasta("Ingrese 1 si completa la operacion , 2 para cancelar : ", 1,2);
                if(opcion ==1)
                {
                    empleados[resultado].salary = nuevoSalario;
                    resultado = 0;
                }
                else
                {
                    resultado = 2;
                }

            break;
        case 5:
                nuevoSector = inputInt("Ingrese nuevo sector : ");
                opcion = inputIntDesdeHasta("Ingrese 1 si completa la operacion , 2 para cancelar : ", 1,2);
                if(opcion ==1)
                {
                    empleados[resultado].sector = nuevoSector;
                    resultado = 0;
                }
                else
                {
                    resultado = 2;
                }

            break;

        }



    }
    switch(resultado)
    {
    case -1:
        printf("\n Empleado inexistente \n");
        break;
    case 0:
        printf("\n Operacion exitosa \n");
        break;
    case 2:
        printf("\n Operacion cancelada \n");
        break;
    }

}

void BorrarEmpleado(Employee empleados[],int tam)
{
    int resultado;
    int id;
    Employee unEmpleado;
    int opcion;
    printEmployees(empleados,tam);
    id = inputInt("Ingrese el ID del empleado a borrar : ");
    resultado = findEmployeeById(empleados,tam,id);
    if(resultado > -1)
    {
        system("cls");
        unEmpleado = empleados[resultado];
        printONEEmployee(unEmpleado);
        opcion = inputIntDesdeHasta("Ingrese 1 si completa la operacion , 2 para cancelar : ", 1,2);
        if(opcion ==1)
        {
            resultado = removeEmployee(empleados,tam,id);
            resultado = 0;
        }
        else
        {
            resultado = 2;
        }

    }

    switch(resultado)
        {
        case -1:
            printf("\n Empleado inexistente \n");
            break;
        case 0:
            printf("\n Operacion exitosa \n");
            break;
        case 2:
            printf("\n Operacion cancelada \n");
            break;
        }
}

void OrdenarPorSectorYporApellido(Employee empleados[],int tam)
{
    int opcion;
    opcion = ObtenerEleccionDeMenu("\n 1 - Descendente \n 2 - Ascendente \n",1,2);
    sortEmployees(empleados,tam,opcion);

}

void TotalPromedioSalariosYcantidadSuperanPromedio(Employee empleados[],int tam)
{
    int i;
    float total = 0.0;
    float promedio = 0.0;
    int cantidad = 0;
    int cantidadEmpleadosSuperanPromedio = 0;
    for(i=0;i<tam;i++)
    {
        if(empleados[i].IsEmpty == 0)
        {
            total += empleados[i].salary;
            cantidad ++;
        }
    }
    if(cantidad > 0)
    {
        promedio = total / cantidad;
        printf("\n El total de salarios es : %10.2f\n",total);
        printf(" El promedio de salarios es : %10.2f\n", promedio);
        for(i=0;i<tam;i++)
        {
            if(empleados[i].IsEmpty == 0)
            {
                if(empleados[i].salary > promedio)
                {
                    cantidadEmpleadosSuperanPromedio ++;
                }
            }
        }
        printf(" Hay %d empleados que superan ese promedio \n", cantidadEmpleadosSuperanPromedio);
    }

}




void Menu(Employee empleados[],int tam)
{
    int errores;
    int opcion;
    int salir = 0;

    errores = initEmployees(empleados,tam);
    if(errores == -1)
    {
        printf("\n Hubieron errores en la inicialización de array de empleados \n");
    }
    HarcodeoDeEmpleados(empleados);

    do
    {
       if(ContarEmpleados(empleados,tam) > 0)
       {
           opcion = ObtenerEleccionDeMenu("\n--- MENU PRINCIPAL--- \n 1 - ALTAS\n 2 - MODIFICAR\n 3 - BAJA\n 4 - ORDENAMIENTO (apellido luego sector)\n 5 - TOTAL ,PROMEDIO SALARIOS y CANTIDAD QUE SUPERA PROMEDIO\n 6 - MOSTRAR LISTA\n 7 - SALIR\n",1,7);

           switch(opcion)
            {
            case 1:
                system("cls");
                CargarNuevoEmpleado(empleados,tam);
                break;
            case 2:
                system("cls");
                ModificarEmpleado(empleados,tam);
                break;
            case 3:
                system("cls");
                BorrarEmpleado(empleados,tam);
                break;
            case 4:
                system("cls");
                OrdenarPorSectorYporApellido(empleados,tam);
                break;
            case 5:

                TotalPromedioSalariosYcantidadSuperanPromedio(empleados,tam);
                break;
            case 6:
                system("cls");
                printEmployees(empleados,tam);
                break;
            case 7:
                salir = 1;
                break;
            }

       }
       else
       {
           opcion = ObtenerEleccionDeMenu("\n 1 - ALTAS\n 2 - SALIR\n",1,2);
            switch(opcion)
            {
            case 1:
                CargarNuevoEmpleado(empleados,tam);
                break;
            case 2:
                salir = 1;
                break;
            }

       }

    }
    while(!salir);

}


int inputIntDesdeHasta(char mensaje[], int desde,int hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    int retorno;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(salida,tam,stdin);
        largo = strlen(salida) - 1;
        salida[largo]='\0';
        for(i=0;i<largo;i++)
        {
            switch(salida[i])
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case '-':
                    mal = 0;
                break;
                default:
                    mal = 1;
                break;

            }
            if(mal)
            {
                printf("\n Debe ser numerica la entrada, intente nuevamente \n");
                break;
            }
        }

        retorno = atoi(salida);
        if( retorno < desde || retorno > hasta)
        {
            mal = 1;
            printf("\n Debe estar comprendido entre %d y %d, intente nuevamente \n",desde,hasta);
        }

    }while(mal);


    return retorno;

}


