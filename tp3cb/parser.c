#include <stdio.h>
#include <stdlib.h>
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* auxEmpleado = NULL;
    int cant;
    char buffer[4][20];
    do
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
        if (cant<4){
            break;
        }
        else{
            auxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if (auxEmpleado!=NULL){
                ll_add(pArrayListEmployee,auxEmpleado);
                auxEmpleado = NULL;
                retorno = 1;
            }
        }
    }while (!feof(pFile));

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* auxEmpleado = NULL;

    do
    {
        auxEmpleado = employee_new();
        if (auxEmpleado!=NULL){
            if (fread(auxEmpleado,sizeof(Employee),1,pFile))
            {
                ll_add(pArrayListEmployee,auxEmpleado);
                auxEmpleado = NULL;
                retorno = 1;
            }
            else
            {
                break;
            }
        }

    }while (!feof(pFile));

    return retorno;
}

