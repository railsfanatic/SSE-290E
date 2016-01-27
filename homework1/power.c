/*	HOMEWORK 1.2
	power.c:  Prompts user for a Voltage and Resistance;
		Calculates Current and Power dissipated by resistor.
		Ohm's law:	I = V/R
		Power: 		P = VI
	Tom Grushka
	Jan. 26, 2016 */

#include <stdio.h>
#include <stdlib.h> 	// use atof()
#include <string.h>		// strcmp() for argument check

/*  Function definitions  */
float getFloat(char* prompt); 		// input wrapper function
int runTests(); 					// testing subroutine
float calcCurrent(float voltage, float resistance);	// calculate the current
float calcPower(float voltage, float current);	// calculate the power

int main(int argc, char *argv[])
{
	float	v = 0.0,	// input voltage
			r = 0.0,	// input resistance
			i = 0.0,	// calculated current
			p = 0.0;	// calculated power
	
	/*	TESTING:
		Run the program with -t option to test  */
	if (argc == 2 && strcmp(argv[1], "-t") == 0) {
		int failedCount = runTests();
		#ifdef _MSC_VER	// Extra pause (Visual Studio only)
			getFloat("");
		#endif
		return failedCount;  // return number of failed tests
	}
	
	v = getFloat("Voltage (V): ");
	r = getFloat("Resistance (Ohm): ");
	
	i = calcCurrent(v, r);
	p = calcPower(v, i);
	
	// OUTPUT the final data:
	printf("For a given %.2f V applied to a %.2f-Ohm resistor,\n", v, r);
	printf("the current is %.2f A and the power dissipated is %.2f W.\n\n", i, p);
	
	#ifdef _MSC_VER	// Extra pause (Visual Studio only)
		// http://c-faq.com/stdio/stdinflush2.html
		int c = 0;
		while((c = getchar()) != '\n' && c != EOF)
			/* discard */ ;
		getchar();
	#endif
	return 0;	// Exit program with no error
}

float calcCurrent(float voltage, float resistance)
{
	if (resistance > 0) {
		return voltage / resistance;
	} else {
		return 0;
	}
}

float calcPower(float voltage, float current)
{
	return voltage * current;
}


/*	getFloat input wrapper:
	Argument:		char* prompt: string for user prompt
	Returns:		float (converted from input string)	*/
float getFloat(char* prompt)
{
	char numString[10];				// variable to store input
	printf("%s", prompt);			// prompt user
	fgets(numString, 10, stdin);	// get input as string
	return atof(numString);  		// stdlib fn converts string to float
}

/*	runTests:
	Argument:		none
	Returns:		number of failed tests (0 for all pass)	*/
int runTests()
{
	// Visual Studio does not allow dimming arrays with a const!
	#define NUM_TESTS 0
	return 0;
}
