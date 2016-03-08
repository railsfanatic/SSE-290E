#include <stdio.h>
#include <math.h>

float hypotenuse(float a, float b)
{
	return sqrt(pow(a, 2) + pow(b, 2));
}

void runHypotenuse()
{
	float a = 0, b = 0, c = 0;
	
	printf("HYPOTENUSE\n\n");
	printf("Function that calculates the floating-point hypotenuse\n"
		"of a right triangle given the two legs: c^2 = a^2 + b^2.\n\n");
	
	printf("Please enter side A: ");
	scanf(" %f", &a);
	
	printf("Please enter side B: ");
	scanf(" %f", &b);
	
	c = hypotenuse(a, b);
	
	printf("The hypotenuse is %f.\n", c);
}
