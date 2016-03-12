#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "common.h"

const char *PASSWORD = "Ins3curePassword";

int runGuessPassword()
{
	char *pass;
	int correct = 0;
	
	printf("4. GUESS THE PASSWORD\n\n");
	
	do {
		pass = getpass("Please enter the password. ");
		correct = strcmp(pass, PASSWORD) == 0;
		if (!correct) printf("\n\aIncorrect password. Please try again.\n\n");
	} while (!correct);
	
	printf("\nWELCOME! But there's no way you guessed that! You must have looked at the source code.\n");
	
	return 0;
}
 