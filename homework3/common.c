/*	HOMEWORK 3
	File:	common.c
	Module:	Common functions for Homework 3
	by Tom Grushka
	Mar. 11, 2016
*/

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
	// declarations
	char *s = (char *)malloc(length);	// allocate return string
	int i;	// length of entered string
	
	// print prompt
	printf("%s", prompt);
	
	// get string from user, store in s
	fgets(s, length, stdin);
	
	// length of string entered
	i = strlen(s);
	
	// clear remaining buffer and remove newline from s
	if (s[i-1] != '\n') while (getchar() != '\n');
	if (s[i-1] == '\n') s[i-1] = '\0';
	
	// return entered string
	return s;
}

/*	getInteger: gets an integer input from the user
		in: prompt (const char *):	prompt to print out
		depends on:	getString()
		returns:	input string converted to integer
*/
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

/*	getInteger: inputs an integer array from the user
		in:			size (int) = size of array
					pointer to a[size] (int) = the array
		depends on:	getInteger()
		stores user input back into array at *a
*/
void inputArray(int size, int *a)
{
	int i = 0;	// loop counter
	
	for (i = 0; i < size; i++)	// loop through array
	{
		printf("[%3d]  ", i);	// print index position
		a[i] = getInteger("");	// input array element
	}
}

/*	reverseArray: reverses an array in place
		using bitwise XOR manipulation
		in:	size (int) = size of array
			pointer to a[size] (int) = the array
*/
void reverseArray(int size, int *a)
{
	// declarations
	int i = 0, j = size;
	
	// loop count to half of array
	for (i = 0; i < size / 2; i++)
	{
		j = size - i - 1;	// "other end" position
		a[i] = a[i] ^ a[j];	// bitwise XOR swap
		a[j] = a[i] ^ a[j];
		a[i] = a[i] ^ a[j];
	}
}

/*	fillRandom: fill existing array with random integers
		in:	size (int) = size of array
			*a[size] (int) = pointer to array
			min (int) = minimum random value
			max (int) = maximum random value
		fills in place (no return value)
*/
void fillRandom(int size, int *a, int min, int max)
{
	int i = 0;	// loop counter
	
	// seed random number generator with current time
	srand(time(NULL));
	
	// loop through array
	for (i = 0; i < size; i++)
	{
		/*	set array element to random value between
			min and max */
		a[i] = rand() % (max - min) + min;
	}
}

/*	printArray: print an array out to the user
		in:	size (int) = size of array
			*a[size] (int) = pointer to array
*/
void printArray(int size, int *a)
{
	int i = 0;	// loop counter
	
	// loop through the array
	for (i = 0; i < size; i++)
	{
		// print position index and element value
		printf("[%2d]  %4d     ", i, a[i]);
		
		// print 5 values per row, then newline
		if (i % 5 == 4) printf("\n");
	}
	printf("\n");	// print newline at the end
}

/*	findLowest: find lowest value in an array
		in:	size (int) = size of array
			*a[size] (int) = pointer to array
		returns:	(int) index of lowest value in a
*/
int findLowest(int size, int *a)
{
	int i = 0;	// loop counter
	int lowest = 0;	// lowest value index
	for (i = 0; i < size; i++)	// loop through array
	{
		// if this value is the lowest, update lowest index
		if (a[i] < a[lowest]) lowest = i;
	}
	return lowest;	// return index of lowest value
}

/*	bubbleSort: sorts array using slow bubble algorithm
		in:	size (int) = size of array
			*a[size] (int) = pointer to array
		returns:	(int) index of lowest value in a
*/
void bubbleSort(int size, int *a)
{
	// declarations
	int i = 0;	// loop counter
	int temp = 0;	// temp swap variable
	int swapped = 0;	// flag if swap performed
	
	do { // repeat the loop
		// loop through array
		for (i = 0; i < (size - 1); i++)
		{
			if (a[i] > a[i+1]) {
				// swap using temp variable
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			
				// set swapped flag
				swapped = 1;
			}
		}
	} while (swapped); // keep looping until nothing swapped
}

/*	mergeSort:
	Code derived from Top-down implementation:
	https://en.wikipedia.org/wiki/Merge_sort  */

/*	copyArray: copies int array elements from b to a
		in:	*b[] (int) = pointer to source array
			*a[] (int) = pointer to destination array
			iBegin (int) = copy from index
			iEnd (int) = copy to index
*/
void copyArray(int *b, int iBegin, int iEnd, int *a)
{
	int k = 0;	// counter
	for (k = iBegin; k < iEnd; k++)
	{
		// copy from b to a at index k
		a[k] = b[k];
	}
}

/*	topDownMerge: does the real "work" of sorting for the
		split-merge algorithm
		in:	*a[] (int) = pointer to A array
			*b[] (int) = pointer to B array
			iBegin (int) = beginning index
			iMiddle (int) = index between iBegin and iEnd
			iEnd (int) = end index
*/
void topDownMerge(int *a, int iBegin, int iMiddle, int iEnd, int *b)
{
	// declare index counters
	int i = iBegin;
	int j = iMiddle;
	int k = 0;
	
	// loop from beginning to end of range
	for (k = iBegin; k < iEnd; k++)
	{
		// perform the sort
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

/*	splitMerge: sorts an array using split merge algorithm
		in:	*a[] (int) = pointer to A array
			*b[] (int) = pointer to B array
			iBegin (int) = index to begin
			iEnd (int) = index to end
*/
void splitMerge(int *a, int iBegin, int iEnd, int *b)
{
	// if only one element left, we're done
	if (iEnd - iBegin < 2) return;
	
	// get index exactly between iBegin and iEnd
	int iMiddle = (iEnd + iBegin) / 2;
	
	// recursively call splitMerge for "left" side
	splitMerge(a, iBegin, iMiddle, b);
	
	// recursively call splitMerge for "right" side
	splitMerge(a, iMiddle, iEnd, b);
	
	// perform top-down merge on the range
	topDownMerge(a, iBegin, iMiddle, iEnd, b);
	
	// copy A array to B from index iBegin to iEnd
	copyArray(b, iBegin, iEnd, a);
}

/*	mergeSort: sorts an array using split merge algorithm
		in:	size (int) = size of array
			*a[size] (int) = pointer to array to sort
	this is mainly a wrapper function so a work array
	and 0 do not need to be passed in;
	real work done in splitMerge()
*/
void mergeSort(int size, int *a)
{
	int work[size];	// temporary "work" array
	splitMerge(a, 0, size, work);
}



