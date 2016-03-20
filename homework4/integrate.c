/*	HOMEWORK 4.2
	Filename: integrate.c
	Description: Allows user to enter up to NUM_POINTS
		of (time, acceleration) pairs
		(units: seconds, m/s^2)
		into an array of structs, then integrates using
		the trapezoidal rule to get the final velocity.
		Assumes (0, 0) for starting time & velocity.
		Enter 0 for time to stop.
	by Tom Grushka
	3/17/2016
*/

#include <stdio.h>

#define NUM_POINTS 100

// struct to store an acceleration data point
struct ACCEL
{
	double seconds;
	double acceleration;
};

/*	inputData
	function to get acceleration data from user
	in:  data (pointer to struct ACCEL) - holds the data
	     numPoints (pointer to int) - max # of points to input
	out: *data - array of acceleration data
	     *numPoints - updated to actual # of points
*/
void inputData(struct ACCEL *data, int *numPoints)
{
	double seconds;		// stores seconds input
	double acceleration;  // stores acceleration input
	int numValuesEntered = 0;  // for each point we need 2 values
	char c;		// temporary variable to clear input buffer
	int i = 0;	// counter variable
	
	// print header & begin loop (up to max # of points)
	printf("Enter: Seconds (decimal), Acceleration (decimal, m/s^2), 0 to stop.\n");
	for (i = 0; i < *numPoints; i++)
	{
		numValuesEntered = 0;
		// data entered in pairs separated by comma;
		// numValuesEntered must = 2 for each point except when stopping
		while (numValuesEntered != 2)
		{
			printf("%d.  ", i+1);
			// scanf returns # of values entered
			numValuesEntered = scanf("%lf, %lf", &seconds, &acceleration);
			// if stopping (seconds == 0), trick our while loop
			// to think we've entered 2 values
			if (seconds == 0) numValuesEntered = 2;
			// clear input buffer
			while ((c = getchar()) != '\n' && c != 0);
			// print "redo" message to user
			if (numValuesEntered != 2) printf("Please type exactly two values.\n");
		}
		if (seconds == 0)	// stopping
		{
			*numPoints = i;
			break;
		}
		// add entered values to data array
		data[i].seconds = seconds;
		data[i].acceleration = acceleration;
		// printf("You entered %lf seconds at an acceleration of %lf m/s^2.\n", seconds, acceleration);
	}
}

/*	sortData
	function to sort acceleration data by # of seconds
	(needed to integrate with trapezoidal rule)
	in:  data (pointer to struct ACCEL) - holds the data
	     numPoints (int) - # of points
	out: *data - sorted data
*/
void sortData(struct ACCEL *data, int numPoints)
{
	int i = 0;	// counter variable
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

/*	printData
	function to print array of acceleration data
	in:  data (pointer to struct ACCEL) - array of acceleration data
	     numPoints (pointer to int) - # of data points
	out: no changes to *data
*/
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

/*	integrate
	function to integrate the array using trapezoidal rule
	in:  data (pointer to struct ACCEL) - array of acceleration data
	     (assumes *data is sorted)
	     numPoints (int) - # of data points
	out: (double) - velocity - the integration result
*/
double integrate(struct ACCEL *data, int numPoints)
{
	int i = 0;		// counter variable
	double velocity = 0;	// result = integration sum
	double x1 = 0, x2 = 0;	// simplify actual trapezoidal
	double y1 = 0, y2 = 0;	// ... calculation
	
	// loop through the *data array
	for (i = 0; i < numPoints; i++)
	{
		// set bounds to simplify trapezoidal function
		x1 = (i == 0) ? 0 : data[i-1].seconds;
		x2 = data[i].seconds;
		y1 = (i == 0) ? 0 : data[i-1].acceleration;
		y2 = data[i].acceleration;
		
		// the actual trapezoidal rule calcuation
		// https://en.wikipedia.org/wiki/Trapezoidal_rule#Non-uniform_grid
		velocity += 0.5 * (x2 - x1) * (y2 + y1);
	}
	
	return velocity;	// return the result
}

/* * * * * * * * * * * * * * * * * * * * * * * * *
		Main Program
* * * * * * * * * * * * * * * * * * * * * * * * */
int main()
{
	// declarations
	struct ACCEL data[NUM_POINTS];	// array of structs of acceleration data points
	int numPoints = NUM_POINTS;		// # of data points
	double result = 0;				// store the result
	
	// get data from the user
	inputData(data, &numPoints);
	
	// confirm data the user entered
	printf("\nYou entered the following acceleration data:\n\n");
	printData(data, numPoints);
	
	// sort the data for proper trapezoidal integration
	// and print sorted data
	printf("\nSorting...\n");
	sortData(data, numPoints);
	printData(data, numPoints);
	
	// integrate the data using trapezoidal rule
	printf("\nIntegrating...\n");
	result = integrate(data, numPoints);
	
	// print resultant velocity
	printf("\nThe resultant velocity is %lf m/s.\n", result);
	
	return 0;	// exit without error
}