#include <stdio.h>
#include <stdlib.h>
double func(int n, double *a);

int main()
{
	double a[5] = {1, 2, 3, 4, 5};
	double b[6] = {1, 2, 3, 4, 5, 6};
	double c[2][3] = {1, 2, 3, 4, 5, 6};
	double sum;
	
	sum = func(5, a);
	printf("sum = %f\n", sum);
	
	sum = func(6, &b[0]);
	printf("sum = %f\n", sum);
	
	sum = func(2*3, c[0]);
	printf("sum = %f\n", sum);
	
	return 0;
}

double func(int n, double *a)
{
	double sum = 0;
	int i;
	
	for (i=0; i<n; i++)
	{
		sum += *(a+i);
	}
	
	return sum;
}