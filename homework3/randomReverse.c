/*	HOMEWORK 3
	File:	randomReverse.c
	Module:	Homework 3.2: Random and Reverse
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include "common.h"

int runRandomReverse() {
	// declarations
	int a[ARRAY_SIZE] = {0}; // array of integers
	
	// print banner
	printf("2. RANDOM AND REVERSE\n\n");
	printf("Fills an array with random integers and then prints the array.\n"
		"Reverses the elements in the array (in-place without creating\n"
		"a second array) and prints it again.\n\n");
	
	// fill array with random ints & print
	fillRandom(ARRAY_SIZE, a, -1000, 1000);
	printf("Random array:\n");
	printArray(ARRAY_SIZE, a);
	
	// reverse the array
	reverseArray(ARRAY_SIZE, a);
	
	// print the result
	printf("Reversed array:\n");
	printArray(ARRAY_SIZE, a);
	return 0;
}
