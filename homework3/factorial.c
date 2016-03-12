/*	HOMEWORK 3
	File:	factorial.c
	Module:	Homework 3.8: Factorial
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include "common.h"

/*	factorial:	perform n!
	in:	n (int) = number to factorial
	returns: (long long) the factorial
*/
long long factorial(int n)
{
	// declarations
	int i = 1;			// counter
	long long fact = 1;	// cumulative product
	
	if (n < 0) return -1;	// undefined
	
	// loop counter, multiply product by counter
	for (i = 1; i <= n; i++) fact *= i;
	
	return fact;
}

int runFactorial()
{
	int n = 0;	// store the number to factorial
	
	// print banner
	printf("8. FACTORIAL\n\n");
	printf("Function that calculates the factorial of an integer.\n\n");
	
	// loop until user enters a valid number
	do {
		n = getInteger("Please enter an integer between 0 and 20: ");
	} while (n < 0 || n > 20);
	
	// print the factorial of n
	printf("The factorial is %lld.\n", factorial(n));
	
	return 0;
}
