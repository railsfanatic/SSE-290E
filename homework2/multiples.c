/*	HOMEWORK 2.1
	multiples.c:
	Prompts the user for a POSITIVE INTEGER limit and prints all
	multiples of 5 that DO NOT EXCEED the entered limit.
	Tom Grushka
	February 5, 2016	*/

#include <stdio.h>
#include <stdlib.h>

const int MULTIPLIER = 5;	// constant multiplier (5 given in assignment spec)

int getInteger(const char *prompt);

int main(int argc, char** argv)
{
	int limit = 0;		// user-specified positive integer to count up to
	int i = 0;			// counter
	int product = 0;	// product = counter * MULTIPLIER
	
	/*	Input loop: keep prompting user for limit until
		a reasonable value is entered. 	*/
	do {
		limit = getInteger("Enter an integer greater than zero: ");
	} while (limit <= 0);
	
	// Tell user what we're doing
	printf("\nCounting to %d by multiples of %d:\n", limit, MULTIPLIER);
	
	/*	Begin output loop:
		As long as i * MULTIPLIER <= limit ... */
	while (product <= limit) {
		printf("%5d * %1d = %7d\n", i, MULTIPLIER, product);  // pretty print
		i++;	// increment counter
		product = i * MULTIPLIER;	// calculate product
	}	// if while condition not met, stop looping
	
	if (limit % MULTIPLIER > 0)	// check for remainder
		// explain remainder to user
		printf("I cannot reach %d because it is not a multiple of %d.\n", limit, MULTIPLIER);
	
	return 0;	// We shouldn't have an error
}

/*	getInteger
	argument:	prompt (const char *)
				string to prompt the user
	return:		user input converted to integer	*/
int getInteger(const char *prompt)
{
	// Some code by David C. Rankin, http://stackoverflow.com/questions/27326839/how-to-read-input-of-unknown-length-using-fgets
	char *input = NULL;		// input buffer
	int myInt = 0;			// integer to return
    size_t n = 0;           // max chars to read (0 = no limit)
    ssize_t nchr = 0;       // # chars read
	
	printf("%s", prompt);	// Display the prompt
	
	if ((nchr = getline(&input, &n, stdin)) != -1)
		input[--nchr] = 0;	// strip newline
	
	myInt = atoi(input);	// convert to integer & store
	
	free(input);			// "de-allocate" input variable
	
	return myInt;			// return integer
}
