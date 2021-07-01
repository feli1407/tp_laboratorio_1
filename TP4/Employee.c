#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->id=0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas=0;
        nuevoEmpleado->sueldo=0;
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado!=NULL)
    {
        if(!(employee_setId(nuevoEmpleado,atoi(idStr)) &&
                employee_setNombre(nuevoEmpleado,nombreStr) &&
                employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr)) &&
                employee_setSueldo(nuevoEmpleado,atoi(sueldo))
            ))
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }

    return nuevoEmpleado;
}

void employee_delete(Employee* p)
{
    free(p);
}

int employee_setId(Employee* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id > 0)
    {
        this->id=id;
        todoOk=1;
    }
    return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;
    if(this!=NULL && nombre != NULL && strlen(nombre)<128 && strlen(nombre)>2)//validacion 20 caracteres y no menos de 2 caracteres
    {
        strcpy(this->nombre, nombre);
        todoOk=1;
    }
    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(nombre != NULL && this != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        todoOk=1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;
        todoOk=1;
    }
    return todoOk;
}
