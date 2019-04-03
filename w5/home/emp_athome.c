/*
 ============================================================================
 Name        : emp_inlab.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : February 3, 2019 - Workshop 5 - Home
 ============================================================================
*/

/*
 ============================================================================
 Description : limited employee management database with error checking and
 	 	main menu to perform different actions on employee records
       	        including displaying the current employees, adding employees
 	 	if there is space, removing employees, and modifying a specific
 	 	employees salary.
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS // fixes errors caused by scanf() in MSVisualStudio IDE

#include <stdio.h>

#define SIZE 4			// declare SIZE which is total number of employees

struct Employee {		// declare structure for Employees
	int id;
	int age;
	double salary;
};


int main(void) {		// start program

	int i;			// for loop counter
	int userEntry;		// used as main menu entry and ID entered by user to modify or delete record
	int locToMod = -1;	// used as a flag and as the location of array element to modify / remove

	struct Employee employee[SIZE] = {{0}};	    // declare array of Employee structures with size of SIZE


	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		printf("1. Display Employee Information\n");	// display the menu to user
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		scanf("%d",&userEntry);				// Get and store the value entered
		printf("\n");

		switch (userEntry) {

		case 0: 	// exit program

			break;

		case 1:		// display employee information

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");


			for (i = 0; i < SIZE; i++){		// display all employees in table format
				if (employee[i].id != 0){
					printf("%6d%9d%11.2lf\n",employee[i].id,
							employee[i].age, employee[i].salary);
				}
			}

			printf("\n");

			break;

		case 2:		// add a new employee if there is space

			printf("Adding Employee\n");
			printf("===============\n");

			for (i = 0; i < SIZE; i++){		// finds the first empty spot in the employee array
				if (employee[i].id == 0 && locToMod == -1){
					locToMod = i;
				}
			}

			if (locToMod == -1){
				printf("ERROR!!! Maximum Number of "
						"Employees Reached\n\n");	// error if the array has no empty space
			} else {
				printf("Enter Employee ID: ");			// otherwise get new data from user
				scanf("%d", &employee[locToMod].id);
				printf("Enter Employee Age: ");
				scanf("%d", &employee[locToMod].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &employee[locToMod].salary);
				printf("\n");
			}

			locToMod = -1;						// reset flag

			break;

		case 3:		// update/change a specific employee's salary found by their ID number

			printf("Update Employee Salary\n");
			printf("======================\n");

			do {

				printf("Enter Employee ID: ");	// loop until a valid ID is found
				scanf("%d", &userEntry);

				for (i = 0; i < SIZE; i++){	// will return the location in the employee array
					if (userEntry == employee[i].id){	//   that matches ID entered
						locToMod = i;
					}
				}

				if (locToMod < 0){		// prints error message if ID not found
					printf("*** ERROR: Employee ID "
							"not found! ***\n");
				}

			} while (locToMod < 0);			// loop exits when a valid ID is found


			printf("The current salary is "		// display current salary
					"%.2lf\n", employee[locToMod].salary);

			printf("Enter Employee New Salary: ");	// prompt for and store new salary
			scanf("%lf", &employee[locToMod].salary);
			printf("\n");

			locToMod = -1;				// reset flag

			break;

		case 4:	// remove an employee based on ID entered by user

			printf("Remove Employee\n");
			printf("===============\n");

			do {

				printf("Enter Employee ID: ");		// get ID from user
				scanf("%d", &userEntry);

				for (i = 0; i < SIZE; i++){		// find ID in employee array
					if (userEntry == employee[i].id){
						locToMod = i;
					}
				}

				if (locToMod < 0){			// if ID not found display error
					printf("*** ERROR: Employee ID "
							"not found! ***\n");
				}

			} while (locToMod < 0);				// re-run loop if ID not found

			printf("Employee %d will be removed\n",
					employee[locToMod].id);
			printf("\n");

			employee[locToMod].id = 0;			// reset all values to 0 for
			employee[locToMod].age = 0;			// element to be deleted
			employee[locToMod].salary = 0;

			locToMod = -1;					// reset flag

			break;

		default:

			printf("ERROR: Incorrect Option: Try Again\n\n");

		}

	} while (userEntry != 0);

	printf("Exiting Employee Data Program. Good Bye!!!\n");

	return 0;
}
