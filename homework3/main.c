#include <sys/ioctl.h>
#include <unistd.h>

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int fact(int n)
{
	if (n == 0) return 1;
	return n*fact(n-1);
}

char pascal(int n)
{
	int r = 0;
	int result = 0;
	char *temp;
	
	for (r = 0; r <= n; r++)
	{
		result = fact(n)/(fact(r)*fact(n-r));
		//temp += sprintf(temp, "%d  ", result);
	}
	//*temp += sprintf("\n");
	return *temp;
}

int main(int argc, char **argv)
{
	int i = 0;
	int n = 0;
	
	int columns = strtol(getenv("COLUMNS"), NULL, 10);
	
	printf("Rows? ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - i); j++) printf(" ");
		
		pascal(i);
	}
	
	return 0;
}

/*
	Pascal's Triangle
	Binomial Expansion
	
*/
