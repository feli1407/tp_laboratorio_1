#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Casco Felipe div 1A
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int flag = 0;//Si no se cargan los empleados desde el archivo de texto o binario, no se puede agregar, modificar o remover ninguno

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option=menu();
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            flag = 1;
            break;
        case 2:
            controller_loadFromBinary("dataB.csv",listaEmpleados);
            flag = 1;
            break;
        case 3:
            if(flag == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados con la opcion 1 o 2.\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados con la opcion 1 o 2.\n");
            }
            break;
        case 5:
            if(flag == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados con la opcion 1 o 2.\n");
            }
            break;
        case 6:
            if(flag == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados con la opcion 1 o 2.\n");
            }
            break;
        case 7:
            if(flag == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("Primero debe cargar los empleados con la opcion 1 o 2.\n");
            }
            break;
        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("dataB.csv",listaEmpleados);
            break;
        default:
            if (option!=10)
            {
                printf("Error, elija una opcion valida entre el 1 y el 10\n");
            }
            break;
        }
        system("pause");
        system("cls");
    }
    while(option != 10);
    return 0;
}
