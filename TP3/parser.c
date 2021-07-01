#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    Employee* auxEmpleado;
    char auxId[20];
    char auxNombre[20];
    char auxHoras[20];
    char auxSueldo[20];
    int validar;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {

        fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxHoras,auxSueldo);

        do
        {
            validar=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",auxId,auxNombre,auxHoras,auxSueldo);
            auxEmpleado=employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
            if(auxEmpleado!=NULL && validar==4)
            {
                ll_add(pArrayListEmployee,auxEmpleado);
            }

        }
        while(!feof(pFile));

        printf("La carga de datos se realizo de manera exitosa!\n");
        todoOk=1;
    }
    else
    {
        printf("Error, el archivo no existe\n\n");
    }

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* auxEmpleado;
    int status;
    int todoOk = 0;
    while(!feof(pFile))
    {
        auxEmpleado = employee_new();
        status = fread(auxEmpleado, sizeof(Employee), 1, pFile);
        if(status == 1 && auxEmpleado != NULL)
        {
            ll_add(pArrayListEmployee, auxEmpleado);
        }
        else if(status != 1)
        {
            if(!feof(pFile))
            {
                printf("\tError al leer el ultimo dato.");
                break;
            }
            else
            {
                printf("Carga exitosa.\n");
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
