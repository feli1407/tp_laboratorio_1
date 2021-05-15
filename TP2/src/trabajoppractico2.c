/*
 ============================================================================
 Name        : TP2.c
 Author      : Casco Felipe Div 1A
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"
#define EMPLOYEES 1000


int main()
{
	setbuf(stdout,NULL);
    int id=1;
    char salir='n';//Confirmacion para salir del programa
    char volver='n';//Confirmacion para volver al menu principal
    int flagAlta=0;//flag para validar si se dio de alta algun empleado


    Employee list[EMPLOYEES];
    if(!(initEmployees(list,EMPLOYEES)))
    {
        printf("Ocurrio un error al inicializar empleados\n");
    }

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            printf("ALTAS\n");
            if(altaEmpleado(list,EMPLOYEES,&id))
            {
                printf("Alta exitosa\n");
            }
            flagAlta = 1;
            break;
        case 2:
            if(flagAlta==1)
            {
                system("cls");
                if(!(modificarEmpleado(list,EMPLOYEES)))
                {
                    printf("Ocurrio un error al modificar al empleado\n");
                }
            }
            else
            {
               printf("Primero debe dar de alta un empleado\n");
            }
            break;
        case 3:
            if(flagAlta==1)
            {
                system("cls");
                printf("   ***BAJA***\n");
                if(!(bajaEmpleado(list,EMPLOYEES)))
                {
                    printf("Hubo un error al dar de baja al empleado\n");
                }
            }
            else
            {
               printf("Primero debe dar de alta un empleado\n");
            }
            break;
        case 4:
            if(flagAlta==1)
            {
            system("cls");
            do
            {
                system("cls");
                switch(menuInformes())
                {
                case 1:
                    if((printEmployees(list,EMPLOYEES))!=0)
                    {
                        printf("Ocurrio un error al mostrar los empleados\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(!(totalSueldoEmpleado(list,EMPLOYEES)))
                    {
                        printf("Ocurrio un error\n");
                    }
                    system("pause");
                    break;
                case 3:
                    printf("Estas seguro que deseas volver al menu principal? (s o n)\n");
                    fflush(stdin);
                    volver = getchar();
                    break;
                }

            }
            while(volver=='n');
            volver='n';
            }
            else
            {
                printf("Primero debe dar de alta un empleado\n");
            }
            break;
        case 5:
            printf("Estas seguro que deseas salir? (s o n)\n");
            fflush(stdin);
            salir = getchar();//esto seria para evitar usar un if, ahorra codigo, obtiene el char
            break;
        }

        system("pause");

    }
    while(salir == 'n');

    return 0;
}
