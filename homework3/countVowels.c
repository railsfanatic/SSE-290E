/*	HOMEWORK 3
	File:	countVowels.c
	Module:	Homework 3.5: Count Vowels
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "common.h"

int runCountVowels()
{
	// declarations
	char *s;  // init pointer to the entered string
	char *i;  // init pointer that loops through s
	int count = 0;  // init & set vowel counter to 0
	
	// print banner
	printf("5. COUNT THE VOWELS\n\n");
	printf("Prompts the user for a string and then counts all the vowels\n"
		"in the string and prints the count.\n\n");
	
	// get string input
	s = getString(255, "Please enter a string (up to 255 characters):\n");
	
	/*	set pointer i to the beginning of s; increment i
		through s until we reach its null terminator	*/
	for (i = s; *i != 0; i++)
	{
		/*	compare the lower case character at pointer i to
			list of vowels; increment counter if match	*/
		if (strchr("aeiou", tolower(*i))) count++;  // increment vowel counter
	}
	
	// print number of vowels
	printf("The entered string has %d vowels.\n", count);
	
	return 0;
}
