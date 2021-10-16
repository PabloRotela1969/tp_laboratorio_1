/*
 * Biblioteca.c
 *
 *  Created on: 12 oct. 2021
 *      Author: MI COMPU
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"




int ObtenerEleccionDeMenu(char menu[],int desde,int hasta)
{
    int opcion;
    int mal;
    do
    {
        mal = 0;

        printf("%s",menu);
        printf("Elija numero del %d al %d", desde,hasta);
        opcion = inputInt(" : ");
        if(opcion < desde || opcion > hasta)
        {
            mal = 1;
            printf("\nPreste atención a los numeros, vuelva a intentarlo \n");
        }
    }while(mal);

    return opcion;
}

void inputString(char mensaje[], char salida[], int tam)
{
    printf("%s",mensaje);
    fflush(stdin);
    fgets(salida,tam,stdin);
    salida[strlen(salida)-1]='\0';
    fflush(stdin);
}

int inputInt(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];

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

    }while(mal);

    return atoi(salida);

}

float inputFloat(char mensaje[])
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    float resultado = -1.1;

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
                case '.':
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

    }while(mal);
    resultado = atof(salida);

    return resultado;
}
