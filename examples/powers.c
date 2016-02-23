#include <stdio.h>
#include <math.h>

int power(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += pow(i, 2);
	}
	return sum;
}

int main()
{
	printf("Power series sum of %d: %d\n", 5, power(5));
	return 0;
}
