/*	HOMEWORK 5.1
	grow.c
	Grows an array dynamically.
	by Tom Grushka
	April 18, 2016	*/

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5

int main()
{
	int *a = malloc(INITIAL_SIZE * sizeof(int));
	int arraySize = INITIAL_SIZE;
	int *a_start = a;
	int *new;
	int *new_start;
	
	do {
		scanf("%d", a);
		a++;
		if (a - a_start == arraySize)
		{
			new = malloc(2 * arraySize * sizeof(int));
			new_start = new;
			for (a = a_start; a - a_start < arraySize; a++)
			{
				*new = *a;
				new++;
			}
			free(a_start);
			a_start = new_start;
			a = a_start + arraySize;
			arraySize *= 2;
			printf("Grew array to %d\n", arraySize);
		}
	} while (1);
	
	return 0;
}
