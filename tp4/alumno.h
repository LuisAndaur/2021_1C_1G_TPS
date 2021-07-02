#include "LinkedList.h"

#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    int edad;
    char sexo;
}eAlumno;

#endif // ALUMNO_H_INCLUDED
eAlumno* nuevoAlumno();
eAlumno* nuevoAlumnoParametros(int id, char* nombre, int edad, char sexo);
void mostrarAlumno(eAlumno* alumno);
void mostrarAlumnos(LinkedList* lista);
int alumnoSetId(eAlumno* this, int id);
int alumnoSetNombre(eAlumno* this, char* nombre);
int alumnoSetEdad(eAlumno* this, int edad);
int alumnoSetSexo(eAlumno* this, int sexo);
int compareId(void* a, void* b);
