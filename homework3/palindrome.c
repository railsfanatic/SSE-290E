/*	HOMEWORK 3
	File:	palindrome.c
	Module:	Homework 3.6: Palindrome
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "common.h"

/*	strAlphaNumericLower: returns only the lowercase alphanumeric characters of a string
		in: str (char *):		string to reverse
		returns:	(char *):	reversed string
		from: http://stackoverflow.com/questions/1726302/removing-spaces-from-a-string-in-c
*/
char *strAlphaNumericLower(char *s)
{
	char *q = (char *)malloc(strlen(s));	// allocate new string
	q = strdup(s);	// duplicate passed in string
	
	// initialize two pointers at start of s
	char *i = q, *j = q;
	
	while (*j != 0)  // until null terminator
	{
		// set *i to lowercase of next *j
		*i = tolower(*j++);
		if ((*i >= 48 && *i <= 57) || (*i >= 97 && *i <= 122)) // if *i is a letter
			i++; // increment pointer
	}
	*i = 0; // set null terminator of stripped string
	
	return q;
}

/*	isPalindrome: converts string to alphanumeric only, downcase,
		removes whitespace; determines if palindrome
		in: p (char *):		string to check
		returns:	int:	1 if palindrome, 0 if not
*/
int isPalindrome(char *p)
{
	char *r;	// store the reverse
	char *s = strAlphaNumericLower(strdup(p));	// convert to alphanumeric
	r = strrev(s);
	//printf("%s\n%s\n%d\n", s, r, strcmp(r, s));
	return (strcmp(r, s) == 0);
}

/*	runPalindrome:	palindrome checker subroutine	*/
int runPalindrome() {
	// declarations
	char *p;	// pointer to start of user string
	char *t;	// pointer to start of test string
	char *is_isnot;	// display string for is/is not
	
	// print banner
	printf("6. PALINDROME\n\n");
	printf("Prompts you for a string and then tests to see if it is a palindrome.\n"
		"Prints a message based on the results. (A palindrome is a word or\n"
		"phrase that is spelled the same forwards as backwards.\n"
		"For example \"racecar\" is a palindrome.)\n\n");
	
	// get user string
	p = getString(255, "");
	
	// set test string
	t = strAlphaNumericLower(p);
	
	// set display string for is or is not
	is_isnot = isPalindrome(p) ? "IS" : "is NOT";
	
	// print output
	printf("The string:\n\n\t%s\n\t(%s)\n\n%s a palindrome.\n", p, t, is_isnot);
	
	return 0;
}
 