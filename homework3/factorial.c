#include <stdio.h>

long long factorial(int n)
{
	int i = 1;
	long long fact = 1;
	if (n < 0) return -1;
	for (i = 1; i <= n; i++) fact *= i;
	return fact;
}

void runFactorial()
{
	int n = 0;
	
	printf("FACTORIAL\n\n");
	printf("Function that calculates the factorial of an integer.\n\n");
	
	do {
		printf("Please enter an integer between 0 and 20: ");
		scanf(" %d", &n);
	} while (n < 0 || n > 20);
	
	printf("The factorial is %lld.\n", factorial(n));
}
