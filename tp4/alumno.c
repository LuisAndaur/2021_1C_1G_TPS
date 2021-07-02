#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

eAlumno* nuevoAlumno()
{
    eAlumno* nuevoAlumno = (eAlumno*) malloc(sizeof(eAlumno));
    return nuevoAlumno;
}

eAlumno* nuevoAlumnoParametros(int id, char* nombre, int edad, char sexo)
{
    eAlumno* nuevoAlumnoParam = nuevoAlumno();
    if(nuevoAlumnoParam != NULL)
    {
        if(!((alumnoSetId(nuevoAlumnoParam, id)) &&
           (alumnoSetNombre(nuevoAlumnoParam, nombre)) &&
           (alumnoSetEdad(nuevoAlumnoParam, edad)) &&
           (alumnoSetSexo(nuevoAlumnoParam, sexo))))
        {
            free(nuevoAlumnoParam);
            nuevoAlumnoParam = NULL;
        }
    }
    return nuevoAlumnoParam;
}

void mostrarAlumno(eAlumno* alumno)
{
    printf("%4d %10s    %2d    %2c\n", alumno->id,alumno->nombre,alumno->edad,alumno->sexo);
}

void mostrarAlumnos(LinkedList* lista)
{
    printf("Lista de alumnos");
    printf("\nId       nombre  edad  sexo\n");
    for (int i=0;i<ll_len(lista);i++)
    {
        mostrarAlumno((eAlumno*)ll_get(lista,i));
    }
}

int alumnoSetId(eAlumno* this, int id)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int alumnoSetNombre(eAlumno* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int alumnoSetEdad(eAlumno* this, int edad)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->edad = edad;
        retorno = 1;
    }
    return retorno;
}

int alumnoSetSexo(eAlumno* this, int sexo)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->sexo = sexo;
        retorno = 1;
    }
    return retorno;
}

int alumnoGetNombre(eAlumno* this,char* nombre)
{
    int retorno = 0;
    if(this!=NULL && nombre!=NULL){
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}

int compareId(void* a, void* b)
{
    int retorno = 0;
    eAlumno* alumno1 = NULL;
    eAlumno* alumno2 = NULL;
    if (a!=NULL && b!=NULL){
        alumno1 = (eAlumno*) a;
        alumno2 = (eAlumno*) b;
        if (alumno1->id > alumno2->id){
            retorno = 1;
        }
        else{
            if (alumno1->id < alumno2->id){
                retorno = -1;
            }
        }
    }
    return retorno;
}
