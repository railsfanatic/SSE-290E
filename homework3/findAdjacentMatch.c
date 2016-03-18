/*	HOMEWORK 3
	File:	findAdjacentMatch.c
	Module:	Homework 3.3: Find First Adjacent Match
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include "common.h"

/*	firstAdjacentMatch: finds the first adjacent match index
		in:	size (int) = size of array
			a[size] = array of numbers to test
	returns:	index in a[] of first adjacent match
*/
int firstAdjacentMatch(int size, int *a)
{
	// declarations
	int matchIndex = -1;	// index of first adjacent match
	int i = 0;	// loop counter
	
	// loop through array starting at 2nd element
	for (i = 1; i < ARRAY_SIZE; i++)
	{
		if(a[i-1] == a[i])	// if this element = previous
		{
			matchIndex = i - 1; // set match index to previous & stop searching
			break;
		}
	}
	
	return matchIndex;
}

int runFindAdjacentMatch() {
	// declarations
	int matchIndex = -1;	// first index of adjacent match
	int a[ARRAY_SIZE] = {0};	// array of integers
	
	// print banner
	printf("3. FIND ADJACENT MATCH\n\n");
	printf("Allows you to enter values into an array. Finds the first pair of\n"
		"adjacent elements that are the same. Prints out the value of the identical\n"
		"elements and the position of the first element that is a match.\n\n");
	
	// input array from user
	inputArray(ARRAY_SIZE, a);
	
	// print the input array
	printf("You entered the following array:\n");
	printArray(ARRAY_SIZE, a);
	
	matchIndex = firstAdjacentMatch(ARRAY_SIZE, a);
	
	if (matchIndex >= 0)	// found a match!
		printf("Found at least two elements matching at index [%d] = %d.\n", matchIndex, a[matchIndex]);
	else // if match index still -1 then no matches
		printf("No matching elements found.\n");
	
	return 0;
}
