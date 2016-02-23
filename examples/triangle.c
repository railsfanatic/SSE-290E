#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	int sum = 0;
	
	do {
		printf("Enter n: ");
		scanf("%d", &n);
	} while (n < 1);
	
	for (int i = 1; i <= n; i ++)
	{
		sum += i;
		for (int j = 0; j < n-i; j++) printf(" ");
		for (int j = 0; j < i; j++) printf("* ");
		printf("\n");
	}
	
	printf("Total: %d\n", sum);
}
