/*	HOMEWORK 5.2
	wordcount.c
	Counts the number of words in a text file.
	by Tom Grushka
	April 18, 2016	*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define DEFAULT_FILENAME "test.txt"

int main(int argc, char **argv)
{
	FILE *fp;
	char c;
	int wordCount = 0;
	int inWord = 0;
	char fileName[255];
	
	if (argc == 1)
	{
		printf("Please enter the file name:\n");
		scanf("%s", fileName);
	}
	else strcpy(fileName, argv[1]);
	if (strcmp(fileName, "") == 0) strcpy(fileName, DEFAULT_FILENAME);
	
	printf("Counting words in %s...\n", fileName);
	fp = fopen(fileName, "r");
	
	if (fp != NULL)
	{
		c = fgetc(fp);
		while (!feof(fp))
		{
			if (isspace(c)) inWord = 0;
			else if (inWord == 0)
			{
				inWord = 1;
				wordCount ++;
			}
			c = getc(fp);
		}
		fclose(fp);
		printf("The word count is %d.\n", wordCount);
	}
	else
	{
		printf("The file %s does not exist or cannot be opened.\n", fileName);
	}
	
	return 0;
}
