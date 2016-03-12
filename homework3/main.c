/*	HOMEWORK 3
	File:	main.c
	Module:	Homework 3 MAIN PROGRAM & Menu
	by Tom Grushka
	Mar. 11, 2016
	
	NOTE: HOMEWORK 3 is set up as a single large
	program with a menu for selection and "module"
	for each of the 1-9 problems.
	
	Each "module" could easily be made its own
	program by redefining its run(ModuleName)
	function to main() and compiling it separately.
	
	Example:
		1. In hypotenuse.c and hypotenuse.h, change:
			int runHypotenuse() to int main()
		2. Execute:
			cc hypotenuse.c common.c -o hypotenuse
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include header for common functions
#include "common.h"

// include modules for 9 parts of homework 
#include "smallestRandomNumber.h"	// 3.1
#include "randomReverse.h"			// 3.2
#include "findAdjacentMatch.h"		// 3.3
#include "password.h"				// 3.4
#include "countVowels.h"			// 3.5
#include "palindrome.h"				// 3.6
#include "hypotenuse.h"				// 3.7
#include "factorial.h"				// 3.8
#include "averageUL.h"				// 3.9

// print the menu
void printMenu()
{
	printf("\n\nHOMEWORK 3\n==========\n\n"
		"1.  Smallest Random Number\n\n"
		"2.  Random and Reverse\n\n"
		"3.  Find Adjacent Match\n\n"
		"4.  Guess the Password\n\n"
		"5.  Count the Vowels\n\n"
		"6.  Palindrome\n\n"
		"7.  Hypotenuse\n\n"
		"8.  Factorial\n\n"
		"9.  Average with Upper Limit\n\n");
}

/*	main program:
		if argument passed:
			run corresponding module and quits;
		else:
			print menu;
			input choice from user;
			run corresponding module;
			repeat
*/
int main(int argc, char **argv)
{
	// declarations
	int choice = 0;		// user selection
	int quit = 0;		// flag whether to stop looping
	
	do {
		// check if argument passed
		if (argc == 2 && argv[1])
		{
			// if -h or --help, print menu and quit
			if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
			{
				printMenu();
				break;
			}
			// set user choice and quit flag, then proceed to switch
			choice = atoi(argv[1]);
			quit = 1;
		}
		else	// no argument
		{
			// print menu, input choice, proceed to switch
			printMenu();
			choice = getInteger("Please enter a number (1-9, 0 to quit). ");
			printf("\n\n");
		}
		
		// execute user selected program
		switch(choice)
		{
			case 1:
				runSmallestRandomNumber();
				break;
			case 2:
				runRandomReverse();
				break;
			case 3:
				runFindAdjacentMatch();
				break;
			case 4:
				runGuessPassword();
				break;
			case 5:
				runCountVowels();
				break;
			case 6:
				runPalindrome();
				break;
			case 7:
				runHypotenuse();
				break;
			case 8:
				runFactorial();
				break;
			case 9:
				runAverageWithUpperLimit();
				break;
			default:
				printf("Goodbye!\n\n");
				quit = 1;
				break;
		}
		
		// only prompt user to continue if not quitting
		if (!quit) getString(1, "\nPress Enter/Return to continue. ");
	} while (quit == 0);  // loop while not quitting
	
	return 0;
}
