/*
 ============================================================================
 Name        : cashRegister.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164 - IPC144J
 Date        : January 18, 2019 - Workshop 2 - Lab
 ============================================================================
 */

/*
 ============================================================================
 Description : Calculate the change required for an amount of money
 	 	 	   and display any amount remaining
 ============================================================================
*/


#define _CRT_SECURE_NO_WARNINGS 	// fixes errors created by scanf() in my version of MS Visual Studio

#include <stdio.h> 			// include external library header file for input/output operations


int main (void) // start program
{
	// declare variables
	double cashAmount;  	// entered by user - the amount of money to calculate
	int looniesReq;		// amount of loonies in change
	int quartersReq;	// amount of quarters in change

	printf("Please enter the amount to be paid: $"); 			// Prompt user for information i.e. an amount of money
	scanf("%lf", &cashAmount);		 				// get and store the amount entered by user

	printf("Loonies required: %d", looniesReq = cashAmount);		// round the amount entered to have no decimal places
	cashAmount -= looniesReq;						// calculate the balance owing
	printf(", balance owing $%.2lf\n", cashAmount);				// display amount owing to 2 decimal places

	printf("Quarters required: %d", quartersReq = cashAmount / .25);	// calculate the number of quarters from the remaining balance
	cashAmount = cashAmount - (quartersReq * .25);				// update the balance owing variable
	printf(", balance owing $%.2lf\n", cashAmount);				// display the final amount owing in cents to 2 decimal places

	return 0;
}
