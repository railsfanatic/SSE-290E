#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*	getString: gets a string input from the user
		in: length (int):			max length of string
			prompt (const char *):	prompt to print out
		returns:	(char *)
*/
char *getString(int length, const char *prompt)
{
	char *s = (char *)malloc(length);	// allocate return string
	int i;
	
	printf("%s", prompt);
	
	fgets(s, length, stdin);
	i = strlen(s);
	if (s[i-1] != '\n') while (getchar() != '\n');
	if (s[i] == '\n') s[i] = '\0';
	
	return s;
}

int getInteger(const char *prompt)
{
	return atoi(getString(10, prompt));
}

/*	strrev: returns a string reversed
		in: str (char *):		string to reverse
		returns:	(char *):	reversed string
		from: http://stackoverflow.com/questions/8534274/is-the-strrev-function-not-available-in-linux
*/
char *strrev(char *str)
{
      char *p1, *p2;	// char swap pointers
	  char *rev;		// reversed string pointer
	  
      if (! str || ! *str) return str;	// no input
      
	  rev = (char *)malloc(strlen(str));	// allocate rev
	  strcpy(rev, str);		// copy str to rev to keep original intact
	  
	  // swap loop: two counters from start and end
	  for (p1 = rev, p2 = rev + strlen(rev) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;		// bitwise XOR swap
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return rev;	// return rev; we still have original str!
}

void inputArray(int size, int *a)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("[%3d]  ", i);
		a[i] = getInteger("");
	}
}

void reverseArray(int size, int *a)
{
	int i = 0, j = size;
	for (i = 0; i < size / 2; i++)
	{
		j = size - i - 1;
		a[i] = a[i] ^ a[j];
		a[j] = a[i] ^ a[j];
		a[i] = a[i] ^ a[j];
	}
}

void fillRandom(int size, int *a, int min, int max)
{
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min) + min;
	}
}

void printArray(int size, int *a)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("[%2d]  %4d     ", i, a[i]);
		if (i % 5 == 4) printf("\n");
	}
	printf("\n");
}

int findLowest(int size, int *a)
{
	int i = 0;
	int lowest = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] < a[lowest]) lowest = i;
	}
	return lowest;
}

void bubbleSort(int size, int *a)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] > a[i+1]) {
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
}

/* private funcs for mergeSort */

void copyArray(int *b, int iBegin, int iEnd, int *a)
{
	int k = 0;
	for (k = iBegin; k < iEnd; k++)
	{
		a[k] = b[k];
	}
}

void topDownMerge(int *a, int iBegin, int iMiddle, int iEnd, int *b)
{
	int i = iBegin;
	int j = iMiddle;
	int k = 0;
	for (k = iBegin; k < iEnd; k++)
	{
		if (i < iMiddle && (j >= iEnd || a[i] <= a[j]))
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
	}
}

void splitMerge(int *a, int iBegin, int iEnd, int *b)
{
	if (iEnd - iBegin < 2) return;
	int iMiddle = (iEnd + iBegin) / 2;
	splitMerge(a, iBegin, iMiddle, b);
	splitMerge(a, iMiddle, iEnd, b);
	topDownMerge(a, iBegin, iMiddle, iEnd, b);
	copyArray(b, iBegin, iEnd, a);
}

void mergeSort(int size, int *a)
{
	int work[size];
	splitMerge(a, 0, size, work);
}



