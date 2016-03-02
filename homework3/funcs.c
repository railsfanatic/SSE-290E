#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillRandom(int size, int *array)
{
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		array[i] = rand();
	}
}

void printArray(int size, int *array)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("[%d]\t%d\n", i, array[i]);
	}
}