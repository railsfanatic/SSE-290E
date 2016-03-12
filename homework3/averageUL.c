/*	HOMEWORK 3
	File:	averageUL.c
	Module:	Homework 3.9: Average Upper Limit
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include "common.h"

/*	averageUL:	calculates the average of numbers at
	or below an upper limit
		inputs:	size (int) = size of the array
				a[size] (int) = array of integers
				limit (int) = the upper limit
		returns:	(double) average */
double averageUL(int size, int *a, int limit)
{
	int i = 0;	// loop counter
	int n = 0;	// count of numbers to average
	double average = 0;	// the average itself
	
	for (i = 0; i < size; i++)	// loop through array
	{
		if (a[i] <= limit) {	// if ith element <= limit
			average += a[i];	// add to average
			n++;				// increment # of elements in average
		}
	}
	if (n > 0) average /= n;	/* set average;
		simply avoid divide-by-zero if no elements found  */
	
	return average;	// return the result
}

int runAverageWithUpperLimit()
{
	int a[ARRAY_SIZE];
	double average = 0;	// for storing the average
	int limit = 0;		// for storing the limit
	
	printf("9. AVERAGE WITH UPPER LIMIT\n\n");
	printf("Function that accepts an array of integers and an upper limit\n"
		"as its parameters and returns the average of all the elements with\n"
		"values less than or equal to the upper limit.\n\n");
	
	// fill & print an array with random numbers
	fillRandom(ARRAY_SIZE, a, -1000, 1000);
	printArray(ARRAY_SIZE, a);
	
	// get upper limit from the user
	limit = getInteger("Enter upper limit: ");
	
	// calculate the average with upper limit
	average = averageUL(ARRAY_SIZE, a, limit);
	
	// print the result
	printf("The average of the numbers less than %d in the above array is %0.2lf.\n", limit, average);
	
	return 0;
}
