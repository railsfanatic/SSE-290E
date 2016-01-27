/*	HOMEWORK 1.3
	seconds.c:  Prompts user for a number of seconds; converts and
		prints it in:  h:mm:ss  (ex: 87654 to 24:20:54)
	Tom Grushka
	Jan. 26, 2016 */

#include <stdio.h>
#include <stdlib.h> 	// use atoi()
#include <string.h> 	// use strcmp()

/*  Function definitions  */
int getInteger(char* prompt); 		// input wrapper function
const char* timeCode(int seconds); 	// timeCode formatter function
int runTests(); 					// testing subroutine

int main(int argc, char *argv[])
{
	int	intSec = 0;  // input seconds
	
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
		Check for "unreasonable" values (< 0 or > 999:59:59):  */
	intSec = getInteger("Please enter number of seconds: ");
	if (intSec < 0) intSec = 0;
	if (intSec > 3599999) intSec = 359999;
	
	// OUTPUT the final time code in the desired format:
	printf("%d Seconds to Timecode: \n\n\t%s\n\n", intSec, timeCode(intSec));
	
	#ifdef _MSC_VER	// Extra pause (Visual Studio only)
		// http://c-faq.com/stdio/stdinflush2.html
		int c = 0;
		while((c = getchar()) != '\n' && c != EOF)
			/* discard */ ;
		getchar();
	#endif
	return 0;	// Exit program with no error
}

/*	timeCode:  function that calculates, formats & returns the Timecode
	Argument:		int seconds = number of seconds to convert to h:mm:ss
	Returns:		const char* of the time code in desired format	*/
const char* timeCode(int seconds)
{
	int h = 0, 		// hours
		m = 0, 		// minutes
		s = 0;		// seconds
	static char buffer[10];	// pass to snprintf to store formatted string for return
	
	h = seconds / 3600;					// Calculate # of whole hours
	m = (seconds % 3600) / 60;			// Calculate # of remaining whole minutes
	s = seconds - (h * 3600 + m * 60);	// Calculate # of remaining seconds
	
	// Format the Timecode and store in buffer:
	snprintf(buffer, 10, "%d:%02d:%02d", h, m, s);
	
	return buffer;
}

/*	getInteger input wrapper:
	Argument:		char* prompt: string for user prompt
	Returns:		integer (converted from input string)	*/
int getInteger(char* prompt)
{
	char numString[8];				// variable to store input
	printf("%s", prompt);			// prompt user
	fgets(numString, 8, stdin);		// get input as string
	return atoi(numString);  		// stdlib fn converts string to integer
}

/*	runTests:
	Argument:		none
	Returns:		number of failed tests (0 for all pass)	*/
int runTests()
{
	// Visual Studio does not allow dimming arrays with a const!
	#define NUM_TESTS 6
	
	// Some human determined values and expected results
	int testInputs[NUM_TESTS] = {
			    0,			  100,			 501,
			 3600,			11234,			87654
	};
	char* testResults[NUM_TESTS] = {
		 "0:00:00",		 "0:01:40",		 "0:08:21",
		 "1:00:00",		 "3:07:14",		 "24:20:54"
 	};
	const char* testCode;	// Store result of timeCode fn
	int pass;				// Store result of string comparison
	int failedCount = 0;	// Count failed tests
	
	printf(" #    Seconds      Should be         Result  Pass?\n");
	for (int i = 0; i < NUM_TESTS; i++) {
		testCode = timeCode(testInputs[i]);		// run the actual test
		pass = (strcmp(testCode, testResults[i]) == 0);
		failedCount += !pass;	// Increment counter if test does NOT pass
		printf("%2d %10d %14s %14s %4d \n", i, testInputs[i], testResults[i], testCode, pass);
	}
	printf("\n");	// Summarize & return
	printf("%d Passed, %d Failed\n\n", (NUM_TESTS - failedCount), failedCount);
	return failedCount;
}
