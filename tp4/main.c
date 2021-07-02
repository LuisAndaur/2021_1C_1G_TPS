#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "LinkedList.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaSub = NULL;
    LinkedList* listaClon = NULL;

    int indice = 0;
    int retorno;
    eAlumno* aux = NULL;

    eAlumno* alumno1 = nuevoAlumnoParametros(1234,"Carlos",12,'m');
    eAlumno* alumno2 = nuevoAlumnoParametros(3245,"Alfredo",15,'m');
    eAlumno* alumno3 = nuevoAlumnoParametros(4568,"Lucia",15,'f');
    eAlumno* alumno4 = nuevoAlumnoParametros(5659,"Susana",13,'f');
    eAlumno* alumno5 = nuevoAlumnoParametros(7652,"Moria",18,'f');
    eAlumno* alumno6 = nuevoAlumnoParametros(8961,"Alex",17,'m');
    eAlumno* alumno7 = nuevoAlumnoParametros(2569,"Carla",16,'f');


    //ll_add
    ll_add(lista,alumno1);
    ll_add(lista,alumno2);
    ll_add(lista,alumno3);
    ll_add(lista,alumno4);
    ll_add(lista,alumno5);
    ll_add(lista,alumno6);
    mostrarAlumnos(lista);
    printf("\n\n");


    //ll_len
    printf("El total de alumnos es: %d\n", ll_len(lista));
    printf("\n\n");


    //ll_get
    ll_add(lista,alumno7);
    printf("Se agrego un alumno\n");
    mostrarAlumno((eAlumno*)ll_get(lista,6));
    printf("\n");
    mostrarAlumnos(lista);
    printf("\n\n");


    //ll_set
    printf("Piso un alumno con uno nuevo\n");
    eAlumno* alumno8 = nuevoAlumnoParametros(3446,"Oscar",14,'m');
    mostrarAlumno(alumno8);
    if(!ll_set(lista,3,alumno8))
    {
        printf("Se ha modificado el alumno en la posicion 4.\n");
    }
    mostrarAlumnos(lista);
    printf("\n\n");


    //ll_remove
    printf("Elimino un alumno en la posicion 3.\n");
    if(!ll_remove(lista,2))
    {
        printf("Se ha eliminado el alumno\n");
    }
    mostrarAlumnos(lista);
    printf("\n\n");


    //ll_indexOf
    printf("\nSe encuentra: ");
    mostrarAlumno(alumno5);
    indice = ll_indexOf(lista,alumno5);
    if (indice!=-1)
    {
        printf("Si, se encuentra en la posicion %d\n", indice);
    }
    else
    {
        printf("\nNo, no se encuentra.");
    }
    printf("\n\n");


    //ll_isEmpty
    printf("La lista esta vacia?\n");
    retorno = ll_isEmpty(lista);
    if (!retorno)
    {
        printf("La lista no esta vacia\n");
    }
    else
    {
        printf("La lista esta vacia\n");
    }
    printf("\n\n");


    //ll_push
    printf("Inserto un nuevo elemento a la lista en la posicion 5.\n");
    eAlumno* alumno9 = nuevoAlumnoParametros(2856,"Lautaro",13,'m');
    if(!ll_push(lista,4,alumno9))
    {
        printf("Se ha insertado el alumno correctamente\n");
    }
    mostrarAlumnos(lista);
    printf("\n\n");


    //ll_pop
    printf("Eliminamos un alumno de la lista pero guardamos sus datos\n");
    aux = (eAlumno*)ll_pop(lista,4);
    if(aux!=NULL)
    {
        printf("Se ha eliminado al alumno %s de la lista\n", aux->nombre);
    }
    mostrarAlumnos(lista);
    printf("\n\n");


    //ll_contains
    printf("Se encuentra en la lista Lautaro?\n");
    retorno = ll_contains(lista, alumno9);
    if (retorno)
    {
        printf("Lautaro esta en la lista\n");
    }
    else
    {
        printf("Lautaro no esta en la lista\n");
    }
    printf("\n\n");


    //ll_sublist
    printf("Creamos una sublista\n");
    listaSub = ll_subList(lista,2,5);
    if(listaSub!=NULL)
    {
        printf("La sublista se creo con exito\n");
    }
    mostrarAlumnos(listaSub);
    printf("\n\n");


    //ll_containsAll
    printf("Se encuentra en la lista todos los elementos?\n");
    retorno = ll_containsAll(lista, listaSub);
    if (retorno)
    {
        printf("Todos los elementos estan en la lista\n");
    }
    else
    {
        printf("No estan todos los elementos en la lista\n");
    }
    printf("\n\n");


    //ll_clone
    printf("Clono la lista\n");
    listaClon = ll_clone(lista);
    if(listaClon!=NULL)
    {
        printf("La lista se clono con exito\n");
    }
    mostrarAlumnos(listaClon);
    printf("\n\n");


    //ll_clear
    printf("Limpiamos toda la lista\n");
    if(!ll_clear(listaClon))
    {
        printf("La lista clonada se vacio con exito\n");
    }
    mostrarAlumnos(listaClon);
    printf("\n\n");

    //ll_deleteLinkedList
    printf("Eliminamos las listas auxiliares\n");
    if(!ll_deleteLinkedList(listaClon) && !ll_deleteLinkedList(listaSub))
    {
        printf("Las listas auxiliares se eliminaron con exito\n");
    }
    printf("\n\n");


    //ll_sort
    printf("Lista sin ordenar\n");
    mostrarAlumnos(lista);
    printf("\n\n");

    printf("Lista ordenada por id descendente\n");
    if(!ll_sort(lista,compareId,0))
    {
        printf("La lista se ordeno con exito\n");
    }
    mostrarAlumnos(lista);
    printf("\n\n");


    return 0;
}
