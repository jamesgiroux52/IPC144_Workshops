/*
 ============================================================================
 Name        : emp_inlab.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : February 3, 2019 - Workshop 5 - Lab
 ============================================================================
*/

/*
 ============================================================================
 Description : limited employee management database with error checking and
 	 	main menu to perform different actions on employee records.
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS // fixes errors caused by scanf() in MSVisualStudio IDE

#include <stdio.h>

#define SIZE 2				// declare SIZE which is total number of employees

struct Employee {			// declare structure for Employees
	int id;
	int age;
	double salary;
};

int main(void) {			// start program

	int userOption;
	int i;
	int locToAdd = -1;		// flag and placeholder when adding employees

	struct Employee emp[SIZE] = {{0}};	// declare array of type struct with size of SIZE

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("1. Display Employee Information\n");		// display the menu to user
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d",&userOption);				// Get and store the value entered
		printf("\n");

		switch (userOption) {

		case 0:		// break to end of case construct
			
			break;
		
		case 1:		// display the employees in the database

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");


			for (i = 0; i < SIZE; i++){
				if (emp[i].id > 0){
					printf("%6d%9d%11.2lf\n",emp[i].id, emp[i].age, emp[i].salary );
				}
			}

			printf("\n");

			break;

		case 2:		// add an employee to the database

			printf("Adding Employee\n");
			printf("===============\n");

			for (i = 0; i < SIZE; i++){		// Find first empty location in employee array
				if (emp[i].id == 0 && locToAdd == -1){
					locToAdd = i;
				}
			}

			if (locToAdd == -1){			// if locToAdd remains unchanged then the DB is full
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			} else {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[locToAdd].id);		// get the new employee data
				printf("Enter Employee Age: ");
				scanf("%d", &emp[locToAdd].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[locToAdd].salary);
				printf("\n");
			}

			locToAdd = -1;					// reset flag

			break;

		default:	// case for invalid user entry

			printf("ERROR: Incorrect Option: Try Again\n\n");

		}

	} while (userOption != 0);					// exit program when user enters 0

	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
