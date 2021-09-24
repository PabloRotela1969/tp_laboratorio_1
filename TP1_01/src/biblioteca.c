/*
 * biblioteca.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Pablo F. Rotela
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

/**
 * @brief metodo necesario al ingreso de los dos numeros, puesto que por la implementación del factorial, es necesario validar el tamaño del numero que podrá calcular
 * si se supera, se le muestra una advertencia al usuario sobre la precisión que obtendrá al calcular el factorial, las otras operaciones no tienen esta limitacion
 *
 * @param mensaje por unsarse más de una vez, se pasa el mensaje que recibirá el método que permita ingresar los números
 * @param tope es el máximo calculado por ejemplos prefijado en el método Menu() para que aparezca la advertencia al usuario
 * @return un entero que representa el valor ingresado por el usuario
 */
int ingresoValidandoPorFactorial(char mensaje[] , int tope)
{
	int numero;

	int reintenta;
	do
	{
		reintenta = 0;
	    numero = inputInt(mensaje);
	    if(numero <0)
	    {
	    	printf("\nTenga en cuenta sólo números positivos para el cálculo del factorial \n ");
	    	reintenta = inputIntDesdeHasta("Si desea modificar el valor, tipee 1 y enter, 0 para proseguir", "solo se permite 0 o 1", 0,1);

	    }
	    if(numero > tope)
	    {
	    	printf("\nTenga en cuenta que el cálculo del factorial de números superiores a %d no dará numeros confiables \n ",tope);
	    	reintenta = inputIntDesdeHasta("Si desea modificar el valor, tipee 1 y enter, 0 para proseguir", "solo se permite 0 o 1", 0,1);
	    }


	}while(reintenta);
	return numero;
}

/**
 * @brief es donde sucede la acción y como se basa en el menú de acción que puede repetirse indefinidamente hasta que el usuario pulse la opción de salida, el programa se desarrolla
 * completamente dentro de este método
 * El metodo permite pedir un número, procesar la tanda de operaciones de  +,-,*,/ y ! con ese número o completar con un segundo número a las operaciones binarias, las que de faltar un número
 * procesarán por defecto el 0 mostrando cuando se pueda el resultado, cada operación valida sus entradas y devuelve resultado por puntero, devolviendo a su vez un número que representa el resultado
 * de su ejecución que puede ser desde una advertencia hasta un error, guardando estos resultados en un array y se evalúa al ejecutar, ese mismo array permite mostrar los resultados coherentemente con
 * los errores de haberlos, Tomo como tope de número a calcular exitosamente el factorial el numero 12
 * Como se trata de una lista corta de operaciones que dependen de la devolución de cada método, uso variables para alojar los resultados, así mismo por ser mayoría de operaciones binarias empleo dos
 * variables bandera de la carga de cada número para poder tomarlas como validación
 */
void menu()
{

	// tomo este como el tope de cálculo del factorial
	int topeFactorial = 12;
	// variables que alojarán lo que el usuario ingrese para operar
	int primerNumero = 0;
	int segundoNumero = 0;
	// estas banderas permiten seguir qué rol de dato está cargado actualmente
	int cargadoPrimero = 0;
	int cargadoSegundo = 0;

	// array que recibe las devoluciones de cada método de operación
	int devolucionInt[6];

	// variables de resultado por opoeración
	int resultadoSuma;
	int resultadoResta;
	int resultadmoMultiplicacion;
	float resultadoDivision;
	long resultadoFactorial1;
	long resultadoFactorial2;
	int opcionInt;



	do
	{

		printf("\n MENU\n");
		printf("1. Ingresar 1er operando (A=x)\n");
		printf("2. Ingresar 2do operando (B=y)\n");
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		opcionInt = inputIntDesdeHasta("Ingrese su opción : ", "intente nuevamente " , 1, 5);

		switch(opcionInt)
		{
		case 1:// cargo el primer número

			primerNumero = ingresoValidandoPorFactorial("Ingrese el primer numero : ", topeFactorial);
			cargadoPrimero = 1;
			break;
		case 2:// cago el segundo número

			segundoNumero = ingresoValidandoPorFactorial("Ingrese el segundo numero : ", topeFactorial);
			cargadoSegundo = 1;
			break;
		case 3:// proceso la tanda de operaciones con los números que tenga ingresados del usuario guardando resultados en el array

			devolucionInt[0] = suma(primerNumero, segundoNumero, &resultadoSuma);
			devolucionInt[1] = resta(primerNumero, segundoNumero, &resultadoResta);
			devolucionInt[2] = multiplicacion(primerNumero, segundoNumero, &resultadmoMultiplicacion);
			devolucionInt[3] = division(primerNumero, segundoNumero, &resultadoDivision, cargadoPrimero, cargadoSegundo);
			devolucionInt[4] = factorial(primerNumero,&resultadoFactorial1);
			devolucionInt[5] = factorial(segundoNumero,&resultadoFactorial2);
			// evalúo el array por operación
			errores(devolucionInt[0], " suma ");
			errores(devolucionInt[1], " resta ");
			errores(devolucionInt[2], " multiplicacion ");
			errores(devolucionInt[3], " division ");
			errores(devolucionInt[4], " Factorial de primer numero ");
			errores(devolucionInt[5], " Factorial de segundo numero ");

			break;
		case 4:// muestro los resultados mostrables
			printf("\n El resultado de %d + %d es %d ",primerNumero, segundoNumero, resultadoSuma);
			printf("\n El resultado de %d - %d es %d ",primerNumero, segundoNumero, resultadoResta);
			printf("\n El resultado de %d * %d es %d ",primerNumero, segundoNumero, resultadmoMultiplicacion);
			if(devolucionInt[3] == 0)
			{
				printf("\n El resultado de %d / %d es %f ",primerNumero, segundoNumero, resultadoDivision);
			}

			if(devolucionInt[4] == 0)
			{
				printf("\n El factorial de %d es %lu ",primerNumero,  resultadoFactorial1);
			}

			if(devolucionInt[5] == 0)
			{
				printf("\n El factorial de %d es %lu ",segundoNumero,  resultadoFactorial2);
			}
			printf("\n");
			break;

		}
	}while(opcionInt < 5);// el 5 sale

	printf("\n ok ");
}

/**
 * @brief recibe dos enteros y apunta resultado, devuelve el código de las validaciones y errores que pudo implementar
 *
 * @param primero primer número para operar, si falta se asume 0
 * @param segundo segundo número, si falta se asume 0
 * @param resultado escribe la suma entre el primer y el segundo numero como puntero
 * @return devuelve 1 si la variable resultado no está apuntando a ninguna parte, 0 si es un puntero, la suma no precisa muchas validaciones extra
 */
int suma(int primero,int segundo, int* resultado)
{
	int devolucion = 1;
	if( resultado != NULL)
	{

		*resultado = primero + segundo;
		devolucion = 0;

	}
	return devolucion;
}

/**
 * @brief recibe dos enteros y apunta resultado, devuelve el código de las validaciones y errores que pudo implementar
 *
 * @param primero primer número para operar, si falta se asume 0
 * @param segundo segundo número, si falta se asume 0
 * @param resultado escribe la resta entre el primer y el segundo numero como puntero
 * @return devuelve 1 si la variable resultado no está apuntando a ninguna parte, 0 si es un puntero, la resta no precisa muchas validaciones extra
 */
int resta(int primero,int segundo, int* resultado)
{
	int devolucion = 1;
	if( resultado != NULL)
	{

		*resultado = primero - segundo;
		devolucion = 0;

	}
	return devolucion;
}

/**
 * @brief recibe dos enteros y apunta resultado, devuelve el código de las validaciones y errores que pudo implementar
 *
 * @param primero primer número para operar, si falta se asume 0
 * @param segundo segundo número, si falta se asume 0
 * @param resultado escribe el producto entre el primer y el segundo numero como puntero
 * @return devuelve 1 si la variable resultado no está apuntando a ninguna parte, 0 si es un puntero, el producto no precisa muchas validaciones extra
 */
int multiplicacion(int primero,int segundo, int* resultado)
{
	int devolucion = 1;
	if( resultado != NULL)
	{

		*resultado = primero * segundo;
		devolucion = 0;

	}
	return devolucion;
}


/**
 * @brief recibe dos enteros para operar, numerador y denominador, un puntero para devolver resultado y una bandera por cada numero cargado para operar, de esta forma
 * puedo validar denominador distinto de cero
 *
 * @param primero entero numerador
 * @param segundo entero denominador
 * @param resultado flotante resultado
 * @param cargado1 entero bandera de carga del numerador
 * @param cargado2 entero bandera de carga del denominador
 * @return devuelve
 * 		   0 sin errores
 *         1 si el puntero resultado vino en nulo
 *         2 si numerador y denominador vinieron con basura
 *         3 si el denominador vino con basura
 *         4 si el numerador vino con basura
 *         5 si el denominador vino especialmente en cero
 *
 */
int division(int primero,int segundo, float* resultado, int cargado1, int cargado2)
{
	int devolucion = 1;
	// si esto llega al return es porque no se apuntó bien el parametro resultado
	if( resultado != NULL)
	{
		if(cargado1 == 0 && cargado2 == 0)
		{
			devolucion = 2;
			// si llega al return, llegaron dos ceros
		}
		if(cargado1 == 1 && cargado2 == 0)
		{
			devolucion = 3;
			// si llega al return, llegó cargado el numerador
		}
		if(cargado1 == 0 && cargado2 == 1)
		{
			devolucion = 4;
			// si llega al return, llegó cargado el denominador
		}
		if(cargado1 == 1 && cargado2 == 1 )
		{
			if(segundo == 0)
			{
				devolucion = 5;
				// si llega al return, ¡¡DIVISION POR CERO!!
			}
			else
			{
				*resultado =  primero / (float) segundo;
				devolucion = 0;
			}
		}
	}

	return devolucion;
}



/**
 * @brief recibe un entero de resultado y un mensaje para mostrar
 *
 * @param resultado se valida el rango de resultados a considerar
 * @param mensaje mensaje que se mostrará al usuario con la operación con el texto resultante del error o advertencia
 */
void errores(int resultado, char mensaje[])
{
	if(resultado > -1 && resultado < 7)
	{
		switch(resultado)
		{
		case 0:
			printf("\n%s Ok ", mensaje);
			break;
		case 1:
			printf("\n Error en los parámetros resultado de %s, parámetro en null", mensaje);
			break;
		case 2:
			printf("\n Error, no llegó ningún numero en %s ", mensaje);
			break;
		case 3:
			printf("\n Error, falta numerador en %s ", mensaje);
			break;
		case 4:
			printf("\n Error en denominador de %s ", mensaje);
			break;
		case 5:
			printf("\n Error en denominador DIVISIÓN POR CERO de %s ", mensaje);
			break;
		case 6:
			printf("\n Error negativo detectado en %s ", mensaje);
			break;
		}
	}

}

/**
 * @brief recibe un entero a procesar, devuelve resultado por puntero y la función devuelve a su vez el código de lo evaluado
 *
 * @param numero entero a sacar el factorial
 * @param resultado long puntero a resultado
 * @return entero
 *             0 ejecución sin problemas
 *             1 puntero de resultado en nulo
 *             2 numero = 0
 *             6 numero negativo
 */
int factorial(int numero, long* resultado)
{
	int devolucion = 1;

	if(resultado != NULL)
	{
		*resultado = 1;
		if(numero < 0)
		{
			devolucion = 6;
		}
		else
		{
			devolucion = 2;
			if(numero > 0)
			{
				for(int i = 1; i <= numero; i++)
				{
					*resultado *= i;
				}
				devolucion = 0;
			}
		}
	}

	return devolucion;
}




/*
 * |||||||||||||||||||||||||||||||||||||||||||||||||||||||||funciones de ingreso de datos||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 */

/**
 * @brief recibe un mensaje que mostrará para indicar la causa del pedido de datos
 *  al dato pulsado por el usuario se le quita el \0 y se valida que esté entre los caracteres permitidos para un entero, de lo contrario
 *  se muestra mensaje indicativo y se vuelve a pedir un entero
 *
 * @param mensaje array de chars a mostrar para pedir el numero
 * @return entero ingresado por el usuario
 */
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





/**
 * @brief recibe un mensaje para orientar el ingreso de dato, un mensaje que mostrar ante un ingreso erróneo, un entero desde y un entero hasta para explicitar el rango de datos permitidos
 * la función muestra el mensaje, y al ingreso del usuario valida que esté entre los caracteres permitidos, de lo contrario muestra mensaje de error además de verificar
 * que dichos caracteres sean números, deben estar dentro del rango ingresado para mostrar el mensaje de error estipulado y permitir el reingreso
 *
 * @param mensaje array de caracteres indicativo para el ingreso de dato
 * @param mensajeError array de caracteres que debe mostrarse ante un numero fuera de rango
 * @param desde límite inferior del rango , se toma inclusive
 * @param hasta límite superior del rango, se toma inclusive
 * @return entero validado por tipo de caracteres y por rango de enteros
 */
int inputIntDesdeHasta(char mensaje[], char mensajeError[],int desde,int hasta)
{
    int i;
    int largo;
    int mal;
    int tam = 60;
    char salida[tam];
    int retorno;

    do
    {
        printf("%s ",mensaje);
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
            printf("\n Debe estar comprendido entre , %d y %d, %s  \n",desde,hasta,mensajeError);
        }

    }while(mal);


    return retorno;

}
