/*
 ============================================================================
 Name        : tp1.c
 Author      : Luis Andaur
 Version     : 1C - 1G - 2021
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);

	int numA;
	int numB;
	char seguir;
	int opcion;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	int rDividir;
	long long int factorialA;
	long long int factorialB;
	int flagOperandoA;
	int flagOperandoB;
	int flagHacerOperaciones;

	flagOperandoA = 0;
	flagOperandoB = 0;
	flagHacerOperaciones = 0;

	seguir = 's';

	do
	{
		opcion = mostrarMenu(numA, numB, flagOperandoA, flagOperandoB);

		switch(opcion)
		{
			case 1:
				system("cls");
				printf("\nSelecciono la opcion 1\n");
				numA = pedirOperando();
				printf("\nEl 1er operando A = %d\n", numA);
				flagOperandoA = 1;
				printf("\n\n");
				system("pause");
				break;

			case 2:
				system("cls");
				if(flagOperandoA)
				{
					printf("\nSelecciono la opcion 2\n");
					numB = pedirOperando();
					printf("\nEl 2do operando B = %d\n", numB);
					flagOperandoB = 1;
				}
				else
				{
					printf("\nERROR: Debe cargar el 1er operando A.\n");
				}
				printf("\n\n");
				system("pause");
				break;

		   case 3:
				system("cls");
				if(flagOperandoA && !flagOperandoB)
				{
					printf("\nERROR: Debe cargar el 2do operando B.\n");
				}
				else
				{
					if(!flagOperandoA)
					{
						printf("\nERROR: Debe cargar el 1er operando A.\n");
					}
					else
					{
						printf("\nSelecciono la opcion 3 \nEl calculo de todas las operaciones fue exitoso.\n");
						calcularOperaciones(numA, numB, &suma, &resta, &multiplicacion, &rDividir, &division, &factorialA, &factorialB);
						flagHacerOperaciones = 1;
					}
				}
				printf("\n\n");
				system("pause");
				break;

			case 4:
				system("cls");
				if(!flagOperandoA)
				{
					printf("\nERROR: Debe cargar el 1er operando A.\n");
				}
				else
				{
					if(flagOperandoA && !flagOperandoB)
					{
						printf("\nERROR: Debe cargar el 2do operando B.\n");
					}
					else
					{
						if(flagOperandoA && flagOperandoB && !flagHacerOperaciones)
						{
							printf("\nERROR: Debe calcular todas las operaciones.\n");
						}
						else
						{
							mostrarResultados(numA, numB, &suma, &resta, &multiplicacion, &rDividir, &division, &factorialA, &factorialB);
							flagOperandoA = 0;
							flagOperandoB = 0;
							flagHacerOperaciones = 0;
						}
					}
				}
				printf("\n\n");
				system("pause");
				break;

			 case 5:
				system("cls");
				seguir = 'n';
				printf("\n\n");
				break;

			default:
				system("cls");
				printf("\nOpcion invalida.\n");
				printf("\n\n");
				system("pause");
				break;
		}//FIN SWITCH

	}while(seguir=='s');

	return EXIT_SUCCESS;
}
