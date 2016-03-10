#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "common.h"

char *getstr(int length, const char *prompt)
{
	char *s = (char *)malloc(length);
	
	getchar();
	fgets(s, length, stdin);
	s[strcspn(s, "\r\n")] = 0;
	
	return s;
}

// http://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux
char *strrev(char *str)
{
      char *p1, *p2;
	  char *rev;
	  
      if (! str || ! *str)
            return str;
      
	  rev = (char *)malloc(strlen(str));
	  strcpy(rev, str);
	  
	  for (p1 = rev, p2 = rev + strlen(rev) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return rev;
}

// http://stackoverflow.com/questions/1726302/removing-spaces-from-a-string-in-c
char *strAlpha(char *s)
{
	char *q = (char *)malloc(strlen(s));
	q = strdup(s);
	
	// initialize two pointers at start of s
	char *i = q;
	char *j = q;
	
	while (*j != 0)  // until null terminator
	{
		// set *i to lowercase of next *j
		*i = tolower(*j++);
		if (*i >= 97 && *i <= 122) // if *i is a letter
			i++; // increment pointer
	}
	*i = 0; // set null terminator of stripped string
	
	return q;
}

int isPalindrome(char *p)
{
	char *r;
	char *s = strAlpha(strdup(p));
	r = strrev(s);
	//printf("%s\n%s\n%d\n", s, r, strcmp(r, s));
	return (strcmp(r, s) == 0);
}

int runPalindrome() {
	char *p = (char *)malloc(255);
	
	printf("PALINDROME\n\n");
	printf("Prompts you for a string and then tests to see if it is a palindrome.\n"
		"Prints a message based on the results. (A palindrome is a word or\n"
		"phrase that is spelled the same forwards as backwards.\n"
		"For example \"racecar\" is a palindrome.)\n\n");
	
	p = getstr(255, "");
	
	printf("The string:\n\n\t%s\n\t%s\n\n%s a palindrome.\n", p, strAlpha(p), (isPalindrome(p) ? "IS" : "IS NOT"));
	
	exit(0);
	//if (isPalindrome(p)) printf("The string you entered is a palindrome!\n");
	//else printf("Sorry, that string is NOT a palindrome.\n");
	
	return 0;
}
 