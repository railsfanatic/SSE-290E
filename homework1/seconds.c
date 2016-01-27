/*	HOMEWORK 1.3
	seconds.c:  Prompts user for a number of seconds; converts and
		prints it in:  h:mm:ss  (ex: 87654 to 24:20:54)
	Tom Grushka
	Jan. 26, 2016 */

#include <stdio.h>
#include <stdlib.h> 	// use atoi()
#include <string.h> 	// use strcmp()

/*  function definitions  */
int getInteger(char* prompt); 		// input wrapper function
const char* timeCode(int seconds); 	// timeCode formatter function
int runTests(); 					// testing subroutine

int main(int argc, char *argv[])
{
	int	intSec = 3600000;  // input seconds (set to "unreasonable" value)
	
	/*	TESTING:
		Run the program with -t option to test  */
	if (argc == 2 && strcmp(argv[1], "-t") == 0) {
		int failedCount = runTests();
		#ifdef _MSC_VER	// Extra pause (Visual Studio only)
			getInteger("");
		#endif
		return failedCount;  // return number of failed tests
	}
	
	/*	INPUT number of seconds using an input wrapper;
		Check for "unreasonable" value (< –999:59:59 or > 999:59:59):  */
	while (intSec < -3599999 || intSec > 3599999) {
		intSec = getInteger("Please enter number of seconds: ");
	}
	
	// OUTPUT the final time code in the desired format:
	printf("Time code: %s\n\n", timeCode(intSec));
	
	#ifdef _MSC_VER	// Extra pause (Visual Studio only)
		getInteger("");
	#endif
	return 0;	// Exit program with no error
}

/*	timeCode:  function that generates the desired time format
	Argument:		int seconds = number of seconds
	Returns:		const char* of the time code in desired format	*/
const char* timeCode(int seconds)
{
	int h = 0, 		// hours
		m = 0, 		// minutes
		s = 0;		// seconds
	static char buffer[10];	// pass to snprintf to store formatted string for return
	
	h = seconds / 3600;					// Calculate # of hours
	m = (seconds % 3600) / 60;			// Calculate # of minutes
	s = seconds - (h * 3600 + m * 60);	// Calculate # of seconds
	
	/*	Format the time code based on whether or not we have
		hours and minutes components:	*/
	if (h > 0) {
		snprintf(buffer, 10, "%d:%02d:%02d", h, m, s);
	} else if (m > 0) {
		snprintf(buffer, 10, "%d:%02d", m, s);
	} else {
		snprintf(buffer, 10, "%02d", s);
	}
	
	return buffer;
}

/*	runTests:
	Argument:		none
	Returns:		number of failed tests (0 for all pass)	*/
int runTests()
{
	const int NUM_TESTS = 6;
	
	// Some human determined values and expected results
	int testInputs[NUM_TESTS] = {
			 100,			  500,			 3600,
			 9876,			11234,			87654
	};
	char* testResults[NUM_TESTS] = {
			"1:40",			"8:20",		  "1:00:00",
		 "2:44:36",		 "3:07:14",		 "24:20:54"
 	};
	const char* testCode;	// Store result of timeCode fn
	int pass;				// Store result of string comparison
	int failedCount = 0;
	
	printf(" #    Seconds      Should be         Result  Pass?\n");
	for (int i = 0; i < NUM_TESTS; i++) {
		testCode = timeCode(testInputs[i]);		// run the actual test
		pass = (strcmp(testCode, testResults[i]) == 0);
		failedCount += !pass;	// count number of failed tests
		printf("%2d %10d %14s %14s %4d \n", i, testInputs[i], testResults[i], testCode, pass);
	}
	printf("\n");
	printf("%d Passed, %d Failed\n\n", (NUM_TESTS - failedCount), failedCount);
	return failedCount;
}

/*	getInteger input wrapper:
	Argument:		char* prompt: string for user prompt
	Returns:		integer (converted from input string)	*/
int getInteger(char* prompt)
{
	char numString[7];				// variable to store input
	printf("%s", prompt);			// prompt user
	fgets(numString, 10, stdin);	// get input as string
	return atoi(numString);  	// stdlib fn converts string to integer
}
