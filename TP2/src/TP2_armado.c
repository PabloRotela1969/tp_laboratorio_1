/*
 ============================================================================
 Name        : TP2_armado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define T 1000

int main(void) {
	setbuf(stdout, NULL);
    Employee listaEmpleados[T];
    Menu(listaEmpleados,T);
	return EXIT_SUCCESS;
}
