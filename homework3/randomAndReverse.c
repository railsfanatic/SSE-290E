#include <stdio.h>
#include "common.h"

int runRandomAndReverse() {
	printf("2. RANDOM AND REVERSE\n\n");
	printf("Fills an array with random integers and then prints the array.\n"
		"Reverses the elements in the array (in-place without creating\n"
		"a second array) and prints it again.\n\n");
	int a[ARRAY_SIZE] = {0};
	fillRandom(ARRAY_SIZE, a, -1000, 1000);
	printf("Random array:\n");
	printArray(ARRAY_SIZE, a);
	reverseArray(ARRAY_SIZE, a);
	printf("Reversed array:\n");
	printArray(ARRAY_SIZE, a);
	return 0;
}
