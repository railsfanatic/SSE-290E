/*	HOMEWORK 3
	File:	smallestRandomNumber.c
	Module:	Homework 3.1: Smallest Random Number
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include "common.h"

int runSmallestRandomNumber() {
	// declarations
	int a[ARRAY_SIZE] = {0}; // array of integers
	int index = 0; // index of smallest value
	
	// print banner
	printf("1. SMALLEST RANDOM NUMBER\n\n");
	printf("Fills an array with random integers and then finds the\n"
		"position of the smallest element in the array. Prints the\n"
		"value of the smallest number.\n\n");
	
	// fill & print array with random ints
	fillRandom(ARRAY_SIZE, a, -1000, 1000);
	printArray(ARRAY_SIZE, a);
	
	// set index of smallest value
	index = findLowest(ARRAY_SIZE, a);
	
	// print the result
	printf("The smallest value is a[%d] = %d\n", index, a[index]);
	return 0;
}
