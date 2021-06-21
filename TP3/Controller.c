#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funciones.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f;//inicializar en NULL
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if((f = fopen(path, "r")) != NULL)
        {
            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                printf("\nSe cargaron los empleados con exito!\n");
            }
        }
        else
        {
            if((f = fopen(path, "w")) != NULL)
            {
                printf("\nEl archivo %s no se pudo encontrar. Se creo uno nuevo con este nombre\n", path);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f;//inicializar en NULL
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if((f = fopen(path, "rb")) != NULL)
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
            printf("\nSe cargaron los empleados con exito!\n");
        }
        else
        {
            if((f = fopen(path, "wb")) != NULL)
            {
                printf("\nEl archivo %s no se pudo encontrar. Se creo uno nuevo con este nombre\n", path);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* nuevoEmpleado;
    char buffer[4][20];//1-id 2-nombre 3-horas 4-sueldo
    int auxId;

    if(pArrayListEmployee!=NULL)
    {
        auxId=ll_len(pArrayListEmployee)+1;
        itoa(auxId,buffer[1],20);
        getString(buffer[2],20,"Ingrese nombre: ","Error, ",5);
        getNumerosEnChar(buffer[3],20,"Ingrese horas trabajadas: ","Error, ",5);
        getNumerosEnChar(buffer[4],20,"Ingrese sueldo: ","Error, ",5);
        nuevoEmpleado=employee_newParametros(buffer[1],buffer[2],buffer[3],buffer[4]);
        ll_add(pArrayListEmployee,nuevoEmpleado);
        printf("Empleado cargado con exito!\n");
        todoOk=1;
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int todoOk=0;
    int horas;
    int sueldo;
    int len;
    int retornoId;
    char nombre[20];
    int auxId;

    if (pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        getNumero(&auxId,"Ingrese ID: ","Error, ",1,5000,5);

        for(int i=0; i<len; i++)
        {
            auxEmpleado=ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado,&retornoId);

            if (auxId==retornoId)
            {
                getString(nombre,20,"Ingrese nombre: ","Error, ",5);
                strcpy(auxEmpleado->nombre,nombre);

                getNumero(&horas,"Ingrese horas trabajadas: ","Error, ",1,500,5);
                auxEmpleado->horasTrabajadas=horas;

                getNumero(&sueldo,"Ingrese sueldo: ","Error, ",1,200000,5);
                auxEmpleado->sueldo=sueldo;

                printf("Empleado modificado con exito!\n");
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    int todoOk=0;
    int auxId;
    int len;
    int retornoId;
    char respuesta;

    len=ll_len(pArrayListEmployee);
    getNumero(&auxId,"Ingrese ID: ","Error, ",1,5000,5);

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            auxEmpleado=ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado,&retornoId);

            if (auxId==retornoId)
            {
                printf("***EMPLEADO A ELIMINAR***");
                printf("\n  ID    Nombre   Horas   Sueldo \n\n");
                printf("%4d  %20s %20d %20d \n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
                printf("Desea eliminar este empleado de forma permanente?(s o n)");
                fflush(stdin);
                scanf("%c",&respuesta);
                if (respuesta=='s')
                {
                    ll_remove(pArrayListEmployee,i);
                    employee_delete(auxEmpleado);
                    printf("Dato eliminado de manera exitosa\n");
                    break;
                }
                else
                {
                    printf("El dato no se elimino\n");
                }
            }
        }
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxEmpleado = employee_new();
    int auxId;
    char auxNombre[20];
    int auxHorasDeTrabajo;
    int auxSueldo;

    printf("***LISTA DE EMPLEADOS***");
    printf("\n  ID    Nombre   Horas   Sueldo \n\n");
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,auxNombre);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasDeTrabajo);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            printf("%4d  %20s %20d %20d \n",auxId,auxNombre,auxHorasDeTrabajo,auxSueldo);
        }
        todoOk=1;
    }
    return todoOk;
}

int ordenarEmpleadoNombre (void* empleadoUno, void* empleadoDos)
{
    int retorno = -2;

    Employee* auxUno;
    Employee* auxDos;

    if(empleadoUno!=NULL && empleadoDos!=NULL)
    {
        auxUno=(Employee*)empleadoUno;
        auxDos=(Employee*)empleadoDos;
        retorno=stricmp(auxUno->nombre,auxDos->nombre);
    }

    return retorno;
}

int ordenarEmpleadoId (void* empleadoUno, void* empleadoDos)
{
    int retorno=-2;
    Employee* auxUno;
    Employee* auxDos;

    if(empleadoUno!=NULL && empleadoDos!=NULL)
    {
        auxUno=(Employee*)empleadoUno;
        auxDos=(Employee*)empleadoDos;
        if((auxUno->id) < (auxDos->id))
        {
            retorno=1 ;
        }
        else if((auxUno->id) == (auxDos->id))
        {
            retorno=0;
        }
        else if((auxUno->id) > (auxDos->id))
        {
            retorno=-1 ;
        }
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1,opcion;

    if(pArrayListEmployee!=NULL)
    {
        printf("1-ID ascendente\n");
        printf("2-ID descendente\n");
        printf("3-Nombre ascendente\n");
        printf("4-Nombre descendente\n");
        getNumero(&opcion,"Ingrese numero: ","Error, ",1,4,5);
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,ordenarEmpleadoId, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 2:
            ll_sort(pArrayListEmployee,ordenarEmpleadoId, 1);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 3:
            ll_sort(pArrayListEmployee,ordenarEmpleadoNombre, 0);
            controller_ListEmployee(pArrayListEmployee);
            break;
        case 4:
            ll_sort(pArrayListEmployee,ordenarEmpleadoNombre, 1);
            controller_ListEmployee(pArrayListEmployee);
            break;
        default:
            printf("\nError, selecione un numero del 1 al 4\n\n");
            break;
        }
        retorno =1;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;
    Employee* auxEmpleado;
    int todoOk=0;
    int len;
    int auxId;
    char auxNombre[20];
    int auxHorasDeTrabajo;
    int auxSueldo;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {

        len=ll_len(pArrayListEmployee);
        f=fopen(path,"w");
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<len; i++)
        {
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,auxNombre);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasDeTrabajo);
            employee_getSueldo(auxEmpleado,&auxSueldo);

            fprintf(f,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasDeTrabajo,auxSueldo);
        }
        printf("Se guardaron los empleados con exito!\n");
        todoOk=1;
        fclose(f);
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f =NULL;
    Employee* auxEmpleado;
    int todoOk=0;

    f=fopen(path,"wb");
    if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee)>0 && f!=NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if(auxEmpleado!=NULL)
            {
                fwrite(auxEmpleado,sizeof(Employee),1,f);
            }
        }
         printf("Se guardaron los empleados con exito!\n");
        todoOk=1;
        fclose(f);
    }
    return todoOk;
}

