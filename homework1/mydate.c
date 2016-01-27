/*	HOMEWORK 1.1
	mydate.c:  Prompts user for a month, day and year and prints
		the input date in the format:  xx/xx/xxxx  (ex: 8/24/2014)
	Tom Grushka
	Jan. 26, 2016 */

#include <stdio.h>
#include <stdlib.h>

int getInteger(char* prompt); // define input wrapper

int main()
{
	int m = 0, 		// month
		d = 0, 		// day
		y = -9999;	// year (set initially to an "unreasonable" value so that it prompts)
	
	/*	Input month, day, and year using an input wrapper;
		Loop each input until "reasonable" value entered.		*/
	while (m < 1 || m > 12) {
		m = getInteger("Month: ");
	}
	while (d < 1 || d > 31) {
		d = getInteger("Day: ");
	}
	while (y < -8000 || y > 9999) {
		/*	This program assumes it will be obsolete in 8,000 years,
			and the oldest known calendar is 10,000 years old.  */
		y = getInteger("Year: ");
	}
	
	// Output the date in the desired format: #/#/####
	printf("Date entered: %d/%d/%04d\n", m, d, y);
	
	#ifdef _MSC_VER	// Extra pause (Visual Studio only)
		// http://c-faq.com/stdio/stdinflush2.html
		int c = 0;
		while((c = getchar()) != '\n' && c != EOF)
			/* discard */ ;
		getchar();
	#endif
	return 0;	// Exit program with no error
}

/*	getInteger input wrapper:
	Argument:		char* prompt: string for user prompt
	Returns:		integer (converted from input string)	*/
int getInteger(char* prompt)
{
	char numString[7];				// variable to store input
	printf("%s", prompt);			// prompt user
	fgets(numString, 10, stdin);	// get input as string
	return atoi(numString);  		// stdlib fn converts string to integer
}