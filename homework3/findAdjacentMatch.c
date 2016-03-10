#include <stdio.h>
#include "common.h"

int runFindAdjacentMatch() {
	int matchIndex = -1;
	int a[ARRAY_SIZE];
	int i = 0;
	
	printf("FIND ADJACENT MATCH\n\n");
	printf("Allows you to enter values into an array. Finds the first pair of\n"
		"adjacent elements that are the same. Prints out the value of the identical\n"
		"elements and the position of the first element that is a match.\n\n");
	
	inputArray(ARRAY_SIZE, a);
	printf("You entered the following array:\n");
	printArray(ARRAY_SIZE, a);
	
	for (i = 1; i < ARRAY_SIZE; i++)
	{
		if(a[i-1] == a[i])
		{
			matchIndex = i - 1;
			printf("Found at least two elements match starting at index [%d] = %d.\n", matchIndex, a[matchIndex]);
			break;
		}
	}
	if (matchIndex == -1) printf("No matching elements found.\n");
	return 0;
}
