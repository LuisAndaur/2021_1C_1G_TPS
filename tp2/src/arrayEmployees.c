#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"

int initEmployees(Employee* list, int len){
    int retorno = -1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int addEmployess(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector){
    int retorno = -1;
    if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && sector>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty == 1){
                list[i].id = id;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                retorno = 0;
                break;
            }
        }
        if(retorno != -1){
            printf("\n\nEmployee upload was successful.\n\n");
        }
    }
    return retorno;
}

int printEmployees(Employee* list, int length){
    int retorno = -1;
    if(list != NULL && length > 0){
        printf("List of employees\n");
        printf("ID         Name    Surname       Salary    Sector\n");
        for(int i = 0; i < length; i++){
            if(list[i].isEmpty == 0){
                printf("%d %10s %10s     $%.2f      %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int removeEmployee(Employee* list, int len, int id){
    int retorno = -1;
    if(list != NULL && len > 0 && id > -1){
        for(int i = 0; i < len; i++){
            if(!list[i].isEmpty && list[i].id == id){
                list[i].isEmpty = 1;
                printf("\nThe employee was eliminated.\n");
                retorno = 0;
                break;
            }
        }
        if(retorno == -1){
            printf("\nEmployee not found.\n");
        }
    }
    return retorno;
}

int sortEmployees(Employee* list, int len, int order){
    int retorno = -1;
    Employee auxList;
    if(list != NULL && len > 0 && order > -1 && order < 2){
        for(int i = 0; i < len -1; i++){
            for(int j = i+1; j < len ;j++){
               if( (list[i].sector < list[j].sector) || (list[i].sector == list[j].sector && strcmpi(list[i].lastName, list[j].lastName) < order) ){
                   auxList = list[i];
                   list[i] = list[j];
                   list[j] = auxList;
               }
            }
        }
      retorno = 0;
    }
    return retorno;
}

int findEmployeeById(Employee* list, int len, int id){
    int retorno = -1;
    if(list != NULL && len > 0 && id > -1){
        for(int i = 0; i < len; i++){
            if(list[i].id == id && list[i].isEmpty == 0){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

float totalSalaries(Employee* list, int len){
    float retorno = -1;
    float accumulator = 0;
    if(list!=NULL && len>0){
        for(int i = 0; i<len; i++){
            if(list[i].isEmpty == 0){
                accumulator+=list[i].salary;
                retorno = accumulator;
            }
        }
    }
    return retorno;
}

float average(Employee* list, int len){
    float retorno = -1;
    float accumulator = 0;
    int accountant = 0;
    float average;
    if(list!=NULL && len>0){
        for(int i = 0; i<len; i++){
            if(list[i].isEmpty == 0){
                accumulator+=list[i].salary;
                accountant++;
            }
        }
        average = accumulator/(float)accountant;
        retorno = average;
    }
    return retorno;
}


int averageSalary(Employee* list, int len){
    int retorno = -1;
    int accountant = 0;
    if(list!=NULL && len>0){
        for(int i = 0; i<len; i++){
            if(list[i].isEmpty == 0 && list[i].salary>average(list,len)){
                accountant++;
            }
        }
        retorno = accountant;
    }
    return retorno;
}
