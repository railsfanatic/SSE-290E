/*	HOMEWORK 3
	File:	password.c
	Module:	Homework 3.4: Guess the Password
	by Tom Grushka
	Mar. 11, 2016
*/

#include <stdio.h>

#if defined(POSIX) // getpass function to hide password entry
#include <unistd.h> // not available on Windows
#endif

#include <string.h>

#include "common.h"

// set the password as a constant
const char *PASSWORD = "Ins3curePassword";

/*	authPassword: authorizes an entered password
		in:	pass (char *) = pointer to entered password
		returns: (int) 1 if right, 2 if wrong
*/
int authPassword(char *pass)
{
	int correct = strcmp(pass, PASSWORD) == 0;
	return correct;
}

int runGuessPassword()
{
	// declarations
	char *pass;		// pointer to start of entered password
	int correct = 0; // flag for correct password
	
	// banner
	printf("4. GUESS THE PASSWORD\n\n");
	printf("Please type a password and I'll tell you if it is correct.\n\n");
	
	// start loop to enter/check password
	do {
		#if defined(POSIX)
			// hide input using getpass() from unistd library
			pass = getpass("Please enter the password. ");
		#else
			pass = getString(30, "Please enter the password. ");
		#endif
		
		// compare entered pass with PASSWORD constant
		correct = authPassword(pass);
		
		// if incorrect print try again message
		if (!correct) printf("\n\aIncorrect password. Please try again. (Hint: it's stored in plaintext in the program file.)\n\n");
	} while (!correct); // while incorrect
	
	// print welcome message
	printf("\nWELCOME! But there's no way you guessed that! You must have looked at the program file.\n");
	
	return 0;
}
 