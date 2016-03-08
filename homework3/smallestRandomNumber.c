#include <stdio.h>
#include "common.h"

int runSmallestRandomNumber() {
	printf("SMALLEST RANDOM NUMBER\n\n");
	printf("Fills an array with random integers and then finds the\n"
		"position of the smallest element in the array. Prints the\n"
		"value of the smallest number.\n\n");
	int a[ARRAY_SIZE];
	int index = 0;
	fillRandom(ARRAY_SIZE, a, -1000, 1000);
	printArray(ARRAY_SIZE, a);
	index = findLowest(ARRAY_SIZE, a);
	printf("The smallest value is a[%d] = %d\n", index, a[index]);
	return 0;
}
