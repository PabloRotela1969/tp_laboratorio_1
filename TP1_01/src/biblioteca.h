/*
 * biblioteca.h
 *
 *  Created on: 24 sep. 2021
 *      Author: Pablo F. Rotela
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int inputInt(char mensaje[]);
int inputIntDesdeHasta(char mensaje[], char mensajeError[],int desde,int hasta);
void menu();
int suma(int primero,int segundo, int* resultado);
int resta(int primero,int segundo, int* resultado);
int multiplicacion(int primero,int segundo, int* resultado);
int division(int primero,int segundo, float* resultado, int cargado1, int cargado2);
int factorial(int numero, long* resultado);
void errores(int resultado, char mensaje[]);
int ingresoValidandoPorFactorial(char mensaje[] , int tope);

#endif /* BIBLIOTECA_H_ */
