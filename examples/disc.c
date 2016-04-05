#include <stdio.h>
#include <math.h>

void disc(double radius, double *area, double *circum)
{
	*area = M_PI * pow(radius, 2);
	*circum = M_PI * 2 * radius;
}

int main()
{
	double radius;
	double area;     // don't declare as pointers
	double circum;
	printf("Enter the radius: ");
	scanf("%lf", &radius);
	// just pass the pointers using &
	disc(radius, &area, &circum);
	printf("Radius = %lf\n", radius);
	printf("Area = %lf\n", area);
	printf("Circumference = %lf\n", circum);
	return 0;
}



