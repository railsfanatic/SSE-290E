/*	HOMEWORK 3
	File:	hypotenuse.c
	Module:	Homework 3.7: Calculate Hypotenuse
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include <math.h>
#include "common.h"

float hypotenuse(float a, float b)
{
	return sqrt(pow(a, 2) + pow(b, 2));
}

int runHypotenuse()
{
	// declarations
	float a = 0, b = 0, c = 0;	// legs a, b, and c of triangle
	
	// print banner
	printf("7. HYPOTENUSE\n\n");
	printf("Function that calculates the floating-point hypotenuse\n"
		"of a right triangle given the two legs: c^2 = a^2 + b^2.\n\n");
	
	// input leg a
	a = getInteger("Please enter side A: ");
	
	// input leg b
	b = getInteger("Please enter side B: ");
	
	// calculate hypotenuse
	c = hypotenuse(a, b);
	
	// print hypotenuse
	printf("The hypotenuse is %f.\n", c);
	
	return 0;
}
