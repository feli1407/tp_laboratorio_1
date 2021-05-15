/*
 * arrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: Casco Felipe Div 1A
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

#endif /* ARRAYEMPLOYEES_H_ */

/** \brief Menu de Empleados
 *
 * \return int La opcion ingresada y validada
 *
 */
int menu();

/** \brief Menu modificar
 *
 * \return int La opcion ingresada y validada
 *
 */
int menuInformes();

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 1 (EXITO) si se obtiene una cadena y 0 (ERROR) si no
*
*/
int myGets(char* cadena, int longitud);

/** \brief To indicate that all position in the array are empty,
 *                        this function put the flag (isEmpty) in TRUE in all
 *                        position of the array.
 *
 * \param list[] Employee Pointer to array of employees
 * \param len int  Array length
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int initEmployees(Employee list[], int len);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 1 (EXITO) si se obtiene un numero entero y 0 (ERROR) si no
*
*/
int getInt(int* pResultado);

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
int esNumerica(char* cadena);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos Es la cantidad de reintentos que tiene el usuario
 * \return Retorna 1 si se obtuvo el numero y 0 si no
 */
int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int
maximo, int reintentos);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (0) if Error [Invalid length or NULL pointer or without
 *            free space] - (1) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

/** \brief Si hay lugar disponible, pide los datos al usario, los valida y llama a la funcion
 * addEmployee para agregar al empleado al sistema
 *
 * \param list[] empleado array de empleados
 * \param tam len tamaño del array
 * \param punteroId int* punttero del id para poder modificarlo despues de usarlo
 * \return int Retorna 1 si el alta fue exitosa el numero y 0 si no
 *
 */
int altaEmpleado(Employee list[], int len, int* punteroId);

/** \brief Recorre la cadena verificando que todo lo de la cadena sean letras o espacios
 *
 * \param cadena[] char cadena a validar
 * \return int Retorna 1 si son todas letras o espacios, y 0 si no
 *
 */
int tieneUnicamenteLetrasDelAlfabeto(char cadena[]);

/** \brief Obtiene un string validando el tamaño y que tenga solo letras o espacios
 *
 * \param cadena[] char Cadena a analizar
 * \param tam int Tamaño maximo de la cadena
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje en caso de error a ser mostrado
 * \param reintentos int Es la cantidad de reintentos que tiene el usuario
 * \return int Retorna 1 si no hubo problemas y 0 si no pudo obtener la cadena correctamente
 *
 */
int getString(char cadena[], int tam, char* mensaje, char* mensajeError,  int reintentos);

/** \brief Busca un lugar vacio en el array de empleados(que tenga isEmpty=1)
 *
 * \param list[] empleado array de empleados
 * \param tam int tamaño del array
 * \return int Retorna -1 si no hay lugar disponible y el lugar del indice vacio si hay lugar
 *
 */
int buscarLibre(Employee list[], int tam);

/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param pResultado float* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return int Retorna 1 si se obtiene un numero flotante y 0 si no
 *
 */
int getFloat(float* pResultado);



/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \param reintentos Es la cantidad de reintentos que tiene el usuario
 * \return Retorna 1 si se obtuvo el numero flotante y 0 si no
 */
int getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float
maximo, int reintentos);

/** \brief Verifica si la cadena ingresada es flotante
 *
 * \param cadena char* Cadena de caracteres a ser analizada
 * \return int Retorna 1 si es flotante y 0 si no lo es
 *
 */
int esFlotante(char* cadena);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee* array de empleados
 * \param len int tamaño del array
 * \param id int id del empleado a buscar
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Menu para el apartado modificar empleado
 *
 * \return int Retorna la opcion validada que ingreso el usuario
 *
 */
int menuModificar();

/** \brief Muestra los empleados, pide un id y valida que exista, muestra el menu de modificar
 * y permite modificar al empleado validando el reingreso de datos
 * \param list[] Employee array de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si no hubo errores y 0 si no pudo hacer la modificacion
 *
 */
int modificarEmpleado(Employee* list, int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee* array de empleados
 * \param len int tamaño del array
 * \param id int id del empleado a eliminar
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Pide el id del empleado que se quiere dar de baja, lo valida, lo muestra y pide
 * confirmacion al usuario
 * \param list Employee* array de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si no hubo problemas en la baja y 0 si no se pudo realizar
 *
 */
int bajaEmpleado(Employee* list, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee* array de empleados
 * \param len int tamaño del array
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee* array de empleados
 * \param length int tamaño del array
 * \return int  (-1) if Error - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Muestra el total y el promedio de los salarios y la cantidad de empleados
 * con salario superior al promedio
 * \param list[] Employee array de empleados
 * \param len int tamaño del array
 * \return int retorna 1 si pudo mostrarlo correctamente y 0 si no
 *
 */
int totalSueldoEmpleado(Employee list[], int len);
