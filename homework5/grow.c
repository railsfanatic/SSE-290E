/*	HOMEWORK 5.1
	grow.c
	Grows an array dynamically.
	by Tom Grushka
	April 18, 2016	*/

#include <stdio.h>
#include <stdlib.h>

// initial size of the array
#define INITIAL_SIZE 5

int main()
{
	// declarations
	int *a = malloc(INITIAL_SIZE * sizeof(int));	// allocate the array
	int arraySize = INITIAL_SIZE;	// stores current array size (capacity)
	int numElements = 0;	// stores the actual number of elements entered
	int *a_start = a;	// save pointer at start
	int *new;			// pointer to new array
	int *new_start;		// pointer to start of new array
	
	// loop indefinitely until we enter 0
	do {
		scanf("%d", a);		// get integer from user
		if (*a == 0) break;	// exit loop if we enter 0
		numElements ++;		// increment # of array elements
		a++;				// increment array pointer
		// if we've filled the array...
		if (a - a_start == arraySize)
		{
			// allocate a new array 2x the size of the existing one
			new = malloc(2 * arraySize * sizeof(int));
			// set start pointer equal to new pointer
			new_start = new;
			// copy the old array to the new one
			for (a = a_start; a - a_start < arraySize; a++)
			{
				*new = *a;
				new++;
			}
			free(a_start);	// free the old array
			a_start = new_start;	// set a_start pointer to new array
			a = a_start + arraySize;	// set "a" pointer to current position
			arraySize *= 2;		// double array size value
			// tell user we've doubled the size of the array
			printf("Grew array to %d\n", arraySize);
		}
	} while (1);	// loop indefinitely
	
	// exit loop when user enters 0,
	// then print the # of elements in the final array
	printf("There are %d elements in the array.\n", numElements);
	
	// print the array in 5 columns
	for (a = a_start; a - a_start < numElements; a++)
	{
		printf("%10d\t", *a);
		if ((a - a_start) % 5 == 4) printf("\n");
	}
	printf("\n");
	
	return 0;
}
