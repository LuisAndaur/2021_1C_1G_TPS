#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(int numA, int numB, int flagA, int flagB)
{
    int opcion;

    system("cls");
    printf("\t||| CALCULADORA |||\n\n");
    printf("1- Ingresar 1er operando A = ");
    if(flagA)
    {
         printf("%d\n", numA);
    }
    else
    {
        printf("x\n");
    }
    printf("2- Ingresar 2do operando B = ");
    if(flagB)
    {
         printf("%d\n", numB);
    }
    else
    {
        printf("y\n");
    }
    printf("3- Calcular todas las operaciones.\n");
        printf("\ta- Calcular la suma (A + B)\n");
        printf("\tb- Calcular la resta (A - B)\n");
        printf("\tc- Calcular la division (A / B)\n");
        printf("\td- Calcular la multiplicacion (A * B)\n");
        printf("\te- Calcular el factorial (A!) (B!)\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int pedirOperando()
{
    int operando;

    printf("\nIngrese un numero: ");
    scanf("%d", &operando);

    return operando;
}

int sumar(int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}

int restar(int a, int b)
{
    int resultado;

    resultado = a - b;

    return resultado;
}

int multiplicar(int a, int b)
{
    int resultado;

    resultado = a * b;

    return resultado;
}

int dividir(int a, int b, float* division)
{
    int retorno = 0;

    if(b!=0)
    {
        *division = (float)a / b;
        retorno = 1;
    }

    return retorno;
}

long long int factorial(int n)
{
    long long int respuesta = 1;

    for(long long int i=1;i<=n;i++)
    {
        respuesta *= i;
    }

    return respuesta;
}

void calcularOperaciones(int numA, int numB, int* suma, int* resta, int* multiplicacion, int* rDividir, float* division, long long int* factorialA, long long int* factorialB)
{
    *suma = sumar(numA, numB);
    *resta = restar(numA, numB);
    *multiplicacion = multiplicar(numA, numB);
    *rDividir = dividir(numA, numB, division);
    *factorialA = factorial(numA);
    *factorialB = factorial(numB);
}

void mostrarResultados(int numA, int numB, int* suma, int* resta, int* multiplicacion, int* rDividir, float* division, long long int* factorialA, long long int* factorialB)
{
    printf("\nSelecciono la opcion 4 \nLos resultados son:\n");
    printf("\ta- El resultado de (%d + %d) es: %d\n", numA, numB, *suma);
    printf("\tb- El resultado de (%d - %d) es: %d\n", numA, numB, *resta);
    printf("\tc- El resultado de (%d * %d) es: %d\n", numA, numB, *multiplicacion);
    if(rDividir)
    {
        printf("\td- El resultado de (%d / %d) es: %.2f\n", numA, numB, *division);
    }
    else
    {
        printf("\td- No es posible dividir por cero\n");
    }
    printf("\te- El factorial de (%d!) es: %I64d y el factorial de (%d!) es: %I64d\n", numA, *factorialA, numB, *factorialB);
}
