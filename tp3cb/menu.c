#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"

int menu()
{
    int opcion;
    system("cls");
    printf("Menu de empleados\n\n");
    printf("1.Cargar los datos de los empleados desde el archivo .csv (modo texto)\n");
    printf("2.Cargar los datos de los empleados desde el archivo .bin (modo binario)\n");
    printf("3.Alta de empleado\n");
    printf("4.Modificar datos de empleado\n");
    printf("5.Baja de empleado\n");
    printf("6.Listar empleados\n");
    printf("7.Ordenar empleados\n");
    printf("8.Guardar los datos de los empleados en el archivo .csv (modo texto)\n");
    printf("9.Guardar los datos de los empleados en el archivo .bin (modo binario)\n");
    printf("10.Salir\n\n");
    getInt("Ingrese una opcion: ",&opcion);
    while(opcion < 1 || opcion > 10)
    {
        getInt("ERROR: Reingrese una opcion: ",&opcion);
    }
    return opcion;
}

int menuModificar()
{
    int opcion;
    system("cls");
    printf("Menu modificar\n\n");
    printf("1.Modificar nombre\n");
    printf("2.modificar horas trabajadas\n");
    printf("3.Modificar sueldo\n");
    printf("4.Salir\n\n");
    getInt("Ingrese una opcion: ",&opcion);
    while(opcion < 1 || opcion > 4)
    {
        getInt("ERROR: Reingrese una opcion: ",&opcion);
    }
    return opcion;
}

int menuOrdenar()
{
    int opcion;
    system("cls");
    printf("Menu ordenar\n\n");
    printf("1.Ordenar por ID\n");
    printf("2.Ordenar por nombre\n");
    printf("3.Ordenar por horas trabajadas\n");
    printf("4.Ordenar por sueldo\n");
    printf("5.Salir\n\n");
    getInt("Ingrese una opcion: ",&opcion);
    while(opcion < 1 || opcion > 5)
    {
        getInt("ERROR: Reingrese una opcion: ",&opcion);
    }
    return opcion;
}
