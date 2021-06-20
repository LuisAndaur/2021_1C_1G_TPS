#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new(){
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    if (nuevoEmpleado!=NULL){
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre,"");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado!=NULL){
        if (!(employee_setId(nuevoEmpleado,atoi(idStr)) && employee_setNombre(nuevoEmpleado,nombreStr)
            && employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr)) && employee_setSueldo(nuevoEmpleado,atoi(sueldoStr)))){

            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}

void employee_delete(Employee* this){
    if (this!=NULL){
        free(this);
    }
}


//SETTERS
int employee_setId(Employee* this,int id){
    int retorno = 0;
    if(this!=NULL && id>0){
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
    int retorno = 0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>2 && strlen(nombre)<20){
        strcpy(this->nombre,nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int retorno = 0;
    if(this!=NULL && horasTrabajadas>0){
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
    int retorno = 0;
    if(this!=NULL && sueldo>0){
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}

//GETTERS
int employee_getId(Employee* this,int* id){
    int retorno = 0;
    if(this!=NULL && id!=NULL){
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
    int retorno = 0;
    if(this!=NULL && nombre!=NULL){
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int retorno = 0;
    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int retorno = 0;
    if(this!=NULL && sueldo!=NULL){
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

//COMPARISONS
int empleadoCompareId(void* a, void* b){
    int retorno = 0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if (a!=NULL && b!=NULL){
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        if (emp1->id > emp2->id){
            retorno = 1;
        }
        else{
            if (emp1->id < emp2->id){
                retorno = -1;
            }
        }
    }
    return retorno;
}

int empleadoCompareNombre(void* a, void* b){
    int retorno = 0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if (a!=NULL && b!=NULL){
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        retorno = strcmp(emp1->nombre, emp2->nombre);
    }
    return retorno;
}

int empleadoCompareHorasTrabajadas(void* a, void* b){
    int retorno = 0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if (a!=NULL && b!=NULL){
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        if (emp1->horasTrabajadas > emp2->horasTrabajadas){
            retorno = 1;
        }
        else{
            if (emp1->horasTrabajadas < emp2->horasTrabajadas){
                retorno = -1;
            }
        }
    }
    return retorno;
}

int empleadoCompareSueldo(void* a, void* b){
    int retorno = 0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if (a!=NULL && b!=NULL){
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        if (emp1->sueldo > emp2->sueldo){
            retorno = 1;
        }
        else{
            if (emp1->sueldo < emp2->sueldo){
                retorno = -1;
            }
        }
    }
    return retorno;
}
