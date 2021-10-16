/*
 * Biblioteca.h
 *
 *  Created on: 12 oct. 2021
 *      Author: MI COMPU
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/** \brief permite ingresar un entero mostrando un mensaje indicativo
 *
 * \param mensaje[] char mensaje que orienta al usuario
 * \return float obtiene un valor decimal
 *
 */
float inputFloat(char mensaje[]);


/** \brief permite obtener un entero mostrando un mensaje indicativo
 *
 * \param mensaje[] char mensaje orientativo al usuario
 * \return int entero
 *
 */
int inputInt(char mensaje[]);

/** \brief permite el igreso de alfanumericos mostrando cartel indicativo al usuario
 *
 * \param mensaje[] char para orientar al usuario
 * \param salida[] char array de char con lo ingresado por el usuario
 * \param tam int tamaño que debe tener el array de caracteres
 * \return void
 *
 */
void inputString(char mensaje[], char salida[], int tam);

/** \brief ingresando un mensaje indicativo y dos numeros, desde y hasta, devuelve un numero entero comprendido en desde y hasta
 *
 * \param mensaje[] char mensaje de lo que se espera recibir
 * \param desde int tope mínimo
 * \param hasta int tope máximo
 * \return int número entero comprendido entre tope minimo y tope máximo
 *
 */
int inputIntDesdeHasta(char mensaje[], int desde,int hasta);


#endif /* BIBLIOTECA_H_ */
