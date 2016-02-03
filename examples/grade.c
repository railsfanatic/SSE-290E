/*	grade.c:
	Display letter grade for entered mark.
	by Tom Grushka
	February 1, 2016	*/

#include <stdio.h>
#include <stdlib.h>

/*  Function definitions  */
double getDouble(char* prompt); 		// input wrapper function

int main(int argc, char* argv[])
{
	double mark;
	char buffer[10];
	char* grade;
	
	if (!argv[1]) {
		mark = getDouble("Please enter a mark: ");
	} else {
		mark = atof(argv[1]);
	}
	
	printf("Mark: %.03f\n", mark);
	
	if (mark <= 100.0 && mark >= 90.0) {
		grade = "A";
	} else if (mark >= 80.0) {
		grade = "B";
	} else if (mark >= 70.0) {
		grade = "C";
	} else if (mark >= 60.0) {
		grade = "D";
	} else if (mark >= 0.0 && mark < 60) {
		grade = "F";
	} else {
		grade = "Invalid mark entered.";
	}
	printf("Grade: %s\n", grade);
}

/*	getDouble input wrapper:
	Argument:		char* prompt: string for user prompt
	Returns:		double (converted from input string)	*/
double getDouble(char* prompt)
{
	char numString[10];				// variable to store input
	printf("%s", prompt);			// prompt user
	fgets(numString, 10, stdin);	// get input as string
	return atof(numString);  		// stdlib fn converts string to double
}
