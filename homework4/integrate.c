#include <stdio.h>

#define NUM_POINTS 100

struct ACCEL
{
	double seconds;
	double acceleration;
};

void inputData(struct ACCEL *data, int *numPoints)
{
	double seconds;
	double acceleration;
	int scanned = 0;
	char c;
	int i = 0;
	
	printf("Enter: Seconds (decimal), Acceleration (decimal, m/s^2)\n");
	for (i = 0; i < *numPoints; i++)
	{
		scanned = 0;
		while (scanned != 2)
		{
			printf("%d.  ", i+1);
			scanned = scanf("%lf, %lf", &seconds, &acceleration);
			if (seconds == 0) scanned = 2;
			while ((c = getchar()) != '\n' && c != 0);
		}
		if (seconds == 0)
		{
			*numPoints = i;
			break;
		}
		data[i].seconds = seconds;
		data[i].acceleration = acceleration;
		printf("You entered %lf seconds at an acceleration of %lf m/s^2.\n", seconds, acceleration);
	}
}

void sortData(struct ACCEL *data, int numPoints)
{
	int i = 0;
	int sorted = 0;	// keep going through list if swap made
	struct ACCEL tempData; // temp variable to store data for swapping
	
	if (numPoints < 2) return;	// no need to sort 1 person
	while (!sorted)
	{
		sorted = 1; // assume sorted; as soon as swap made, set sorted = 0 (unsorted)
		// printf("Starting over.\n"); // diagnostic print
		for (i = 0; i < numPoints - 1; i++)
		{
			// if data[i+1].seconds < data[i].seconds, swap
			if (data[i+1].seconds < data[i].seconds)
			{
				// printf("Swapping data %d and %d\n", i, i+1); // diagnostic print
				tempData = data[i]; // swap using temporary variable
				data[i] = data[i+1];
				data[i+1] = tempData;
				sorted = 0; // we swapped, so assume we're not sorted
			}
		}
	}
}

void printData(struct ACCEL *data, int numPoints)
{
	int i = 0;
	printf("Time (s)\t\tAcceleration (m/s^2)\n");
	printf("========\t\t====================\n");
	
	for (i = 0; i < numPoints; i++)
	{
		printf("%7.4lf\t\t\t%7.4lf\n", data[i].seconds, data[i].acceleration);
	}
}

double integrate(struct ACCEL *data, int numPoints)
{
	int i = 0;
	double velocity = 0;
	double x1 = 0, x2 = 0;
	double y1 = 0, y2 = 0;
	
	if (numPoints < 2) return data[0].acceleration; // need at least 2 points to integrate
	for (i = 0; i < numPoints; i++)
	{
		x1 = (i > 0) ? data[i-1].seconds : 0;
		x2 = data[i].seconds;
		y1 = (i > 0) ? data[i-1].acceleration : 0;
		y2 = data[i].acceleration;
		
		// https://en.wikipedia.org/wiki/Trapezoidal_rule#Non-uniform_grid
		velocity += (x2 - x1) * (y2 + y1);
	}
	velocity /= 2;
	
	return velocity;
}

int main()
{
	struct ACCEL data[NUM_POINTS];
	int numPoints = NUM_POINTS;
	double result = 0;
	
	inputData(data, &numPoints);
	
	printf("\nYou entered the following acceleration data:\n\n");
	
	printData(data, numPoints);
	
	printf("\nSorting...\n");
	
	sortData(data, numPoints);
	printData(data, numPoints);
	
	printf("\nIntegrating...\n");
	
	result = integrate(data, numPoints);
	
	printf("\nThe resultant velocity is %lf m/s.\n", result);
	
	return 0;
}
