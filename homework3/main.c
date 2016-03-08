#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "menu.h"
#include "smallestRandomNumber.h"
#include "randomAndReverse.h"
#include "hypotenuse.h"
#include "factorial.h"

int main(int argc, char **argv)
{
	int choice = 0;
	int quit = 0;
	
	do {
		printf("\n\nHOMEWORK 3 MENU\n===============\n\n"
		
			"1.  Smallest Random Number\n\n"
			"2.  Random and Reverse\n\n"
			"3.  Find Adjacent Match\n\n"
			"4.  Guess the Password\n\n"
			"5.  Count the Vowels\n\n"
			"6.  Palindrome\n\n"
			"7.  Hypotenuse\n\n"
			"8.  Factorial\n\n"
			"9.  Average with Upper Limit\n\n\n"
		
			"Please enter a number (1-9, 0 to quit). ");
	
		scanf(" %d", &choice);
		printf("\n\n");
	
		switch(choice)
		{
			case 1:
				runSmallestRandomNumber();
				break;
			case 2:
				runRandomAndReverse();
				break;
			case 3:
				//runFindAdjacentMatch();
				break;
			case 4:
				//runGuessThePassword();
				break;
			case 5:
				//runCountTheVowels();
				break;
			case 6:
				//runPalindrome();
				break;
			case 7:
				runHypotenuse();
				break;
			case 8:
				runFactorial();
				break;
			case 9:
				//runAverageWithUpperLimit();
				break;
			default:
				printf("Goodbye!\n\n");
				quit = 1;
				exit(0);
				break;
		}
		getchar();
		getchar();
	} while (quit == 0);
	return 0;
}
