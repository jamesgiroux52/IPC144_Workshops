/*
 ============================================================================
 Name        : temps.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : January 26, 2019 - Workshop 3 - Home
 ============================================================================
*/

/*
 ============================================================================
 Description : Temperature analyzer program that also calculates the average
 	 	 	   temperature, highest and lowest temperature, and error checks
 	 	 	   that all values are within the range of -40 to 40 and that the
 	 	 	   high is greater than the low
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS

#define NUMS 4					// declare number of days to calculate

#include <stdio.h>

int main(void) {

	int highTemp,				// variables for high and low temperatures
		lowTemp,
		maxTemp,			// variables for lowest and highest temperatures
		minTemp,
		highestDay,			// variables for the day number that was the highest or lowest
		lowestDay;
	float totalHigh = 0;			// variables to add to the total so I can calculate the averages
	float totalLow = 0;
	float average;				// variable to store average
	int i;					// for loop counter

	puts("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++) {					// initiate for loop for the amount of days

		printf("Enter the high value for day %d: ", i + 1);	// prompt for high temp and store
		scanf("%d", &highTemp);

		printf("\nEnter the low value for day %d: ", i + 1);	// prompt for low temp and store
		scanf("%d", &lowTemp);
		printf("\n");

		while (highTemp < lowTemp || highTemp > 40 || lowTemp < -40) {		// error checking loop
			printf("Incorrect values, temperatures must be in the range "
					"-40 to 40, high must be greater than low.\n");

			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &highTemp);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &lowTemp);
			printf("\n");
		}

		totalHigh += highTemp;					// add temperatures entered to totals
		totalLow += lowTemp;

		if (maxTemp < highTemp || i == 0){			// check if temperature is the highest entered and
			maxTemp = highTemp;				// update the maxTemp and highestDay if it is
			highestDay = i + 1;				// also if it is the first value entered
		}

		if (minTemp > lowTemp || i == 0){			// same check to see if lowest temperature
			minTemp = lowTemp;
			lowestDay = i + 1;
		}

	}

	average = ((totalHigh + totalLow) / NUMS) / 2;					// calculate average

	printf("The average (mean) LOW temperature was: %.2f\n", totalLow / NUMS);	// display information about averages and
	printf("The average (mean) HIGH temperature was: %.2f\n", totalHigh / NUMS);	// highest and lowest temp days
	printf("The average (mean) temperature was: %.2f\n", average);
	printf("The highest temperature was %d, on day %d\n", maxTemp, highestDay);
	printf("The lowest temperature was %d, on day %d\n", minTemp, lowestDay);

	return 0;							// return control to OS with a success code
}

