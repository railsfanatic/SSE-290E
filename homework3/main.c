#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "smallestRandomNumber.h"
#include "randomAndReverse.h"
#include "findAdjacentMatch.h"
#include "guessPassword.h"
#include "countVowels.h"
#include "averageUL.h"
#include "palindrome.h"
#include "hypotenuse.h"
#include "factorial.h"

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

int main(int argc, char **argv)
{
	int choice = 0;
	int quit = 0;
	
	do {
		if (argc == 2 && argv[1])
		{
			if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
			{
				printMenu();
				break;
			}
			choice = atoi(argv[1]);
			quit = 1;
		}
		else
		{
			printMenu();
			choice = getInteger("Please enter a number (1-9, 0 to quit). ");
			printf("\n\n");
		}
		
		switch(choice)
		{
			case 1:
				runSmallestRandomNumber();
				break;
			case 2:
				runRandomAndReverse();
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
				exit(0);
				break;
		}
		
		getString(1, "\nPress Enter/Return to continue. ");
	} while (quit == 0);
	return 0;
}
