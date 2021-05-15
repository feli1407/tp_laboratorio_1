/*
 * arrayEmployees.c
 *
 *  Created on: 14 may. 2021
 *      Author: Casco Felipe Div 1A
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

int initEmployees(Employee list[], int len)
{
    int todoOk=0;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int menu()
{
    int opcion;
    system("cls");
    printf("     ***MENU DE EMPLEADOS***\n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n");
    fflush(stdin);
    getNumero(&opcion,"\nIngrese opcion: ","Opcion invalida!",1,5,3);
    return opcion;
}

int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 1;
    }
    return 0;
}

int getInt(int* pResultado)
{
    int retorno=0;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==1 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 1)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int getString(char cadena[], int tam, char* mensaje, char* mensajeError,  int reintentos)
{
    char bufferChar[tam];
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(myGets(bufferChar,sizeof(bufferChar))==1)
        {
            if(tieneUnicamenteLetrasDelAlfabeto(bufferChar) && strlen(bufferChar) < tam)
            {
                strcpy(cadena,bufferChar);
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int tieneUnicamenteLetrasDelAlfabeto(char cadena[])
{
    int i = 0;
    while (cadena[i])
    {
        if (!isalpha(cadena[i]) && cadena[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int altaEmpleado(Employee list[], int len, int* punteroId)
{
    int todoOk=0;
    Employee nuevoempleado;//variable auxuliar
    int errorValidacion=0;//1 si hay error y 0 si no hay


    system("cls");
    printf("      Alta empleado\n\n");
    printf("\nId del empleado: %d\n",*punteroId);

    if(list!=NULL &&len>0 && punteroId!=NULL)
    {
        if(buscarLibre(list,len)!=-1)
        {
            do
            {
                fflush(stdin);
                if(!(getString(nuevoempleado.name,51,"Ingrese nombre: ","Error, ",3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    break;
                }

                fflush(stdin);
                if(!(getString(nuevoempleado.lastName,51,"Ingrese apellido: ","Error, ",3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    break;
                }

                fflush(stdin);
                if(!(getNumeroFlotante(&nuevoempleado.salary,"Ingrese sueldo:","Error ",0,99000,3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    break;
                }

                fflush(stdin);
                if(!(getNumero(&nuevoempleado.sector,"Ingrese sector:","Error ",0,1000,3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    break;
                }

            }
            while(errorValidacion!=0);

            if(errorValidacion==0)
            {
                if((addEmployee(list,len,*punteroId,nuevoempleado.name,nuevoempleado.lastName,nuevoempleado.salary,
                nuevoempleado.sector))==0)
                {
                    (*punteroId)++;
                    todoOk=1;
                }
                else
                {
                    printf("Ocurrio un error al dar de alta al empleado\n");
                }

            }
        }
        else
        {
            printf("No hay lugar disponible para dar de alta empleados\n");
        }
    }
    return todoOk;
}

int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector)
{
    int todoOk=-1;
    int indice=-1;
    if(len>0&&name!=NULL&&lastName!=NULL)
    {
        indice=buscarLibre(list,len);
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary=salary;
        list[indice].sector=sector;
        list[indice].isEmpty=0;
        list[indice].id=id;
        todoOk=0;
    }
    return todoOk;
}

int buscarLibre(Employee list[], int tam)
{
    int lugarlibre=-1;

    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpty==1)
        {
            lugarlibre=i;
            break;
        }
    }
    return lugarlibre;
}

int getFloat(float* pResultado)
{
    int retorno=0;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==1 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float
                      maximo, int reintentos)
{
    float bufferFloat;
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 1)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int esFlotante(char* cadena)
{
    int retorno=1;
    int contadorPuntos=0;
    if(cadena != NULL && strlen(cadena) > '0')
    {
        for(int i=0; cadena[i]!='\0'; i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]<'0'|| cadena[i]>'9')
            {
                if(cadena[i]=='.'&&contadorPuntos=='0')
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno=0;
                    break;
                }
            }

        }
    }
    return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int indiceDelId=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id==id&&list[i].isEmpty==0)
        {
            indiceDelId=i;
            break;
        }
    }
    return indiceDelId;
}

int modificarEmpleado(Employee* list, int len)
{
    int idModificar;
    int indice;
    char confirmacionModificar='n';
    char salirModificarMenu='n';
    int todoOk=0;



    if(len>0)
    {
        printEmployees(list,len);

        do
        {
            getNumero(&idModificar,"\nIngrese id del empleado: ","Opcion invalida!",1,1000,3);
        }
        while(findEmployeeById(list,len,idModificar)==-1);

        indice=findEmployeeById(list,len,idModificar);

        printf("Esta seguro que desea modificar este empleado?(s o n)\n");
        fflush(stdin);
        confirmacionModificar=getchar();

        if(confirmacionModificar=='s')
        {
            do
            {
                system("cls");
                printf("    ***MODIFICAR***\n\n");
                switch(menuModificar())
                {
                case 1:
                    fflush(stdin);
                    if(!(getString(list[indice].name,51,"Ingrese el nuevo nombre: ","Error, ",3)))
                    {
                        printf(" ocurrio un error en la validacion\n");
                    }
                    else
                    {
                        printf("Nombre modificado correctamente\n");
                        system("pause");
                    }
                    break;
                case 2:
                    fflush(stdin);
                    if(!(getString(list[indice].lastName,51,"Ingrese el nuevo apellido: ","Error, ",3)))
                    {
                        printf(" ocurrio un error en la validacion\n");
                    }
                    else
                    {
                        printf("Apellido modificado correctamente\n");
                        system("pause");
                    }
                    break;
                case 3:
                    fflush(stdin);
                    if(!(getNumeroFlotante(&list[indice].salary,"Ingrese el nuevo salario:","Error ",0,99000,3)))
                    {
                        printf("Ocurrio un error en la validacion\n");
                    }
                    else
                    {
                        printf("Salario modificado correctamente\n");
                        system("pause");
                    }
                    break;
                case 4:
                    fflush(stdin);
                    if(!(getNumero(&list[indice].sector,"Ingrese el nuevo sector:","Error ",0,1000,3)))
                    {
                        printf("Ocurrio un error en la validacion\n");
                    }
                    else
                    {
                        printf("Sector modificado correctamente\n");
                        system("pause");
                    }
                    break;
                case 5:
                    printf("Estas seguro que deseas volver al menu principal? (s o n)\n");
                    fflush(stdin);
                    salirModificarMenu = getchar();
                    break;
                default:
                    printf("Error, ingrese opcion valida");
                    break;
                }
            }
            while(salirModificarMenu=='n');
            todoOk=1;
        }
    }
    return todoOk;
}

int menuModificar()
{
    int opcionM;
    printf("1. Modificar el nombre.\n");
    printf("2. Modificar el apellido.\n");
    printf("3. Modificar el salario.\n");
    printf("4. Modificar el sector.\n");
    printf("5. Volver al menu principal\n");
    fflush(stdin);
    getNumero(&opcionM,"\nIngrese opcion: ","Opcion invalida!",1,5,3);
    return opcionM;
}

int menuInformes()
{
    int opcionI;
    printf("    ***INFORMES***\n\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("3. Volver al menu principal\n");
    fflush(stdin);
    getNumero(&opcionI,"\nIngrese opcion: ","Opcion invalida!",1,5,3);
    return opcionI;
}

int removeEmployee(Employee* list, int len, int id)
{
    int todoOk=-1;
    int indice=-1;

    if(len>0&&id!=0)
    {
        indice=findEmployeeById(list,len,id);

        if(indice!=-1)
        {
            list[indice].isEmpty=1;
            todoOk=0;
        }

    }
    return todoOk;
}

int bajaEmpleado(Employee* list, int len)
{
    int todoOk=0;
    int idDeLaBaja=0;
    char confirmacionDarBaja='n';

    system("cls");
    printEmployees(list,len);

    do
    {
        getNumero(&idDeLaBaja,"\nIngrese el id del empleado que quiere dar de baja:","Error",1,1000,3);
    }
    while(findEmployeeById(list,len,idDeLaBaja)!=-1&&list[idDeLaBaja].isEmpty!=1);

    printf("Esta seguro que desea dar de baja este empleado?(s o n)\n");
    fflush(stdin);
    confirmacionDarBaja=getchar();

    if(confirmacionDarBaja=='s')
    {
        if((removeEmployee(list,len,idDeLaBaja))==0)
        {
            todoOk=1;
            printf("Baja de empleado confirmada\n");
        }
        else
        {
            printf("Ocurrio un problema\n");
        }
    }
    return todoOk;

}

int sortEmployees(Employee* list, int len, int order)
{
    int todoOk=-1;
    Employee auxEmpleado;

    if(list!=NULL && len>0 && (order==1 || order==0))
    {
        if(order==0)
        {
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].sector>list[j].sector||
                            (list[i].sector==list[j].sector&&strcmp(list[i].lastName,list[j].lastName)>0))
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }
            }
        }
        if(order==1)
        {
            for(int i=0; i<len-1; i++)
            {
                for(int j=i+1; j<len; j++)
                {
                    if(list[i].sector<list[j].sector||
                            (list[i].sector==list[j].sector&&strcmp(list[i].lastName,list[j].lastName)>1))
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                }
            }
        }

        todoOk=0;
    }
    return todoOk;
}

int mostrarEmpleado(Employee numEmpleado)
{
    int todoOk=1;

    printf("  %d   %15s   %15s         %9.2f    %d   "
           ,numEmpleado.id
           ,numEmpleado.lastName
           ,numEmpleado.name
           ,numEmpleado.salary
           ,numEmpleado.sector);
    printf("\n");

    return todoOk;
}

int printEmployees(Employee* list, int length)
{
    int todoOk=-1;
    int flag=1;

    if(length>0)
    {
        sortEmployees(list,length,0);
        system("cls");
        printf("                    ***LISTA DE EMPLEADOS***\n\n");
        printf("  id           apellido          nombre          salario    sector\n");
        printf("-------------------------------------------------------------------\n");


        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
                if(mostrarEmpleado(list[i]))
                {
                    flag=0;
                }
            }
        }
        if(flag==1)
        {
            printf("\n    No esta disponible mostrar empleados\n\n");
        }
        printf("\n\n");
        todoOk=0;
    }
    return todoOk;
}

int totalSueldoEmpleado(Employee list[], int len)
{
    int todoOk=0;
    float totalSueldo=0;
    int contadorSalarios=0;
    float promedio=0;
    int contEmpSueldoMayorProm=0;//contador de empleados con sueldo mayor al promedio

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                totalSueldo+=list[i].salary;
                contadorSalarios++;
            }

        }
        promedio=totalSueldo/contadorSalarios;
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0&&list[i].salary>promedio)
            {
                contEmpSueldoMayorProm++;
            }

        }
        system("cls");
        printf("             ***INFORMES***\n\n");
        printf("El total de todos los sueldos es: %.2f\n\n",totalSueldo);
        printf("El promedio de todos los sueldos es: %.2f\n\n",promedio);
        printf("El total de empleados que cobran un sueldo mayor al promedio es: %d\n\n",contEmpSueldoMayorProm);
        todoOk=1;
    }
    return todoOk;
}
