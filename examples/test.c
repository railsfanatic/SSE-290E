#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	// your code goes here
	int a[255] = {};
	a[0] = 17;
	a[1] = 5;
	a[2] = 8;
	a[3] = 7;
	printf("size: %lu\n", sizeof(a)/sizeof(a[0]));
	return 0;
}
