#include <stdio.h>
#include "common.h"

int runSmallestRandomNumber() {
	printf("SMALLEST RANDOM NUMBER\n\n");
	printf("Fill an array with random integers and then find the position of the smallest element in the array. It should also print the value of the smallest number.\n\n");
	int a[ARRAY_SIZE];
	int index = 0;
	fillRandom(ARRAY_SIZE, a);
	printArray(ARRAY_SIZE, a);
	index = findLowest(ARRAY_SIZE, a);
	printf("The smallest value is [%d] = %d\n", index, a[index]);
	return 0;
}
