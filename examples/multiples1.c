/*	multiples1.c
	*/

#include <stdio.h>

int main(int argc, char **argv)
{
	int number = 0;
	int multiple = 0;
	int i = 0, j = 0;
	
	do
	{
		printf("Please enter an integer greater than 0: ");
		scanf("%d", &number);
	} while (number <= 0);
	
	do
	{
		printf("Please enter a multiple greater than 0: ");
		scanf("%d", &multiple);
	} while (multiple <= 0);
	
	printf("Counting to %d by %d:\n", number, multiple);
	
	i = 0;
	for (j = 0; j <= number; j += multiple)
	{
		printf("%8d * %8d = %8d\n", i, multiple, j);
		i ++;
	}
	if ((j -= multiple) < number)
	{
		printf("I have %d remaining.\n", number - j);
	}
	return 0;
}
