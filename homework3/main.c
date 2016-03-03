#include <stdio.h>

#include "funcs.h"

const int ARRAY_SIZE = 1000000;

int main(int argc, char **argv)
{
	int choice = 0;
	
	printf("\n\nHOMEWORK 3 MENU\n===============\n\n"
		
		"1.  Smallest Random Number\n\n"
		"2.  Random and Reverse\n\n"
		"3.  Find Adjacent Match\n\n"
		"4.  Guess the Password\n\n"
		"5.  Count the Vowels\n\n"
		"6.  Palindrome\n\n"
		"7.  Hypotenuse\n\n"
		"8.  Factorial\n\n"
		"9.  Average with Upper Limit\n\n\n"
		
		"Please enter a number (1-9, other to quit). ");
	
	scanf(" %d", &choice);
	printf("\n\n");
	
	switch(choice)
	{
		case 1:
			printf("SMALLEST RANDOM NUMBER\n\n");
			int data[ARRAY_SIZE];
			fillRandom(ARRAY_SIZE, data);
			//printf("The array is: \n");
			//printArray(ARRAY_SIZE, data);
			printf("\n");
			int i = findLowest(ARRAY_SIZE, data);
			printf("The lowest value is [%d] = %d.\n", i, data[i]);
			mergeSort(ARRAY_SIZE, data);
			printf("Sorted array:\n");
			//printArray(ARRAY_SIZE, data);
			break;
		default:
			printf("Goodbye!\n\n");
			break;
	}
	return 0;
}
