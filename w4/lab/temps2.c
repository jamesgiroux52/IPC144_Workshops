/*
 ============================================================================
 Name        : temps2.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section	 : SJJ
 Date        : January 27, 2019 - Workshop 4 - Lab
 ============================================================================
*/

/*
 ============================================================================
 Description : Temperature analyzer program that also error checks that the
 	 	 	   user enters a valid number of days to calculate.  Then prints
 	 	 	   out the days and their respective temperatures in chart form
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS  // removes errors caused by scanf() in my version of MS Visual studio IDE

#include <stdio.h>

int main(void) {

	int numDays;				// number of days to calculate

	puts("---=== IPC Temperature Calculator V2.0 ===---");

	printf("Please enter the number of days, between "		// prompt for and get number of days
			"3 and 10, inclusive: ");
	scanf("%d", &numDays);

	while (numDays < 3 || numDays > 10) {					// error check that user enters between 3-10
		printf("\nInvalid entry, please enter a "
				"number between 3 and 10, inclusive: ");
		scanf("%d", &numDays);
	}

	printf("\n");

	int highTemps [numDays];								// initialize arrays with size of numDays
	int lowTemps [numDays];
	int i;

	for (i = 0; i < numDays; i++){							// get high and low temps from user for all days
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTemps[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTemps[i]);
	}

	printf("\nDay  Hi  Low\n");								// table title

	for (i = 0; i < numDays; i++){
		printf("%d    %d    %d\n", i + 1,					// display values entered by user in a table
				highTemps[i], lowTemps[i]);
	}

	return 0;						// return control to OS with a success code
}

