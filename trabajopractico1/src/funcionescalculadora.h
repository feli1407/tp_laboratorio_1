/*
 * funcionescalculadora.h
 *
 *  Created on: 11 abr. 2021
 *      Author: Felipe Casco
 */

#ifndef FUNCIONESCALCULADORA_H_
#define FUNCIONESCALCULADORA_H_

/** \brief funcion para sumar
 *
 * \param a int numero ingresado en A
 * \param b int numero ingresado en B
 * \return int suma de dato A y B
 *
 */
int sumar(int a, int b);

/** \brief funcion para restar
 *
 * \param a int  numero ingresado en A
 * \param b int  numero ingresado en B
 * \return int   la resta de A y B
 *
 */
int resta(int a, int b);

/** \brief funcion para multiplicar
 *
 * \param a int  numero ingresado en A
 * \param b int  numero ingresado en B
 * \return int  multiplicacion entre A y B
 *
 */
int multiplicacion(int a, int b);

/** \brief funcion para sacar factorial de un numero
 *
 * \param a int numero que se va a sacar el factorial
 * \return int  factorial de a
 *
 */
int factorial(int a);

/** \brief realiza la division entre dos enteros
 *
 * \param a int  ividendo de la operacion
 * \param b int  divisor de la operacion
 * \param c float* puntero
 * \return int  devuelve 1 si pudo hacer la division, o 0 si no pudo
 *
 */
int division(int a, int b, float* c);

#endif /* FUNCIONESCALCULADORA_H_ */
