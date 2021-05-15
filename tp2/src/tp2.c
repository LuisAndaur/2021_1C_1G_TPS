/*
 ============================================================================
 Name        : tp2.c
 Author      : Luis Andaur
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "utn.h"

#define LEN 1000

int menu();
int reportsMenu();

int main(void) {
	setbuf(stdout,NULL);

	Employee employees[LEN];
	Employee newEmployee;

	int id = 1000;
	int numberEmployees = 0;
	int idSearch;
	int flagModify = 1;
	char answer = 'n';
	int opcion;
	int retorno;

	initEmployees(employees, LEN);

	do
	{
		system("cls");
		switch(menu())
		{
		case 1:
			if(numberEmployees<LEN)
			{
				system("cls");
				printf("Employee load\n\n");
				printf("ID Employee: %d\n", id);
				getString("Enter name: ", newEmployee.name);
				getString("Enter surname: ", newEmployee.lastName);
				getFloat("Enter salary: $", &newEmployee.salary);
				getInt("Enter sector: ", &newEmployee.sector);

				addEmployess(employees, LEN, id, newEmployee.name, newEmployee.lastName, newEmployee.salary, newEmployee.sector);

				id++;
				numberEmployees++;
			}
			else
			{
				printf("\nThe system is full.\n");
			}
			break;

		case 2:
			if(numberEmployees != 0)
			{
				system("cls");
				sortEmployees(employees, LEN, 0);
				printEmployees(employees, LEN);
				getInt("\nEnter ID of the employee you want to modify: ", &idSearch);
				retorno = findEmployeeById(employees, LEN, idSearch);
				if( retorno != -1)
				{
					printf("\n%d %s %s %.2f %d\n", employees[retorno].id, employees[retorno].name, employees[retorno].lastName, employees[retorno].salary, employees[retorno].sector);
					getInt("\nWhat do you want to modify?: \n\n1.Name\n2.Surname\n3.Salary\n4.Sector\n5.Exit\nChoose option: ", &opcion);
					newEmployee = employees[retorno];

					switch(opcion)
					{
					case 1:
						getString("Enter new name: ", newEmployee.name);
						break;
					case 2:
						getString("Enter new surname: ", newEmployee.lastName);
						break;
					case 3:
						getFloat("Enter new salary: ", &newEmployee.salary);
						break;
					case 4:
						getInt("Enter new sector: ", &newEmployee.sector);
						break;
					case 5:
						printf("The modification was canceled.\n");
						flagModify = 0;
						break;
					}

					employees[retorno] = newEmployee;
					if(flagModify)
					{
						printf("\n%d %s %s %.2f %d\n", employees[retorno].id, employees[retorno].name, employees[retorno].lastName, employees[retorno].salary, employees[retorno].sector);
					}
					else
					{
						printf("\nEmployee not found.\n");
					}

				}
				else
				{
					printf("\nThere are no employees to modify.\n");
				}
				break;
			}
			case 3:
				if(numberEmployees > 0)
				{
					system("cls");
					sortEmployees(employees, LEN, 0);
					printEmployees(employees, LEN);
					getInt("\nEnter ID of the employee you want to remove: ", &idSearch);
					if(removeEmployee(employees, LEN, idSearch) != -1)
					{
						numberEmployees--;
					}
				}
				else
				{
					printf("\nThere are no employees in the list.\n");
				}
				break;

			case 4:
				if(numberEmployees != 0)
				{
					do{
						switch(reportsMenu()){
							case 1:
								if(numberEmployees > 0){
									sortEmployees(employees, LEN, 0);
									printEmployees(employees, LEN);
								}else{
									printf("\nThere are no employees in the list.\n");
								}
								system("pause");
								break;

							case 2:
								if(numberEmployees > 0){
									system("cls");
									printf("Salary and average.\n\n");
									printf("Total salaries: $%.2f.\n", totalSalaries(employees,LEN));
									printf("Average: %.2f.\n", average(employees,LEN));
									printf("Employees that exceed the average salary: %d\n\n", averageSalary(employees,LEN));
								}else{
									printf("\nThere are no employees in the list.\n");
								}
								system("pause");
								break;

							case 3:
								opcion = 3;
								break;
						system("pause");
						}
					}while(opcion!=3);
				}
				else
				{
					printf("\nThere are no employees to report.\n");
				}
				break;

			case 5:
				printf("Are you sure you want to leave? y/n: ");
				fflush(stdin);
				scanf("%c", &answer);
				answer = tolower(answer);
				while(answer != 'y' && answer != 'n')
				{
					printf("Error. Are you sure you want to leave? y/n:");
					fflush(stdin);
					scanf("%c", &answer);
					answer = tolower(answer);
				}
				break;
			}
			system("pause");
		}
		while(answer == 'n');
	return EXIT_SUCCESS;
}

int menu()
{
    int opcion;
    printf("||| Employee |||\n\n");
    printf("1- Add employee\n");
    printf("2- Modify employee\n");
    printf("3- Remove employee\n");
    printf("4- Report\n");
    printf("5- Exit\n");
    printf("\nEnter option: ");
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 5)
    {
        printf("Error. Invalid option: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

int reportsMenu()
{
    int opcion;
    system("cls");
    printf("||| Reports menu |||\n\n");
    printf("1- List of employees arranged alphabetically by Surname and Sector.\n");
    printf("2- Total and average salaries, and how many employees are above the average salary.\n");
    printf("3- Exit\n");
    printf("\nEnter option: ");
    scanf("%d", &opcion);
    while(opcion < 1 || opcion > 3)
    {
        printf("Error. Invalid option: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

