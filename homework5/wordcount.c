/*	HOMEWORK 5.2
	wordcount.c
	Counts the number of words in a text file.
	by Tom Grushka
	April 18, 2016	*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// set default filename
#define DEFAULT_FILENAME "test.txt"

int main(int argc, char **argv)
{
	// declarations
	FILE *fp;				// file pointer
	char c;					// stores char as we loop through file
	int wordCount = 0;		// stores the word count
	int inWord = 0;			// flags that we are currently "in" a word
	char fileName[255];		// stores the filename
	
	if (argc == 1)	// no filename passed as argument
	{
		printf("Please enter the file name:\n");
		scanf("%s", fileName);
	}
	// filename passed as argument
	else strcpy(fileName, argv[1]);
	// blank filename -- set to default
	if (strcmp(fileName, "") == 0) strcpy(fileName, DEFAULT_FILENAME);
	
	printf("Counting words in %s...\n", fileName);
	fp = fopen(fileName, "r");	// open the file
	
	if (fp != NULL)	// if fp not null, the file was opened successfully
	{
		c = fgetc(fp);	// get first char in file
		while (!feof(fp))	// loop until end of file
		{
			if (isspace(c)) inWord = 0;	// it's a space!
			else if (inWord == 0)	// it's a word!
			{
				inWord = 1;	// set inWord flag until we get a space
				wordCount ++;	// increment word count
			}
			c = getc(fp);	// get next char in file
		}
		fclose(fp);		// close the file
		// print the word count
		printf("The word count is %d.\n", wordCount);
	}
	else	// the file could not be opened
	{
		printf("The file %s does not exist or cannot be opened.\n", fileName);
	}
	
	return 0;
}
