/*
 ============================================================================
 Name        : temps.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section	 : SJJ
 Date        : January 18, 2019 - Workshop 3 - Lab
 ============================================================================
*/

/*
 ============================================================================
 Description : Temperature analyzer program
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS		// removes errors caused by scanf() in my version of MS Visual Studio

#define NUMS 3				// declare number of days to calculate

#include <stdio.h>			// include external header file with input/output functions

int main(void) {

	int highTemp, lowTemp;			// declare variables for high and low temperatures
	int i;					// for loop counter

	puts("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++) {							// initiate for loop for the amount of days

		printf("Enter the high value for day %d: ", i + 1);			// prompt for high temp and store
		scanf("%d", &highTemp);

		printf("\nEnter the low value for day %d: ", i + 1);			// prompt for low temp and store
		scanf("%d", &lowTemp);
		printf("\n");

		while (highTemp < lowTemp || highTemp > 40 || lowTemp < -40) {		// error checking while loop
			printf("Incorrect values, temperatures must be in the range "
				"-40 to 40, high must be greater than low.\n\n");

			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);
			printf("\n");
		}
	}

	return 0;								// return control to OS with successful code
}
