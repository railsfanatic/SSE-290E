#include <stdio.h>
#include <math.h>

int main()
{
	double x = 0;
	double n = 0;
	double sum = 0;
	int i = 0;
	
	printf("Enter x:\n");
	scanf("%lf", &x);
	
	printf("Enter n:\n");
	scanf("%lf", &n);
	
	for (i = 0; i <= n; i++)
	{
		sum += pow(x, i);
	}
	
	printf("%.0lf\n", sum);
	
	return 0;
}	
