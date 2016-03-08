#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void reverseArray(int size, int *a)
{
	int i = 0;
	int b[size];
	for (i = 0; i < size; i++) b[size-i-1] = a[i];
	for (i = 0; i < size; i++) a[i] = b[i];
}

void fillRandom(int size, int *array)
{
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
}

void printArray(int size, int *array)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("[%d]\t%d\n", i, array[i]);
	}
	printf("\n");
}

int findLowest(int size, int *array)
{
	int i = 0;
	int lowest = 0;
	for (i = 0; i < size; i++)
	{
		if (array[i] < array[lowest]) lowest = i;
	}
	return lowest;
}

void bubbleSort(int size, int *a)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] > a[i+1]) {
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
}

/* private funcs for mergeSort */

void copyArray(int *b, int iBegin, int iEnd, int *a)
{
	int k = 0;
	for (k = iBegin; k < iEnd; k++)
	{
		a[k] = b[k];
	}
}

void topDownMerge(int *a, int iBegin, int iMiddle, int iEnd, int *b)
{
	int i = iBegin;
	int j = iMiddle;
	int k = 0;
	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || a[i] <= a[j]))
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
	}
}

void splitMerge(int *a, int iBegin, int iEnd, int *b)
{
	if (iEnd - iBegin < 2) return;
	int iMiddle = (iEnd + iBegin) / 2;
	splitMerge(a, iBegin, iMiddle, b);
	splitMerge(a, iMiddle, iEnd, b);
	topDownMerge(a, iBegin, iMiddle, iEnd, b);
	copyArray(b, iBegin, iEnd, a);
}

void mergeSort(int size, int *array)
{
	int work[size];
	splitMerge(array, 0, size, work);
}



