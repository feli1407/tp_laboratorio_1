/*
 * funcionescalculadora.c
 *
 *  Created on: 12 abr. 2021
 *      Author: Felipe Casco
 */

int sumar(int a, int b)
{
    return a + b;
}

int resta(int a, int b)
{
    return a - b;
}

int multiplicacion(int a, int b)
{
    return a * b;
}

int factorial(int a)
{
    int x=1;
    int factorial=1;
    for(x=a;x>1;x--)
    {
        factorial*=x;
    }
    return factorial;
}

int division(int a, int b, float* c)
{
    int todoOk=0;

    if(b != 0)
    {
        *c = (float) a / b;
        todoOk=1;
    }

    return todoOk;
}
