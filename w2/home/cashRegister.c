/*
 ============================================================================
 Name        : cashRegister.c
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164 - IPC144j
 Date        : January 18, 2019 - Workshop 2 - Home
 ============================================================================
 */

/*
 ============================================================================
 Description : Calculate the balOwing required for an amount of money
 	 	 	   and display any amount remaining
 ============================================================================
*/


#define _CRT_SECURE_NO_WARNINGS // fixes errors created by scanf() in my version of MS Visual Studio

#include <stdio.h> 		// include external library header file for input/output functions

int main (void) 		// start program
{
	// declare variables
	double cashAmount;  	// entered by user - the amount of money to calculate
	int balOwing;           // used for integer calculations on balOwing after loonies subtracted
	int coinsReq;		// amount of coins in balOwing - used multiple times for all coin types
	double tax;		// the amount of tax to be added to the dollar amount entered by the user


	printf("Please enter the amount to be paid: $");            	// Prompt user for information i.e. an amount of money
	scanf("%lf", &cashAmount);                                  	// get and store the amount entered by user

	printf("GST: %.2lf\n", tax = cashAmount * .13 + .005);		// Calculate the tax and display.. This (+ .005) can cause issues with certain
									// dollar amounts. But the workshop explicitly states to do this i.e. for $8.68

	printf("Balance owing: $%.2lf\n", cashAmount += tax);       	// add the tax and display

	printf("Loonies required: %d, ", coinsReq = cashAmount);    	// cast the cashAmount into an integer and it will give us the loonies required
	balOwing = (cashAmount -= coinsReq) * 100;          		/* subtract the amount of loonies from the total and multiply by 100 then
									   cast to (int balOwing) */
	printf("balance owing $%1.2f\n", (float)balOwing/100);      	// display the balance owing in decimal form by /100 and casting as a float

	printf("Quarters required: %d, ", coinsReq = balOwing/25);  	// calculate the quarters owing and display balance
	balOwing %=  25;						// calculate the balance owing using modulus
	printf("balance owing $%1.2f\n", (float)balOwing/100);

	printf("Dimes required: %d, ", coinsReq = balOwing/10);		// calculate the dimes owing and display balance
	balOwing %=  10;
	printf("balance owing $%1.2f\n", (float)balOwing/100);

	printf("Nickels required: %d, ", coinsReq = balOwing/5);    	// calculate the nickels owing and display balance
	balOwing %=  5;
	printf("balance owing $%1.2f\n", (float)balOwing/100);

	printf("Pennies required: %d, ", coinsReq = balOwing);		// calculate the pennies owing and display balance.
	balOwing %= coinsReq;                                   	// coinsReq is no longer needed, i just kept the code the same
	printf("balance owing $%1.2f\n", (float)balOwing/100);		// because in the real world we would use a function for these
									// calculations

	return 0;							// return control to OS
}
