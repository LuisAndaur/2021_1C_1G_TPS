#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"
#include "Controller.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char confirmacion;
    FILE* f;
    f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL){
        f = fopen(path, "r");
        if (f==NULL){
            printf("No se pudo abrir el archivo.\n");
        }
        else{
            if (ll_len(pArrayListEmployee)>0){
                printf("CUIDADO!\nSe van a sobrescribir los empleados.\nConfirma? Ingrese [s]Si - [n]No: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
                while (confirmacion!='s' && confirmacion!='n'){
                    printf("ERROR: Confirma? Ingrese [s]Si - [n]No: ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                }
            }

            if (!ll_len(pArrayListEmployee) || confirmacion=='s'){
                ll_clear(pArrayListEmployee);
                retorno = parser_EmployeeFromText(f,pArrayListEmployee);
            }
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char confirmacion;
    FILE* f;
    f = NULL;

    if(path!=NULL && pArrayListEmployee!=NULL){
        f = fopen(path, "rb");
        if (f==NULL){
            printf("No se pudo abrir el archivo.\n");
        }
        else{
            if (ll_len(pArrayListEmployee)>0){
                printf("CUIDADO!\nSe van a sobrescribir los empleados.\nConfirma? Ingrese [s]Si - [n]No: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
                while (confirmacion!='s' && confirmacion!='n'){
                    printf("ERROR: Confirma? Ingrese [s]Si - [n]No: ");
                    fflush(stdin);
                    scanf("%c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                }
            }

            if (!ll_len(pArrayListEmployee) || confirmacion=='s'){
                ll_clear(pArrayListEmployee);
                retorno = parser_EmployeeFromBinary(f,pArrayListEmployee);
            }
        }
    }
    fclose(f);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
    int retorno = 0;
    int auxId;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmpleado = NULL;

    if(pArrayListEmployee!=NULL && id!=NULL){

        buscarMayorId(pArrayListEmployee,id);
        auxId = *id;

        auxEmpleado = employee_new();
        if (auxEmpleado!=NULL){

            printf("Alta de usuario\n\n");
            printf("ID usuario: %d\n",auxId);
            employee_setId(auxEmpleado,auxId);

            getString("Ingrese nombre: ", nombre);
            while(!employee_setNombre(auxEmpleado,nombre)){
                getString("ERROR: Reingrese nombre: ", nombre);
            }

            getInt("Ingrese horas trabajadas: ", &horasTrabajadas);
            while(!employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas)){
                getInt("ERROR: Reingrese horas trabajadas: ", &horasTrabajadas);
            }

            getInt("Ingrese sueldo: $", &sueldo);
            while(!employee_setSueldo(auxEmpleado,sueldo)){
                getInt("ERROR: Reingrese sueldo: ", &sueldo);
            }

            if(ll_add(pArrayListEmployee, auxEmpleado)!=-1){
                *id = auxId;
                printf("\nEl empleado se cargo con exito.\n\n");
                retorno = 1;
            }
        }
    }
    return retorno;
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
    int retorno = 0;
    int idBuscar;
    int buscadorId;
    int indice;
    int opcion;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmpleado = NULL;

    if(pArrayListEmployee!=NULL){
        system("cls");
        printf("MODIFICAR EMPLEADO\n");
        controller_ListEmployee(pArrayListEmployee);

        getInt("\nIngrese el ID que desea modificar: ", &idBuscar);
        while(idBuscar<0){
            getInt("\nReingrese el ID que desea modificar: ", &idBuscar);
        }

        for (int i=0;i<ll_len(pArrayListEmployee);i++){
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            if (auxEmpleado!=NULL && employee_getId(auxEmpleado,&buscadorId)){
                if (buscadorId == idBuscar){
                    indice = i;
                    break;
                }
            }
            else{
                printf("El empleado con ID %d no existe.\n\n", idBuscar);
            }
        }

        auxEmpleado = (Employee*)ll_get(pArrayListEmployee,indice);

        do{
            switch(menuModificar()){
                case 1:
                     getString("\nIngrese nuevo nombre: ", nombre);
                    while(!employee_setNombre(auxEmpleado,nombre)){
                        getString("ERROR: Reingrese nuevo nombre: ", nombre);
                    }
                    printf("\nEl nombre se modifico con exito.\n\n");
                    printf("\n\n");
                    break;

                case 2:
                    getInt("\nIngrese nuevas horas trabajadas: ", &horasTrabajadas);
                    while(!employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas)){
                        getInt("ERROR: Reingrese nuevas horas trabajadas: ", &horasTrabajadas);
                    }
                    printf("\nLas horas trabajadas se modificaron con exito.\n\n");
                    printf("\n\n");
                    break;

                case 3:
                    getInt("\nIngrese nuevo sueldo: ", &sueldo);
                    while(!employee_setSueldo(auxEmpleado,sueldo)){
                        getInt("ERROR: Reingrese nuevo sueldo: ", &sueldo);
                    }
                    printf("\nEl sueldo se modifico con exito.\n\n");
                    printf("\n\n");
                    break;

                case 4:
                    opcion = 4;
                    break;

                default:
                    printf("Opcion incorrecta.\n");
                    break;
            }
        if(opcion!=4){
            system("pause");
        }
        }while(opcion!= 4);

        if(ll_set(pArrayListEmployee, indice, auxEmpleado)!=-1){
            printf("El empleado se modifico con exito.\n\n");
            retorno = 1;
        }
    }
    return retorno;
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
    int retorno = 0;
    int idBuscar;
    int buscadorId;
    int indice;
    Employee* auxEmpleado = NULL;

    if(pArrayListEmployee!=NULL){
        system("cls");
        printf("MODIFICAR EMPLEADO\n");
        controller_ListEmployee(pArrayListEmployee);

        getInt("\nIngrese el ID que desea modificar: ", &idBuscar);
        while(idBuscar<0){
            getInt("\nReingrese el ID que desea modificar: ", &idBuscar);
        }

        for (int i=0;i<ll_len(pArrayListEmployee);i++){
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            if (auxEmpleado!=NULL && employee_getId(auxEmpleado,&buscadorId)){
                if (buscadorId == idBuscar){
                    indice = i;
                    break;
                }
            }
            else{
                printf("El empleado con ID %d no existe.\n\n", idBuscar);
            }
        }

        if(ll_remove(pArrayListEmployee, indice)!=-1){
            printf("El empleado se dio de baja con exito.\n\n");
            retorno = 1;
        }
    }
    return retorno;
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
    int retorno = 0;
    int id;
    char nombre[20];
    int horas;
    int sueldo;
    Employee* empleado = NULL;

    if (pArrayListEmployee!=NULL){
        printf("LISTA DE EMPLEADOS\n");
        printf("  ID            NOMBRE    HORAS      SALARIO  \n");

        for (int i=0;i<ll_len(pArrayListEmployee);i++){
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            if (employee_getId(empleado,&id) && employee_getNombre(empleado,nombre) && employee_getHorasTrabajadas(empleado,&horas) && employee_getSueldo(empleado,&sueldo)){
                printf("%4d   %15s     %4d      $%4d\n", id, nombre, horas, sueldo);
                retorno = 1;
            }
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
    int retorno = 0;
    int opcion = 0;
    int orden;

    if(pArrayListEmployee!=NULL){
        do
        {
            system("cls");
            opcion = menuOrdenar();
            if (opcion==5){
                break;
            }
            getInt("Ingrese para ordenar: [1] Ascendente - [0] Descendente: ", &orden);
            while(orden<0 || orden>1){
                getInt("ERROR: Reingrese para ordenar: [1] Ascendente - [0] Descendente: ", &orden);
            }
            switch (opcion)
            {
                case 1:
                    if (!ll_sort(pArrayListEmployee,empleadoCompareId,orden)){
                        printf("\nLista ordenado por ID correctamente.\n\n");
                    }
                    break;

                case 2:
                    if (!ll_sort(pArrayListEmployee,empleadoCompareNombre,orden)){
                        printf("\nLista ordenado por Nombre correctamente.\n\n");
                    }
                    break;

                case 3:
                    if (!ll_sort(pArrayListEmployee,empleadoCompareHorasTrabajadas,orden)){
                        printf("\nLista ordenado por Horas trabajadas correctamente.\n\n");
                    }
                    break;

                case 4:
                    if (!ll_sort(pArrayListEmployee,empleadoCompareSueldo,orden)){
                        printf("\nLista ordenado por sueldo correctamente.\n\n");
                    }
                    break;
            }
            system("pause");
        } while (opcion!=5);
        retorno = 1;
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
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int i;
    char confirmacion = 's';
    FILE* pFile;
    pFile = NULL;
    Employee* empleado;

    if (path!=NULL && pArrayListEmployee!=NULL){
        pFile = fopen(path,"r");
        if (pFile!=NULL){
            printf("CUIDADO!\nEl archivo ya existe y se va a sobrescribir.\nConfirma? Ingrese [s]Si - [n]No: ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            while (confirmacion!='s' && confirmacion!='n'){
                printf("ERROR: Confirma? Ingrese [s]Si - [n]No: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
            }
        }
        fclose(pFile);

        if(confirmacion=='s'){
            pFile = fopen(path,"w");
            if (pFile==NULL){
                printf("\nNo se pudo abrir el archivo.\n\n");
            }
            else{
                for (i=0;i<ll_len(pArrayListEmployee);i++){
                    empleado = (Employee*) ll_get(pArrayListEmployee,i);
                    if (empleado!=NULL){
                        fprintf(pFile,"%d,%s,%d,%d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                    }
                }
                retorno = 0;
            }
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int i;
    char confirmacion = 's';
    FILE* pFile;
    pFile = NULL;
    Employee* empleado;

    if (path!=NULL && pArrayListEmployee!=NULL){
        pFile = fopen(path,"rb");
        if (pFile!=NULL){
            printf("CUIDADO!\nEl archivo ya existe y se va a sobrescribir.\nConfirma? Ingrese [s]Si - [n]No: ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            while (confirmacion!='s' && confirmacion!='n'){
                printf("ERROR: Confirma? Ingrese [s]Si - [n]No: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);
            }
        }
        fclose(pFile);

        if(confirmacion=='s'){
            pFile = fopen(path,"wb");
            if (pFile==NULL){
                printf("\nNo se pudo abrir el archivo.\n\n");
            }
            else{
                for (i=0;i<ll_len(pArrayListEmployee);i++){
                    empleado = (Employee*) ll_get(pArrayListEmployee,i);
                    if (empleado!=NULL){
                        fwrite(empleado,sizeof(Employee),1,pFile);
                    }
                }
                retorno = 0;
            }
            fclose(pFile);
        }
    }
    return retorno;
}


int buscarMayorId(LinkedList* pArrayListEmployee, int* id){
    int retorno = 0;
    Employee* auxEmpleado = NULL;
    int mayor;

    if (pArrayListEmployee!=NULL){
        if (!ll_len(pArrayListEmployee)){
            *id = 1;
        }
        else{
            for (int i=0;i<ll_len(pArrayListEmployee);i++){
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                if (i==0 || auxEmpleado->id>mayor){
                    mayor = auxEmpleado->id;
                }
            }
            *id = mayor+1;
        }
        retorno = 1;
    }
    return retorno;
}
