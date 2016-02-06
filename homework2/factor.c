/*	HOMEWORK 2.3
	factor.c:
	Prompts the user for a POSITIVE INTEGER and prints
	all the integer factors of that integer.
	by Tom Grushka
	February 5, 2016	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*	Execution time from Thomas Pornin
	http://stackoverflow.com/questions/5248915/execution-time-of-c-program	*/
clock_t begin, end;
double time_spent;

/*	Array type adapted from casablanca
	http://stackoverflow.com/questions/3536153/c-dynamically-growing-array 	*/
	typedef struct {
	  long long *array;
	  size_t used;
	  size_t size;
	} Array;
	
	// function to initialise the array
	void initArray(Array *a, size_t initialSize) {
	  a->array = (long long *)malloc(initialSize * sizeof(long long));
	  a->used = 0;
	  a->size = initialSize;
	}
	
	// function to add an item to the array
	void insertArray(Array *a, long long element) {
	  if (a->used == a->size) {
	    a->size *= 2;
	    a->array = (long long *)realloc(a->array, a->size * sizeof(long long));
	  }
	  a->array[a->used++] = element;
	}
	
	// function to free the memory used by the array
	void freeArray(Array *a) {
	  free(a->array);
	  a->array = NULL;
	  a->used = a->size = 0;
	}
/*	End of Array type	*/

Array prime;

// 	declare functions
long long getLongLong(const char *prompt);
int checkPrime(long long number);

/*	checkPrime: determine if the given number is prime;
		if prime, add it to the prime Array and return 1;
		if not, return 0.
	arguments: number (long long)
	returns: integer 0 (false) or 1 (true)	*/
int checkPrime(long long number)
{
	int isPrime = 1;	// flag (0 = false, 1 = true)
	int sq = 0;			// store square root
	sq = sqrt(number);	// get square root of number
	if (number == 1) return 0;	// not a prime; prevent false negatives
	//  these quick checks cut processing time a little
	if (number % 2 == 0 || number % 3 == 0) return 0;
	//  loop through the array:
	for (int i = 0; i < prime.used; i++)
	{
		if (prime.array[i] > sq) break;  // stopping at square root of the number saves a whole lot of time
		if (number % prime.array[i] == 0) {
			isPrime = 0; 	// divisible by another prime
			break;			// don't check any more
		}
	}
	// if prime, add to array
	if (isPrime) insertArray(&prime, number);
	return isPrime;			// return the flag
}

int main(int argc, char** argv)
{
	long long number = 0;	// input number (long long)
	long long sqroot = 0;	// square root of input number (long long)
	
	int checkForPrime = 0;		// input - skip prime number checking if 0
	int checkEvenNumbers = 0;	// input - skip even number checking if 0
	int printAllNumbers = 0;	// input - print out all numbers, not just factors; or, print just primes
	
	int isPrime = 0;
	initArray(&prime, 10);  // initially 10 spaces for prime numbers
	insertArray(&prime, 2);
	
	do {
		number = getLongLong("Enter a positive integer: ");
	} while (number < 1);
	
	checkForPrime = (int)getLongLong("Check for Prime Numbers? ");
	
	if (number % 2 == 1)
		checkEvenNumbers = 0;
	else
		checkEvenNumbers = (int)getLongLong("Check Even Numbers? ");
	
	if (checkForPrime)
		printAllNumbers = (int)getLongLong("Print All Prime Numbers? ");
	else
		printAllNumbers = (int)getLongLong("Print All Numbers? ");
	
	sqroot = sqrt(number);
	
	printf("Square Root (rounded down): %lld\n\n", sqroot);
	
	printf("Number                          Prime  Multiplier\n");
	printf("==============================  =====  ==============================\n");
	begin = clock();
	for (long long factor = 1; factor < sqroot; factor += (1 + (!checkEvenNumbers)))
	{
		if (checkForPrime) isPrime = checkPrime(factor);
		if (number % factor == 0) {
			printf("%30lld  %5s  %30lld\n", factor, (isPrime ? "Y" : ""), number / factor);
		} else if ((checkForPrime && isPrime && printAllNumbers) || (!checkForPrime && printAllNumbers)) {
			printf("%30lld  %5s\n", factor, (isPrime ? "Y" : ""));
		}
	}
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nExecution time: %f s\n\n", time_spent);
	
	freeArray(&prime);
	
	return 0;
}

/*	getInteger
	argument:	prompt (const char *)
				string to prompt the user
	return:		user input converted to integer	*/
long long getLongLong(const char *prompt)
{
	// Some code by David C. Rankin, http://stackoverflow.com/questions/27326839/how-to-read-input-of-unknown-length-using-fgets
	char *input = NULL;		// input buffer
	long long myLongLong = 0;			// integer to return
    size_t n = 0;           // max chars to read (0 = no limit)
    ssize_t nchr = 0;       // # chars read
	
	printf("%s", prompt);	// Display the prompt
	
	if ((nchr = getline(&input, &n, stdin)) != -1)
		input[--nchr] = 0;	// strip newline
	
	myLongLong = atoll(input);	// convert to integer & store
	
	free(input);			// "de-allocate" input variable
	
	return myLongLong;			// return integer
}
