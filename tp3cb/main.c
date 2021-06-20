#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "menu.h"

/****************************************************
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
    char option;
    int nextId = 1;
    char path[50];
    int flagTxt = 0;
    int flagBin = 0;
    int flagAdd = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if (listaEmpleados==NULL){
        printf("Hubo problemas para generar espacio.\n\n");
        exit(1);
    }
    do{
        switch(menu())
        {
            system("cls");
            case 1:
                if(!flagBin){
                    printf("Ingrese Path: ");
                    fflush(stdin);
                    gets(path);
                    if(controller_loadFromText(path,listaEmpleados)){
                        printf("\nEl archivo de texto se cargo con exito\n\n");
                        flagTxt = 1;
                    }
                }
                else{
                    printf("\nYa se cargo un archivo binario. No puede cargar el archivo de texto\n\n");
                }
                break;

            case 2:
                if (!flagTxt){
                    printf("Ingrese Path: ");
                    fflush(stdin);
                    gets(path);
                    if(controller_loadFromBinary(path,listaEmpleados)){
                        printf("\nEl archivo binario se cargo con exito\n\n");
                        flagBin = 1;
                    }
                }
                else{
                    printf("\nYa se cargo un archivo de texto. No puede cargar el archivo binario\n\n");
                }
                break;

            case 3:
                system("cls");
                if(!controller_addEmployee(listaEmpleados,&nextId)){
                    printf("\nHubo un problema en la carga del empleado.\n\n");
                }
                else{
                    flagAdd = 1;
                }
                break;

            case 4:
                if (flagTxt || flagBin || flagAdd){
                    system("cls");
                    if(!controller_editEmployee(listaEmpleados)){
                        printf("Hubo un problema para modificar el empleado.\n\n");
                    }
                }
                else{
                    printf("\nDebe cargar un archivo o un empleado antes de poder editar empleado.\n\n");
                }
                break;

            case 5:
                if (flagTxt || flagBin || flagAdd){
                    system("cls");
                    if(!controller_removeEmployee(listaEmpleados)){
                        printf("Hubo un problema para dar de baja el empleado.\n\n");
                    }
                }
                else{
                    printf("\nDebe cargar un archivo o un empleado antes de poder eliminar un empleado.\n\n");
                }
                break;

            case 6:
                if (flagTxt || flagBin || flagAdd){
                    system("cls");
                    if(!controller_ListEmployee(listaEmpleados)){
                        printf("Hubo un problema para listar los empleados.\n\n");
                    }
                }
                else{
                    printf("\nDebe cargar un archivo o un empleado antes de poder listar los empleados.\n\n");
                }
                break;

            case 7:
                if (flagTxt || flagBin || flagAdd){
                    system("cls");
                    controller_sortEmployee(listaEmpleados);
                }
                else{
                    printf("\nDebe cargar un archivo o un empleado antes de poder ordenar los empleados.\n\n");
                }
                break;

            case 8:
                if ((flagTxt && !flagBin) || flagAdd){
                    printf("Ingrese Path: ");
                    fflush(stdin);
                    gets(path);
                    controller_saveAsText(path,listaEmpleados);
                    printf("\nEl archivo de texto se guardo con exito\n\n");
                }
                else{
                    printf("\nDebe cargar un archivo o un empleado antes de poder guardar los empleados.\n\n");
                }
                break;

            case 9:
                if ((!flagTxt && flagBin) || flagAdd){
                    printf("Ingrese Path: ");
                    fflush(stdin);
                    gets(path);
                    controller_saveAsBinary(path,listaEmpleados);
                    printf("\nEl archivo binario se guardo con exito\n\n");
                }
                else{
                    printf("\nDebe cargar un archivo o un empleado antes de poder guardar los empleados.\n\n");
                }
                break;

            case 10:
                printf("Seguro desea salir? [s]Si - [n]No: ");
                fflush(stdin);
                scanf("%c", &option);
                option = tolower(option);
                while(option!='s' && option!='n'){
                    printf("ERROR: Ingrese [s]Si - [n]No: ");
                    fflush(stdin);
                    scanf("%c", &option);
                    option = tolower(option);
                }
                break;
        }
        system("pause");
    }while(option != 's');
    return 0;
}



