/*
 ============================================================================
 Name        : TP1.c
 Author      : Felipe Casco Div 1A
 Version     :
 Copyright   :
 Description : Calculadora tp1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionescalculadora.h"


int main(void) {
        setbuf(stdout,NULL);
            int opcion=0;
            int x=0;
            int y=0;
            char salir='n';
            int resultadosuma=0;
            int resultadoresta=0;
            float resultadodivision=0;
            int okDivision;
            int resultadomultiplicacion=0;
            int facta=0;
            int factb=0;
            int flagnumeroa=0;
            int flagnumerob=0;
            int flagresultados=0;
            int flagfactorialx=0;
            int flagfactorialy=0;



            do
            {

                system("cls");
                printf("1. Ingresar 1er operando (A=%d)\n",x);
                printf("2. Ingresar 2do operando (B=%d)\n",y);
                printf("3. Calcular todas las operaciones\n");
                printf("  a) Calcular la suma (A+B)\n");
                printf("  b) Calcular la resta (A-B)\n");
                printf("  c) Calcular la division (A/B)\n");
                printf("  d) Calcular la multiplicacion (A*B)\n");
                printf("  e) Calcular el factorial (A!)(B!)\n");
                printf("4. Informar resultados\n");
                printf("5. Salir\n");
                printf("\n Ingrese opcion: ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese 1er operando: ");
                    scanf("%d",&x);
                    flagnumeroa=1;
                    break;
                case 2:
                    printf("\nIngrese 2do operando: ");
                    scanf("%d",&y);
                    flagnumerob=1;
                    break;
                case 3:
                    if(flagnumeroa==1 && flagnumerob==1)
                    {
                        resultadosuma=sumar(x,y);
                        resultadoresta=resta(x,y);

                        okDivision = division(x, y, &resultadodivision);

                        resultadomultiplicacion=multiplicacion(x,y);
                        if(x>=0)
                        {
                            facta=factorial(x);
                            flagfactorialx=1;
                        }
                        if(y>=0)
                        {
                            factb=factorial(y);
                            flagfactorialy=1;
                        }
                        flagresultados=1;
                    }
                    else
                    {
                        printf("Primero debe ingresar los numeros A y B\n");
                        system("pause");
                    }
                    break;
                case 4:
                    if(flagresultados==1)
                    {


                        printf("  a) El resultado de A+B es: %d\n",resultadosuma);
                        printf("  b) El resultado de A-B es: %d\n",resultadoresta);
                        if(okDivision)
                        {
                            printf("  c) El resultado de A/B es: %.2f\n",resultadodivision);
                        }
                        else
                        {
                            printf("   c) No es posible dividir por cero\n");
                        }
                        printf("  d) El resultado de A*B es: %d\n",resultadomultiplicacion);
                        if(flagfactorialx == 1 && flagfactorialy == 1)
                        {
                            printf("  e) El factorial de A es: %d y El factorial de B es: %d\n",facta,factb);
                        }
                        else if(flagfactorialx == 1 && flagfactorialy == 0)
                        {
                            printf("  e) El factorial de A es: %d y El factorial de B no existe\n",facta);
                        }
                        else if(flagfactorialx == 0 && flagfactorialy == 1)
                        {
                            printf("  e) El factorial de A no existe y El factorial de B es: %d\n",factb);
                        }
                        else
                        {
                            printf("  e) El factorial de A y El factorial de B no existen\n");
                        }



                        x=0;
                        y=0;
                        flagnumeroa=0;
                        flagnumerob=0;
                        flagresultados=0;
                        flagfactorialx=0;
                        flagfactorialy=0;
                        system("pause");
                    }
                    else
                    {
                        printf("Primero debe realizar las operaciones con la opcion 3\n");
                        system("pause");

                    }
                    break;
                case 5:
                    printf("Estas seguro que deseas salir? (s o n)\n");
                    fflush(stdin);
                    salir = getchar();
                    break;
                default:
                    printf("Error, ingrese una opcion valida\n");
                    system("pause");
                    break;
                }




            }
            while(salir=='n');

	return EXIT_SUCCESS;
}
