/*
 ============================================================================
 Name        : temps2.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : SJJ
 Date        : January 27, 2019 - Workshop 4 - Lab
 ============================================================================
*/

/*
 ============================================================================
 Description : Temperature analyzer program that also calculates the average
 	       temperature, highest and lowest temperature, error checks the
 	 	correct amount of days
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS  // removes warnings caused by scanf() in Visual Studio

#include <stdio.h>

#define DAYS 10

int main(void) {

	int numDays;			// number of days too analyze
	int i;				// for counter
	int highestDay, lowestDay;	// variables for the day number that was the highest or lowest
	int daysToAnalyze;		// number of days to analyze for average
	float averageHigh;		// average variables
	float averageLow;
	float average;

	int highTemps [DAYS];		// Initialize arrays with a size of DAYS = 10
	int lowTemps [DAYS];

	int maxTemp = 0;		// maximum and minimum temperatures
	int minTemp = 0;

	puts("---=== IPC Temperature Calculator V2.0 ===---");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");		// prompt for and get the num days to analyze
	scanf("%d", &numDays);

	while (numDays < 3 || numDays > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");	// error check that value is 3-10
		scanf("%d", &numDays);
	}

	printf("\n");

	for (i = 0; i < numDays; i++){					// loop through array and store values entered
		printf("Day %d - High: ", i + 1);
		scanf("%d", &highTemps[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowTemps[i]);

		if (maxTemp <= highTemps[i] || i == 0){			// checks if temp entered is highest or lowest
			maxTemp = highTemps[i];				// or if it's the first value entered
			highestDay = i + 1;
		}

		if (minTemp >= lowTemps[i] || i == 0){
			minTemp = lowTemps[i];
			lowestDay = i + 1;
		}
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < numDays; i++){					// display values entered
		printf("%d    %d    %d\n", i + 1, highTemps[i], lowTemps[i]);
	}

	printf("\nThe highest temperature was %d, on day %d\n", maxTemp, highestDay);	// display the highest and lowest temperatures
	printf("The lowest temperature was %d, on day %d\n\n", minTemp, lowestDay);	// and on which day


	do {  				// loop for analyzing averages

		averageHigh = 0;	// initialize/reset average variables
		averageLow = 0;

		printf("Enter a number between 1 and %d to see the average temperature for the "
				"entered number of days, enter a negative number to exit: ", numDays);
		scanf("%d", &daysToAnalyze);

		if (daysToAnalyze < 0){

			printf("\nGoodbye!\n");						// if user enters a negative number exit program
			return 0;

		} else {

			while (daysToAnalyze < 1 || daysToAnalyze > numDays){		// error check that user enters valid day range
				printf("\nInvalid entry, please enter a number "
						"between 1 and %d, inclusive: ", numDays);
				scanf("%d", &daysToAnalyze);
			}

		}

		for (i = 0; i < daysToAnalyze; i++){					// get totals from high and low temperatures
			averageHigh += highTemps[i];
			averageLow += lowTemps[i];
		}

		average = ((averageHigh + averageLow)/ daysToAnalyze) / 2;		// calculate average

		printf("\nThe average temperature up to day "				// display average
				"%d is: %.2f\n\n", daysToAnalyze, average);

	} while (daysToAnalyze > 0);

	return 0;
}
