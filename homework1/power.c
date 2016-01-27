/*	HOMEWORK 1.2
	power.c:  Prompts user for a Voltage and Resistance;
		Calculates Current and Power dissipated by resistor.
		Ohm's law:	I = V/R
		Power: 		P = VI
	Tom Grushka
	Jan. 27, 2016 */

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
	
	while (1) {
		// INPUT the Voltage and Resistance as float values
		v = getFloat("Voltage (V) (0 to quit): ");
		
		if (v == 0) break;
		
		r = getFloat("Resistance (Ohm): ");
	
		// CALCULATE the Current and Power
		i = calcCurrent(v, r);
		p = calcPower(v, i);
	
		// OUTPUT the final data:
		printf("For a given %.2f V applied to a %.2f-Ohm resistor,\n", v, r);
		printf("the current is %.2f A and the power dissipated is %.2f W.\n\n", i, p);
	}
	
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
	float test_values[] = {
	//	Volts,  Resistance,  Current (Expected),  Power (Expected)
	//	TEST PROBLEMS from http://www.allaboutcircuits.com/textbook/direct-current/chpt-2/calculating-electric-power/:
		   18,			 3,					  6,			   108,
		   36,			 3,					 12,			   432,
	//	TEST PROBLEMS from https://www.grc.nasa.gov/www/k-12/Sample_Projects/Ohms_Law/ohmslaw.html:
		    9,			18,				    0.5,			   4.5,
		  110,	 	  2200,				   0.05,			   5.5,
		  4.0,			40,				    0.1,			   0.4,
		  0
	};
	int 	index = 0,
			failedCount = 0;
	float	v = 0.0,	// input voltage
			r = 0.0,	// input resistance
			i_exp = 0.0,	// expected current
			p_exp = 0.0,	// expected power
			i_calc = 0.0,	// actual (calculated) current
			p_calc = 0.0;	// actual (calculated) power
	int 	pass = 0;
	printf("\033[0m");
	printf("     Volts  Resistance  Current(Exp)   Power(Exp)  Current(Act)  Power(Act)  Pass?\n");
	while (test_values[index] > 0) {
			 v = test_values[index];
			 r = test_values[index+1];
		 i_exp = test_values[index+2];
		 p_exp = test_values[index+3];
		i_calc = calcCurrent(v, r);
		p_calc = calcPower(v, i_calc);
		  pass = (i_calc == i_exp && p_calc == p_exp);
		
		if (pass) printf("\x1B[32m"); else printf("\x1B[31m");
		printf("%10.2f  %10.2f    %10.2f  %10.2f     %10.2f  %10.2f      %d\n", v, r, i_exp, p_exp, i_calc, p_calc, pass);
		
		index += 4;
		failedCount += !pass;
	}
	
	printf("\033[0m");
	
	int total = index / 4;
	printf("Exp = Expected value, Act = Actual value.\n\n");
	printf("%d tests run;  %d Passed,  %d Failed.\n\n", total, total - failedCount, failedCount);
	
	return failedCount;
}
